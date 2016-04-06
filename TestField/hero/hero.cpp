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
    if (this->currentScore == this->heroScore)
        QMetaObject::invokeMethod(Root, "setActiveHero", Q_ARG(QVariant,true));
}

int Hero::getCurrentScrore()
{
    return this->currentScore;
}
