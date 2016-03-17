#ifndef IMAGECONTROLLER_H
#define IMAGECONTROLLER_H

#include <QPixmap>

class ImageController
{
private:
    static ImageController *ic;
    ImageController();
public:
    static ImageController *init();
    QPixmap Red;
    QPixmap RedHover;
    QPixmap RedClicked;
    QPixmap Green;
    QPixmap GreenHover;
    QPixmap GreenClicked;
    QPixmap Blue;
    QPixmap BlueHover;
    QPixmap BlueClicked;
    QPixmap Yellow;
    QPixmap YellowHover;
    QPixmap YellowClicked;
    QPixmap Hunter;
    QPixmap Mage;
    QPixmap Warrior;
    QPixmap HunterActive;
    QPixmap MageActive;
    QPixmap WarriorActive;

    QPixmap back1;
    QPixmap back2;

};

#endif // IMAGECONTROLLER_H
