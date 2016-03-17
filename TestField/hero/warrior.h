#ifndef WARRIOR_H
#define WARRIOR_H
#include "hero.h"
#include "QTime"
#include <QThread>

class Warrior : public Hero
{
public:
    Warrior(int score);
    void heroPower(int i, int j, Field* field);
};

#endif // WARRIOR_H
