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
    browser();

    ui->editSqlQuery->setPlaceholderText("ex.: SELECT name FROM employee WHERE salary = null"); //example query write to help
    ui->actualDbPath->setText(""); // initial clear of information about opened file


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionExit_triggered()
{
    exit(0);
}


void MainWindow::on_editSqlQuery_textEdited()
{



}

void MainWindow::on_actionOpen_triggered()
{
        sqlfilename=QFileDialog::getOpenFileName(
               this,
               tr("Open file"),
               "C://",
               //"SQLite (*.SQLite);;db (*.db)"
               "ALL files (*.*)"
               );
//calling function from Browser class
   openDb(sqlfilename);
//

   ui->actualDbPath->setText(sqlfilename);
}

void MainWindow::on_editSqlQuery_editingFinished()
{
    QString querycommand=ui->editSqlQuery->text();

    execDb(querycommand);

   // ui->tableView->setModel(query->);

}

