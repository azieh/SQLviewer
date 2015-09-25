/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionOpen;
    QAction *actionExit;
    QWidget *centralWidget;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout_3;
    QFormLayout *formLayout_5;
    QLabel *staticActualOpenDb;
    QLabel *actualDbPath;
    QLabel *staticSQLquery;
    QLineEdit *editSqlQuery;
    QSpacerItem *horizontalSpacer;
    QTableView *tableView;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->setWindowModality(Qt::ApplicationModal);
        MainWindow->resize(935, 621);
        QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(935, 621));
        MainWindow->setMaximumSize(QSize(935, 621));
        MainWindow->setFocusPolicy(Qt::StrongFocus);
        MainWindow->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        MainWindow->setDocumentMode(false);
        MainWindow->setTabShape(QTabWidget::Rounded);
        MainWindow->setDockOptions(QMainWindow::AllowTabbedDocks|QMainWindow::AnimatedDocks);
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName(QStringLiteral("actionOpen"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/ico/open_256.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionOpen->setIcon(icon);
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QStringLiteral("actionExit"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/ico/close_sq.ico"), QSize(), QIcon::Normal, QIcon::Off);
        actionExit->setIcon(icon1);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayoutWidget = new QWidget(centralWidget);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(0, 10, 931, 481));
        verticalLayout_3 = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setSizeConstraint(QLayout::SetNoConstraint);
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        formLayout_5 = new QFormLayout();
        formLayout_5->setSpacing(6);
        formLayout_5->setObjectName(QStringLiteral("formLayout_5"));
        formLayout_5->setSizeConstraint(QLayout::SetDefaultConstraint);
        formLayout_5->setFieldGrowthPolicy(QFormLayout::ExpandingFieldsGrow);
        formLayout_5->setRowWrapPolicy(QFormLayout::WrapLongRows);
        formLayout_5->setFormAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        formLayout_5->setHorizontalSpacing(13);
        formLayout_5->setVerticalSpacing(7);
        formLayout_5->setContentsMargins(9, 9, 11, 11);
        staticActualOpenDb = new QLabel(verticalLayoutWidget);
        staticActualOpenDb->setObjectName(QStringLiteral("staticActualOpenDb"));
        staticActualOpenDb->setMaximumSize(QSize(192, 16777215));
        QFont font;
        font.setPointSize(9);
        staticActualOpenDb->setFont(font);

        formLayout_5->setWidget(0, QFormLayout::LabelRole, staticActualOpenDb);

        actualDbPath = new QLabel(verticalLayoutWidget);
        actualDbPath->setObjectName(QStringLiteral("actualDbPath"));
        QSizePolicy sizePolicy1(QSizePolicy::Maximum, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(actualDbPath->sizePolicy().hasHeightForWidth());
        actualDbPath->setSizePolicy(sizePolicy1);
        actualDbPath->setFont(font);
        actualDbPath->setFrameShape(QFrame::StyledPanel);
        actualDbPath->setFrameShadow(QFrame::Sunken);
        actualDbPath->setLineWidth(5);

        formLayout_5->setWidget(0, QFormLayout::FieldRole, actualDbPath);

        staticSQLquery = new QLabel(verticalLayoutWidget);
        staticSQLquery->setObjectName(QStringLiteral("staticSQLquery"));
        staticSQLquery->setEnabled(true);
        QSizePolicy sizePolicy2(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(staticSQLquery->sizePolicy().hasHeightForWidth());
        staticSQLquery->setSizePolicy(sizePolicy2);
        staticSQLquery->setMaximumSize(QSize(84, 21));
        QFont font1;
        font1.setPointSize(10);
        staticSQLquery->setFont(font1);
        staticSQLquery->setLayoutDirection(Qt::LeftToRight);
        staticSQLquery->setFrameShape(QFrame::NoFrame);
        staticSQLquery->setFrameShadow(QFrame::Plain);
        staticSQLquery->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        staticSQLquery->setMargin(0);
        staticSQLquery->setIndent(0);

        formLayout_5->setWidget(1, QFormLayout::LabelRole, staticSQLquery);

        editSqlQuery = new QLineEdit(verticalLayoutWidget);
        editSqlQuery->setObjectName(QStringLiteral("editSqlQuery"));
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::Maximum);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(editSqlQuery->sizePolicy().hasHeightForWidth());
        editSqlQuery->setSizePolicy(sizePolicy3);
        editSqlQuery->setFont(font);
        editSqlQuery->setFrame(true);
        editSqlQuery->setDragEnabled(false);
        editSqlQuery->setCursorMoveStyle(Qt::LogicalMoveStyle);

        formLayout_5->setWidget(1, QFormLayout::FieldRole, editSqlQuery);


        verticalLayout_3->addLayout(formLayout_5);

        horizontalSpacer = new QSpacerItem(40, 3, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout_3->addItem(horizontalSpacer);

        tableView = new QTableView(verticalLayoutWidget);
        tableView->setObjectName(QStringLiteral("tableView"));
        QSizePolicy sizePolicy4(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(tableView->sizePolicy().hasHeightForWidth());
        tableView->setSizePolicy(sizePolicy4);
        tableView->setMaximumSize(QSize(1000, 1000));

        verticalLayout_3->addWidget(tableView);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 935, 26));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        mainToolBar->setLayoutDirection(Qt::LeftToRight);
        mainToolBar->setAutoFillBackground(false);
        mainToolBar->setMovable(false);
        mainToolBar->setAllowedAreas(Qt::NoToolBarArea);
        mainToolBar->setIconSize(QSize(78, 40));
        mainToolBar->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        mainToolBar->setFloatable(true);
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuFile->addAction(actionOpen);
        menuFile->addSeparator();
        menuFile->addAction(actionExit);
        mainToolBar->addAction(actionOpen);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionExit);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Sherly SQLviewer", 0));
        actionOpen->setText(QApplication::translate("MainWindow", "Open", 0));
        actionExit->setText(QApplication::translate("MainWindow", "Exit", 0));
        staticActualOpenDb->setText(QApplication::translate("MainWindow", "Actual opened db connection:", 0));
        actualDbPath->setText(QApplication::translate("MainWindow", "actual db path", 0));
        staticSQLquery->setText(QApplication::translate("MainWindow", "SQL Query:", 0));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
