#ifndef COMMPORT_H
#define COMMPORT_H

#include <QDialog>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QMap>
#include <QComboBox>
#include <QMessageBox>
#include <QDebug>

struct PORTSET
{
    QString             Value;  // Значение ключа по умолчанию
    QMap<QString, int>  Choose; // Массив пар возможных строковых значений ключа и их числовая интерпретация (массив мб пустым - подразумевает допустимость любого строкового значения)
};

namespace Ui {
class CommPort;
}

class CommPort : public QDialog
{
    Q_OBJECT

public:
    explicit CommPort(QWidget *parent = nullptr);
    ~CommPort();

private slots:
    void on_actionPortReConnection_triggered();
    void RecvPortSettings(QPair<QString, QString> arg1); //получает пару ключ - значение по ключу проверяет значение на валидность и пытается сделать его текущим
    void RecvEndPortSettings();
    void OpenCommPort();

public slots:
    void RecvPortIniSettings(); // получить сигнал на начало работы и SendPortSection(QString arg1)

signals:
    void SendPortSection(QString arg1); //передать название секции
    void SendPortSettings(QPair<QString, QString> arg1); // записать установленное значение
    void SendPortOpen(); // порт открыт
    void SendPortClose();// порт закрыт

private:
    Ui::CommPort *ui;
    static const QMap<QString, PORTSET> m_DeclPortSettings; // key - Name - Наименование ключа
    static const QString m_PortGroupName;
    QMap<QString, QComboBox *> m_ComboBoxes;

    QList<QSerialPortInfo> m_commports;
    QSerialPort * m_serial;
    bool m_commportopened;

};

#endif // COMMPORT_H
