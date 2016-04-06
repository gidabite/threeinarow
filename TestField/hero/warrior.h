#ifndef WARRIOR_H
#define WARRIOR_H
#include "hero.h"
#include "QTime"
#include <QThread>

class Warrior : public Hero
{
    Q_OBJECT
public:
    Warrior(int score, QQuickItem *Root);
    void heroPower(int i, int j, Field* field);
signals:
    void destroy(QVector<Cell*> deleteList);
};

#endif // WARRIOR_H
