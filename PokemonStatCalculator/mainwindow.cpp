#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "calculations.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setCentralWidget(ui->verticalLayoutWidget);
    this->inputTitle("Pokemon Base Stat Range Calculation", "Total Stat:", "Level:", "EV:", "IV:", CalcMode::BASE_STAT);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionCalculateEV_triggered()
{
    this->inputTitle("Pokemon EV Range Calculation", "Total Stat:", "Base Stat:", "Level:", "IV:", CalcMode::EV);
}

void MainWindow::on_actionCalculateIV_triggered()
{
    this->inputTitle("Pokemon IV Range Calculation", "Total Stat:", "Base Stat:", "Level:", "EV:", CalcMode::IV);
}

void MainWindow::on_actionCalculateBaseStat_triggered()
{
    this->inputTitle("Pokemon Base Stat Range Calculation", "Total Stat:", "Level:", "EV:", "IV:", CalcMode::BASE_STAT);
}

void MainWindow::on_actionCalculateTotalStat_triggered()
{
    m_currentOperation = CalcMode::STAT;
    setWindowTitle("Pokemon Total Stat Calculation");
}

void MainWindow::on_pushCalculate_clicked()
{
    int value1 = ui->input1->value();
    int value2 = ui->input2->value();
    int value3 = ui->input3->value();
    int value4 = ui->input4->value();

    bool isHP = ui->isHP->isChecked();
    double natureMod;

    //Processes the values in the list picker to get a numerical value for the nature modifier
    std::string nature = ui->natureMods->currentText().toStdString();
    if (nature == "+")
        natureMod = 1.1;
    else if (nature == "-")
        natureMod = 0.9;
    else
        natureMod = 1.0;



    std::vector<int> range;
    switch(m_currentOperation) {
        case CalcMode::EV:
            range = findEV(value1, value2, value3, value4, isHP, natureMod);
        break;
        case CalcMode::IV:
            range = findIV(value1, value2, value3, value4, isHP, natureMod);
        break;
        case CalcMode::BASE_STAT:
            range = findBaseStat(value1, value2, value3, value4, isHP, natureMod);
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

void MainWindow::inputTitle(QString windowTitle, QString title1, QString title2, QString title3, QString title4, CalcMode operation)
{
    m_currentOperation = operation;
    setWindowTitle(windowTitle);

    ui->label1->setText(title1);
    ui->label2->setText(title2);
    ui->label3->setText(title3);
    ui->label4->setText(title4);
}
