#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "browser.h"
#include "editstrategysettings.h"
//
#include <QtSql>
#include <QFileDialog>
#include <QMessageBox>
//

MainWindow::MainWindow(Browser* browser, EditStrategySettings* settings,  QWidget *parent) :
    QMainWindow(parent),
    _browser( browser ),
    _settings ( settings ),
    ui(new Ui::MainWindow)
{
    setWindowIcon(QIcon(":/ico/icoSherly.png")); //set Sher.ly ico to main window

    ui->setupUi(this);

    ui->tableView->setAlternatingRowColors(true);

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
    _browser->openDb(sqlfilename);



    statusBar()->showMessage(_browser->actualstatus); // Path status info | Use always after openDb();
}


void MainWindow::on_pushClearButton_clicked()
{
    ui->editSqlQuery->clear();
}

void MainWindow::on_pushQueryButton_clicked()
{
    QString querycommand=ui->editSqlQuery->text(); //read query command from window

      _browser->execDb(querycommand); //execute query command
      statusBar()->showMessage(_browser->actualstatus); // Query status info | Use always after execDb();

      _browser->model->setQuery(*_browser->query);
      ui->tableView->setModel(_browser->model);
}

void MainWindow::on_actionSettings_triggered()
{
     _settings->show();
}
