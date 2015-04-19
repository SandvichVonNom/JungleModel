#ifndef STATS_H
#define STATS_H

#include <QDialog>

namespace Ui {
class Stats;
}

class Stats : public QDialog
{
    Q_OBJECT

public:
    explicit Stats(QWidget *parent = 0);
    ~Stats();
    struct ChampionStats
    {
        QString name;
        int level;
        double adbase;
        double adlevel;
        double aditems;
        double adcurrent;

        double asbase;
        double aslevel;
        double asitems;
        double ascurrent;

        double hpbase;
        double hplevel;
        double hpcurrent;

        double hp5base;
        double hp5level;
        double hp5current;

        double mpbase;
        double mplevel;
        double mpcurrent;

        double mp5base;
        double mp5level;
        double mp5current;

        double arbase;
        double arlevel;
        double arcurrent;

        double mrbase;
        double mrlevel;
        double mrcurrent;

        int atkrange;
        int movespeed;

        double qDmg1;
        double qCd1;
        int qMana1;

        double wDmg1;
        double wCd1;
        int wMana1;

        double eDmg1;
        double eCd1;
        int eMana1;
    };

    std::vector<ChampionStats> importAllChampions();
    void testChampions();
    void updateChampionList();
    void saveChampion();
    Stats::ChampionStats importSingleChampion(QString championName);


public slots:

private slots:

    void on_listChampions_itemSelectionChanged();

    void on_buttonApply_clicked();

    void on_Stats_accepted();

private:
    Ui::Stats *ui;
};

#endif // STATS_H
