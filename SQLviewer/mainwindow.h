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
    QString     sqlfilename;

private:

    Browser*        _browser;
    Ui::MainWindow  *ui;

    bool        _openwindow;
    int         _radioselectedstrategy;
    int         _strategysetting;



signals:

    void setSettingsSignal          (int newstrategy);
    void openSettingsWindowSignal   ();

public slots:

    void setSettingsSlot            (int strategy);

private slots:
    void on_actionExit_triggered    ();

    void on_actionOpen_triggered    ();

    void on_pushPushButton_clicked  ();

    void on_pushCommitButton_clicked();

    void on_actionSettings_triggered();

    void on_checkReadOnly_clicked   ();

    void on_listView_clicked        ();

    void setViewSettings            (int& strategy);

    void updateTableModel           ();

    void keyPressEvent(QKeyEvent *event);
};

#endif // MAINWINDOW_H
