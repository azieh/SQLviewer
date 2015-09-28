#ifndef BROWSER_H
#define BROWSER_H
#include <QSqlTableModel>
#include <QMainWindow>
#include <QMessageBox>
#include <QtWidgets>
#include <QtSql>
#include <QMessageBox>

class Browser
{
public:


    Browser()
    {
        /*******************************************/
        /*Sequence of creating instans is important*/
        /*******************************************/

        mydb=QSqlDatabase::addDatabase("QSQLITE");
        mydb.setHostName("localhost");
        query = new QSqlQuery(mydb);
        tableview=new QTableView();
        model = new QSqlQueryModel(tableview);

    }

    ~Browser()
    {
        mydb.close();
    }

    QSqlDatabase mydb;
    QSqlQueryModel * model;
    QSqlQuery * query;
    QTableView * tableview;
    QString actualstatus;



    void execDb(QString & command);
    void openDb(QString & path);
    void execQuery();
    void createDb();
    void insertSomeIntoDb();



private:


};

#endif // BROWSER_H
