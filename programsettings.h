#ifndef PROGRAMSETTINGS_H
#define PROGRAMSETTINGS_H
#include <QApplication>
#include <QDir>
#include <QSettings>

class ProgramSettings : public QSettings
{
    Q_OBJECT

public:
    ProgramSettings();

private slots:
    void RecvPortSection(QString arg1);
    void RecvDBSection(QString arg1);
    void RecvMeterSection(QString arg1);
    void RecvPortSettings(QPair<QString, QString> arg1);
    void RecvDBSettings(QPair<QString, QString> arg1);
    void RecvMeterSettings(QPair<QString, QString> arg1);

signals:
    void SendPortSettings(QPair<QString, QString> arg1);
    void SendDBSettings(QPair<QString, QString> arg1);
    void SendMeterSettings(QPair<QString, QString> arg1);
    void SendEndPortSettings();
    void SendEndDBSettings();
    void SendEndMeterSettings();

private:
    QString m_PortGroupName;
    QString m_DBGroupName;
    QString m_MeterGroupName;
    bool m_PortSettingsSem;
    bool m_DBSettingsSem;
    bool m_MeterSettingsSem;

    QString SearchConfigFile();
};

#endif // PROGRAMSETTINGS_H
