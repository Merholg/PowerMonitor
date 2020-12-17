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
    m_SerialPort(new QSerialPort(this))
{
    //зарядка указателей на гуй элементы
    ui->setupUi(this);
    m_ComboBoxes.insert("Port", ui->comboPortName);
    m_ComboBoxes.insert("BaudRate", ui->comboPortBaudRate);
    m_ComboBoxes.insert("DataBits", ui->comboPortDataBits);
    m_ComboBoxes.insert("Parity", ui->comboPortParity);
    m_ComboBoxes.insert("StopBits", ui->comboPortStopBits);
    m_ComboBoxes.insert("FlowControl", ui->comboPortFlowControl);
    QMap<QString, QComboBox *>::iterator  itCombo;        //итератор комбобоксов
    for(itCombo = m_ComboBoxes.begin(); itCombo != m_ComboBoxes.end(); ++itCombo) itCombo.value()->setEnabled(false); // Запрет доступа

    ui->buttonPortReConnect->setEnabled(false);
    // подключение к кнопке (Re)Connect действия
    QAction* pactReCon = new QAction("Port (Re)Connection action", 0);
    pactReCon->setText("&ReConnect");
    pactReCon->setShortcut(QKeySequence("CTRL+O"));
    pactReCon->setToolTip("Connect/Disconnect serial port");
    pactReCon->setStatusTip("Port Connected");
    pactReCon->setWhatsThis("When pressed, the application tries to open/close the selected port based on its current state");
//    pactReCon->seticon(QPixmap(":/img4.png"));
    QObject::connect(pactReCon, SIGNAL(triggered()), this, SLOT(on_actionPortReConnection_triggered()));
    ui->buttonPortReConnect->addAction(pactReCon);

    //ui->buttonPortClose->setEnabled(false);
    QObject::connect(ui->buttonPortClose, SIGNAL(clicked()), this, SLOT(hide())); // кнопка закрытия окна

    QMap<QString, PORTSET>::const_iterator itDecl;        //итератор установок порта
    QMap<QString, int>::const_iterator itChoose;          //существующие варианты значения выбранной переменной (map из PORTSETa)
    // заполнение комбобоксов установочными данными
    int intIndex;
    for(itCombo = m_ComboBoxes.begin(); itCombo != m_ComboBoxes.end(); ++itCombo)
    {
        itDecl = m_DeclPortSettings.constFind(itCombo.key()); // найти в описании значений PORTSET с названием как текущее в списке комбобоксов и установить туда указатель
        if(itDecl != m_DeclPortSettings.end()) // если нашли
        {
            for (itChoose = itDecl.value().Choose.constBegin(); itChoose != itDecl.value().Choose.constEnd(); ++itChoose) // цикл по выбираемым опциям указанной переменной и заполнение соотв. комбобокса
            {
                itCombo.value()->addItem(itChoose.key(), itChoose.value()); // зарядка в комбобокс наименования параметра как Qt::DisplayRole и его числового значения как Qt::UserRole
            }
            intIndex = itCombo.value()->findText(itDecl.value().Value); // найти в комбобоксе индекс значения совпадающего с умолчательным
            if(intIndex >= 0) itCombo.value()->setCurrentIndex(intIndex); // если найдено установить текущим
            else itCombo.value()->setCurrentIndex(0);
        }
    }

    intIndex = 0;
    foreach(const QSerialPortInfo portitem, QSerialPortInfo::availablePorts())
    {
        m_SerialPorts.insert(intIndex, portitem);
        ui->comboPortName->addItem(portitem.portName(), intIndex); // зарядка в комбобокс наименования параметра как Qt::DisplayRole и его числового значения как Qt::UserRole
        ++intIndex;
    }
    if(intIndex > 0) ui->comboPortName->setCurrentIndex(0);
    else ui->comboPortName->setCurrentIndex(-1);
    // создать очередь сообщений обмена с ком портом
    //    qDebug() << "CommPort(QWidget *parent)";
}

CommPort::~CommPort()
{
    if(m_SerialPort->isOpen()) m_SerialPort->close();
    // очистить очереди
    delete m_SerialPort;
    delete ui;
}

void CommPort::on_actionPortReConnection_triggered()
{
    // нажатие кнопки Port ReConnect
}

void CommPort::CloseCommPort()
{

}

void CommPort::OpenCommPort()
{
//    QMap<QString, PORTSET>::const_iterator itDecl;
//    QMap<QString, int>::const_iterator itChoose;          //существующие варианты значения переменной
//    int intIndex;
//    if(m_commportopened)
//    {
//        // очистить очереди
//        m_serial->close();
//        m_commportopened = false;
//    }
//    if(ui->comboPortName->count() > 0)
//    {
//        if(ui->comboPortName->currentIndex() < 0) intIndex = 0;
//        else intIndex = ui->comboPortName->currentIndex();
//        m_serial->setPortName(ui->comboPortName->itemText(intIndex));

//        itDecl = m_DeclPortSettings.constFind("BaudRate");
//        itChoose = itDecl.value().Choose.constFind(ui->comboPortBaudRate->currentText());
//        if(itChoose == itDecl.value().Choose.end()) itChoose = itDecl.value().Choose.constFind(itDecl.value().Value);
//        m_serial->setBaudRate(itChoose.value());

//        itDecl = m_DeclPortSettings.constFind("DataBits");
//        itChoose = itDecl.value().Choose.constFind(ui->comboPortDataBits->currentText());
//        if(itChoose == itDecl.value().Choose.end()) itChoose = itDecl.value().Choose.constFind(itDecl.value().Value);
//        m_serial->setDataBits(static_cast<QSerialPort::DataBits>(itChoose.value()));

//        itDecl = m_DeclPortSettings.constFind("Parity");
//        itChoose = itDecl.value().Choose.constFind(ui->comboPortParity->currentText());
//        if(itChoose != itDecl.value().Choose.end()) itChoose = itDecl.value().Choose.constFind(itDecl.value().Value);
//        m_serial->setParity(static_cast<QSerialPort::Parity>(itChoose.value()));

//        itDecl = m_DeclPortSettings.constFind("StopBits");
//        itChoose = itDecl.value().Choose.constFind(ui->comboPortStopBits->currentText());
//        if(itChoose != itDecl.value().Choose.end()) itChoose = itDecl.value().Choose.constFind(itDecl.value().Value);
//        m_serial->setStopBits(static_cast<QSerialPort::StopBits>(itChoose.value()));

//        itDecl = m_DeclPortSettings.constFind("FlowControl");
//        itChoose = itDecl.value().Choose.constFind(ui->comboPortFlowControl->currentText());
//        if(itChoose != itDecl.value().Choose.end()) itChoose = itDecl.value().Choose.constFind(itDecl.value().Value);
//        m_serial->setFlowControl(static_cast<QSerialPort::FlowControl>(itChoose.value()));

//        if (m_serial->open(QIODevice::ReadWrite))
//        {
//            m_commportopened = true;
////            ui->statusBar->showMessage(tr("Connected to %1 : %2, %3, %4, %5, %6")
////                                   .arg(p.name).arg(p.stringBaudRate).arg(p.stringDataBits)
////                                   .arg(p.stringParity).arg(p.stringStopBits).arg(p.stringFlowControl));
////        showStatusMessage(tr("Connected to %1 : %2, %3, %4, %5, %6")
////                          .arg(p.name).arg(p.stringBaudRate).arg(p.stringDataBits)
////                          .arg(p.stringParity).arg(p.stringStopBits).arg(p.stringFlowControl));
//        }
//        else
//        {
//            QMessageBox::critical(this, tr("Error"), m_serial->errorString());

////        showStatusMessage(tr("Open error"));
////            ui->statusBar->showMessage(tr("Open error"));
//        }
//    }

}

void CommPort::RecvEndPortSettings()
{
    // отправить в programsettings m_ComboBoxes
    QMap<QString, QComboBox *>::const_iterator  itCombo;
    for(itCombo = m_ComboBoxes.constBegin(); itCombo != m_ComboBoxes.constEnd(); ++itCombo) emit SendPortSettings(qMakePair(itCombo.key(), itCombo.value()->currentText())); // записать все в ini файл

    for(itCombo = m_ComboBoxes.constBegin(); itCombo != m_ComboBoxes.constEnd(); ++itCombo) itCombo.value()->setEnabled(true); // все разрешить
    ui->buttonPortReConnect->setEnabled(true);
    //ui->buttonPortClose->setEnabled(true);


}

void CommPort::RecvPortSettings(QPair<QString, QString> arg1)
{
    QMap<QString, QComboBox *>::iterator  itCombo;
    int intIndex;

    itCombo = m_ComboBoxes.find(arg1.first); // поиск комбобокса с названием как у переменной ini файла
    if(itCombo != m_ComboBoxes.end()) // найден
    {
        intIndex = itCombo.value()->findText(arg1.second); // поиск в комбобоксе вибираемого значения совпадающего с заданным в ini файле
        {
            if(intIndex >= 0) itCombo.value()->setCurrentIndex(intIndex);// найдено - устанавливается соотв индекс
        }
    }
}

void CommPort::RecvPortIniSettings()
{
    emit SendPortSection(m_PortGroupName);
}
