/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTreeView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLineEdit *sourcePathEdit;
    QTreeView *sourceDirView;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_2;
    QLineEdit *destinationPathEdit;
    QTreeView *destinationDirView;
    QListView *fileListView;
    QWidget *horizontalLayoutWidget_3;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *copyButton;
    QPushButton *upButton;
    QPushButton *homeButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(901, 741);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        horizontalLayoutWidget = new QWidget(centralwidget);
        horizontalLayoutWidget->setObjectName("horizontalLayoutWidget");
        horizontalLayoutWidget->setGeometry(QRect(10, 10, 381, 311));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        label = new QLabel(horizontalLayoutWidget);
        label->setObjectName("label");

        verticalLayout->addWidget(label);

        sourcePathEdit = new QLineEdit(horizontalLayoutWidget);
        sourcePathEdit->setObjectName("sourcePathEdit");
        sourcePathEdit->setReadOnly(false);

        verticalLayout->addWidget(sourcePathEdit);

        sourceDirView = new QTreeView(horizontalLayoutWidget);
        sourceDirView->setObjectName("sourceDirView");
        sourceDirView->setMaximumSize(QSize(377, 16777215));
        sourceDirView->setSelectionMode(QAbstractItemView::SelectionMode::ExtendedSelection);
        sourceDirView->setSelectionBehavior(QAbstractItemView::SelectionBehavior::SelectItems);

        verticalLayout->addWidget(sourceDirView);


        horizontalLayout->addLayout(verticalLayout);

        horizontalLayoutWidget_2 = new QWidget(centralwidget);
        horizontalLayoutWidget_2->setObjectName("horizontalLayoutWidget_2");
        horizontalLayoutWidget_2->setGeometry(QRect(500, 10, 391, 311));
        horizontalLayout_2 = new QHBoxLayout(horizontalLayoutWidget_2);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        label_2 = new QLabel(horizontalLayoutWidget_2);
        label_2->setObjectName("label_2");

        verticalLayout_2->addWidget(label_2);

        destinationPathEdit = new QLineEdit(horizontalLayoutWidget_2);
        destinationPathEdit->setObjectName("destinationPathEdit");
        destinationPathEdit->setReadOnly(false);

        verticalLayout_2->addWidget(destinationPathEdit);

        destinationDirView = new QTreeView(horizontalLayoutWidget_2);
        destinationDirView->setObjectName("destinationDirView");
        destinationDirView->setSelectionMode(QAbstractItemView::SelectionMode::ExtendedSelection);
        destinationDirView->setSelectionBehavior(QAbstractItemView::SelectionBehavior::SelectItems);

        verticalLayout_2->addWidget(destinationDirView);


        horizontalLayout_2->addLayout(verticalLayout_2);

        fileListView = new QListView(centralwidget);
        fileListView->setObjectName("fileListView");
        fileListView->setGeometry(QRect(300, 330, 281, 271));
        fileListView->setSelectionMode(QAbstractItemView::SelectionMode::ExtendedSelection);
        horizontalLayoutWidget_3 = new QWidget(centralwidget);
        horizontalLayoutWidget_3->setObjectName("horizontalLayoutWidget_3");
        horizontalLayoutWidget_3->setGeometry(QRect(280, 620, 331, 41));
        horizontalLayout_3 = new QHBoxLayout(horizontalLayoutWidget_3);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        copyButton = new QPushButton(horizontalLayoutWidget_3);
        copyButton->setObjectName("copyButton");

        horizontalLayout_3->addWidget(copyButton);

        upButton = new QPushButton(horizontalLayoutWidget_3);
        upButton->setObjectName("upButton");

        horizontalLayout_3->addWidget(upButton);

        homeButton = new QPushButton(horizontalLayoutWidget_3);
        homeButton->setObjectName("homeButton");

        horizontalLayout_3->addWidget(homeButton);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 901, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\320\230\321\201\321\202\320\276\321\207\320\275\320\270\320\272:", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "\320\235\320\260\320\267\320\275\320\260\321\207\320\265\320\275\320\270\320\265:", nullptr));
        copyButton->setText(QCoreApplication::translate("MainWindow", "\320\232\320\276\320\277\320\270\321\200\320\276\320\262\320\260\321\202\321\214", nullptr));
        upButton->setText(QCoreApplication::translate("MainWindow", "\320\222\320\262\320\265\321\200\321\205", nullptr));
        homeButton->setText(QCoreApplication::translate("MainWindow", "\320\224\320\276\320\274\320\276\320\271", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
