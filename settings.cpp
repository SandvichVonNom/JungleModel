#include "settings.h"
#include "mainwindow.h"
#include <QSettings>
#include <QDebug>

Settings::Settings(QObject *parent) : QObject(parent)
{

}

Settings::~Settings()
{

}

void Settings::importChampions()
{

    QSettings championSettings("champion_stats.ini",
                       QSettings::IniFormat);

    static const int championCount = 2;

    QString championArray[championCount] = {"AATROX", "AMUMU"};

    for (int iii=0; iii < championCount; iii++)
    {
        qDebug() << championArray[iii];
        championSettings.beginGroup(championArray[iii]);
        qDebug() << championSettings.value("BASEAD").toInt();
        qDebug() << championSettings.value("BASEAS").toDouble();
        qDebug() << championSettings.value("Q_DMG").toInt();
        qDebug() << championSettings.value("Q_CD").toDouble();
        qDebug() << championSettings.value("Q_MANA").toInt();
        championSettings.endGroup();
    }

}

void Settings::importJungle()
{
    qDebug() << "Hello Nature";
}
