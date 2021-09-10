#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "calculations.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setCentralWidget(ui->verticalLayoutWidget);
    this->on_actionCalculateTotalStat_triggered();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionCalculateEV_triggered()
{
    m_currentOperation = CalcMode::EV;
    setWindowTitle("Pokemon EV Range Calculation");
}

void MainWindow::on_actionCalculateIV_triggered()
{
    m_currentOperation = CalcMode::IV;
    setWindowTitle("Pokemon IV Range Calculation");
}

void MainWindow::on_actionCalculateBaseStat_triggered()
{
    m_currentOperation = CalcMode::BASE_STAT;
    setWindowTitle("Pokemon Base Stat Range Calculation");
}

void MainWindow::on_actionCalculateTotalStat_triggered()
{
    m_currentOperation = CalcMode::STAT;
    setWindowTitle("Pokemon Total Stat Calculation");
}

void MainWindow::on_isHP_stateChanged(int arg1)
{
    m_isHP = ui->isHP->isChecked();
}

void MainWindow::on_natureMods_currentTextChanged(const QString &arg1)
{
    if(arg1 == "+")
        m_natureMod = 1.1;
    else if (arg1 == "-")
        m_natureMod = 0.9;
    else
        m_natureMod = 1.0;
}

void MainWindow::on_pushCalculate_clicked()
{

}



