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
    setWindowIcon (QIcon (":/ico/SQL.ico"));                  //set Sher.ly ico to main window

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
                "SQLite (*.SQLite)"              // default posible file extension
                );

    if (!sqlfilename.isEmpty()){

        setWindowTitle ("SQLviewer:  "
                        +sqlfilename);                          // inform user about actual DB directory

        _browser->openDatabase (sqlfilename);                         // calling function from Browser class
        statusBar()->showMessage (_browser->actualstatus);      // Path status info | Use always after openDb();
        ui->listView->setModel (_browser->tableslistmodel);     //update tables list view
    }
}


void
MainWindow::on_pushPushButton_clicked()
{
    if (_browser->database.isOpen()){
        QString querycommand = ui->editSqlQuery->text();        // read query command from window

        _browser->execDatabase(querycommand);                         // execute query command
        statusBar()->showMessage(_browser->actualstatus);       // Query status info | Use always after execDb();
        updateTableModel();
    }
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
    emit setSettingsSignal (_strategysetting);
}

void
MainWindow::on_listView_clicked()
{

    _browser->currenttable = ui->listView->currentIndex().data().toString();

    _browser->execDatabase (NULL);
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
void MainWindow::keyPressEvent(QKeyEvent *event)
{
    QItemSelectionModel* model = ui->tableView->selectionModel();
    // If Ctrl-C typed
    // Or use event->matches(QKeySequence::Copy)
    if (event->key() == Qt::Key_C && (event->modifiers() & Qt::ControlModifier))
    {
        QModelIndexList cells = model->selectedIndexes();
        qSort(cells); // Necessary, otherwise they are in column order

        QString text;
        int currentRow = 0; // To determine when to insert newlines
        foreach (const QModelIndex& cell, cells) {
            if (text.length() == 0) {
                // First item
            } else if (cell.row() != currentRow) {
                // New row
                text += '\n';
            } else {
                // Next cell
                text += '\t';
            }
            currentRow = cell.row();
            text += cell.data().toString();
        }

        QApplication::clipboard()->setText(text);
        delete model;
        model = nullptr;
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


