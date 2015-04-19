#include <QSettings>
#include <QDebug>
#include <iostream>
#include <algorithm>
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
    singleChampionStats.adBase = championSettings.value("ADBASE").toDouble();
    singleChampionStats.adLevel = championSettings.value("ADLEVEL").toDouble();
    singleChampionStats.asBase = championSettings.value("ASBASE").toDouble();
    singleChampionStats.asLevel = championSettings.value("ASLEVEL").toDouble();
    singleChampionStats.hpBase = championSettings.value("HPBASE").toDouble();
    singleChampionStats.hpLevel = championSettings.value("HPLEVEL").toDouble();
    singleChampionStats.hp5Base = championSettings.value("HP5BASE").toDouble();
    singleChampionStats.hp5Level = championSettings.value("HP5LEVEL").toDouble();
    singleChampionStats.mpBase = championSettings.value("MPBASE").toDouble();
    singleChampionStats.mpLevel = championSettings.value("MPLEVEL").toDouble();
    singleChampionStats.mp5Base = championSettings.value("MP5BASE").toDouble();
    singleChampionStats.mp5Level = championSettings.value("MP5LEVEL").toDouble();
    singleChampionStats.arBase = championSettings.value("ARBASE").toDouble();
    singleChampionStats.arLevel = championSettings.value("ARLEVEL").toDouble();
    singleChampionStats.mrBase = championSettings.value("MRBASE").toDouble();
    singleChampionStats.mrLevel = championSettings.value("MRLEVEL").toDouble();
    singleChampionStats.atkRange = championSettings.value("ATKRANGE").toDouble();
    singleChampionStats.moveSpeed = championSettings.value("MOVESPEED").toDouble();
    singleChampionStats.qDmg1 = championSettings.value("QDMG1").toDouble();
    singleChampionStats.qCd1 = championSettings.value("QCD1").toDouble();
    singleChampionStats.qMana1 = championSettings.value("QMANA1").toInt();
    singleChampionStats.wDmg1 = championSettings.value("WDMG1").toDouble();
    singleChampionStats.wCd1 = championSettings.value("WCD1").toDouble();
    singleChampionStats.wMana1 = championSettings.value("WMANA1").toInt();
    singleChampionStats.eDmg1 = championSettings.value("EDMG1").toDouble();
    singleChampionStats.eCd1 = championSettings.value("ECD1").toDouble();
    singleChampionStats.eMana1 = championSettings.value("EMANA1").toInt();
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
        championSettings.setValue("ADBASE", ui->adbase->value());
        championSettings.setValue("ADLEVEL", ui->adlevel->value());
        championSettings.setValue("ASBASE", ui->asbase->value());
        championSettings.setValue("ASLEVEL", ui->aslevel->value());
        championSettings.setValue("HPBASE", ui->hpbase->value());
        championSettings.setValue("HPLEVEL", ui->hplevel->value());
        championSettings.setValue("HP5BASE", ui->hp5base->value());
        championSettings.setValue("HP5LEVEL", ui->hp5level->value());
        championSettings.setValue("MPBASE", ui->mpbase->value());
        championSettings.setValue("MPLEVEL", ui->mplevel->value());
        championSettings.setValue("MP5BASE", ui->mp5base->value());
        championSettings.setValue("MP5LEVEL", ui->mp5level->value());
        championSettings.setValue("ARBASE", ui->arbase->value());
        championSettings.setValue("ARLEVEL", ui->arlevel->value());
        championSettings.setValue("MRBASE", ui->mrbase->value());
        championSettings.setValue("MRLEVEL", ui->mrlevel->value());
        championSettings.setValue("ATKRANGE", ui->atkrange->value());
        championSettings.setValue("MOVESPEED", ui->movespeed->value());
        championSettings.setValue("QDMG1", ui->qdmg1->value());
        championSettings.setValue("QCD1", ui->qcd1->value());
        championSettings.setValue("QMANA1", ui->qmana1->value());
        championSettings.setValue("WDMG1", ui->wdmg1->value());
        championSettings.setValue("WCD1", ui->wcd1->value());
        championSettings.setValue("WMANA1", ui->wmana1->value());
        championSettings.setValue("EDMG1", ui->edmg1->value());
        championSettings.setValue("ECD1", ui->ecd1->value());
        championSettings.setValue("EMANA1", ui->emana1->value());
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
        ui->adbase->setValue(championSettings.value("ADBASE").toDouble());
        ui->adlevel->setValue(championSettings.value("ADLEVEL").toDouble());
        ui->asbase->setValue(championSettings.value("ASBASE").toDouble());
        ui->aslevel->setValue(championSettings.value("ASLEVEL").toDouble());
        ui->hpbase->setValue(championSettings.value("HPBASE").toDouble());
        ui->hplevel->setValue(championSettings.value("HPLEVEL").toDouble());
        ui->hp5base->setValue(championSettings.value("HP5BASE").toDouble());
        ui->hp5level->setValue(championSettings.value("HP5LEVEL").toDouble());
        ui->mpbase->setValue(championSettings.value("MPBASE").toDouble());
        ui->mplevel->setValue(championSettings.value("MPLEVEL").toDouble());
        ui->mp5base->setValue(championSettings.value("MP5BASE").toDouble());
        ui->mp5level->setValue(championSettings.value("MP5LEVEL").toDouble());
        ui->arbase->setValue(championSettings.value("ARBASE").toDouble());
        ui->arlevel->setValue(championSettings.value("ARLEVEL").toDouble());
        ui->mrbase->setValue(championSettings.value("MRBASE").toDouble());
        ui->mrlevel->setValue(championSettings.value("MRLEVEL").toDouble());
        ui->atkrange->setValue(championSettings.value("ATKRANGE").toDouble());
        ui->movespeed->setValue(championSettings.value("MOVESPEED").toDouble());
        ui->qdmg1->setValue(championSettings.value("QDMG1").toDouble());
        ui->qcd1->setValue(championSettings.value("QCD1").toDouble());
        ui->qmana1->setValue(championSettings.value("QMANA1").toInt());
        ui->wdmg1->setValue(championSettings.value("WDMG1").toDouble());
        ui->wcd1->setValue(championSettings.value("WCD1").toDouble());
        ui->wmana1->setValue(championSettings.value("WMANA1").toInt());
        ui->edmg1->setValue(championSettings.value("EDMG1").toDouble());
        ui->ecd1->setValue(championSettings.value("ECD1").toDouble());
        ui->emana1->setValue(championSettings.value("EMANA1").toInt());
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
}

void Stats::on_Stats_accepted()
{
    saveChampion();
}
