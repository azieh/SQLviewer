#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class Browser;
class EditStrategySettings;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(Browser* _browser, EditStrategySettings* _settings, QWidget *parent = 0);
    ~MainWindow();
    QString sqlfilename;


private slots:
    void on_actionExit_triggered();

    void on_actionOpen_triggered();

    void on_pushClearButton_clicked();

    void on_pushQueryButton_clicked();

    void on_actionSettings_triggered();

private:

    Browser* _browser;
    EditStrategySettings* _settings;
    Ui::MainWindow *ui;


};

#endif // MAINWINDOW_H
