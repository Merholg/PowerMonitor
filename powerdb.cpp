#include "powerdb.h"
#include "ui_powerdb.h"

PowerDB::PowerDB(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PowerDB)
{
    ui->setupUi(this);
}

PowerDB::~PowerDB()
{
    delete ui;
}
