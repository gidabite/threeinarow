#include "cellbutton.h"
#include <QPainter>
#include <QPixmap>

CellButton::CellButton(QWidget *parent) : QPushButton(parent)
{
    this->type = 0;
    this->isHover = 0;
    this->isClicked = 0;
}

void CellButton::paintEvent(QPaintEvent *pe)
{
    QPainter painter(this);
    switch (this->type)
    {
        case 0:
            if (!isHover)
            {
                painter.drawPixmap(0,0,this->width(),this->height(),ImageController::init()->Red);
            } else painter.drawPixmap(0,0,this->width(),this->height(),ImageController::init()->RedHover);
            break;
        case 1:
            if (!isHover)
            {
                painter.drawPixmap(0,0,this->width(),this->height(),ImageController::init()->Green);
            } else painter.drawPixmap(0,0,this->width(),this->height(),ImageController::init()->GreenHover);
            break;
        case 2:
            if (!isHover)
            {
                painter.drawPixmap(0,0,this->width(),this->height(),ImageController::init()->Blue);
            } else painter.drawPixmap(0,0,this->width(),this->height(),ImageController::init()->BlueHover);
            break;
        case 3:
            if (!isHover)
            {
                painter.drawPixmap(0,0,this->width(),this->height(),ImageController::init()->Yellow);
            } else painter.drawPixmap(0,0,this->width(),this->height(),ImageController::init()->YellowHover);
            break;
    }
}

void CellButton::enterEvent(QEvent *event)
{
    this->isHover = true;
    emit repaint();
}

void CellButton::leaveEvent(QEvent *event)
{
    this->isHover = false;
    emit repaint();
}

void CellButton::UpdateType(int type)
{
    this->type = type;

    emit repaint();
}
