#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "smartptr.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QDebug>




MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , dirModel(new QFileSystemModel(this))
    , fileModel(new QFileSystemModel(this))
{
    ui->setupUi(this);
    setupFileSystem();

    // Подключение сигналов к слотам с правильными типами
    connect(ui->sourceDirView, &QTreeView::doubleClicked,
            this, &MainWindow::onSourceDirectoryChanged);
    connect(ui->destinationDirView, &QTreeView::doubleClicked,
            this, &MainWindow::onDestinationDirectoryChanged);
    connect(ui->fileListView->selectionModel(), &QItemSelectionModel::selectionChanged,
            this, &MainWindow::onSelectionChanged);
    connect(ui->copyButton, &QPushButton::clicked,
            this, &MainWindow::onCopyButtonClicked);
    connect(ui->upButton, &QPushButton::clicked,
            this, &MainWindow::onUpButtonClicked);
    connect(ui->homeButton, &QPushButton::clicked,
            this, &MainWindow::onHomeButtonClicked);
    connect(ui->upButton, &QPushButton::clicked,
            this, &MainWindow::onUpButtonClicked);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setupFileSystem()
{
    dirModel->setFilter(QDir::NoDotAndDotDot | QDir::AllDirs);
    fileModel->setFilter(QDir::NoDotAndDotDot | QDir::Files);

    ui->sourceDirView->setModel(dirModel);
    ui->destinationDirView->setModel(dirModel);
    ui->fileListView->setModel(fileModel);

    QString homePath = QDir::homePath();
    dirModel->setRootPath(homePath);
    fileModel->setRootPath(homePath);

    ui->sourceDirView->setRootIndex(dirModel->index(homePath));
    ui->destinationDirView->setRootIndex(dirModel->index(homePath));
    ui->fileListView->setRootIndex(fileModel->index(homePath));

    currentSourcePath = homePath;
    currentDestinationPath = homePath;
    ui->sourcePathEdit->setText(homePath);
    ui->destinationPathEdit->setText(homePath);
}


void MainWindow::onSourceDirectoryChanged(const QModelIndex &index)
{
    QString path = dirModel->filePath(index);
    if (dirModel->isDir(index)) {
        currentSourcePath = path;
        ui->sourcePathEdit->setText(path);
        fileModel->setRootPath(path);
        ui->fileListView->setRootIndex(fileModel->index(path));
    }
}

void MainWindow::onDestinationDirectoryChanged(const QModelIndex &index)
{
    QString path = dirModel->filePath(index);
    if (dirModel->isDir(index)) {
        currentDestinationPath = path;
        ui->destinationPathEdit->setText(path);
    }
}


void MainWindow::onSelectionChanged(const QItemSelection &selected, const QItemSelection &deselected)
{
    Q_UNUSED(deselected);
    selectedFiles.clear();

    // Получаем список всех выделенных индексов
    QModelIndexList indexes = ui->fileListView->selectionModel()->selectedIndexes();

    foreach(const QModelIndex &index, indexes) {
        // Проверяем, что индекс валиден и соответствует файлу (а не директории)
        if (index.isValid() && !fileModel->isDir(index)) {
            QString filePath = fileModel->filePath(index);
            if (!selectedFiles.contains(filePath)) {  // Защита от дубликатов
                selectedFiles.append(filePath);
            }
        }
    }
}

void MainWindow::onCopyButtonClicked()
{
    if (selectedFiles.isEmpty()) {
        QMessageBox::warning(this, "Ошибка", "Не выбраны файлы для копирования");
        return;
    }

    if (currentDestinationPath.isEmpty()) {
        QMessageBox::warning(this, "Ошибка", "Не выбрана целевая директория");
        return;
    }

    QDir destDir(currentDestinationPath);
    if (!destDir.exists()) {
        QMessageBox::warning(this, "Ошибка", "Целевая директория не существует");
        return;
    }

    // Проверка и подтверждение перезаписи
    QStringList filesToCopy;
    foreach (const QString &filePath, selectedFiles) {
        QFileInfo fileInfo(filePath);
        QString destinationPath = currentDestinationPath + "/" + fileInfo.fileName();

        if (QFile::exists(destinationPath)) {
            QMessageBox::StandardButton reply = QMessageBox::question(
                this, "Подтверждение",
                QString("Файл %1 уже существует. Перезаписать?").arg(fileInfo.fileName()),
                QMessageBox::Yes|QMessageBox::No);
            if (reply == QMessageBox::No) continue;
            QFile::remove(destinationPath);
        }
        filesToCopy.append(filePath);
    }

    // Основное копирование
    int successCount = 0;
    int errorCount = 0;
    bool allSuccess = copyFiles(filesToCopy, currentDestinationPath, successCount, errorCount);

    // Отчет о результатах
    if (!allSuccess) {
        QMessageBox::information(this, "Результат",
                                 QString("Скопировано %1 файлов, %2 ошибок").arg(successCount).arg(errorCount));
    } else {
        QMessageBox::information(this, "Успех",
                                 QString("Все %1 файлов успешно скопированы").arg(successCount));
    }
}


void MainWindow::onUpButtonClicked()
{
    QDir dir(currentSourcePath);
    if (dir.cdUp()) {
        currentSourcePath = dir.path();
        ui->sourcePathEdit->setText(currentSourcePath);
        fileModel->setRootPath(currentSourcePath);
        ui->fileListView->setRootIndex(fileModel->index(currentSourcePath));
        ui->sourceDirView->setRootIndex(dirModel->index(currentSourcePath));
    }
}

void MainWindow::onHomeButtonClicked()
{
    QString homePath = QDir::homePath();
    currentSourcePath = homePath;
    ui->sourcePathEdit->setText(homePath);
    fileModel->setRootPath(homePath);
    ui->fileListView->setRootIndex(fileModel->index(homePath));
    ui->sourceDirView->setRootIndex(dirModel->index(homePath));
}

bool MainWindow::copyFiles(const QStringList &files, const QString &destination, int &successCount, int &errorCount)
{
    successCount = 0;
    errorCount = 0;

    foreach (const QString &filePath, files) {
        QFileInfo fileInfo(filePath);
        QString destinationPath = destination + "/" + fileInfo.fileName();

        smart_ptr<QFile> sourceFile(new QFile(filePath));
        if (!sourceFile->open(QIODevice::ReadOnly)) {
            qDebug() << "Не удалось открыть файл для чтения:" << filePath;
            errorCount++;
            continue;
        }

        smart_ptr<QFile> destFile(new QFile(destinationPath));
        if (!destFile->open(QIODevice::WriteOnly)) {
            qDebug() << "Не удалось открыть файл для записи:" << destinationPath;
            errorCount++;
            continue;
        }

        bool copyError = false;
        while (!sourceFile->atEnd()) {
            QByteArray data = sourceFile->read(8192);
            if (destFile->write(data) != data.size()) {
                errorCount++;
                copyError = true;
                break;
            }
        }

        if (!copyError) {
            successCount++;
        }
    }

    return (errorCount == 0);
}

void MainWindow::on_upDestButton_clicked()
{
    QDir dir(currentDestinationPath);
    if (dir.cdUp()) {
        currentDestinationPath = dir.path();
        ui->destinationPathEdit->setText(currentDestinationPath);
        fileModel->setRootPath(currentDestinationPath);
        ui->fileListView->setRootIndex(fileModel->index(currentDestinationPath));
        ui->destinationDirView->setRootIndex(dirModel->index(currentDestinationPath));
    }
}


