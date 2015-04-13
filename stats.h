#ifndef STATS_H
#define STATS_H

#include <QObject>
#include <QString>
#include <algorithm>
#include <iostream>

class Stats : public QObject
{
    Q_OBJECT

public:
    explicit Stats(QObject *parent = 0);
    ~Stats();
    struct ChampionStats
    {
        QString name;
        int basead;
        double baseas;
        int q_dmg;
        double q_cd;
        int q_mana;
    };

    std::vector<ChampionStats> importChampions();
    void testChampions();
    int vectorSearch(std::vector<ChampionStats> vector, QString name, int length);

signals:

public slots:
};

#endif // STATS_H
