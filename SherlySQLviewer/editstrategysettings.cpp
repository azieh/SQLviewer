#include "editstrategysettings.h"
#include "ui_editstrategysettings.h"


EditStrategySettings::EditStrategySettings(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EditStrategySettings)
{
    ui->setupUi (this);
    ui->radioManualSubmit->setChecked (true);
}

EditStrategySettings::~EditStrategySettings()
{
    delete ui;
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

    default:
        ui->radioManualSubmit->setChecked   (true);
        break;

    }
}

void
EditStrategySettings::openSettingsWindowSlot()
{
    show();
}

/************ END OF CONNECT SIGNALS AND SLOTS **************************/
