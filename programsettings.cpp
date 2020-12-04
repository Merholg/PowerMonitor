#include "programsettings.h"

/** Search the configuration file */
QString ProgramSettings::SearchConfigFile()
{
    QString binDir = QCoreApplication::applicationDirPath();
    QString appName = QCoreApplication::applicationName();
    QString fileName(appName+".ini");
    QString FullFileName = "";

    QStringList searchList;
    searchList.append(binDir);
    searchList.append(binDir+"/etc");
    searchList.append(binDir+"/../etc");
    searchList.append(binDir+"/../../etc"); // for development without shadow build
    searchList.append(binDir+"/../"+appName+"/etc"); // for development with shadow build
    searchList.append(binDir+"/../../"+appName+"/etc"); // for development with shadow build
    searchList.append(binDir+"/../../../"+appName+"/etc"); // for development with shadow build
    searchList.append(binDir+"/../../../../"+appName+"/etc"); // for development with shadow build
    searchList.append(binDir+"/../../../../../"+appName+"/etc"); // for development with shadow build
    searchList.append(QDir::rootPath()+"etc/opt");
    searchList.append(QDir::rootPath()+"etc");

    foreach (QString dir, searchList)
    {
        QFile file(dir+"/"+fileName);
        if (file.exists())
        {
            // found
            FullFileName=QDir(file.fileName()).canonicalPath();
            qDebug("Using config file %s",qPrintable(fileName));
            return FullFileName;
        }
    }

    // not found
    QFile file(binDir+"/"+fileName);
    FullFileName=QDir(file.fileName()).canonicalPath();
    qDebug("Create config file %s",qPrintable(fileName));
    return FullFileName;

}

//// Find the configuration file
//QString configFileName=searchConfigFile();
//// Configure logging into a file
//QSettings* logSettings=new QSettings(configFileName,QSettings::IniFormat,&app);
//logSettings->beginGroup("logging");
//FileLogger* logger=new FileLogger(logSettings,10000,&app);
//logger->installMsgHandler();


ProgramSettings::ProgramSettings()
    : QSettings(SearchConfigFile(), QSettings::IniFormat),
      m_PortGroupName {},
      m_DBGroupName {},
      m_MeterGroupName {},
      m_PortSettingsSem {false},
      m_DBSettingsSem {false},
      m_MeterSettingsSem {false}
{

}

void ProgramSettings::RecvPortSection(QString arg1)
{
    if(!m_PortSettingsSem)
    {
        m_PortGroupName = arg1;
        this->beginGroup(m_PortGroupName);
        QStringList gkeys = this->childKeys();
        foreach(const QString gkey, gkeys) emit SendPortSettings(qMakePair(gkey, this->value(gkey).toString()));
        this->endGroup();
        m_PortSettingsSem = true;
    }
    if(m_PortSettingsSem && m_DBSettingsSem && m_MeterSettingsSem) this->clear();
    emit SendEndPortSettings();
}

void ProgramSettings::RecvDBSection(QString arg1)
{
    if(!m_DBSettingsSem)
    {
        m_DBGroupName = arg1;
        this->beginGroup(m_DBGroupName);
        QStringList gkeys = this->childKeys();
        foreach(const QString gkey, gkeys) emit SendDBSettings(qMakePair(gkey, this->value(gkey).toString()));
        this->endGroup();
        m_DBSettingsSem = true;
    }
    if(m_PortSettingsSem && m_DBSettingsSem && m_MeterSettingsSem) this->clear();
    emit SendEndDBSettings();
}

void ProgramSettings::RecvMeterSection(QString arg1)
{
    if(!m_MeterSettingsSem)
    {
        m_MeterGroupName = arg1;
        this->beginGroup(m_MeterGroupName);
        QStringList gkeys = this->childKeys();
        foreach(const QString gkey, gkeys) emit SendMeterSettings(qMakePair(gkey, this->value(gkey).toString()));
        this->endGroup();
        m_MeterSettingsSem = true;
    }
    if(m_PortSettingsSem && m_DBSettingsSem && m_MeterSettingsSem) this->clear();
    emit SendEndMeterSettings();
}


void ProgramSettings::RecvPortSettings(QPair<QString, QString> arg1)
{
    this->beginGroup(m_PortGroupName);
    this->setValue(arg1.first, arg1.second);
    this->endGroup();
    if(m_PortSettingsSem) m_PortSettingsSem = false;
}

void ProgramSettings::RecvDBSettings(QPair<QString, QString> arg1)
{
    this->beginGroup(m_DBGroupName);
    this->setValue(arg1.first, arg1.second);
    this->endGroup();
    if(m_DBSettingsSem) m_DBSettingsSem = false;
}

void ProgramSettings::RecvMeterSettings(QPair<QString, QString> arg1)
{
    this->beginGroup(m_MeterGroupName);
    this->setValue(arg1.first, arg1.second);
    this->endGroup();
    if(m_MeterSettingsSem) m_MeterSettingsSem = false;
}
