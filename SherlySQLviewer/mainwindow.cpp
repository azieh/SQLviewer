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
    setWindowIcon (QIcon (":/ico/icoSherly.png"));                  //set Sher.ly ico to main window

    ui->setupUi (this);
    ui->tableView->setAlternatingRowColors (true);                  //set colours of tableview
    ui->editSqlQuery->setPlaceholderText ("ex.: City = 'Krakow'");  //example query write to help
    ui->pushCommitButton->setVisible (false);                       //hide Commit button | set Visible after disable option READ ONLY

    statusBar()->showMessage (tr ("Load DB file"));                 // set first information for user

    _strategysetting = 3;
    setSettingsSlot (_strategysetting);


}

MainWindow::~MainWindow()
{
    delete ui;
}

void
MainWindow::on_actionExit_triggered()
{
    exit (0);
}

void
MainWindow::on_actionOpen_triggered()
{
    sqlfilename = QFileDialog::getOpenFileName(
                this,
                tr ("Open file"),
                "C://",                                     // default open directory
                "db (*.db);;SQLite (*.SQLite)"              // default posible file extension
                );

    setWindowTitle ("SQLviewer:  "
                    +sqlfilename);                          // inform user about actual DB directory

    _browser->openDb (sqlfilename);                         // calling function from Browser class
    statusBar()->showMessage (_browser->actualstatus);      // Path status info | Use always after openDb();

    ui->listView->setModel (_browser->tableslistmodel);     //update tables list view
}


void
MainWindow::on_pushPushButton_clicked()
{
    QString querycommand = ui->editSqlQuery->text();        // read query command from window

    _browser->execDb(querycommand);                         // execute query command
    statusBar()->showMessage(_browser->actualstatus);       // Query status info | Use always after execDb();
    updateTableModel();
}

void
MainWindow::on_pushCommitButton_clicked()                   //commit all changes in database
{
    if (_browser->tableviewmodel!=nullptr)
        _browser->tableviewmodel->submitAll();
}

void
MainWindow::on_actionSettings_triggered()
{
    emit openSettingsWindowSignal();                        // Signal to open window in editstrategysettings.ui
}

void
MainWindow::on_listView_clicked()
{

    _browser->currenttable = ui->listView->currentIndex().data().toString();

    _browser->execDb ("");
    statusBar()->showMessage (_browser->actualstatus);                                  // Query status info | Use always after execDb();

    ui->groupBoxQueryWhere->setTitle("SELECT * FROM "
                                     +_browser->currenttable+" WHERE");                 //tool to help user understand query

    updateTableModel();

}

void
MainWindow::on_checkReadOnly_clicked()
{
    setViewSettings (_strategysetting);
}

void
MainWindow::setViewSettings(int& strategy)
{
    if (ui->checkReadOnly->isChecked()){
        ui->tableView->setEditTriggers  (QAbstractItemView::NoEditTriggers);
        ui->listView->setEditTriggers   (QAbstractItemView::NoEditTriggers);
        ui->pushCommitButton->setVisible(false);
    }

    if (!ui->checkReadOnly->isChecked()){
        ui->tableView->setEditTriggers  (QAbstractItemView::DoubleClicked);
        ui->listView->setEditTriggers   (QAbstractItemView::DoubleClicked);

        if (strategy != 3)
            ui->pushCommitButton->setVisible (false);
        else
            ui->pushCommitButton->setVisible (true);

    }
}

void
MainWindow::updateTableModel()
{
    if (_browser->tableviewmodel != nullptr)
        ui->tableView->setModel (_browser->tableviewmodel); // Update tableview
}


/************* CONNECT SIGNALS AND SLOTS **************************/
void MainWindow::setSettingsSlot(int strategy)
{
    _strategysetting = strategy;
    _browser->strategySetting (strategy);
    setViewSettings (_strategysetting);


    switch (strategy){
    case 1:
        ui->labelStrategy->setText      ("OnFieldChange");
        break;

    case 2:
        ui->labelStrategy->setText      ("OnRowChange");
        return;

    case 3: ui->labelStrategy->setText  ("OnManualSubmit");
        return;
    }

}

/******* CONNENCT END OF SIGNALS AND SLOTS **************************/






