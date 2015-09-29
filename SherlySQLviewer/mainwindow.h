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
    explicit MainWindow(Browser* _browser, QWidget *parent = 0);
    ~MainWindow();
    QString sqlfilename;

    int strategy() const { return _radioselectedstrategy; }

private:

    Browser* _browser;
    Ui::MainWindow *ui;

    int _radioselectedstrategy;
    bool _openwindow;

signals:

    void setSettingsSignal(int newstrategy);
    void openSettingsWindowSignal();

public slots:

    void setSettingsSlot(int strategy);

private slots:
    void on_actionExit_triggered();

    void on_actionOpen_triggered();

    void on_pushClearButton_clicked();

    void on_pushQueryButton_clicked();

    void on_actionSettings_triggered();



};

#endif // MAINWINDOW_H
