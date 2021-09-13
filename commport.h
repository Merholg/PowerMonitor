#ifndef COMMPORT_H
#define COMMPORT_H

#include <QDialog>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QMap>
#include <QComboBox>
#include <QAction>
#include <QMessageBox>
#include <QErrorMessage>
#include <QDebug>
//#include <algorithm>

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
    void RecvRequestData(QByteArray arg1, QList<int> arg2); // запрос на нередачу данных и последующий прием ожидаемого количества байт
    void RecvResponseData(); // чтение данных из порта и отправка их сигналом SendResponseData
    void RecvOccurredError(); // cообщение об ошибке во время работы с экземпляром порта
    void RecvAboutToClose(); // сообщение в статусбар при закрытии порта

public slots:
    void RecvPortIniSettings(); // получить сигнал на начало работы и SendPortSection(QString arg1)

signals:
    void SendPortSection(QString arg1); //передать название секции с параметрами компорта в экз. ini файла
    void SendPortSettings(QPair<QString, QString> arg1); // записать установленное значение в файл ini
    void SendResponseData(QByteArray arg1, int arg2, QString arg3); // отправить полученные данные
    void SendStatusString(QString arg1); // отправка строки состояния в статусбар

private:
    Ui::CommPort *ui;
    static const QMap<QString, PORTSET> m_DeclPortSettings; // key - Name - Наименование ключа - описание параметров ком порта и их возможных значений
    static const QString m_PortGroupName; //наименование секции с записями значений относящихся к ком порту
    QMap<QString, QComboBox *> m_ComboBoxes; //указатели на комбобоксы с параметрами компорта для автоматической обработки

    QSerialPort * m_SerialPort; // экземпляр открытого порта
    QMap<int, QSerialPortInfo> m_SerialPorts; // список существующих портов
    QList<int> m_ExpectedBytes; // варианты ожидаемого количества байт при  приеме
//    QByteArray m_ReadBytes; // массив с прочитанными данными

};

#endif // COMMPORT_H
