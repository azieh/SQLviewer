#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "browser.h"
#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow, Browser
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    QString sqlfilename;


private slots:
    void on_actionExit_triggered();



    void on_editSqlQuery_textEdited();

    void on_actionOpen_triggered();

    void on_editSqlQuery_editingFinished();


private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
