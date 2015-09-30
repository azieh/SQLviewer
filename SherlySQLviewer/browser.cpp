#include "browser.h"
#include <QtWidgets>
#include <QtSql>
#include <QMessageBox>

Browser::Browser() :
    mydb(),
    tableviewmodel(nullptr),
    tableslistmodel(nullptr),
    tableview(nullptr),
    tableslist(nullptr)
{
    mydb=QSqlDatabase::addDatabase("QSQLITE");
    mydb.setHostName("localhost");
}

Browser::~Browser()
{
    mydb.close();
}


void Browser::openDb(QString & path)
{
    if (mydb.isOpen())
    {
        mydb.close();
        delete tableslistmodel;
    }

    qWarning() << "Path:" << path ;

    mydb.setDatabaseName(path); // set db path

    tableslist = mydb.tables(QSql::Tables);
    tableslistmodel = new QStringListModel();

    openDbStatus();
}

void Browser::execDb(const QString & command)
{
    if( tableviewmodel != nullptr )        {
        delete tableviewmodel;
    }
    tableview = new QTableView();
    tableviewmodel = new QSqlTableModel(tableview);


    tableviewmodel->setTable(currenttable);
    if (!command.isEmpty())
        tableviewmodel->setFilter(command);

    execQuery();
}


void Browser::execQuery()
{

    /* Execute query sequence */
    if(!tableviewmodel->select()){ // you can use model->select() only once after clearing query
        qWarning() << "Query error after execute command:" << tableviewmodel->lastError().text();
        actualstatus="Query error: "+tableviewmodel->lastError().text();
    }
    else{
        qWarning() << "Query has executed successfully";
        actualstatus="Query has executed successfully";
    }
}

void Browser::openDbStatus()
{
    // Information for user about openDB file status
    if (!mydb.open())
        actualstatus="Cannot open DB | Error: " +  mydb.lastError().text();
    else
    {
        actualstatus="DB was loaded successfully";

        tableslist = mydb.tables(QSql::Tables);
        tableslistmodel->setStringList( = new QStringListModel(tableslist);
    }

}

void Browser::strategySetting(int strategysetting)
{
    if (tableviewmodel!=nullptr)
    {

        switch (strategysetting)
        {
        case 1: tableviewmodel->setEditStrategy(QSqlTableModel::OnFieldChange);
            return;

        case 2: tableviewmodel->setEditStrategy(QSqlTableModel::OnRowChange);
            return;

        case 3: tableviewmodel->setEditStrategy(QSqlTableModel::OnManualSubmit);
            return;
        }
    }
}





