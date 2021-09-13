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
    ui->label1->setText("Total Stat:");
    ui->label2->setText("Base Stat:");
    ui->label3->setText("Level");
    ui->label4->setText("IV:");
}

void MainWindow::on_actionCalculateIV_triggered()
{
    m_currentOperation = CalcMode::IV;
    setWindowTitle("Pokemon IV Range Calculation");
    ui->label1->setText("Total Stat:");
    ui->label2->setText("Base Stat:");
    ui->label3->setText("Level");
    ui->label4->setText("EV:");
}

void MainWindow::on_actionCalculateBaseStat_triggered()
{
    m_currentOperation = CalcMode::BASE_STAT;
    setWindowTitle("Pokemon Base Stat Range Calculation");
    ui->label1->setText("Total Stat:");
    ui->label2->setText("Level:");
    ui->label3->setText("EV");
    ui->label4->setText("IV:");
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
    int value1 = ui->input1->value();
    int value2 = ui->input2->value();
    int value3 = ui->input3->value();
    int value4 = ui->input4->value();

    std::vector<int> range;
    switch(m_currentOperation) {
        case CalcMode::EV:
            range = findEV(value1, value2, value3, value4, m_isHP, m_natureMod);
        break;
        case CalcMode::IV:
            range = findIV(value1, value2, value3, value4, m_isHP, m_natureMod);
        break;
        case CalcMode::BASE_STAT:
            range = findBaseStat(value1, value2, value3, value4, m_isHP, m_natureMod);
        break;
        case CalcMode::LEVEL:
            //TODO: write backend for this
        break;
        case CalcMode::STAT:
            //TODO: write backend for this
        break;
    }

    //Sets Minimum/Maximum values in UI, converts string to c-string to QString
    ui->lowResult->setText(QString(("Min: " + std::to_string(range[0])).c_str()));
    ui->highResult->setText(QString(("Max: " + std::to_string(range[1])).c_str()));
}
