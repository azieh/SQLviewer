#include "mainwindow.h"
#include "editstrategysettings.h"
#include "browser.h"
#include <QString>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    EditStrategySettings ess;
    Browser b;
    MainWindow w(&b);

    QObject::connect(&w, SIGNAL(openSettingsWindowSignal()),   // Connect mainwindow signal to open
                     &ess, SLOT(openSettingsWindowSlot()));    // editstrategysetting window
    QObject::connect(&ess, SIGNAL(setSettingsSignal(int)),     // Connect editstrategysettings signal to change
                     &w, SLOT(setSettingsSlot(int)));          // mainwindow SQLTableView settings
    QObject::connect(&w, SIGNAL(setSettingsSignal(int)),       // Connect mainwidnow signal to update
                     &ess, SLOT(setSettingsSlot(int)));        // editstrategysettings SQLTableView settings


    w.show();

    return a.exec();
}
