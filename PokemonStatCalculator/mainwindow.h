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

    void on_pushCalculate_clicked();

private:
    enum CalcMode {EV, IV, BASE_STAT, STAT, LEVEL};

    Ui::MainWindow *ui;
    CalcMode m_currentOperation;

    void inputTitle(QString windowTitle, QString title1, QString title2, QString title3, QString title4, CalcMode operation);

};
#endif // MAINWINDOW_H
