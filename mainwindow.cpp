#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSettings>
#include <QDebug>
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

    Stats *allChampionStats = new Stats;
    allChampionStats->importChampions();

    ui->testLine->setText("kekeke");

//    Stats::ChampionStats("rawr");
//    qDebug() << amumu.getAD();
//    amumu.setAD();
//    qDebug() << "6";
//    qDebug() << amumu.getAD();

//    Settings *importAll = new Settings;
//    importAll->importChampions();

}

void MainWindow::on_testButton_clicked()
{
    qDebug() << ui->testLine->text();
}
