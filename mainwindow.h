#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QObject>
#include <QFileSystemModel>
#include <QItemSelection>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onSourceDirectoryChanged(const QModelIndex &index);
    void onDestinationDirectoryChanged(const QModelIndex &index);
    void onSelectionChanged(const QItemSelection &selected, const QItemSelection &deselected);
    void onCopyButtonClicked();
    void onUpButtonClicked();
    void onHomeButtonClicked();

private:
    Ui::MainWindow *ui;
    QFileSystemModel *dirModel;
    QFileSystemModel *fileModel;
    QList<QString> selectedFiles;
    QString currentSourcePath;
    QString currentDestinationPath;

    void setupFileSystem();
    void copyFiles(const QStringList &files, const QString &destination);
};

#endif // MAINWINDOW_H
