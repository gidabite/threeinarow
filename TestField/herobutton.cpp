#include "herobutton.h"

HeroButton::HeroButton(Hero* h, QWidget *parent) : QPushButton(parent)
{
    this->hero = h;
}

void HeroButton::paintEvent(QPaintEvent *pe)
{
    QPainter painter(this);
    switch (hero->getTypeCrystal())
    {
        case 0:
            if (hero->getCurrentScrore() == hero->getHeroScore())
            {
                painter.drawPixmap(0,0,this->width(),this->height(),ImageController::init()->WarriorActive);
            }
            else
                painter.drawPixmap(0,0,this->width(),this->height(),ImageController::init()->Warrior);
            break;
        case 1:
            if (hero->getCurrentScrore() == hero->getHeroScore())
            {
                painter.drawPixmap(0,0,this->width(),this->height(),ImageController::init()->HunterActive);
            }
            else
                painter.drawPixmap(0,0,this->width(),this->height(),ImageController::init()->Hunter);
            break;
        case 2:
            if (hero->getCurrentScrore() == hero->getHeroScore())
            {
                painter.drawPixmap(0,0,this->width(),this->height(),ImageController::init()->MageActive);
            }
            else
                painter.drawPixmap(0,0,this->width(),this->height(),ImageController::init()->Mage);
            break;
    }
}

