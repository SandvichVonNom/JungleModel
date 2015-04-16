#include <QSettings>
#include <QDebug>
#include <iostream>
#include <algorithm>
#include "mainwindow.h"
#include "stats.h"
#include "ui_stats.h"

Stats::Stats(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Stats)
{
    ui->setupUi(this);
    std::vector<Stats::ChampionStats> allChampionStats = importChampions();
    updateChampionList(allChampionStats);
}

Stats::~Stats()
{
    delete ui;
}

std::vector<Stats::ChampionStats> Stats::importChampions()
{

    QSettings championSettings("champion_stats.ini",
                       QSettings::IniFormat);

    std::vector<Stats::ChampionStats> championVector;

    for (int iii=0; iii < championSettings.childGroups().count(); iii++)
    {
        Stats::ChampionStats tempStats;

        tempStats.name = championSettings.childGroups()[iii];
        championSettings.beginGroup(tempStats.name);
        tempStats.basead = championSettings.value("BASEAD").toInt();
        tempStats.baseas = championSettings.value("BASEAS").toDouble();
        tempStats.q_dmg = championSettings.value("Q_DMG").toInt();
        tempStats.q_cd = championSettings.value("Q_CD").toDouble();
        tempStats.q_mana = championSettings.value("Q_MANA").toInt();
        championSettings.endGroup();
        championVector.push_back(tempStats);

        qDebug() << championVector.at(iii).name;

    }

    return championVector;

}

void Stats::on_buttonUpdateChampions_clicked()
{
    std::vector<Stats::ChampionStats> allChampionStats = importChampions();
    updateChampionList(allChampionStats);
}

void Stats::updateChampionList(std::vector<ChampionStats> allChampionStats)
{
    ui->listChampions->clear();

    int championCount = allChampionStats.size();

    qDebug() << "Champion count:";
    qDebug() << championCount;

    for (int iii = 0; iii < championCount; iii++)
    {
        ui->listChampions->addItem(allChampionStats.at(iii).name);
        if (allChampionStats.at(iii).name == "AMUMU")
        {
            qDebug() << "Found the mummy";
            qDebug() << "Index is:";
            qDebug() << iii;
        }
    }

    qDebug() << "Woo";
    std::cout << "Wat";
    ui->lineBaseAD->setText("Interesting");
}

void Stats::on_listChampions_itemSelectionChanged()
{
    qDebug() << "Switchers";
}
