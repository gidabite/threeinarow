#ifndef HEROBUTTON_H
#define HEROBUTTON_H
#include <QPushButton>
#include "hero/hero.h"
#include "imagecontroller.h"
#include "QPainter"
class HeroButton : public QPushButton
{
    Q_OBJECT
private:
    Hero* hero;
public:
    explicit HeroButton(Hero* h, QWidget *parent);
    void paintEvent(QPaintEvent *pe);

signals:

public slots:

};

#endif // HEROBUTTON_H
