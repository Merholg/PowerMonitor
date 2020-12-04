#include "powermonitor.h"
#include "commport.h"
#include "powerdb.h"
#include "powermeter.h"
#include "programsettings.h"

//#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setApplicationName("PowerMonitor");
    a.setOrganizationName("Butterfly");

    CommPort cport;
    PowerDB dbase;
    PowerMeter  emeter;
    PowerMonitor w;
    ProgramSettings asettings;

    CommPort *pcport = &cport;
    PowerDB *pdbase = &dbase;
    PowerMeter  *pemeter = &emeter;
    PowerMonitor *papp = &w;
    ProgramSettings *pasettings = &asettings;

    QObject::connect(papp, &PowerMonitor::showCommPort, pcport, &CommPort::show);
    QObject::connect(papp, &PowerMonitor::showPowerDB, pdbase, &PowerDB::show);
    QObject::connect(papp, &PowerMonitor::showPowerMeter, pemeter, &PowerMeter::show);
    QObject::connect(papp, &PowerMonitor::SendIniSettings, pcport, &CommPort::RecvPortIniSettings);
    QObject::connect(papp, &PowerMonitor::SendIniSettings, pdbase, &PowerDB::RecvDBIniSettings);
    QObject::connect(papp, &PowerMonitor::SendIniSettings, pemeter, &PowerMeter::RecvMeterIniSettings);

    QObject::connect(pcport, SIGNAL(SendPortSection(QString)), pasettings, SLOT(RecvPortSection(QString)));
    QObject::connect(pdbase, SIGNAL(SendDBSection(QString)), pasettings, SLOT(RecvDBSection(QString)));
    QObject::connect(pemeter, SIGNAL(SendMeterSection(QString)), pasettings, SLOT(RecvMeterSection(QString)));
    QObject::connect(pasettings, SIGNAL(SendPortSettings(QPair<QString, QString>)), pcport, SLOT(RecvPortSettings(QPair<QString, QString>)));
    QObject::connect(pasettings, SIGNAL(SendDBSettings(QPair<QString, QString>)), pdbase, SLOT(RecvDBSettings(QPair<QString, QString>)));
    QObject::connect(pasettings, SIGNAL(SendMeterSettings(QPair<QString, QString>)), pemeter, SLOT(RecvMeterSettings(QPair<QString, QString>)));
    QObject::connect(pasettings, SIGNAL(SendEndPortSettings()), pcport, SLOT(RecvEndPortSettings()));
    QObject::connect(pasettings, SIGNAL(SendEndDBSettings()), pdbase, SLOT(RecvEndDBSettings()));
    QObject::connect(pasettings, SIGNAL(SendEndMeterSettings()), pemeter, SLOT(RecvEndMeterSettings()));
    QObject::connect(pcport, SIGNAL(SendPortSettings(QPair<QString, QString>)), pasettings, SLOT(RecvPortSettings(QPair<QString, QString>)));
    QObject::connect(pdbase, SIGNAL(SendDBSettings(QPair<QString, QString>)), pasettings, SLOT(RecvDBSettings(QPair<QString, QString>)));
    QObject::connect(pemeter, SIGNAL(SendMeterSettings(QPair<QString, QString>)), pasettings, SLOT(RecvMeterSettings(QPair<QString, QString>)));

    emit papp->SendIniSettings();
    w.show();
    return a.exec();
}
