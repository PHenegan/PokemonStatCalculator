/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionCalculate_EV_range;
    QAction *actionCalculate_IV_range;
    QAction *actionCalculate_Base_Stat_Range;
    QAction *actionCalculate_Level_Range;
    QAction *actionCalculate_Total_Stat;
    QAction *actionExit;
    QWidget *centralwidget;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QMenuBar *menubar;
    QMenu *menuPokemon_Stat_Calculator;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1214, 600);
        actionCalculate_EV_range = new QAction(MainWindow);
        actionCalculate_EV_range->setObjectName(QString::fromUtf8("actionCalculate_EV_range"));
        actionCalculate_IV_range = new QAction(MainWindow);
        actionCalculate_IV_range->setObjectName(QString::fromUtf8("actionCalculate_IV_range"));
        actionCalculate_Base_Stat_Range = new QAction(MainWindow);
        actionCalculate_Base_Stat_Range->setObjectName(QString::fromUtf8("actionCalculate_Base_Stat_Range"));
        actionCalculate_Level_Range = new QAction(MainWindow);
        actionCalculate_Level_Range->setObjectName(QString::fromUtf8("actionCalculate_Level_Range"));
        actionCalculate_Total_Stat = new QAction(MainWindow);
        actionCalculate_Total_Stat->setObjectName(QString::fromUtf8("actionCalculate_Total_Stat"));
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QString::fromUtf8("actionExit"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        horizontalLayoutWidget = new QWidget(centralwidget);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(80, 40, 1011, 471));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(horizontalLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setPointSize(18);
        label->setFont(font);

        verticalLayout->addWidget(label, 0, Qt::AlignHCenter|Qt::AlignTop);


        horizontalLayout->addLayout(verticalLayout);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1214, 30));
        menuPokemon_Stat_Calculator = new QMenu(menubar);
        menuPokemon_Stat_Calculator->setObjectName(QString::fromUtf8("menuPokemon_Stat_Calculator"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuPokemon_Stat_Calculator->menuAction());
        menuPokemon_Stat_Calculator->addAction(actionCalculate_EV_range);
        menuPokemon_Stat_Calculator->addAction(actionCalculate_IV_range);
        menuPokemon_Stat_Calculator->addAction(actionCalculate_Base_Stat_Range);
        menuPokemon_Stat_Calculator->addAction(actionCalculate_Level_Range);
        menuPokemon_Stat_Calculator->addAction(actionCalculate_Total_Stat);
        menuPokemon_Stat_Calculator->addAction(actionExit);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionCalculate_EV_range->setText(QCoreApplication::translate("MainWindow", "Calculate EV range", nullptr));
        actionCalculate_IV_range->setText(QCoreApplication::translate("MainWindow", "Calculate IV range", nullptr));
        actionCalculate_Base_Stat_Range->setText(QCoreApplication::translate("MainWindow", "Calculate Base Stat Range", nullptr));
        actionCalculate_Level_Range->setText(QCoreApplication::translate("MainWindow", "Calculate Level Range", nullptr));
        actionCalculate_Total_Stat->setText(QCoreApplication::translate("MainWindow", "Calculate Total Stat", nullptr));
        actionExit->setText(QCoreApplication::translate("MainWindow", "Exit", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Pokemon Total Stat Calculator", nullptr));
        menuPokemon_Stat_Calculator->setTitle(QCoreApplication::translate("MainWindow", "File", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
