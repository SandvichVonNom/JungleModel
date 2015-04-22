#ifndef CALC_H
#define CALC_H

#include <QObject>
#include "stats.h"

class Calc : public QObject
{
    Q_OBJECT
public:
    explicit Calc(QObject *parent = 0);
    ~Calc();

    Stats::ChampionStats championUpdateLevel(Stats::ChampionStats championStats, int level);
    Stats::ChampionStats initChampion(Stats::ChampionStats championStats);
    Stats::JungleStats jungleUpdateLevel(Stats::JungleStats jungleStats, int level);
    Stats::JungleStats initJungle(Stats::JungleStats jungleStats);
    Stats::ChampionStats fightJungle(Stats::ChampionStats championStats, Stats::JungleStats jungleStats);

signals:

public slots:
};

#endif // CALC_H
