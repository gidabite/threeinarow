#include "levelcontroller.h"

LevelController::LevelController(int cscore)
{
    this->i1 = -1;
    this->j1 = -1;
    this->i2 = -1;
    this->j2 = -1;
    this->condition = 0;
    this->score = 0;
    this->score = cscore;
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
            this->btn1 = btn;
            this->condition = 1;
            btn->setStyleSheet(btn->styleSheet() + "; " + QString("border : 5px solid black;"));
            break;
        case 1:
            if ((i == this->i1 - 1 && j == this->j1) || (i == this->i1 + 1 && j == this->j1) || (i == this->i1 && j == this->j1 - 1) || (i == this->i1 && j == this->j1 + 1))
            {
                    this->i2 = i;
                    this->j2 = j;
                    this->btn2 = btn;
                    this->condition = 0;
                    btn->setStyleSheet(btn->styleSheet() + "; " + QString("border : 5px solid black;"));
                    field->start(this->i1, this->j1, this->i2, this->j2);
            }
            break;
    }
}

int LevelController::getCondition()
{
    return this->condition;
}

