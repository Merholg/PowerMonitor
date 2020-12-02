#ifndef POWERMETER_H
#define POWERMETER_H

#include <QDialog>

namespace Ui {
class PowerMeter;
}

class PowerMeter : public QDialog
{
    Q_OBJECT

public:
    explicit PowerMeter(QWidget *parent = nullptr);
    ~PowerMeter();

private:
    Ui::PowerMeter *ui;
};

#endif // POWERMETER_H
