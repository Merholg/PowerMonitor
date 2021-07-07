#include "powermeter.h"
#include "ui_powermeter.h"

// xxxxTime = 0 - не читать группу никогда

const QMap<QString, METERSET> PowerMeter::m_DeclMeterSettings
{
    {"RepeatTimes", {3, 0, 10}},
    {"AccessLevel", {DEFAULTACCESSLEVEL, MINACCESSLEVEL, MAXACCESSLEVEL}},
    {"PasswordBYTE1", {1, 0, 255}},
    {"PasswordBYTE2", {1, 0, 255}},
    {"PasswordBYTE3", {1, 0, 255}},
    {"PasswordBYTE4", {1, 0, 255}},
    {"PasswordBYTE5", {1, 0, 255}},
    {"PasswordBYTE6", {1, 0, 255}},
    {"VolumeTimeDay", {0, 0, 365}},
    {"VolumeTimeHour", {0, 0, 23}},
    {"VolumeTimeMin", {5, 0, 59}},
    {"EnergyTimeDay", {0, 0, 365}},
    {"EnergyTimeHour", {12, 0, 23}},
    {"EnergyTimeMin", {0, 0, 59}},
    {"StateTimeDay", {1, 0, 365}},
    {"StateTimeHour", {0, 0, 23}},
    {"StateTimeMin", {0, 0, 59}},
    {"ConsistTimeDay", {7, 0, 365}},
    {"ConsistTimeHour", {0, 0, 23}},
    {"ConsistTimeMin", {0, 0, 59}}
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

    QMap<QString, METERSET>::const_iterator itDecl;
    QMap<QString, QSpinBox *>::iterator  itCombo;        //итератор спинбоксов
    for(itCombo = m_ComboBoxes.begin(); itCombo != m_ComboBoxes.end(); ++itCombo)
    {
        itDecl = m_DeclMeterSettings.constFind(itCombo.key());
        if(itDecl != m_DeclMeterSettings.end())
        {
            itCombo.value()->setValue(itDecl.value().Value);
            itCombo.value()->setRange(itDecl.value().MinLimit, itDecl.value().MaxLimit);
        }
        itCombo.value()->setEnabled(false); // Запрет доступа
    }

    ui->spinMeterAccessLevel->setRange(ui->spinMeterAccessLevelDef->minimum(), ui->spinMeterAccessLevelDef->maximum());
    ui->spinMeterPasswordB1->setRange(ui->spinMeterPasswordB1Def->minimum(), ui->spinMeterPasswordB1Def->maximum());
    ui->spinMeterPasswordB2->setRange(ui->spinMeterPasswordB2Def->minimum(), ui->spinMeterPasswordB2Def->maximum());
    ui->spinMeterPasswordB3->setRange(ui->spinMeterPasswordB3Def->minimum(), ui->spinMeterPasswordB3Def->maximum());
    ui->spinMeterPasswordB4->setRange(ui->spinMeterPasswordB4Def->minimum(), ui->spinMeterPasswordB4Def->maximum());
    ui->spinMeterPasswordB5->setRange(ui->spinMeterPasswordB5Def->minimum(), ui->spinMeterPasswordB5Def->maximum());
    ui->spinMeterPasswordB6->setRange(ui->spinMeterPasswordB6Def->minimum(), ui->spinMeterPasswordB6Def->maximum());
    ui->spinMeterAddressFROM->setRange(BCASTMETERADDRESS, MAXMETERADDRESS);
    ui->spinMeterAddressTO->setRange(BCASTMETERADDRESS, MAXMETERADDRESS);
    ui->spinMeterAccessLevel->setValue(ui->spinMeterAccessLevelDef->value());
    ui->spinMeterPasswordB1->setValue(ui->spinMeterPasswordB1Def->value());
    ui->spinMeterPasswordB2->setValue(ui->spinMeterPasswordB2Def->value());
    ui->spinMeterPasswordB3->setValue(ui->spinMeterPasswordB3Def->value());
    ui->spinMeterPasswordB4->setValue(ui->spinMeterPasswordB4Def->value());
    ui->spinMeterPasswordB5->setValue(ui->spinMeterPasswordB5Def->value());
    ui->spinMeterPasswordB6->setValue(ui->spinMeterPasswordB6Def->value());
    ui->spinMeterAddressFROM->setValue(MINMETERADDRESS);
    ui->spinMeterAddressTO->setValue(MAXMETERADDRESS);

    ui->buttonMeterAdd->setEnabled(false);
    ui->buttonMeterDelete->setEnabled(false);
    ui->tableMeterDevices->setEnabled(false);
    //ui->buttonMeterClose->setEnabled(false);

    // подключение к кнопке Add действия
    QAction * pactAdd = new QAction("Search&Add new device with address range action", 0);
    pactAdd->setText("&Add");
    pactAdd->setShortcut(QKeySequence("CTRL+A"));
    pactAdd->setToolTip("Search&Add new device");
    pactAdd->setStatusTip("Device Added");
    pactAdd->setWhatsThis("When pressed, the application tries to search and add founded devices");
//    pactAdd->seticon(QPixmap(":/img4.png"));
    QObject::connect(pactAdd, SIGNAL(triggered()), this, SLOT(on_actionDeviceAdd_triggered())); // кнопка Add
    ui->buttonMeterAdd->addAction(pactAdd);

    // подключение к кнопке Delete действия
    QAction * pactDelete = new QAction("Delete device with address range action", 0);
    pactDelete->setText("&Delete");
    pactDelete->setShortcut(QKeySequence("CTRL+D"));
    pactDelete->setToolTip("Delete devices with address range from table");
    pactDelete->setStatusTip("Port Connected");
    pactDelete->setWhatsThis("When pressed, the application tries to delete devices for setted address range");
//    pactDelete->seticon(QPixmap(":/img4.png"));
    QObject::connect(pactDelete, SIGNAL(triggered()), this, SLOT(on_actionDeviceDelete_triggered())); // кнопка Delete
    ui->buttonMeterDelete->addAction(pactDelete);

    QObject::connect(ui->buttonMeterClose, SIGNAL(clicked()), this, SLOT(hide()));



}

PowerMeter::~PowerMeter()
{
    delete ui;
}

void PowerMeter::on_actionDeviceDelete_triggered()
{
    ui->buttonMeterAdd->setEnabled(false);
    ui->buttonMeterDelete->setEnabled(false);
    ui->tableMeterDevices->setEnabled(false);
    for(int i = ui->spinMeterAddressFROM->value(); i <= ui->spinMeterAddressTO->value(); ++i)
    {
//        QMap<int, DEVICEDATA>::iterator  itDevice;
//        itDevice = m_DeviceTable.find(i);
//        if(itDevice != m_DeviceTable.end())
//        {
//        }
        m_DeviceTable.remove(i);
    }
    ui->buttonMeterAdd->setEnabled(true);
    ui->buttonMeterDelete->setEnabled(true);
    ui->tableMeterDevices->setEnabled(true);
}

void PowerMeter::on_actionDeviceAdd_triggered()
{
    ui->buttonMeterAdd->setEnabled(false);
    ui->buttonMeterDelete->setEnabled(false);
    ui->tableMeterDevices->setEnabled(false);
    for(int i = ui->spinMeterAddressFROM->value(); i <= ui->spinMeterAddressTO->value(); ++i)
    {
//        QMap<int, DEVICEDATA>::iterator  itDevice;
//        itDevice = m_DeviceTable.find(i);
//        if(itDevice != m_DeviceTable.end())
//        {
//        }
        m_DeviceTable.remove(i);
    }
    ui->buttonMeterAdd->setEnabled(true);
    ui->buttonMeterDelete->setEnabled(true);
    ui->tableMeterDevices->setEnabled(true);
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

    ui->buttonMeterAdd->setEnabled(true);
    ui->buttonMeterDelete->setEnabled(true);
    ui->tableMeterDevices->setEnabled(true);
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
