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
        model = new QSqlTableModel(tableview);




    }

    ~Browser()
    {
        mydb.close();
    }

    QSqlDatabase mydb;
    QSqlTableModel * model;
    QSqlQuery * query;
    QTableView * tableview;
    QStringList tableslist;
    QStringListModel * tableslistmodel;



    QString actualstatus;
    QString currenttable;


    void execDb(const QString & command);
    void openDb(QString & path);
    void execQuery();
    void createDb();
    void insertSomeIntoDb();



};

#endif // BROWSER_H
