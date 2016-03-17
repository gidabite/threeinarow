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
            if (isHover)
            {
                painter.drawPixmap(0,0,this->width(),this->height(),ImageController::init()->RedHover);
            } else if (isClicked)
            {
                painter.drawPixmap(0,0,this->width(),this->height(),ImageController::init()->RedClicked);
            } else painter.drawPixmap(0,0,this->width(),this->height(),ImageController::init()->Red);
            break;
        case 1:
            if (isHover)
            {
                painter.drawPixmap(0,0,this->width(),this->height(),ImageController::init()->GreenHover);
            } else if (isClicked)
            {
                painter.drawPixmap(0,0,this->width(),this->height(),ImageController::init()->GreenClicked);
            } else painter.drawPixmap(0,0,this->width(),this->height(),ImageController::init()->Green);
            break;
        case 2:
            if (isHover)
            {
                painter.drawPixmap(0,0,this->width(),this->height(),ImageController::init()->BlueHover);
            } else if (isClicked)
            {
                painter.drawPixmap(0,0,this->width(),this->height(),ImageController::init()->BlueClicked);
            } else painter.drawPixmap(0,0,this->width(),this->height(),ImageController::init()->Blue);
            break;
        case 3:
            if (isHover)
            {
                painter.drawPixmap(0,0,this->width(),this->height(),ImageController::init()->YellowHover);
            } else if (isClicked)
            {
                painter.drawPixmap(0,0,this->width(),this->height(),ImageController::init()->YellowClicked);
            } else painter.drawPixmap(0,0,this->width(),this->height(),ImageController::init()->Yellow);
            break;
    }
}

void CellButton::enterEvent(QEvent *event)
{
    this->isHover = true;
    if (this->isClicked) this->isHover = false;
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
    this->isHover = false;
    this->isClicked = false;
    emit repaint();
}

void CellButton::clickedButton()
{
    this->isClicked = true;
    this->isHover = false;
    emit repaint();
}
