#ifndef STATS_H
#define STATS_H
#define CHAMPIONCOUNT 2

#include <QObject>
#include <QString>

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

    void importChampions();
    void testChampions();

signals:

public slots:
};

#endif // STATS_H
