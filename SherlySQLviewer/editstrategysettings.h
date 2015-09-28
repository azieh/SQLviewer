#ifndef EDITSTRATEGYSETTINGS_H
#define EDITSTRATEGYSETTINGS_H

#include <QDialog>


namespace Ui {
class EditStrategySettings;
}

class EditStrategySettings : public QDialog
{
    Q_OBJECT

public:



    explicit EditStrategySettings(QWidget *parent = 0);
    ~EditStrategySettings();

    Ui::EditStrategySettings *ui;

    int strategy() const { return _radioselectedstrategy; }


signals:
    void settingsChanged(int newstrategy);

public slots:
    void setSettings(int strategy);

private slots:
    void on_buttonBox_accepted();

private:
    int _radioselectedstrategy;

};

#endif // EDITSTRATEGYSETTINGS_H
