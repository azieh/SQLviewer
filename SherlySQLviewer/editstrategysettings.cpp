#include "editstrategysettings.h"
#include "ui_editstrategysettings.h"


EditStrategySettings::EditStrategySettings(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EditStrategySettings)
{
    ui->setupUi(this);

}

EditStrategySettings::~EditStrategySettings()
{
    delete ui;
}

void EditStrategySettings::on_buttonBox_accepted()
{
    if (ui->radioFieldChange->isChecked())
    {
        _radioselectedstrategy=1;
    }
    if (ui->radioRowChange->isChecked())
    {
        _radioselectedstrategy=2;
    }
    if (ui->radioManualSubmit->isChecked())
    {
        _radioselectedstrategy=3;
    }

    emit setSettingsSignal(_radioselectedstrategy);
}


/****************** CONNECT SIGNALS AND SLOTS **************************/
void EditStrategySettings::setSettingsSlot(int strategy)
{
    switch (strategy)
    {

    case 1: ui->radioFieldChange->setChecked(true);

    case 2: ui->radioRowChange->setChecked(true);

    case 3: ui->radioManualSubmit->setChecked(true);

    default: ui->radioManualSubmit->setChecked(true);

    }
}

void EditStrategySettings::openSettingsWindowSlot()
{
  show();
}

/************ END OF CONNECT SIGNALS AND SLOTS **************************/
