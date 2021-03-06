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

private:

    void    _radioButtonUpdate(int strategy);

    int     _radioselectedstrategy;
    int     _strategy;

signals:
    void    setSettingsSignal       (int newstrategy);

public slots:
    void    setSettingsSlot         (int strategy);
    void    openSettingsWindowSlot  ();

private slots:
    void    on_buttonBox_accepted   ();
};

#endif // EDITSTRATEGYSETTINGS_H
