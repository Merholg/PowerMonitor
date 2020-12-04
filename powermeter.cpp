#include "powermeter.h"
#include "ui_powermeter.h"

#define REPEATLIMIT 10

#define MAXVOLUMETIME 5
#define MAXENERGYTIME 1440
#define MAXSTATETIME 1440
#define MAXCONSISTTIME 10080
// xxxxTime = 0 - не читать группу никогда

const QMap<QString, QString> PowerMeter::m_DeclMeterSettings
{
    {"RepeatTimes", "3"},
    {"AccessLevel", "1"},
    {"PasswordBYTE1", "1"},
    {"PasswordBYTE2", "1"},
    {"PasswordBYTE3", "1"},
    {"PasswordBYTE4", "1"},
    {"PasswordBYTE5", "1"},
    {"PasswordBYTE6", "1"},
    {"VolumeTimeDay", "0"},
    {"VolumeTimeHour", "0"},
    {"VolumeTimeMin", "5"},
    {"EnergyTimeDay", "0"},
    {"EnergyTimeHour", "12"},
    {"EnergyTimeMin", "0"},
    {"StateTimeDay", "1"},
    {"StateTimeHour", "0"},
    {"StateTimeMin", "0"},
    {"ConsistTimeDay", "7"},
    {"ConsistTimeHour", "0"},
    {"ConsistTimeMin", "0"}
};
const QString PowerMeter::m_MeterGroupName {"METER"};

PowerMeter::PowerMeter(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PowerMeter)
{
    ui->setupUi(this);
    m_ComboBoxes.insert("RepeatTimes", ui->spinMeterRepeat);
    m_ComboBoxes.insert("AccessLevel", ui->spinMeterAccessLevelDef);
    m_ComboBoxes.insert("PasswordBYTE1", ui->spinMeterPasswordB1Def);
    m_ComboBoxes.insert("PasswordBYTE2", ui->spinMeterPasswordB2Def);
    m_ComboBoxes.insert("PasswordBYTE3", ui->spinMeterPasswordB3Def);
    m_ComboBoxes.insert("PasswordBYTE4", ui->spinMeterPasswordB4Def);
    m_ComboBoxes.insert("PasswordBYTE5", ui->spinMeterPasswordB5Def);
    m_ComboBoxes.insert("PasswordBYTE6", ui->spinMeterPasswordB6Def);
    m_ComboBoxes.insert("VolumeTimeDay", ui->spinMeterVolumeDay);
    m_ComboBoxes.insert("VolumeTimeHour", ui->spinMeterVolumeHour);
    m_ComboBoxes.insert("VolumeTimeMin", ui->spinMeterVolumeMin);
    m_ComboBoxes.insert("EnergyTimeDay", ui->spinMeterEnergyDay);
    m_ComboBoxes.insert("EnergyTimeHour", ui->spinMeterEnergyHour);
    m_ComboBoxes.insert("EnergyTimeMin", ui->spinMeterEnergyMin);
    m_ComboBoxes.insert("StateTimeDay", ui->spinMeterStateDay);
    m_ComboBoxes.insert("StateTimeHour", ui->spinMeterStateHour);
    m_ComboBoxes.insert("StateTimeMin", ui->spinMeterStateMin);
    m_ComboBoxes.insert("ConsistTimeDay", ui->spinMeterConsistDay);
    m_ComboBoxes.insert("ConsistTimeHour", ui->spinMeterConsistHour);
    m_ComboBoxes.insert("ConsistTimeMin", ui->spinMeterConsistMin);

    QObject::connect(ui->buttonMeterClose, SIGNAL(clicked()), this, SLOT(hide()));

    ui->spinMeterAddressFROM->setRange(BCASTMETERADDRESS, MAXMETERADDRESS);
    ui->spinMeterAddressFROM->setValue(MINMETERADDRESS);
    ui->spinMeterAddressTO->setRange(MINMETERADDRESS, MAXMETERADDRESS);
    ui->spinMeterAddressTO->setValue(MAXMETERADDRESS);
    ui->spinMeterRepeat->setRange(0, REPEATLIMIT);
    ui->spinMeterRepeat->setValue(REPEATLIMIT);
    ui->spinMeterAccessLevelDef->setRange(MINACCESSLEVEL, MAXACCESSLEVEL);
    ui->spinMeterAccessLevelDef->setValue(MINACCESSLEVEL);
    QMap<QString, QString>::const_iterator itDecl;
    QMap<QString, QSpinBox *>::iterator  itCombo;
    for (itCombo = m_ComboBoxes.begin(); itCombo != m_ComboBoxes.end(); ++itCombo)
    {
        itDecl = m_DeclMeterSettings.constFind(itCombo.key());
        if(itDecl != m_DeclMeterSettings.end()) itCombo.value()->setValue(itDecl.value().toInt());
    }


}

PowerMeter::~PowerMeter()
{
    delete ui;
}

void PowerMeter::on_spinMeterAddressFROM_valueChanged(int arg1)
{
    if(arg1 > BCASTMETERADDRESS)
    {
        ui->spinMeterAddressTO->setRange(arg1, MAXMETERADDRESS);
        if(ui->spinMeterAddressTO->value() < arg1) ui->spinMeterAddressTO->setValue(arg1);
    }
    else
    {
        ui->spinMeterAddressTO->setRange(BCASTMETERADDRESS, BCASTMETERADDRESS);
        ui->spinMeterAddressTO->setValue(BCASTMETERADDRESS);
    }
}

void PowerMeter::RecvEndMeterSettings()
{
    // отправить в programsettings m_ComboBoxes
    QMap<QString, QSpinBox *>::const_iterator  itCombo;
    for(itCombo = m_ComboBoxes.constBegin(); itCombo != m_ComboBoxes.constEnd(); ++itCombo) emit SendMeterSettings(qMakePair(itCombo.key(), QString::number(itCombo.value()->value())));
    for(itCombo = m_ComboBoxes.constBegin(); itCombo != m_ComboBoxes.constEnd(); ++itCombo) itCombo.value()->setEnabled(true);
}

void PowerMeter::RecvMeterSettings(QPair<QString, QString> arg1)
{
    QMap<QString, QSpinBox *>::iterator  itCombo;
    itCombo = m_ComboBoxes.find(arg1.first);
    if(itCombo != m_ComboBoxes.end())
    {
        if(itCombo.value()->minimum() <= arg1.second.toInt() && arg1.second.toInt() <= itCombo.value()->maximum())
            itCombo.value()->setValue(arg1.second.toInt());
    }
}

void PowerMeter::RecvMeterIniSettings()
{
    emit SendMeterSection(m_MeterGroupName);
}
