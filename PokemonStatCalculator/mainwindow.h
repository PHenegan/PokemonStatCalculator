#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDialog>

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
    void on_actionCalculateEV_triggered();

    void on_actionCalculateIV_triggered();

    void on_actionCalculateBaseStat_triggered();

    void on_actionCalculateTotalStat_triggered();

private:
    Ui::MainWindow *ui;
    QString currentOperation = "";
};
#endif // MAINWINDOW_H
