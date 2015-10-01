#include "editstrategysettings.h"
#include "ui_editstrategysettings.h"


EditStrategySettings::EditStrategySettings(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EditStrategySettings)
{
    ui->setupUi (this);
}

EditStrategySettings::~EditStrategySettings()
{
    delete ui;
    ui = nullptr;
}

void
EditStrategySettings::_radioButtonUpdate(int strategy)
{
    switch (strategy) {
    case 1:
        ui->radioFieldChange->setChecked    (true);
        break;

    case 2:
        ui->radioRowChange->setChecked      (true);
        break;

    case 3:
        ui->radioManualSubmit->setChecked   (true);
        break;
    }
}

void
EditStrategySettings::on_buttonBox_accepted()
{
    if (ui->radioFieldChange->isChecked())
        _radioselectedstrategy = 1;

    if (ui->radioRowChange->isChecked())
        _radioselectedstrategy = 2;

    if (ui->radioManualSubmit->isChecked())
        _radioselectedstrategy = 3;

    emit setSettingsSignal (_radioselectedstrategy);
}

/****************** CONNECT SIGNALS AND SLOTS **************************/
void
EditStrategySettings::setSettingsSlot(int strategy)
{
    _radioButtonUpdate (strategy);
}

void
EditStrategySettings::openSettingsWindowSlot()
{
    show();
}

/************ END OF CONNECT SIGNALS AND SLOTS **************************/


