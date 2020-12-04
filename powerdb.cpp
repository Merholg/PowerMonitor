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
{
    ui->setupUi(this);
    m_ComboBoxes.insert("HostName", ui->lineHostName);
    m_ComboBoxes.insert("Database", ui->lineDatabase);
    m_ComboBoxes.insert("UserName", ui->lineUserName);
    m_ComboBoxes.insert("Password", ui->linePassword);

    QObject::connect(ui->buttonDBClose, SIGNAL(clicked()), this, SLOT(hide()));

    QMap<QString, QString>::const_iterator itDecl;
    QMap<QString, QLineEdit *>::iterator  itCombo;
    for (itCombo = m_ComboBoxes.begin(); itCombo != m_ComboBoxes.end(); ++itCombo)
    {
        itDecl = m_DeclDBSettings.constFind(itCombo.key());
        if(itDecl != m_DeclDBSettings.end()) itCombo.value()->setText(itDecl.value());
    }

}

PowerDB::~PowerDB()
{
    delete ui;
}

void PowerDB::RecvEndDBSettings()
{
    // отправить в programsettings m_ComboBoxes
    QMap<QString, QLineEdit *>::const_iterator  itCombo;
    for(itCombo = m_ComboBoxes.constBegin(); itCombo != m_ComboBoxes.constEnd(); ++itCombo) emit SendDBSettings(qMakePair(itCombo.key(), itCombo.value()->text()));
    for(itCombo = m_ComboBoxes.constBegin(); itCombo != m_ComboBoxes.constEnd(); ++itCombo) itCombo.value()->setEnabled(true);
    ui->buttonDBReConnect->setEnabled(true);
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
