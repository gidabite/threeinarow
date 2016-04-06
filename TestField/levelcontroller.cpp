#include "levelcontroller.h"

LevelController::LevelController(int cscore, QWidget* window, int classHero, QQuickItem* Root)
{
    this->Root = Root;
    this->i1 = -1;
    this->j1 = -1;
    this->i2 = -1;
    this->j2 = -1;
    this->condition = 0;
    this->score = 0;
    this->CompleteScore = cscore;

    switch (classHero)
    {
        case 0:
            this->hero = new Warrior(1000, Root);
            break;
        case 1:
            this->hero = new Hunter(1000, Root);
            break;
        case 2:
            this->hero = new Mage(1000, Root);
            break;
    default: break;
    }

    QMetaObject::invokeMethod(Root, "setHero", Q_ARG(QVariant, hero->getTypeCrystal()));
    QMetaObject::invokeMethod(Root, "setText1", Q_ARG(QVariant, "Очки: " + QString::number(this->score) + "/" + QString::number(this->CompleteScore)));
    QMetaObject::invokeMethod(Root, "setText2", Q_ARG(QVariant, "Энергия: " + QString::number(this->hero->getCurrentScrore()) + "/" + QString::number(this->hero->getHeroScore())));
}

LevelController::~LevelController()
{

}

void LevelController::addCell(int i, int j, Field* field)
{

    switch (this->condition)
    {
        case 0:
            if (!field->getCell(i,j)->getTrap())
            {
                this->i1 = i;
                this->j1 = j;
                this->condition = 1;
            }
            break;
        case 1:
            if ((i == this->i1 - 1 && j == this->j1) || (i == this->i1 + 1 && j == this->j1) || (i == this->i1 && j == this->j1 - 1) || (i == this->i1 && j == this->j1 + 1))
            {
                if (!field->getCell(i,j)->getTrap())
                {
                    this->i2 = i;
                    this->j2 = j;
                    this->condition = 0;
                    emit go(this->i1, this->j1, this->i2, this->j2);
                }
                    break;
            }
            this->condition = 0;
            field->getCell(i1,j1)->setType(field->getCell(i1,j1)->getType());
            break;
        case 2:
            QMetaObject::invokeMethod(Root, "setActiveHero", Q_ARG(QVariant,false));
            hero->heroPower(i, j, field);
            this->condition = 0;
            break;
    }
}

int LevelController::getCondition()
{
    return this->condition;
}

void LevelController::increaseScore(int score, int type)
{
    this->score += score;
    QMetaObject::invokeMethod(Root, "setText1", Q_ARG(QVariant, "Очки: " + QString::number(this->score) + "/" + QString::number(this->CompleteScore)));

    if (type == hero->getTypeCrystal())
    {
        hero->setCurrentScore(hero->getCurrentScrore() + score);
        if (hero->getCurrentScrore() > hero->getHeroScore())
        {
            hero->setCurrentScore(hero->getHeroScore());
        }
        QMetaObject::invokeMethod(Root, "setText2", Q_ARG(QVariant, "Энергия: " + QString::number(this->hero->getCurrentScrore()) + "/" + QString::number(this->hero->getHeroScore())));
    }

}

void LevelController::changeConditionForActivateSkill()
{
    if (this->hero->getCurrentScrore() == this->hero->getHeroScore())
    {
        this->condition = 2;
        this->hero->setCurrentScore(0);
        QMetaObject::invokeMethod(Root, "setText2", Q_ARG(QVariant, "Энергия: " + QString::number(this->hero->getCurrentScrore()) + "/" + QString::number(this->hero->getHeroScore())));
    }
}

