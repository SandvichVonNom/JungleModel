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

    Stats::ChampionStats updateLevel(Stats::ChampionStats championStats, int level);

signals:

public slots:
};

#endif // CALC_H
