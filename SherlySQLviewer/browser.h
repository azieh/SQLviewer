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
    Browser ();
    ~Browser();

    QSqlDatabase        database;
    QStringListModel*   tableslistmodel;
    QSqlTableModel*     tableviewmodel;


    QString actualstatus;
    QString currenttable;

    void execDatabase       (const QString & command);
    void openDatabase       (QString & path);
    void strategySetting    (int strategysetting);

private:

    void _execQuery     ();

};

#endif // BROWSER_H
