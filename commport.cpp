#include <QAction>
#include "commport.h"
#include "ui_commport.h"

const QMap<QString, PORTSET> CommPort::m_DeclPortSettings
{
    {"BaudRate", {"Baud9600",
        {
            {"Baud1200", QSerialPort::Baud1200},
            {"Baud2400", QSerialPort::Baud2400},
            {"Baud4800", QSerialPort::Baud4800},
            {"Baud9600", QSerialPort::Baud9600},
            {"Baud19200", QSerialPort::Baud19200},
            {"Baud38400", QSerialPort::Baud38400},
            {"Baud57600", QSerialPort::Baud57600},
            {"Baud115200", QSerialPort::Baud115200}
        }}},
    {"DataBits", {"Data8",
        {
            {"Data5", QSerialPort::Data5},
            {"Data6", QSerialPort::Data6},
            {"Data7", QSerialPort::Data7},
            {"Data8", QSerialPort::Data8}
        }}},
    {"Parity", {"NoParity",
        {
            {"NoParity", QSerialPort::NoParity},
            {"EvenParity", QSerialPort::EvenParity},
            {"OddParity", QSerialPort::OddParity},
            {"SpaceParity", QSerialPort::SpaceParity},
            {"MarkParity", QSerialPort::MarkParity}
        }}},
    {"StopBits", {"OneStop",
        {
            {"OneStop", QSerialPort::OneStop},
            {"OneAndHalfStop", QSerialPort::OneAndHalfStop},
            {"TwoStop", QSerialPort::TwoStop}
        }}},
    {"FlowControl", {"NoFlowControl",
        {
            {"NoFlowControl", QSerialPort::NoFlowControl},
            {"HardwareControl", QSerialPort::HardwareControl},
            {"SoftwareControl", QSerialPort::SoftwareControl}
        }}}
};
const QString CommPort::m_PortGroupName {"COMMPORT"};

CommPort::CommPort(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CommPort),
    m_serial(new QSerialPort(this)),
    m_commportopened(false)
{
    ui->setupUi(this);
    m_ComboBoxes.insert("BaudRate", ui->comboPortBaudRate);
    m_ComboBoxes.insert("DataBits", ui->comboPortDataBits);
    m_ComboBoxes.insert("Parity", ui->comboPortParity);
    m_ComboBoxes.insert("StopBits", ui->comboPortStopBits);
    m_ComboBoxes.insert("FlowControl", ui->comboPortFlowControl);

    QAction* pactReCon = new QAction("Port ReConnection action", 0);
    pactReCon->setText("&ReConnect");
    pactReCon->setShortcut(QKeySequence("CTRL+O"));
    pactReCon->setToolTip("Connect/Disconnect serial port");
    if(m_commportopened) pactReCon->setStatusTip("Port Connected");
    else pactReCon->setStatusTip("Port Disconnected");
    pactReCon->setWhatsThis("When pressed, the application tries to open/close the selected port based on its current state");
//    pactReCon->seticon(QPixmap(":/img4.png"));
    QObject::connect(pactReCon, SIGNAL(triggered()), this, SLOT(on_actionPortReConnection_triggered()));

    QObject::connect(ui->buttonPortClose, SIGNAL(clicked()), this, SLOT(hide()));

    ui->buttonPortReConnect->addAction(pactReCon);

    QMap<QString, PORTSET>::const_iterator itDecl;
    QMap<QString, int>::const_iterator itChoose;          //существующие варианты значения переменной
    QMap<QString, QComboBox *>::iterator  itCombo;
    int intIndex;
    for(itCombo = m_ComboBoxes.begin(); itCombo != m_ComboBoxes.end(); ++itCombo)
    {
        itDecl = m_DeclPortSettings.constFind(itCombo.key());
        if(itDecl != m_DeclPortSettings.end())
        {
            for (itChoose = itDecl.value().Choose.constBegin(); itChoose != itDecl.value().Choose.constEnd(); ++itChoose)
                itCombo.value()->addItem(itChoose.key());
            intIndex = itCombo.value()->findText(itDecl.value().Value);
            if(intIndex >= 0) itCombo.value()->setCurrentIndex(intIndex);
            else itCombo.value()->setCurrentIndex(0);
        }
    }

    intIndex = 0;
    m_commports = QSerialPortInfo::availablePorts();
    foreach(const QSerialPortInfo portitem, m_commports)
    {
        ui->comboPortName->addItem(portitem.portName());
        ++intIndex;
    }
    m_ComboBoxes.insert("Port", ui->comboPortName);
    if(intIndex > 0) ui->comboPortName->setCurrentIndex(0);

    //    qDebug() << "CommPort(QWidget *parent)";
}

CommPort::~CommPort()
{
    if(m_commportopened)
    {
        // очистить очереди
        m_serial->close();
        m_commportopened = false;
    }
    delete m_serial;
    delete ui;
}

void CommPort::on_actionPortReConnection_triggered()
{
    // нажатие кнопки Port ReConnect
}

void CommPort::OpenCommPort()
{
    QMap<QString, PORTSET>::const_iterator itDecl;
    QMap<QString, int>::const_iterator itChoose;          //существующие варианты значения переменной
    int intIndex;
// создать очередь сообщений обмена с ком портом
    if(m_commportopened)
    {
        // очистить очереди
        m_serial->close();
        m_commportopened = false;
    }
    if(ui->comboPortName->count() > 0)
    {
        if(ui->comboPortName->currentIndex() < 0) intIndex = 0;
        else intIndex = ui->comboPortName->currentIndex();
        m_serial->setPortName(ui->comboPortName->itemText(intIndex));

        itDecl = m_DeclPortSettings.constFind("BaudRate");
        itChoose = itDecl.value().Choose.constFind(ui->comboPortBaudRate->currentText());
        if(itChoose == itDecl.value().Choose.end()) itChoose = itDecl.value().Choose.constFind(itDecl.value().Value);
        m_serial->setBaudRate(itChoose.value());

        itDecl = m_DeclPortSettings.constFind("DataBits");
        itChoose = itDecl.value().Choose.constFind(ui->comboPortDataBits->currentText());
        if(itChoose == itDecl.value().Choose.end()) itChoose = itDecl.value().Choose.constFind(itDecl.value().Value);
        m_serial->setDataBits(static_cast<QSerialPort::DataBits>(itChoose.value()));

        itDecl = m_DeclPortSettings.constFind("Parity");
        itChoose = itDecl.value().Choose.constFind(ui->comboPortParity->currentText());
        if(itChoose != itDecl.value().Choose.end()) itChoose = itDecl.value().Choose.constFind(itDecl.value().Value);
        m_serial->setParity(static_cast<QSerialPort::Parity>(itChoose.value()));

        itDecl = m_DeclPortSettings.constFind("StopBits");
        itChoose = itDecl.value().Choose.constFind(ui->comboPortStopBits->currentText());
        if(itChoose != itDecl.value().Choose.end()) itChoose = itDecl.value().Choose.constFind(itDecl.value().Value);
        m_serial->setStopBits(static_cast<QSerialPort::StopBits>(itChoose.value()));

        itDecl = m_DeclPortSettings.constFind("FlowControl");
        itChoose = itDecl.value().Choose.constFind(ui->comboPortFlowControl->currentText());
        if(itChoose != itDecl.value().Choose.end()) itChoose = itDecl.value().Choose.constFind(itDecl.value().Value);
        m_serial->setFlowControl(static_cast<QSerialPort::FlowControl>(itChoose.value()));

        if (m_serial->open(QIODevice::ReadWrite))
        {
            m_commportopened = true;
//            ui->statusBar->showMessage(tr("Connected to %1 : %2, %3, %4, %5, %6")
//                                   .arg(p.name).arg(p.stringBaudRate).arg(p.stringDataBits)
//                                   .arg(p.stringParity).arg(p.stringStopBits).arg(p.stringFlowControl));
//        showStatusMessage(tr("Connected to %1 : %2, %3, %4, %5, %6")
//                          .arg(p.name).arg(p.stringBaudRate).arg(p.stringDataBits)
//                          .arg(p.stringParity).arg(p.stringStopBits).arg(p.stringFlowControl));
        }
        else
        {
            QMessageBox::critical(this, tr("Error"), m_serial->errorString());

//        showStatusMessage(tr("Open error"));
//            ui->statusBar->showMessage(tr("Open error"));
        }
    }

}

void CommPort::RecvEndPortSettings()
{
    // отправить в programsettings m_ComboBoxes
    QMap<QString, QComboBox *>::const_iterator  itCombo;
    for(itCombo = m_ComboBoxes.constBegin(); itCombo != m_ComboBoxes.constEnd(); ++itCombo) emit SendPortSettings(qMakePair(itCombo.key(), itCombo.value()->currentText()));

    for(itCombo = m_ComboBoxes.constBegin(); itCombo != m_ComboBoxes.constEnd(); ++itCombo) itCombo.value()->setEnabled(true);
    ui->buttonPortReConnect->setEnabled(true);


}

void CommPort::RecvPortSettings(QPair<QString, QString> arg1)
{
    QMap<QString, PORTSET>::const_iterator itDecl;
    QMap<QString, QComboBox *>::iterator  itCombo;
    int intIndex;

    itCombo = m_ComboBoxes.find(arg1.first);
    if(itCombo != m_ComboBoxes.end())
    {
        intIndex = itCombo.value()->findText(arg1.second);
        {
            if(intIndex < 0)
            {
                //itDecl.value().Value;
                itDecl = m_DeclPortSettings.constFind(arg1.first);
                if(itDecl != m_DeclPortSettings.end())
                {
                    intIndex = itCombo.value()->findText(itDecl.value().Value);
                    if(intIndex >= 0) itCombo.value()->setCurrentIndex(intIndex);
                }
            }
            else
            {
                //arg1.second
                itCombo.value()->setCurrentIndex(intIndex);
            }
        }
    }
}

void CommPort::RecvPortIniSettings()
{
    emit SendPortSection(m_PortGroupName);
}
