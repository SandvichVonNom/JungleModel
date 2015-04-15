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

void Stats::on_Stats_show()
{
    qDebug() << "Hi?";
}
