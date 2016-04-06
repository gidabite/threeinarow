#include "cell.h"
#include "QTime"
#include <QObject>


#include <QGraphicsObject>
#include <QtGui>

void Cell::setTrap(bool value)
{
    trap = value;
    QMetaObject::invokeMethod(btn, "setTrap", Q_ARG(QVariant, trap));
}

bool Cell::getTrap() const
{
    return trap;
}

Cell::Cell()
{


}

Cell::Cell(int i, int j, TypeCell t, QObject* Root)
{
    this->trap = false;
    this->i = i;
    this->j = j;
    btn = Root->findChild<QObject*>("cell_" + QString::number(i) + "_" +  QString::number(j));

   // QObject::connect(this, SIGNAL(clickedButton()), btn, SLOT(clickedButton()));
    int type = (int)t;
    QMetaObject::invokeMethod(btn, "updateType", Q_ARG(QVariant, type));

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
    delete btn;
}

TypeCell Cell::getType()
{
    return this->type;
}

void Cell::setType(int type)
{
    if (this->trap)
    {
        this->setTrap(false);
    }
    else{
        this->type = (TypeCell)type;
        QMetaObject::invokeMethod(btn, "updateType", Q_ARG(QVariant, type));
    }
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
    QMetaObject::invokeMethod(btn, "clickedButton");
}

