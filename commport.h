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
    QMap<QString, int>  Choose; // Массив пар возможных строковых значений ключа и их числовая интерпретация
};

namespace Ui {
class CommPort;
}

class CommPort : public QDialog //Класс настройки портов обмена и обмена с ними
{
    Q_OBJECT

public:
    explicit CommPort(QWidget *parent = nullptr);
    ~CommPort();

private slots:
    void on_actionPortReConnection_triggered(); //нажатие кнопки (Re)Connect
    void RecvPortSettings(QPair<QString, QString> arg1); //получает пару ключ - значение по ключу проверяет значение на валидность и пытается сделать его текущим
    void RecvEndPortSettings(); //получение - признак завершения передачи начальных установок (все существующие установки переданы) - разрешает ручное редактирование и соединение с установленными параметрами
    void OpenCommPort();
    void CloseCommPort();

public slots:
    void RecvPortIniSettings(); // получить сигнал на начало работы и SendPortSection(QString arg1)

signals:
    void SendPortSection(QString arg1); //передать название секции с параметрами компорта в экз. ini файла
    void SendPortSettings(QPair<QString, QString> arg1); // записать установленное значение
    void SendPortOpen(); // порт открыт
    void SendPortClose();// порт закрыт

private:
    Ui::CommPort *ui;
    static const QMap<QString, PORTSET> m_DeclPortSettings; // key - Name - Наименование ключа - описание параметров ком порта и их возможных значений
    static const QString m_PortGroupName; //наименование секции с записями значений относящихся к ком порту
    QMap<QString, QComboBox *> m_ComboBoxes; //указатели на комбобоксы с параметрами компорта для автоматической обработки

    QSerialPort * m_SerialPort;
    QMap<int, QSerialPortInfo> m_SerialPorts;

};

#endif // COMMPORT_H
