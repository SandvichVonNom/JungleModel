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
    updateChampionList();
}

Stats::~Stats()
{
    delete ui;
}

Stats::ChampionStats Stats::importSingleChampion(QString championName)
{
    QSettings championSettings("champion_stats.ini",
                       QSettings::IniFormat);
    Stats::ChampionStats singleChampionStats;

    singleChampionStats.name = championName;
    championSettings.beginGroup(championName);
    singleChampionStats.adbase = championSettings.value("BASEAD").toInt();
    singleChampionStats.asbase = championSettings.value("BASEAS").toDouble();
    singleChampionStats.q_dmg = championSettings.value("Q_DMG").toInt();
    singleChampionStats.q_cd = championSettings.value("Q_CD").toDouble();
    singleChampionStats.q_mana = championSettings.value("Q_MANA").toInt();
    championSettings.endGroup();

    return singleChampionStats;
}

std::vector<Stats::ChampionStats> Stats::importAllChampions()
{
    QSettings championSettings("champion_stats.ini",
                       QSettings::IniFormat);
    std::vector<Stats::ChampionStats> championVector;
    for (int iii=0; iii < championSettings.childGroups().count(); iii++)
    {
        Stats::ChampionStats tempStats = importSingleChampion(championSettings.childGroups()[iii]);
        championVector.push_back(tempStats);
        qDebug() << tempStats.name;
    }
    return championVector;
}

void Stats::updateChampionList()
{
    QSettings championSettings("champion_stats.ini",
                       QSettings::IniFormat);
    ui->listChampions->clear();
    for (int iii = 0; iii < championSettings.childGroups().count(); iii++)
    {
        ui->listChampions->addItem(championSettings.childGroups()[iii]);
    }
}

void Stats::saveChampion()
{
    QSettings championSettings("champion_stats.ini",
                       QSettings::IniFormat);

    if (ui->listChampions->currentItem() != NULL)
    {
        QString currentChampion = ui->listChampions->currentItem()->text();
        championSettings.beginGroup(currentChampion);
        championSettings.setValue("BASEAD", ui->ADBase->value());
        championSettings.setValue("BASEAS", ui->baseAS->value());
        championSettings.setValue("Q_DMG", ui->QDmg->value());
        championSettings.setValue("Q_CD", ui->QCD->value());
        championSettings.setValue("Q_MANA", ui->QMana->value());
        championSettings.endGroup();
    }
    else
    {
        qDebug() << "You need to select a champion.";
        return;
    }
}

void Stats::on_listChampions_itemSelectionChanged()
{
    QSettings championSettings("champion_stats.ini",
                       QSettings::IniFormat);

    if (ui->listChampions->currentItem() != NULL)
    {
        QString currentChampion = ui->listChampions->currentItem()->text();

        championSettings.beginGroup(currentChampion);
        ui->ADBase->setValue(championSettings.value("BASEAD").toInt());
        ui->baseAS->setValue(championSettings.value("BASEAS").toDouble());
        ui->QDmg->setValue(championSettings.value("Q_DMG").toInt());
        ui->QCD->setValue(championSettings.value("Q_CD").toDouble());
        ui->QMana->setValue(championSettings.value("Q_MANA").toInt());
        championSettings.endGroup();
    }
    else
    {
        qDebug() << "You need to select a champion.";
        return;
    }
}

void Stats::on_buttonApply_clicked()
{
    saveChampion();
    Stats::ChampionStats amumu = importSingleChampion("AMUMU");
    amumu.adbase = 55;
    amumu.level = 5;
    qDebug() << amumu.level;
    amumu.adlevel = 2;
    qDebug() << amumu.adlevel;
    qDebug() << amumu.adcurrent;
}

void Stats::on_Stats_accepted()
{
    saveChampion();
}
