#include "browser.h"
#include <QtWidgets>
#include <QtSql>
#include <QMessageBox>

Browser::Browser() :
    database        (),
    tableslistmodel (nullptr),
    tableviewmodel  (nullptr)

{
   database = QSqlDatabase::addDatabase ("QSQLITE");
   database.setHostName ("localhost");
}

Browser::~Browser()
{
   database.close();

   delete tableslistmodel;
   tableslistmodel = nullptr;

   delete tableviewmodel;
   tableviewmodel = nullptr;
}


void
Browser::openDatabase(QString& path)
{
    if (database.isOpen ())
        database.close ();

    database.setDatabaseName (path);

    if (!database.open())
        actualstatus="Cannot open DB | Error: "
                +database.lastError().text();
    else
        actualstatus="DB was loaded successfully";

    if (tableslistmodel!=nullptr){
        delete tableslistmodel;
        tableslistmodel=nullptr;
    }
    tableslistmodel = new QStringListModel ();
    tableslistmodel->setStringList (database.tables(QSql::Tables));

}

void
Browser::execDatabase(const QString& command)
{
    if( tableviewmodel != nullptr ){
        delete tableviewmodel;
        tableviewmodel=nullptr;
    }
    tableviewmodel = new QSqlTableModel();
    tableviewmodel->setTable(currenttable);

    if (!command.isEmpty())
        tableviewmodel->setFilter(command);

    _execQuery();
}


void
Browser::_execQuery()
{
    if (!tableviewmodel->select())                          // you can use model->select() only once after clearing query

        actualstatus="Query error: "
                +tableviewmodel->lastError().text();
    else
        actualstatus="Query has executed successfully";
}


void
Browser::strategySetting(int strategysetting)
{
    if (tableviewmodel != nullptr)
    {
        switch (strategysetting){
        case 1:
            tableviewmodel->setEditStrategy (QSqlTableModel::OnFieldChange);
            break;
        case 2:
            tableviewmodel->setEditStrategy (QSqlTableModel::OnRowChange);
            break;
        case 3:
            tableviewmodel->setEditStrategy (QSqlTableModel::OnManualSubmit);
            break;
        }
    }
}





