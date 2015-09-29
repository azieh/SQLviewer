#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "browser.h"
#include "editstrategysettings.h"
//
#include <QtSql>
#include <QFileDialog>
#include <QMessageBox>
//

MainWindow::MainWindow(Browser* browser,  QWidget *parent) :
    QMainWindow(parent),
    _browser( browser ),
    ui(new Ui::MainWindow)
{
    setWindowIcon(QIcon(":/ico/icoSherly.png")); //set Sher.ly ico to main window

    ui->setupUi(this);

    ui->tableView->setAlternatingRowColors(true); //set colours of tableview

    ui->editSqlQuery->setPlaceholderText("ex.: City = 'Krakow'"); //example query write to help

    ui->pushCommitButton->setVisible(false); //hide Commit button | set Visible after disable option READ ONLY

    statusBar()->showMessage(tr("Load DB file")); // set first information for user

    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);

    setSettingsSlot(3);


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
    setWindowTitle("SQLviewer:  "+sqlfilename); //inform user about actual DB directory

    _browser->openDb(sqlfilename); //calling function from Browser class

    ui->listView->setModel(_browser->tableslistmodel); //update tables list view

    statusBar()->showMessage(_browser->actualstatus); // Path status info | Use always after openDb();
}


void MainWindow::on_pushPushButton_clicked()
{
    QString querycommand=ui->editSqlQuery->text(); //read query command from window


    _browser->execDb(querycommand); //execute query command
    statusBar()->showMessage(_browser->actualstatus); // Query status info | Use always after execDb();

    ui->tableView->setModel(_browser->model); // Update tableview
}

void MainWindow::on_pushCommitButton_clicked()
{
    _browser->model->submitAll();
}

void MainWindow::on_actionSettings_triggered()
{
     emit openSettingsWindowSignal(); // Signal to open window in editstrategysettings.ui
}

void MainWindow::on_listView_clicked()
{

   _browser->currenttable=ui->listView->currentIndex().data().toString();


   ui->groupBoxQueryWhere->setTitle("SELECT * FROM "+_browser->currenttable+" WHERE"); //tool to help user understand query

}


/************* CONNECT SIGNALS AND SLOTS **************************/
void MainWindow::setSettingsSlot(int strategy)
{
    strategysetting=strategy; //copy int from slot
    on_checkReadOnly_clicked();
    switch (strategysetting)
    {

    case 1: _browser->model->setEditStrategy(QSqlTableModel::OnFieldChange);
            ui->labelStrategy->setText("OnFieldChange");
            qWarning() << "1";
            return;

    case 2: _browser->model->setEditStrategy(QSqlTableModel::OnRowChange);
            ui->labelStrategy->setText("OnRowChange");
            qWarning() << "2";
            return;

    case 3: _browser->model->setEditStrategy(QSqlTableModel::OnManualSubmit);
            ui->labelStrategy->setText("OnManualSubmit");
            qWarning() << "3";
            return;
    }
    on_checkReadOnly_clicked();

}

/******* CONNENCT END OF SIGNALS AND SLOTS **************************/

void MainWindow::on_checkReadOnly_clicked()
{
    if (ui->checkReadOnly->isChecked())
    {
        ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
        ui->pushCommitButton->setVisible(false);
    }

    if (!ui->checkReadOnly->isChecked())
    {
        ui->tableView->setEditTriggers(QAbstractItemView::DoubleClicked);
        if(strategysetting!=3)
            ui->pushCommitButton->setVisible(false);
        else
            ui->pushCommitButton->setVisible(true);

    }

}


