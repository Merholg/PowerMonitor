#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::MainWindow),
    m_model(new NationalityModel( this ))
{
    ui->setupUi(this);
    ui->nationalityCombo->setModel(m_model);
    QMap<QString, int> qm = {
    {"Baud1200", 1200},
    {"Baud2400", 2400},
    {"Baud4800", 4800},
    {"Baud9600", 9600},
    {"Baud19200", 19200},
    {"Baud38400", 38400},
    {"Baud57600", 57600},
    {"Baud115200", 115200}};
    QMap<QString, int>::const_iterator itChoose;
    for(itChoose = qm.begin(); itChoose != qm.end(); ++itChoose)
    {
        ui->comboInsModel->addItem(itChoose.key(), itChoose.value());
    }

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_nationalityCombo_highlighted(const QString &arg1)
{
}

void MainWindow::on_nationalityCombo_highlighted(int index)
{
//    ui->labelSel->setNum(index.data(Qt::DisplayRole).toString();
//    ui->labelSel->setText(index.data(Qt::DisplayRole).toString();
    QModelIndex idx = m_model->index(index, 0);
    QString text = idx.data(Qt::UserRole).toString();
    ui->labelSel->setText(text);
}

void MainWindow::on_nationalityCombo_currentIndexChanged(int index)
{
    QVariant SelData = ui->nationalityCombo->currentData(Qt::UserRole);
    if(index < 0) ui->lineEditSelect->setText(QString::number(index));
    else ui->lineEditSelect->setText(SelData.toString());

}

void MainWindow::on_comboInsModel_currentIndexChanged(int index)
{
    ui->labelUser->setNum(ui->comboInsModel->currentData(Qt::UserRole).toInt());
    ui->labelDSisplay->setText(ui->comboInsModel->currentData(Qt::DisplayRole).toString());
}
