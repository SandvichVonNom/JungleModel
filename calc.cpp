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
    championStats.adcurrent = (championStats.adbase + (championStats.adlevel * (championStats.level - 1)));
    championStats.ascurrent = (championStats.asbase + (championStats.aslevel * (championStats.level - 1)));
    qDebug() << championStats.adcurrent;
    qDebug() << championStats.ascurrent;

    return championStats;
}
