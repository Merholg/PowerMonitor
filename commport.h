#ifndef COMMPORT_H
#define COMMPORT_H

#include <QDialog>

namespace Ui {
class CommPort;
}

class CommPort : public QDialog
{
    Q_OBJECT

public:
    explicit CommPort(QWidget *parent = nullptr);
    ~CommPort();

private:
    Ui::CommPort *ui;
};

#endif // COMMPORT_H
