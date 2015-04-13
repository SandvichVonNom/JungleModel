#include <QSettings>
#include <QDebug>
#include <iostream>
#include "stats.h"
#include "mainwindow.h"
//#include "ui_mainwindow.h"

Stats::Stats(QObject *parent) : QObject(parent)
{

}

Stats::~Stats()
{

}

void Stats::importChampions()
{

    QSettings championSettings("champion_stats.ini",
                       QSettings::IniFormat);

    Stats::ChampionStats championArray[CHAMPIONCOUNT] = {{"AATROX"},{"AMUMU"}};

    for (int iii=0; iii < CHAMPIONCOUNT; iii++)
    {
        qDebug() << "Name: " + championArray[iii].name;
        championSettings.beginGroup(championArray[iii].name);
        championArray[iii].basead = championSettings.value("BASEAD").toInt();
        championArray[iii].baseas =  championSettings.value("BASEAS").toDouble();
        championArray[iii].q_dmg = championSettings.value("Q_DMG").toInt();
        championArray[iii].q_cd = championSettings.value("Q_CD").toDouble();
        championArray[iii].q_mana = championSettings.value("Q_MANA").toInt();
        championSettings.endGroup();

        qDebug() << championArray[iii].basead;
        qDebug() << championArray[iii].baseas;
        qDebug() << championArray[iii].q_dmg;
        qDebug() << championArray[iii].q_cd;
        qDebug() << championArray[iii].q_mana;
    }

}

//struct Stats::ChampionStats
//{
//    int basead;
//    double baseas;
//    int q_dmg;
//    double q_cd;
//    int q_mana;
//};

//void Stats::ChampionStats()
//{
//    int basead;
//    double baseas;
//    int q_dmg;
//    double q_cd;
//    int q_mana;
//}
