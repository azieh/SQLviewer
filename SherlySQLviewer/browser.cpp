#include "browser.h"
#include <QtWidgets>
#include <QtSql>
#include <QMessageBox>
    void Browser::execDb(const QString & command)
    {
        query->clear(); // always clear query at begining!!!!!!!!

        query->prepare(command); //prepare SQL command

        execQuery();
    }


    void Browser::openDb(QString & path)
    {

        qWarning() << "Path:" << path ;
        mydb.setDatabaseName(path); // set db path

        // Information for user about openDB file status
            if (!mydb.open())
              actualstatus="Cannot open DB | Error: " +  mydb.lastError().text();
            else
              actualstatus="DB was loaded successfully";


    }


    void Browser::execQuery()
    {
        /* Execute query sequence */
            if(!query->exec()){ // you can use query->exec() only once after clearing query
                qWarning() << "Query error after execute command:" << query->lastError().text();
                actualstatus="Query error: "+query->lastError().text();
            }
            else{
                qWarning() << "Query has executed successfully";
                actualstatus="Query has executed successfully";
            }
        /////////////////////////////

    }


    void Browser::createDb()
    {

        query->clear(); // always clear query at begining!!!!!!!!

        query->prepare("create table person (id INTIGER primary key, "
                      "firstname varchar(20), lastname varchar(20), number intiger)");

        execQuery();

    }

    void Browser::insertSomeIntoDb()
    {
        query->clear(); // always clear query at begining!!!!!!!!

        int i=1;
            for (i=1; i<=100; i++)
            {
                query->clear();
            query->prepare("INSERT INTO person(id, firstname, lastname, number) VALUES(:id, :firstname, :lastname, :number)");
            query->bindValue(":firstname", "C"+i);
            query->bindValue(":lastname", "D"+i);
            query->bindValue(":number", i);

        execQuery();

            }
     }


