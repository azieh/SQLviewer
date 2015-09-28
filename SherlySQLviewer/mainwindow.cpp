#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "browser.h"
//
#include <QtSql>
#include <QFileDialog>
#include <QMessageBox>
//

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    setWindowIcon(QIcon(":/ico/icoSherly.png")); //set Sher.ly ico to main window

    ui->setupUi(this);

    tableview->setModel(model);
    tableview->setAlternatingRowColors(true);

    ui->editSqlQuery->setPlaceholderText("ex.: SELECT name FROM employee WHERE salary = null"); //example query write to help
    ui->actualDbPath->setText("..."); // initial clear of information about opened file
    statusBar()->showMessage(tr("Load DB file")); // set first information for user

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionExit_triggered()
{
    exit(0);
}

void MainWindow::on_actionOpen_triggered()
{
    sqlfilename=QFileDialog::getOpenFileName(
               this,
               tr("Open file"),
               "C://", // default open directory
               "db (*.db);;SQLite (*.SQLite)" // default posible file extension
               );
    ui->actualDbPath->setText(sqlfilename); //inform user about actual DB directory

//calling function from Browser class
    openDb(sqlfilename);
//


    statusBar()->showMessage(actualstatus); // Path status info | Use always after openDb();
}


void MainWindow::on_pushClearButton_clicked()
{
    ui->editSqlQuery->clear();
}

void MainWindow::on_pushQueryButton_clicked()
{
    QString querycommand=ui->editSqlQuery->text(); //read query command from window

    execDb(querycommand); //execute query command
    statusBar()->showMessage(actualstatus); // Query status info | Use always after execDb();

    model->setQuery(*query);
    ui->tableView->setModel(model);
}
