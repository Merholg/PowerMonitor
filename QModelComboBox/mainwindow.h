#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "nationalitymodel.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_nationalityCombo_highlighted(const QString &arg1);

    void on_nationalityCombo_highlighted(int index);

    void on_nationalityCombo_currentIndexChanged(int index);

    void on_comboInsModel_currentIndexChanged(int index);

private:
    Ui::MainWindow *ui;
    QAbstractListModel *m_model;
};
#endif // MAINWINDOW_H
