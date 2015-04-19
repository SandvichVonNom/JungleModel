#include <QDebug>
#include "calc.h"
#include "stats.h"

Calc::Calc(QObject *parent) : QObject(parent)
{

}

Calc::~Calc()
{

}

Stats::ChampionStats Calc::updateLevel(Stats::ChampionStats championStats, int level)
{
    championStats.level = level;
    championStats.adCurrent = (championStats.adBase + (championStats.adLevel * (championStats.level - 1)));
    championStats.asCurrent = (championStats.asBase + (0.01 * (championStats.asBase * (championStats.asLevel * (championStats.level - 1)))));
    championStats.hpCurrent = (championStats.hpBase + (championStats.hpLevel * (championStats.level - 1)));
    championStats.hp5Current = (championStats.hp5Base + (championStats.hp5Level * (championStats.level - 1)));
    championStats.mpCurrent = (championStats.mpBase + (championStats.mpLevel * (championStats.level - 1)));
    championStats.mp5Current = (championStats.mp5Base + (championStats.mp5Level * (championStats.level - 1)));
    championStats.arCurrent = (championStats.arBase + (championStats.arLevel * (championStats.level - 1)));
    championStats.mrCurrent = (championStats.mrBase + (championStats.mrLevel * (championStats.level - 1)));

    qDebug() << "AD:";
    qDebug() << championStats.adCurrent;
    qDebug() << "AS:";
    qDebug() << championStats.asCurrent;
    qDebug() << "HP:";
    qDebug() << championStats.hpCurrent;
    qDebug() << "HP5:";
    qDebug() << championStats.hp5Current;
    qDebug() << "MP:";
    qDebug() << championStats.mpCurrent;
    qDebug() << "MP5:";
    qDebug() << championStats.mp5Current;
    qDebug() << "Armor:";
    qDebug() << championStats.arCurrent;
    qDebug() << "MR:";
    qDebug() << championStats.mrCurrent;

    return championStats;
}
