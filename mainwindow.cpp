#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSettings>
#include <QFile>
#include <QDebug>
#include <iostream>
#include "stats.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_importButton_clicked()
{
    QFile championStatsFile("champion_stats.ini");
    QFile::copy(":/stats/champion_stats.ini", "champion_stats.ini");
    championStatsFile.setPermissions(QFile::WriteUser | QFile::WriteOwner | QFile::WriteGroup | QFile::WriteOther | QFile::ReadUser | QFile::ReadOwner | QFile::ReadGroup | QFile::ReadOther);

    Stats *statsObj = new Stats;
    std::vector<Stats::ChampionStats> allChampionStats = statsObj->importChampions();

    ui->testLine->setText("kekeke");

    int championCount = allChampionStats.size();

    qDebug() << "Champion count:";
    qDebug() << championCount;

    for (int iii = 0; iii < championCount; iii++)
    {
        if (allChampionStats.at(iii).name == "AMUMU")
        {
            qDebug() << "Found the mummy";
            qDebug() << "Index is:";
            qDebug() << iii;
        }
    }
}

void MainWindow::on_testButton_clicked()
{
    qDebug() << ui->testLine->text();
}
