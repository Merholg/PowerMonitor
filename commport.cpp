#include "commport.h"
#include "ui_commport.h"

CommPort::CommPort(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CommPort)
{
    ui->setupUi(this);
}

CommPort::~CommPort()
{
    delete ui;
}
