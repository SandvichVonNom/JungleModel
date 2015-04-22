#include <QDebug>
#include "calc.h"
#include "stats.h"

Calc::Calc(QObject *parent) : QObject(parent)
{

}

Calc::~Calc()
{

}

Stats::ChampionStats Calc::championUpdateLevel(Stats::ChampionStats championStats, int level)
{
    championStats.level = level;

    championStats.adTotal = (championStats.adBase + (championStats.adLevel * (championStats.level - 1)));
    championStats.adCurrent = championStats.adTotal;

    championStats.asTotal = (championStats.asBase + (0.01 * (championStats.asBase * (championStats.asLevel * (championStats.level - 1)))));
    championStats.asCurrent = championStats.asTotal;

    championStats.hpTotal = (championStats.hpBase + (championStats.hpLevel * (championStats.level - 1)));
    if (championStats.level == 1)
    {
        championStats.hpCurrent = championStats.hpTotal;
    }
    else
    {
        championStats.hpCurrent = (championStats.hpCurrent + championStats.hpLevel);
    }

    championStats.hp5Total = (championStats.hp5Base + (championStats.hp5Level * (championStats.level - 1)));
    championStats.hp5Current = championStats.hp5Total;

    championStats.mpTotal = (championStats.mpBase + (championStats.mpLevel * (championStats.level - 1)));
    if (championStats.level == 1)
    {
        championStats.mpCurrent = championStats.mpTotal;
    }
    else
    {
        championStats.mpCurrent = (championStats.mpCurrent + championStats.mpLevel);
    }

    championStats.mp5Total = (championStats.mp5Base + (championStats.mp5Level * (championStats.level - 1)));
    championStats.mp5Current = championStats.mp5Total;

    championStats.arTotal = (championStats.arBase + (championStats.arLevel * (championStats.level - 1)));
    championStats.arCurrent = championStats.arTotal;

    championStats.mrTotal = (championStats.mrBase + (championStats.mrLevel * (championStats.level - 1)));
    championStats.mrCurrent = championStats.mrTotal;

    return championStats;
}

Stats::ChampionStats Calc::initChampion(Stats::ChampionStats championStats)
{
    championStats = championUpdateLevel(championStats, 1);
    return championStats;
}

Stats::JungleStats Calc::jungleUpdateLevel(Stats::JungleStats jungleStats, int level)
{
    jungleStats.level = level;

    jungleStats.adTotal = (jungleStats.adBase + (jungleStats.adLevel * (jungleStats.level - 1)));
    jungleStats.adCurrent = jungleStats.adTotal;

    jungleStats.asTotal = (jungleStats.asBase + (0.01 * (jungleStats.asBase * (jungleStats.asLevel * (jungleStats.level - 1)))));
    jungleStats.asCurrent = jungleStats.asTotal;

    jungleStats.hpTotal = (jungleStats.hpBase + (jungleStats.hpLevel * (jungleStats.level - 1)));
    jungleStats.hpCurrent = jungleStats.hpTotal;

    jungleStats.arTotal = (jungleStats.arBase + (jungleStats.arLevel * (jungleStats.level - 1)));
    jungleStats.arCurrent = jungleStats.arTotal;

    jungleStats.mrTotal = (jungleStats.mrBase + (jungleStats.mrLevel * (jungleStats.level - 1)));
    jungleStats.mrCurrent = jungleStats.mrTotal;

    return jungleStats;
}

Stats::JungleStats Calc::initJungle(Stats::JungleStats jungleStats)
{
    jungleStats = jungleUpdateLevel(jungleStats, 1);
    return jungleStats;
}

Stats::ChampionStats Calc::fightJungle(Stats::ChampionStats championStats, Stats::JungleStats jungleStats)
{
    championStats = initChampion(championStats);
    jungleStats = initJungle(jungleStats);
//    jungleStats = jungleUpdateLevel(jungleStats, 1);

    double time = 0.00;
    double timeAs = championStats.asCurrent;

    qDebug() << championStats.adCurrent;

    while ((championStats.hpCurrent > 0) && (jungleStats.hpCurrent > 0))
    {
        while (timeAs > time)
        {
            time = time + 0.05;
        }
        qDebug() << timeAs;
        qDebug() << jungleStats.hpCurrent;
        jungleStats.hpCurrent = (jungleStats.hpCurrent - championStats.adCurrent);
        timeAs = timeAs + championStats.asCurrent;
    }

    qDebug() << time;

    return championStats;
}
