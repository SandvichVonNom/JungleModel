#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSettings>
#include <QFile>
#include <QDebug>
#include <iostream>
#include "stats.h"
#include "calc.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    QFile championStatsFile("champion_stats.ini");
    QFile::copy(":/stats/champion_stats.ini", "champion_stats.ini");
    championStatsFile.setPermissions(QFile::WriteUser | QFile::WriteOwner | QFile::WriteGroup | QFile::WriteOther | QFile::ReadUser | QFile::ReadOwner | QFile::ReadGroup | QFile::ReadOther);
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_importButton_clicked()
{
//    Stats *statsObj = new Stats;
//    std::vector<Stats::ChampionStats> allChampionStats = statsObj->importChampions();

    Calc *calcObj = new Calc;
    Stats *statsObj = new Stats;
    Stats::ChampionStats amumu = statsObj->importSingleChampion("AMUMU");
    calcObj->updateLevel(amumu, 2);
    double testdouble = 2.333;
    qDebug() << testdouble;
}

void MainWindow::on_menuFileEdit_triggered()
{
    Stats *statsEditDialog = new Stats;
    statsEditDialog->show();
}
