#include "powermonitor.h"
#include "ui_powermonitor.h"

PowerMonitor::PowerMonitor(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::PowerMonitor)
{
    ui->setupUi(this);

    QObject::connect(ui->actionMonitorOpenPort, SIGNAL(triggered()), SIGNAL(showCommPort()));
    QObject::connect(ui->actionMonitorOpenDB, SIGNAL(triggered()), SIGNAL(showPowerDB()));
    QObject::connect(ui->actionMonitorOpenMeter, SIGNAL(triggered()), SIGNAL(showPowerMeter()));

}

PowerMonitor::~PowerMonitor()
{
    delete ui;
}

void PowerMonitor::on_actionMonitorQuit_triggered()
{
    QApplication::quit();
}
