#ifndef POWERDB_H
#define POWERDB_H

#include <QDialog>
#include <QMap>
#include <QComboBox>

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
    void RecvDBSettings(QPair<QString, QString> arg1);
    void RecvEndDBSettings();

public slots:
    void RecvDBIniSettings();

signals:
    void SendDBSection(QString arg1);
    void SendDBSettings(QPair<QString, QString> arg1);
    void SendDBOpen();
    void SendDBClose();

private:
    Ui::PowerDB *ui;
    static const QMap<QString, QString> m_DeclDBSettings;
    static const QString m_DBGroupName;
    QMap<QString, QLineEdit *> m_ComboBoxes;
};

#endif // POWERDB_H
