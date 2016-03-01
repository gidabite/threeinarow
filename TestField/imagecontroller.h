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
    QPixmap Green;
    QPixmap GreenHover;
    QPixmap Blue;
    QPixmap BlueHover;
    QPixmap Yellow;
    QPixmap YellowHover;

    QPixmap back1;
    QPixmap back2;

};

#endif // IMAGECONTROLLER_H
