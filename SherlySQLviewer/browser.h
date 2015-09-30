#ifndef BROWSER_H
#define BROWSER_H
#include <QSqlTableModel>
#include <QMainWindow>
#include <QMessageBox>
#include <QtWidgets>
#include <QtSql>
#include <QMessageBox>

//#define MY_DELETE(x) delete x; x = nullptr;

class Browser
{
public:
    Browser();
    ~Browser();

    QSqlDatabase mydb;
    QSqlTableModel * tableviewmodel;
    QStringListModel * tableslistmodel;
    QTableView * tableview;
    QStringList tableslist;

    QString actualstatus;
    QString currenttable;

    void execDb(const QString & command);
    void openDb(QString & path);
    void execQuery();
    void openDbStatus();
    void strategySetting(int strategysetting);



};

#endif // BROWSER_H
