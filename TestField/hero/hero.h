#ifndef HERO_H
#define HERO_H

#include <QObject>
#include "field.h"
#include "QQuickItem"

class Hero : public QObject
{
    Q_OBJECT
protected:
    int heroScore;
    QString name;
    int currentScore;
    int typeCrystal;
    QQuickItem *Root;

public:
    explicit Hero();
    virtual void heroPower(int i, int j, Field* field){}
    void setCurrentScore(int currScore);
    int getCurrentScrore();
    int getTypeCrystal();
    int getHeroScore();
signals:
    void destroy(QVector<Cell*> deleteList);
public slots:
};

#endif // HERO_H
