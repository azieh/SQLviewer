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

    }
    if (ui->radioRowChange->isChecked())
    {

    }
    if (ui->radioManualSubmit->isChecked())
    {

    }
}

void EditStrategySettings::setSettings(int strategy)
{

}
