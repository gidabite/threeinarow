#ifndef HUNTER_H
#define HUNTER_H
#include "hero.h"
#include "QTime"
#include <QThread>

class Hunter : public Hero
{

public:
    Hunter(int score);
    void heroPower(int i, int j, Field* field);

};

#endif // HUNTER_H
