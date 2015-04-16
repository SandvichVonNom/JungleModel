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
        int basead;
        double baseas;
        int q_dmg;
        double q_cd;
        int q_mana;
    };

    std::vector<ChampionStats> importChampions();
    void testChampions();
    int vectorSearch(std::vector<ChampionStats> vector, QString name, int length);


public slots:
    void on_buttonUpdateChampions_clicked();

private slots:
//    void on_Stats_show();

private:
    Ui::Stats *ui;
};

#endif // STATS_H
