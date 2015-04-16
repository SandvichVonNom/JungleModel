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
    Stats *statsObj = new Stats;
    std::vector<Stats::ChampionStats> allChampionStats = statsObj->importChampions();

    ui->testLine->setText("You pressed the button");

    int championCount = allChampionStats.size();

    qDebug() << "Champion count:";
    qDebug() << championCount;

    for (int iii = 0; iii < championCount; iii++)
    {
        ui->testList->addItem(allChampionStats.at(iii).name);
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
    qDebug() << ui->testList->currentItem()->text();
}

void MainWindow::on_menuFileEdit_triggered()
{
    Stats *statsEditDialog = new Stats(this);
    QObject::connect(ui->menuFileEdit, &QAction::triggered, statsEditDialog, &Stats::on_buttonUpdateChampions_clicked);
//    connect(statsEditDialog, SIGNAL(opened()), ui->menuFileEdit, SLOT(triggered()));
    statsEditDialog->show();
}
