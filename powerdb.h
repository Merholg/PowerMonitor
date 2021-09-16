#ifndef POWERDB_H
#define POWERDB_H

#include <QDialog>
#include <QMap>
#include <QLineEdit>
#include <QAction>

namespace Ui {
class PowerDB;
}

class PowerDB : public QDialog
{
    Q_OBJECT

public:
    explicit PowerDB(QWidget *parent = nullptr);
    ~PowerDB();

private slots:
    void on_actionDBReConnection_triggered(); //нажатие кнопки (Re)Connect
    void RecvDBSettings(QPair<QString, QString> arg1); //получает пару ключ - значение по ключу проверяет значение на валидность и пытается сделать его текущим
    void RecvEndDBSettings(); //получение - признак завершения передачи начальных установок (все существующие установки переданы) - разрешает ручное редактирование и соединение с установленными параметрами
    void RecvDBData(данные для дб); // запрос на нередачу данных

public slots:
    void RecvDBIniSettings(); // получить сигнал на начало работы и SendDBSection(QString arg1)

signals:
    void SendDBSection(QString arg1);  //передать название секции с параметрами базы данных в экз. ini файла
    void SendDBSettings(QPair<QString, QString> arg1); // записать установленное значение в файл ini
    void SendDBData(данные из дб); // отправить полученные данные
    void SendStatusString(QString arg1); // отправка строки состояния в статусбар

private:
    Ui::PowerDB *ui;
    static const QMap<QString, QString> m_DeclDBSettings;
    static const QString m_DBGroupName;
    QMap<QString, QLineEdit *> m_ComboBoxes;
};

#endif // POWERDB_H
