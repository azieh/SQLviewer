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
    browser();
    QSqlDatabase mydb;
    QSqlQueryModel * model;
    QSqlQuery * query;
    QTableView * tableview;
    QString actualstatus;



    void execDb(QString & command);
    void openDb(QString & path);



private:


};

#endif // BROWSER_H
