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
    //ui->buttonPortClose->setEnabled(false);

    // подключение к кнопке (Re)Connect действия
    QAction * pactReCon = new QAction("Port (Re)Connection action", 0);
    pactReCon->setText("&ReConnect");
    pactReCon->setShortcut(QKeySequence("CTRL+O"));
    pactReCon->setToolTip("ReConnect serial port");
    pactReCon->setStatusTip("Port Connected");
    pactReCon->setWhatsThis("When pressed, the application tries to open/close the selected port based on its current state");
//    pactReCon->seticon(QPixmap(":/img4.png"));
    QObject::connect(pactReCon, SIGNAL(triggered()), this, SLOT(on_actionPortReConnection_triggered())); // кнопка ReConnect
    ui->buttonPortReConnect->addAction(pactReCon);

    QObject::connect(ui->buttonPortClose, SIGNAL(clicked()), SLOT(hide())); // кнопка закрытия окна

    QObject::connect(m_SerialPort, SIGNAL(readyRead()), SLOT(RecvResponseData())); // данные порта получены
    QObject::connect(m_SerialPort, SIGNAL(errorOccurred()), SLOT(RecvOccurredError())); // если в процессе работы возникнет ошибка
    QObject::connect(m_SerialPort, SIGNAL(aboutToClose()), SLOT(RecvAboutToClose())); // если в процессе работы возникнет ошибка

    QMap<QString, PORTSET>::const_iterator itDecl;        //итератор установок порта
    QMap<QString, int>::const_iterator itChoose;          //существующие варианты значения выбранной переменной (map из PORTSETa)
    // заполнение комбобоксов установочными данными
    int intIndex;
    for(itCombo = m_ComboBoxes.begin(); itCombo != m_ComboBoxes.end(); ++itCombo)
    {
        itDecl = m_DeclPortSettings.constFind(itCombo.key()); // найти в описании значений PORTSET с названием как текущее в списке комбобоксов и установить туда указатель
        if(itDecl != m_DeclPortSettings.end()) // если нашли
        {
            for(itChoose = itDecl.value().Choose.constBegin(); itChoose != itDecl.value().Choose.constEnd(); ++itChoose) // цикл по выбираемым опциям указанной переменной и заполнение соотв. комбобокса
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
}

CommPort::~CommPort()
{
    if(m_SerialPort->isOpen()) m_SerialPort->close();
    delete m_SerialPort;
    delete ui;
}

void CommPort::RecvAboutToClose()
{
    emit SendStatusString(QString("Port %1 close").arg(m_SerialPort->portName()));
}

void CommPort::RecvOccurredError()
{
    //QErrorMessage m_SerialPort->errorString()
    QErrorMessage * errorMessage = new QErrorMessage(this);
    errorMessage->showMessage(m_SerialPort->errorString());
    m_SerialPort->clearError();
    delete errorMessage;
}

void CommPort::RecvRequestData(QByteArray arg1, QList<int> arg2)
{
    // получив сигнал на запрос значения переменной сохраняем в m_ExpectedBytes массив ожидаемых длин возвращаемого значения и отсылаем байтмассив запроса
    // если порт не открыт либо ошибка записи - немедленно излучается сигнал SendResponseData содержащий пустой байтмассив и сообщения об ошибке
    // иначе SendResponseData излучается когда будут получены данные ответа на запрос
    QByteArray ReadBytes;
    m_ExpectedBytes.clear();
    if(m_SerialPort->isOpen())
    {
        m_ExpectedBytes = arg2;
        m_SerialPort->clear(QSerialPort::AllDirections);
        if(m_SerialPort->write(arg1) < 0)
        {
//            QMessageBox::critical(this, tr("Error"), m_SerialPort->errorString());
            m_ExpectedBytes.clear();
            emit SendResponseData(ReadBytes, -2, "Port write error"); // m_SerialPort->errorString() мб прибита в RecvOccurredError через  m_SerialPort->clearError();
        }
    }
    else emit SendResponseData(ReadBytes, -1, "Port not open");
}

void CommPort::RecvResponseData()
{
    QByteArray ReadBytes;
    int ErrNumber = 0;
    QString ErrString = "";
    int intIndex = m_ExpectedBytes.indexOf(m_SerialPort->bytesAvailable());
    if(intIndex < 0) // если не найден вариант с подход. длиной полученного сообщения
    {
        ErrNumber = -4;
        ErrString = "Error read response data - unexpected lenght)";
    }
    else
    {
        if(0 != m_ExpectedBytes.at(intIndex))
        {
            ReadBytes = m_SerialPort->read(m_ExpectedBytes.at(intIndex));
            if(ReadBytes.isEmpty())
            {
                ErrNumber = -3;
                ErrString = "Error read response data";
            }
        }
    }
    m_SerialPort->clear(QSerialPort::AllDirections);
    m_ExpectedBytes.clear();
    emit SendResponseData(ReadBytes, ErrNumber, ErrString);
}

void CommPort::on_actionPortReConnection_triggered() // нажатие кнопки Port ReConnect
{
    QMap<QString, QComboBox *>::iterator  itCombo;        //итератор комбобоксов
    if(m_SerialPort->isOpen()) m_SerialPort->close();

    if(ui->comboPortName->currentIndex() >= 0)
    {
        m_SerialPort->setPort(m_SerialPorts[ui->comboPortName->currentData(Qt::UserRole).toInt()]);
//        m_serial->setPortName(ui->comboPortName->itemText(ui->comboPortName->currentData(Qt::DisplayRole).toString()));

        m_SerialPort->setBaudRate(ui->comboPortBaudRate->currentData(Qt::UserRole).toInt());
        m_SerialPort->setDataBits(static_cast<QSerialPort::DataBits>(ui->comboPortDataBits->currentData(Qt::UserRole).toInt()));
        m_SerialPort->setParity(static_cast<QSerialPort::Parity>(ui->comboPortParity->currentData(Qt::UserRole).toInt()));
        m_SerialPort->setStopBits(static_cast<QSerialPort::StopBits>(ui->comboPortStopBits->currentData(Qt::UserRole).toInt()));
        m_SerialPort->setFlowControl(static_cast<QSerialPort::FlowControl>(ui->comboPortFlowControl->currentData(Qt::UserRole).toInt()));

        if(m_SerialPort->open(QIODevice::ReadWrite))
        {
            emit SendStatusString(QString("Port %1 connected as %2,%3,%4,%5,%6")
                                            .arg(ui->comboPortName->currentText())
                                            .arg(ui->comboPortBaudRate->currentText())
                                            .arg(ui->comboPortDataBits->currentText())
                                            .arg(ui->comboPortParity->currentText())
                                            .arg(ui->comboPortStopBits->currentText())
                                            .arg(ui->comboPortFlowControl->currentText()));
        }
    }

}

void CommPort::RecvEndPortSettings()
{
    // отправить в programsettings m_ComboBoxes
    QMap<QString, QComboBox *>::iterator  itCombo;        //итератор комбобоксов
    for(itCombo = m_ComboBoxes.begin(); itCombo != m_ComboBoxes.end(); ++itCombo) emit SendPortSettings(qMakePair(itCombo.key(), itCombo.value()->currentText())); // записать все в ini файл

    for(itCombo = m_ComboBoxes.begin(); itCombo != m_ComboBoxes.end(); ++itCombo) itCombo.value()->setEnabled(true); // все разрешить
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
