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
    singleChampionStats.adbase = championSettings.value("ADBASE").toDouble();
    singleChampionStats.adlevel = championSettings.value("ADLEVEL").toDouble();
    singleChampionStats.asbase = championSettings.value("ASBASE").toDouble();
    singleChampionStats.aslevel = championSettings.value("ASLEVEL").toDouble();
    singleChampionStats.hpbase = championSettings.value("HPBASE").toDouble();
    singleChampionStats.hplevel = championSettings.value("HPLEVEL").toDouble();
    singleChampionStats.hp5base = championSettings.value("HP5BASE").toDouble();
    singleChampionStats.hp5level = championSettings.value("HP5LEVEL").toDouble();
    singleChampionStats.mpbase = championSettings.value("MPBASE").toDouble();
    singleChampionStats.mplevel = championSettings.value("MPLEVEL").toDouble();
    singleChampionStats.mp5base = championSettings.value("MP5BASE").toDouble();
    singleChampionStats.mp5level = championSettings.value("MP5LEVEL").toDouble();
    singleChampionStats.arbase = championSettings.value("ARBASE").toDouble();
    singleChampionStats.arlevel = championSettings.value("ARLEVEL").toDouble();
    singleChampionStats.mrbase = championSettings.value("MRBASE").toDouble();
    singleChampionStats.mrlevel = championSettings.value("MRLEVEL").toDouble();
    singleChampionStats.atkrange = championSettings.value("ATKRANGE").toDouble();
    singleChampionStats.movespeed = championSettings.value("MOVESPEED").toDouble();
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
        championSettings.setValue("ADBASE", ui->adBase->value());
        championSettings.setValue("ADLEVEL", ui->adLevel->value());
        championSettings.setValue("ASBASE", ui->asBase->value());
        championSettings.setValue("ASLEVEL", ui->asLevel->value());
        championSettings.setValue("HPBASE", ui->hpBase->value());
        championSettings.setValue("HPLEVEL", ui->hpLevel->value());
        championSettings.setValue("HP5BASE", ui->hp5Base->value());
        championSettings.setValue("HP5LEVEL", ui->hp5Level->value());
        championSettings.setValue("MPBASE", ui->mpBase->value());
        championSettings.setValue("MPLEVEL", ui->mpLevel->value());
        championSettings.setValue("MP5BASE", ui->mp5Base->value());
        championSettings.setValue("MP5LEVEL", ui->mp5Level->value());
        championSettings.setValue("ARBASE", ui->arBase->value());
        championSettings.setValue("ARLEVEL", ui->arLevel->value());
        championSettings.setValue("MRBASE", ui->mrBase->value());
        championSettings.setValue("MRLEVEL", ui->mrLevel->value());
        championSettings.setValue("ATKRANGE", ui->atkrange->value());
        championSettings.setValue("MOVESPEED", ui->movespeed->value());
        championSettings.setValue("QDMG1", ui->qDmg1->value());
        championSettings.setValue("QCD1", ui->qCd1->value());
        championSettings.setValue("QMANA1", ui->qMana1->value());
        championSettings.setValue("WDMG1", ui->wDmg1->value());
        championSettings.setValue("WCD1", ui->wCd1->value());
        championSettings.setValue("WMANA1", ui->wMana1->value());
        championSettings.setValue("EDMG1", ui->eDmg1->value());
        championSettings.setValue("ECD1", ui->eCd1->value());
        championSettings.setValue("EMANA1", ui->eMana1->value());
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
        ui->adBase->setValue(championSettings.value("ADBASE").toDouble());
        ui->adLevel->setValue(championSettings.value("ADLEVEL").toDouble());
        ui->asBase->setValue(championSettings.value("ASBASE").toDouble());
        ui->asLevel->setValue(championSettings.value("ASLEVEL").toDouble());
        ui->hpBase->setValue(championSettings.value("HPBASE").toDouble());
        ui->hpLevel->setValue(championSettings.value("HPLEVEL").toDouble());
        ui->hp5Base->setValue(championSettings.value("HP5BASE").toDouble());
        ui->hp5Level->setValue(championSettings.value("HP5LEVEL").toDouble());
        ui->mpBase->setValue(championSettings.value("MPBASE").toDouble());
        ui->mpLevel->setValue(championSettings.value("MPLEVEL").toDouble());
        ui->mp5Base->setValue(championSettings.value("MP5BASE").toDouble());
        ui->mp5Level->setValue(championSettings.value("MP5LEVEL").toDouble());
        ui->arBase->setValue(championSettings.value("ARBASE").toDouble());
        ui->arLevel->setValue(championSettings.value("ARLEVEL").toDouble());
        ui->mrBase->setValue(championSettings.value("MRBASE").toDouble());
        ui->mrLevel->setValue(championSettings.value("MRLEVEL").toDouble());
        ui->atkrange->setValue(championSettings.value("ATKRANGE").toDouble());
        ui->movespeed->setValue(championSettings.value("MOVESPEED").toDouble());
        ui->qDmg1->setValue(championSettings.value("QDMG1").toDouble());
        ui->qCd1->setValue(championSettings.value("QCD1").toDouble());
        ui->qMana1->setValue(championSettings.value("QMANA1").toInt());
        ui->wDmg1->setValue(championSettings.value("WDMG1").toDouble());
        ui->wCd1->setValue(championSettings.value("WCD1").toDouble());
        ui->wMana1->setValue(championSettings.value("WMANA1").toInt());
        ui->eDmg1->setValue(championSettings.value("EDMG1").toDouble());
        ui->eCd1->setValue(championSettings.value("ECD1").toDouble());
        ui->eMana1->setValue(championSettings.value("EMANA1").toInt());
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
