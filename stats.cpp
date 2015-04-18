#include <QSettings>
#include <QDebug>
#include <iostream>
#include <algorithm>
#include "mainwindow.h"
#include "stats.h"
#include "ui_stats.h"

Stats::Stats(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Stats)
{
    ui->setupUi(this);
//    std::vector<Stats::ChampionStats> allChampionStats = importChampions();
    updateChampionList();
}

Stats::~Stats()
{
    delete ui;
}

std::vector<Stats::ChampionStats> Stats::importChampions()
{

    QSettings championSettings("champion_stats.ini",
                       QSettings::IniFormat);

    std::vector<Stats::ChampionStats> championVector;

    for (int iii=0; iii < championSettings.childGroups().count(); iii++)
    {
        Stats::ChampionStats tempStats;

        tempStats.name = championSettings.childGroups()[iii];
        championSettings.beginGroup(tempStats.name);
        tempStats.basead = championSettings.value("BASEAD").toInt();
        tempStats.baseas = championSettings.value("BASEAS").toDouble();
        tempStats.q_dmg = championSettings.value("Q_DMG").toInt();
        tempStats.q_cd = championSettings.value("Q_CD").toDouble();
        tempStats.q_mana = championSettings.value("Q_MANA").toInt();
        championSettings.endGroup();
        championVector.push_back(tempStats);

//        qDebug() << championVector.at(iii).name;

    }

    return championVector;

}

void Stats::on_buttonUpdateChampions_clicked()
{
    updateChampionList();
}

void Stats::updateChampionList()
{
    std::vector<Stats::ChampionStats> allChampionStats = importChampions();
    ui->listChampions->clear();
    int championCount = allChampionStats.size();
    for (int iii = 0; iii < championCount; iii++)
    {
        ui->listChampions->addItem(allChampionStats.at(iii).name);
    }
}

void Stats::on_listChampions_itemSelectionChanged()
{
    std::vector<Stats::ChampionStats> allChampionStats = importChampions();
    QString currentChampion = ui->listChampions->currentItem()->text();

    int championIndex = -1;
    int championCount = allChampionStats.size();
    while (championIndex == -1)
    {
        for (int iii = 0; iii < championCount; iii++)
        {
            if (allChampionStats.at(iii).name == currentChampion)
            {
//                qDebug() << "Index is:";
//                qDebug() << iii;
                championIndex = iii;
            }
        }
    }


    ui->baseAD->setValue(allChampionStats.at(championIndex).basead);
    ui->baseAS->setValue(allChampionStats.at(championIndex).baseas);
    ui->QDmg->setValue(allChampionStats.at(championIndex).q_dmg);
    ui->QCD->setValue(allChampionStats.at(championIndex).q_cd);
    ui->QMana->setValue(allChampionStats.at(championIndex).q_mana);

    qDebug() << "Champion:";
    qDebug() << currentChampion;
    qDebug() << "Index:";
    qDebug() << championIndex;
}

void Stats::on_buttonApply_clicked()
{
    QSettings championSettings("champion_stats.ini",
                       QSettings::IniFormat);
    QString currentChampion = ui->listChampions->currentItem()->text();
    championSettings.beginGroup(currentChampion);
    championSettings.setValue("BASEAD", ui->baseAD->value());
    championSettings.setValue("BASEAS", ui->baseAS->value());
    championSettings.setValue("Q_DMG", ui->QDmg->value());
    championSettings.setValue("Q_CD", ui->QCD->value());
    championSettings.setValue("Q_MANA", ui->QMana->value());
    championSettings.endGroup();
}
