#include "powerdb.h"
#include "ui_powerdb.h"

const QMap<QString, QString> PowerDB::m_DeclDBSettings
{
    {"HostName", "localhost"},
    {"Database", "ELECTROMETER"},
    {"UserName", "electrouser"},
    {"Password", "111111"}
};
const QString PowerDB::m_DBGroupName {"DBCONNECTION"};

PowerDB::PowerDB(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PowerDB)
//    ,m_SerialPort(new QSerialPort(this)) экземпляр БД
{
    ui->setupUi(this);
    m_ComboBoxes.insert("HostName", ui->lineHostName);
    m_ComboBoxes.insert("Database", ui->lineDatabase);
    m_ComboBoxes.insert("UserName", ui->lineUserName);
    m_ComboBoxes.insert("Password", ui->linePassword);
    QMap<QString, QLineEdit *>::iterator  itCombo;
    for(itCombo = m_ComboBoxes.begin(); itCombo != m_ComboBoxes.end(); ++itCombo) itCombo.value()->setEnabled(false); // Запрет доступа

    ui->buttonDBReConnect->setEnabled(false);
    // подключение к кнопке (Re)Connect действия
    QAction* pactReCon = new QAction("DB (Re)Connection action", 0);
    pactReCon->setText("&ReConnect");
    pactReCon->setShortcut(QKeySequence("CTRL+D"));
    pactReCon->setToolTip("ReConnect DataBase");
    pactReCon->setStatusTip("DB Connected");
    pactReCon->setWhatsThis("When pressed, the application tries to reopen the current database");
//    pactReCon->seticon(QPixmap(":/img4.png"));
    QObject::connect(pactReCon, SIGNAL(triggered()), this, SLOT(on_actionDBReConnection_triggered())); // кнопка ReConnect
    ui->buttonDBReConnect->addAction(pactReCon);

    //ui->buttonDBClose->setEnabled(false);

    QObject::connect(ui->buttonDBClose, SIGNAL(clicked()), this, SLOT(hide()));

    //QObject::connect(m_SerialPort, SIGNAL(readyRead()), SLOT(RecvResponseData())); // данные порта получены

    QMap<QString, QString>::const_iterator itDecl;
    for (itCombo = m_ComboBoxes.begin(); itCombo != m_ComboBoxes.end(); ++itCombo)
    {
        itDecl = m_DeclDBSettings.constFind(itCombo.key());
        if(itDecl != m_DeclDBSettings.end()) itCombo.value()->setText(itDecl.value()); // заполнение установочными (дефолтными) данными
    }

}

PowerDB::~PowerDB()
{
//    if(m_SerialPort->isOpen()) m_SerialPort->close();
//    delete m_SerialPort;
    delete ui;
}

void PowerDB::on_actionDBReConnection_triggered() // нажатие кнопки Port ReConnect
{
//попытаься открыть БД, а если нет такой - создать QDialog

//    QMap<QString, QComboBox *>::iterator  itCombo;        //итератор комбобоксов
//    int intIndex;
//    if(m_SerialPort->isOpen()) m_SerialPort->close();
//    if(ui->comboPortName->currentIndex() >= 0)
//    {
//        intIndex = ui->comboPortName->currentData(Qt::UserRole).toInt();
//        m_SerialPort->setPort(m_SerialPorts[intIndex]);
////        m_serial->setPortName(ui->comboPortName->itemText(intIndex));

//        itCombo = m_ComboBoxes.find("BaudRate"); // поиск комбобокса с названием
//        if(itCombo != m_ComboBoxes.end()) // найден
//        {
//            intIndex = itCombo.value()->currentData(Qt::UserRole).toInt();
//            m_SerialPort->setBaudRate(intIndex);
//        }
//    if(m_SerialPort->open(QIODevice::ReadWrite))
//    {
//            ui->statusBar->showMessage(tr("Connected to %1 : %2, %3, %4, %5, %6")
////                                   .arg(p.name).arg(p.stringBaudRate).arg(p.stringDataBits)
////                                   .arg(p.stringParity).arg(p.stringStopBits).arg(p.stringFlowControl));
////        showStatusMessage(tr("Connected to %1 : %2, %3, %4, %5, %6")
////                          .arg(p.name).arg(p.stringBaudRate).arg(p.stringDataBits)
////                          .arg(p.stringParity).arg(p.stringStopBits).arg(p.stringFlowControl));
//    }
//    else
//    {
//        QMessageBox::critical(this, tr("Error"), m_SerialPort->errorString());

////        showStatusMessage(tr("Open error"));
////            ui->statusBar->showMessage(tr("Open error"));
//    }

}

void PowerDB::RecvEndDBSettings()
{
    // отправить в programsettings m_ComboBoxes
    QMap<QString, QLineEdit *>::iterator  itCombo;
    for(itCombo = m_ComboBoxes.begin(); itCombo != m_ComboBoxes.end(); ++itCombo) emit SendDBSettings(qMakePair(itCombo.key(), itCombo.value()->text()));

    for(itCombo = m_ComboBoxes.begin(); itCombo != m_ComboBoxes.end(); ++itCombo) itCombo.value()->setEnabled(true);
    ui->buttonDBReConnect->setEnabled(true);
    //ui->buttonDBClose->setEnabled(true);
}

void PowerDB::RecvDBSettings(QPair<QString, QString> arg1)
{
    QMap<QString, QLineEdit *>::iterator  itCombo;

    itCombo = m_ComboBoxes.find(arg1.first);
    if(itCombo != m_ComboBoxes.end()) itCombo.value()->setText(arg1.second);
}

void PowerDB::RecvDBIniSettings()
{
    emit SendDBSection(m_DBGroupName);
}
