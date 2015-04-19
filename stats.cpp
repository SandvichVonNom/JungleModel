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
    updateJungleList();
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
        championSettings.setValue("ADBASE", ui->championadbase->value());
        championSettings.setValue("ADLEVEL", ui->championadlevel->value());
        championSettings.setValue("ASBASE", ui->championasbase->value());
        championSettings.setValue("ASLEVEL", ui->championaslevel->value());
        championSettings.setValue("HPBASE", ui->championhpbase->value());
        championSettings.setValue("HPLEVEL", ui->championhplevel->value());
        championSettings.setValue("HP5BASE", ui->championhp5base->value());
        championSettings.setValue("HP5LEVEL", ui->championhp5level->value());
        championSettings.setValue("MPBASE", ui->championmpbase->value());
        championSettings.setValue("MPLEVEL", ui->championmplevel->value());
        championSettings.setValue("MP5BASE", ui->championmp5base->value());
        championSettings.setValue("MP5LEVEL", ui->championmp5level->value());
        championSettings.setValue("ARBASE", ui->championarbase->value());
        championSettings.setValue("ARLEVEL", ui->championarlevel->value());
        championSettings.setValue("MRBASE", ui->championmrbase->value());
        championSettings.setValue("MRLEVEL", ui->championmrlevel->value());
        championSettings.setValue("ATKRANGE", ui->championatkrange->value());
        championSettings.setValue("MOVESPEED", ui->championmovespeed->value());
        championSettings.setValue("QDMG1", ui->championqdmg1->value());
        championSettings.setValue("QCD1", ui->championqcd1->value());
        championSettings.setValue("QMANA1", ui->championqmana1->value());
        championSettings.setValue("WDMG1", ui->championwdmg1->value());
        championSettings.setValue("WCD1", ui->championwcd1->value());
        championSettings.setValue("WMANA1", ui->championwmana1->value());
        championSettings.setValue("EDMG1", ui->championedmg1->value());
        championSettings.setValue("ECD1", ui->championecd1->value());
        championSettings.setValue("EMANA1", ui->championemana1->value());
        championSettings.endGroup();
    }
    else
    {
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
        ui->championadbase->setValue(championSettings.value("ADBASE").toDouble());
        ui->championadlevel->setValue(championSettings.value("ADLEVEL").toDouble());
        ui->championasbase->setValue(championSettings.value("ASBASE").toDouble());
        ui->championaslevel->setValue(championSettings.value("ASLEVEL").toDouble());
        ui->championhpbase->setValue(championSettings.value("HPBASE").toDouble());
        ui->championhplevel->setValue(championSettings.value("HPLEVEL").toDouble());
        ui->championhp5base->setValue(championSettings.value("HP5BASE").toDouble());
        ui->championhp5level->setValue(championSettings.value("HP5LEVEL").toDouble());
        ui->championmpbase->setValue(championSettings.value("MPBASE").toDouble());
        ui->championmplevel->setValue(championSettings.value("MPLEVEL").toDouble());
        ui->championmp5base->setValue(championSettings.value("MP5BASE").toDouble());
        ui->championmp5level->setValue(championSettings.value("MP5LEVEL").toDouble());
        ui->championarbase->setValue(championSettings.value("ARBASE").toDouble());
        ui->championarlevel->setValue(championSettings.value("ARLEVEL").toDouble());
        ui->championmrbase->setValue(championSettings.value("MRBASE").toDouble());
        ui->championmrlevel->setValue(championSettings.value("MRLEVEL").toDouble());
        ui->championatkrange->setValue(championSettings.value("ATKRANGE").toDouble());
        ui->championmovespeed->setValue(championSettings.value("MOVESPEED").toDouble());
        ui->championqdmg1->setValue(championSettings.value("QDMG1").toDouble());
        ui->championqcd1->setValue(championSettings.value("QCD1").toDouble());
        ui->championqmana1->setValue(championSettings.value("QMANA1").toInt());
        ui->championwdmg1->setValue(championSettings.value("WDMG1").toDouble());
        ui->championwcd1->setValue(championSettings.value("WCD1").toDouble());
        ui->championwmana1->setValue(championSettings.value("WMANA1").toInt());
        ui->championedmg1->setValue(championSettings.value("EDMG1").toDouble());
        ui->championecd1->setValue(championSettings.value("ECD1").toDouble());
        ui->championemana1->setValue(championSettings.value("EMANA1").toInt());
        championSettings.endGroup();
    }
    else
    {
        return;
    }
}

void Stats::on_buttonapplychampions_clicked()
{
    saveChampion();
}

Stats::JungleStats Stats::importSingleJungle(QString jungleName)
{
    QSettings jungleSettings("jungle_stats.ini",
                       QSettings::IniFormat);
    Stats::JungleStats singleJungleStats;

    singleJungleStats.name = jungleName;
    jungleSettings.beginGroup(jungleName);
    singleJungleStats.adBase = jungleSettings.value("ADBASE").toDouble();
    singleJungleStats.adLevel = jungleSettings.value("ADLEVEL").toDouble();
    singleJungleStats.asBase = jungleSettings.value("ASBASE").toDouble();
    singleJungleStats.asLevel = jungleSettings.value("ASLEVEL").toDouble();
    singleJungleStats.hpBase = jungleSettings.value("HPBASE").toDouble();
    singleJungleStats.hpLevel = jungleSettings.value("HPLEVEL").toDouble();
    singleJungleStats.arBase = jungleSettings.value("ARBASE").toDouble();
    singleJungleStats.arLevel = jungleSettings.value("ARLEVEL").toDouble();
    singleJungleStats.mrBase = jungleSettings.value("MRBASE").toDouble();
    singleJungleStats.mrLevel = jungleSettings.value("MRLEVEL").toDouble();
    singleJungleStats.atkRange = jungleSettings.value("ATKRANGE").toDouble();
    singleJungleStats.moveSpeed = jungleSettings.value("MOVESPEED").toDouble();
    jungleSettings.endGroup();

    return singleJungleStats;
}

std::vector<Stats::JungleStats> Stats::importAllJungle()
{
    QSettings jungleSettings("jungle_stats.ini",
                       QSettings::IniFormat);
    std::vector<Stats::JungleStats> jungleVector;
    for (int iii=0; iii < jungleSettings.childGroups().count(); iii++)
    {
        Stats::JungleStats tempStats = importSingleJungle(jungleSettings.childGroups()[iii]);
        jungleVector.push_back(tempStats);
        qDebug() << tempStats.name;
    }
    return jungleVector;
}

void Stats::updateJungleList()
{
    QSettings jungleSettings("jungle_stats.ini",
                       QSettings::IniFormat);
    ui->listjungle->clear();
    for (int iii = 0; iii < jungleSettings.childGroups().count(); iii++)
    {
        ui->listjungle->addItem(jungleSettings.childGroups()[iii]);
    }
}

void Stats::saveJungle()
{
    QSettings jungleSettings("jungle_stats.ini",
                       QSettings::IniFormat);

    if (ui->listjungle->currentItem() != NULL)
    {
        QString currentJungle = ui->listjungle->currentItem()->text();
        jungleSettings.beginGroup(currentJungle);
        jungleSettings.setValue("ADBASE", ui->jungleadbase->value());
        jungleSettings.setValue("ADLEVEL", ui->jungleadlevel->value());
        jungleSettings.setValue("ASBASE", ui->jungleasbase->value());
        jungleSettings.setValue("ASLEVEL", ui->jungleaslevel->value());
        jungleSettings.setValue("HPBASE", ui->junglehpbase->value());
        jungleSettings.setValue("HPLEVEL", ui->junglehplevel->value());
        jungleSettings.setValue("ARBASE", ui->junglearbase->value());
        jungleSettings.setValue("ARLEVEL", ui->junglearlevel->value());
        jungleSettings.setValue("MRBASE", ui->junglemrbase->value());
        jungleSettings.setValue("MRLEVEL", ui->junglemrlevel->value());
        jungleSettings.setValue("ATKRANGE", ui->jungleatkrange->value());
        jungleSettings.setValue("MOVESPEED", ui->junglemovespeed->value());
        jungleSettings.endGroup();
    }
    else
    {
        return;
    }
}

void Stats::on_listjungle_itemSelectionChanged()
{
    QSettings jungleSettings("jungle_stats.ini",
                       QSettings::IniFormat);

    if (ui->listjungle->currentItem() != NULL)
    {
        QString currentJungle = ui->listjungle->currentItem()->text();

        jungleSettings.beginGroup(currentJungle);
        ui->jungleadbase->setValue(jungleSettings.value("ADBASE").toDouble());
        ui->jungleadlevel->setValue(jungleSettings.value("ADLEVEL").toDouble());
        ui->jungleasbase->setValue(jungleSettings.value("ASBASE").toDouble());
        ui->jungleaslevel->setValue(jungleSettings.value("ASLEVEL").toDouble());
        ui->junglehpbase->setValue(jungleSettings.value("HPBASE").toDouble());
        ui->junglehplevel->setValue(jungleSettings.value("HPLEVEL").toDouble());
        ui->junglearbase->setValue(jungleSettings.value("ARBASE").toDouble());
        ui->junglearlevel->setValue(jungleSettings.value("ARLEVEL").toDouble());
        ui->junglemrbase->setValue(jungleSettings.value("MRBASE").toDouble());
        ui->junglemrlevel->setValue(jungleSettings.value("MRLEVEL").toDouble());
        ui->jungleatkrange->setValue(jungleSettings.value("ATKRANGE").toDouble());
        ui->junglemovespeed->setValue(jungleSettings.value("MOVESPEED").toDouble());
        jungleSettings.endGroup();
    }
    else
    {
        return;
    }
}

void Stats::on_buttonapplyjungle_clicked()
{
    saveJungle();
}

void Stats::on_Stats_accepted()
{
    saveChampion();
    saveJungle();
}

