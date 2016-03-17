#ifndef MAGE_H
#define MAGE_H
#include "hero.h"
#include "QTime"
#include <QThread>

class Mage : public Hero
{
public:
    Mage(int score);
    void heroPower(int i, int j, Field* field);
};

#endif // MAGE_H
