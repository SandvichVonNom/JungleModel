#include <QSettings>
#include <QDebug>
#include <iostream>
#include "stats.h"
#include "mainwindow.h"
#include <algorithm>

Stats::Stats(QObject *parent) : QObject(parent)
{

}

Stats::~Stats()
{

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

    QString testqstring = "AMUMU";

//    int x;
//    x = Stats::vectorSearch(championVector, testqstring, 2);

    return championVector;

}


int vectorSearch(std::vector<Stats::ChampionStats> vector, QString name, int length)
{
    int loc = -1;
    for (int i = 0; (i < length) && (loc != -1); i++)
        if (vector.at(i).name == name)
            loc = i;
    return loc;
}
