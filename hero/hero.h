#ifndef HERO_H
#define HERO_H

#include <QObject>
#include "field.h"
class Hero : public QObject
{
    Q_OBJECT
protected:
    int heroScore;
    QString name;
    int currentScore;
    int typeCrystal;

public:
    explicit Hero();
    virtual void heroPower(int i, int j, Field* field){}
    void setCurrentScore(int currScore);
    int getCurrentScrore();
    int getTypeCrystal();
    int getHeroScore();
signals:

public slots:
};

#endif // HERO_H
