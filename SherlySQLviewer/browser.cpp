#include "browser.h"
#include <QtWidgets>
#include <QtSql>
#include <QMessageBox>

Browser::browser()
{
    //Constructor of database
    //sequence of creating instans is important

    mydb=QSqlDatabase::addDatabase("QSQLITE");
    mydb.setHostName("localhost");
    model = new QSqlQueryModel();
    query = new QSqlQuery(mydb);

    return true;
}

void Browser::openDb(QString & path)
{

    qWarning() << "Path:" << path ;
    mydb.setDatabaseName(path); // set db path

    // Information for user about openDB file status
    if (!mydb.open())
              actualstatus=path+ "<- Cannot open that file | Error: " +  mydb.lastError().text();
    else
              actualstatus=path+ "<- Was loaded OK";
    //

}

void Browser::execDb(QString & command)
{
    query->clear(); // always clear query at begining!!!!!!!!

    query->prepare(command); //prepare SQL command

/// TEMP CODE TO CREATE SOME DATABASE ------------------------------------------------------------------------
//    query->prepare("create table person (id INTIGER primary key, "
//                   "firstname varchar(20), lastname varchar(20))");

//    query->prepare("INSERT INTO person(id, firstname, lastname) VALUES(:id, :firstname, :lastname)");
//    query->bindValue(":firstname", "C");
//    query->bindValue(":lastname", "D");
// ------------------------------------------------------------------------------------------------------------


    if(!query->exec()){ // you can use query->exec() only once after clearing query
        qWarning() << "Query error after execute command:" << query->lastError().text();
        actualstatus="Query error: "+query->lastError().text();
    }
    else{
        qWarning() << "Query has executed successfully";
        actualstatus="Query has executed successfully";
    }

}
