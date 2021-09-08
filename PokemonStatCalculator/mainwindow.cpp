#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    currentOperation = calc_type::STAT;
    this->setCentralWidget(ui->verticalLayoutWidget);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionCalculateEV_triggered()
{
    currentOperation = calc_type::EV;
    setWindowTitle("Pokemon EV Range Calculation");
}

void MainWindow::on_actionCalculateIV_triggered()
{
    currentOperation = calc_type::IV;
    setWindowTitle("Pokemon IV Range Calculation");
}

void MainWindow::on_actionCalculateBaseStat_triggered()
{
    currentOperation = calc_type::BASE_STAT;
    setWindowTitle("Pokemon Base Stat Range Calculation");
}

void MainWindow::on_actionCalculateTotalStat_triggered()
{
    currentOperation = calc_type::STAT;
    setWindowTitle("Pokemon Total Stat Calculation");
}



void MainWindow::on_pushCalculate_clicked()
{

}

