#include "powermeter.h"
#include "ui_powermeter.h"

PowerMeter::PowerMeter(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PowerMeter)
{
    ui->setupUi(this);
}

PowerMeter::~PowerMeter()
{
    delete ui;
}
