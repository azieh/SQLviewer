#ifndef BROWSER_H
#define BROWSER_H
#include <QWidget>
#include <QSqlTableModel>
#include <QMainWindow>

class Browser
{
public:
    browser();
    QSqlDatabase mydb;
    QSqlQueryModel * model;
    QSqlQuery* query;



    void execDb(QString & command);
    void openDb(QString & path);



private:


};

#endif // BROWSER_H
