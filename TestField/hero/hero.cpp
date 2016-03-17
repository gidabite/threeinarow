#include "hero.h"

int Hero::getTypeCrystal()
{
    return typeCrystal;
}

int Hero::getHeroScore()
{
    return heroScore;
}

Hero::Hero()
{

}

void Hero::setCurrentScore(int currScore)
{
    this->currentScore = currScore;
}

int Hero::getCurrentScrore()
{
    return this->currentScore;
}
