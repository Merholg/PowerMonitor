#ifndef POWERMONITOR_H
#define POWERMONITOR_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class PowerMonitor; }
QT_END_NAMESPACE

class PowerMonitor : public QMainWindow
{
    Q_OBJECT

public:
    PowerMonitor(QWidget *parent = nullptr);
    ~PowerMonitor();

private slots:
    void on_actionMonitorQuit_triggered();

signals:
    void showCommPort();
    void showPowerDB();
    void showPowerMeter();
    void SendIniSettings();

private:
    Ui::PowerMonitor *ui;
};
#endif // POWERMONITOR_H
