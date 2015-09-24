#include "browser.h"
#include <QtWidgets>
#include <QtSql>
#include <QMessageBox>

Browser::browser()
{
    model = new QSqlQueryModel();
    query = new QSqlQuery(mydb);

}

void Browser::openDb(QString & path)
{
    mydb=QSqlDatabase::addDatabase("QSQLITE");
    mydb.setDatabaseName(path);
    if (!mydb.open())
              qWarning() << path << "<- Cannot open that file | Error: " +  mydb.lastError().text();
}

void Browser::execDb(QString & command)
{
    command = "select *";

    if( query->prepare(command)) {
        return;
    }
    if( query->exec()) {
        return;
    }

}
