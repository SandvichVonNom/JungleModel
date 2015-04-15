#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSettings>
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

    Stats *statsObj = new Stats;
    std::vector<Stats::ChampionStats> allChampionStats = statsObj->importChampions();

    qDebug() << allChampionStats.at(1).name;

    ui->testLine->setText("kekeke");

    int championCount = allChampionStats.size();

    qDebug() << championCount;

    for (int iii = 0; iii < championCount; iii++)
    {
        if (allChampionStats.at(iii).name == "ANIVIA")
        {
            qDebug() << "Found the mummy";
            qDebug() << "Index is:";
            qDebug() << iii;
        }
    }

//    Settings *importAll = new Settings;
//    importAll->importChampions();

}

void MainWindow::on_testButton_clicked()
{
    qDebug() << ui->testLine->text();
}
