#include "cell.h"
#include "QTime"
#include <QObject>
Cell::Cell()
{


}

Cell::Cell(int i, int j, TypeCell t, CellButton* btn)
{
    this->i = i;
    this->j = j;
    QObject::connect(this, SIGNAL(updateType(int)), btn, SLOT(UpdateType(int)));
    QObject::connect(this, SIGNAL(clickedButton()), btn, SLOT(clickedButton()));
    emit updateType(t);
    switch(t)
    {
        case 0:
            this->type = RED;
            break;
        case 1:
            this->type = GREEN;
            break;
        case 2:
            this->type = BLUE;
            break;
        case 3:
            this->type = YELLOW;
            break;
    }
}

Cell::~Cell()
{
    this->btn = NULL;
}

TypeCell Cell::getType()
{
    return this->type;
}

void Cell::setType(int type)
{
    this->type = (TypeCell)type;
    emit updateType(type);
}

int Cell::getI()
{
    return this->i;
}

int Cell::getJ()
{
    return this->j;
}

void Cell::clicked()
{
    emit this->clickedButton();
}

