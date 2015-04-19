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
    qDebug() << championStats.adCurrent;
    qDebug() << championStats.asCurrent;

    return championStats;
}
