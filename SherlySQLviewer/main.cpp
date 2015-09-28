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
    MainWindow w(&b, &ess);






    w.show();

    return a.exec();
}
