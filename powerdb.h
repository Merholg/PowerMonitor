#ifndef POWERDB_H
#define POWERDB_H

#include <QDialog>

namespace Ui {
class PowerDB;
}

class PowerDB : public QDialog
{
    Q_OBJECT

public:
    explicit PowerDB(QWidget *parent = nullptr);
    ~PowerDB();

private:
    Ui::PowerDB *ui;
};

#endif // POWERDB_H
