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
        double adBase;
        double adLevel;
        double adItems;
        double adCurrent;

        double asBase;
        double asLevel;
        double asItems;
        double asCurrent;

        double hpBase;
        double hpLevel;
        double hpCurrent;

        double hp5Base;
        double hp5Level;
        double hp5Current;

        double mpBase;
        double mpLevel;
        double mpCurrent;

        double mp5Base;
        double mp5Level;
        double mp5Current;

        double arBase;
        double arLevel;
        double arCurrent;

        double mrBase;
        double mrLevel;
        double mrCurrent;

        int atkRange;
        int moveSpeed;

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
