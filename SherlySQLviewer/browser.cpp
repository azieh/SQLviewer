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
    query = new QSqlQuery(mydb);
    tableview=new QTableView();
    model = new QSqlQueryModel(tableview);

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
//                   "firstname varchar(20), lastname varchar(20), number intiger)");
//    int i=1;
//    for (i=1; i<=100; i++)
//    {
//        query->clear();
//    query->prepare("INSERT INTO person(id, firstname, lastname, number) VALUES(:id, :firstname, :lastname, :number)");
//    query->bindValue(":firstname", "C");
//    query->bindValue(":lastname", "D");
//    query->bindValue(":number", i);
//    query->exec();
//    }
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
