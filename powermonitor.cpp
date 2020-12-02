#include "powermonitor.h"
#include "ui_powermonitor.h"

PowerMonitor::PowerMonitor(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::PowerMonitor)
{
    ui->setupUi(this);
}

PowerMonitor::~PowerMonitor()
{
    delete ui;
}

