#ifndef SETTINGS_H
#define SETTINGS_H

#include <QObject>

class Settings : public QObject
{
    Q_OBJECT
public:
    explicit Settings(QObject *parent = 0);
    ~Settings();
    void importChampions();
    void importJungle();


signals:

public slots:
};

#endif // SETTINGS_H
