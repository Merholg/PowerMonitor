#include "powermonitor.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    PowerMonitor w;
    w.show();
    return a.exec();
}
