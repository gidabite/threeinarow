#include "levelcontroller.h"

LevelController::LevelController(int cscore, QWidget* window, int classHero)
{
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
            this->hero = new Warrior(1000);
            break;
        case 1:
            this->hero = new Hunter(1000);
            break;
        case 2:
            this->hero = new Mage(1000);
            break;
    default: break;
    }

    HB = new HeroButton(hero,window);
    HB->setGeometry(QRect(75,175,300,300));
    QObject::connect(HB, SIGNAL(clicked(bool)), this, SLOT(changeConditionForActivateSkill()));
    label1 = new QLabel(window);
    label1->setGeometry(QRect(0,25,450,25));
    QPalette* palette = new QPalette();
    palette->setColor(QPalette::WindowText,Qt::black);
    label1->setPalette(*palette);
    QFont font = label1->font();
    font.setPointSize(20);
    font.setFamily("Segoe Print");
    label1->setFont(font);
    label1->setAlignment(Qt::AlignCenter);
    label1->setText("Очки: " + QString::number(this->score) + "/" + QString::number(this->CompleteScore));

    labelHero = new QLabel(window);
    labelHero->setGeometry(QRect(0,50,450,25));
    labelHero->setPalette(*palette);
    labelHero->setFont(font);
    labelHero->setAlignment(Qt::AlignCenter);
    labelHero->setText("Энергия: " + QString::number(this->hero->getCurrentScrore()) + "/" + QString::number(this->hero->getHeroScore()));

}

LevelController::~LevelController()
{
    if (!this->btn1)
        delete this->btn1;
    if (!this->btn2)
        delete this->btn2;
}

void LevelController::addCell(CellButton* btn, Field* field)
{
    int i = btn->accessibleName().toInt();
    int j = i % field->getWidth();
    i /= field->getWidth();
    switch (this->condition)
    {
        case 0:
            this->i1 = i;
            this->j1 = j;
            field->getCell(i,j)->clicked();
            this->btn1 = btn;
            this->condition = 1;
            btn->setStyleSheet(btn->styleSheet() + "; " + QString("border : 5px solid black;"));
            break;
        case 1:
            if ((i == this->i1 - 1 && j == this->j1) || (i == this->i1 + 1 && j == this->j1) || (i == this->i1 && j == this->j1 - 1) || (i == this->i1 && j == this->j1 + 1))
            {
                    this->i2 = i;
                    this->j2 = j;
                    field->getCell(i,j)->clicked();
                    this->btn2 = btn;
                    this->condition = 0;
                    btn->setStyleSheet(btn->styleSheet() + "; " + QString("border : 5px solid black;"));
                    field->start(this->i1, this->j1, this->i2, this->j2);
                    break;
            }
            this->condition = 0;
            field->getCell(i1,j1)->setType(field->getCell(i1,j1)->getType());
            break;
        case 2:
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
    this->label1->setText("Очки: " + QString::number(this->score) + "/" + QString::number(this->CompleteScore));

    if (type == hero->getTypeCrystal())
    {
        hero->setCurrentScore(hero->getCurrentScrore() + score);
        if (hero->getCurrentScrore() > hero->getHeroScore())
        {
            hero->setCurrentScore(hero->getHeroScore());
        }
        labelHero->setText("Энергия: " + QString::number(this->hero->getCurrentScrore()) + "/" + QString::number(this->hero->getHeroScore()));
        emit HB->repaint();
    }

    emit this->label1->repaint();

}

void LevelController::changeConditionForActivateSkill()
{
    if (this->hero->getCurrentScrore() == this->hero->getHeroScore())
    {
        this->condition = 2;
        this->hero->setCurrentScore(0);
        labelHero->setText("Энергия: " + QString::number(this->hero->getCurrentScrore()) + "/" + QString::number(this->hero->getHeroScore()));
        emit HB->repaint();
    }
}

