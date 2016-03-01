#include "imagecontroller.h"

ImageController::ImageController()
{
    this->Red.load(":/image/image/crystalRed.png");
    this->RedHover.load(":/image/image/crystalRedHover.png");
    this->Green.load(":/image/image/crystalGreen.png");
    this->GreenHover.load(":/image/image/crystalGreenHover.png");
    this->Blue.load(":/image/image/crystalBlue.png");
    this->BlueHover.load(":/image/image/crystalBlueHover.png");
    this->Yellow.load(":/image/image/crystalYellow.png");
    this->YellowHover.load(":/image/image/crystalYellowHover.png");

    this->back1.load(":/image/image/background1.jpg");
    this->back2.load(":/image/image/background2.jpg");
}

ImageController *ImageController::init()
{
    if (ic == NULL)
    {
        ic = new ImageController();
    }
    return ic;
}

ImageController* ImageController::ic = NULL;
