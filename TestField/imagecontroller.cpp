#include "imagecontroller.h"

ImageController::ImageController()
{
    this->Red.load(":/image/image/crystalRed.png");
    this->RedHover.load(":/image/image/crystalRedHover.png");
    this->RedClicked.load(":/image/image/crystalRedClicked.png");
    this->Green.load(":/image/image/crystalGreen.png");
    this->GreenHover.load(":/image/image/crystalGreenHover.png");
    this->GreenClicked.load(":/image/image/crystalGreenClicked.png");
    this->Blue.load(":/image/image/crystalBlue.png");
    this->BlueHover.load(":/image/image/crystalBlueHover.png");
    this->BlueClicked.load(":/image/image/crystalBlueClicked.png");
    this->Yellow.load(":/image/image/crystalYellow.png");
    this->YellowHover.load(":/image/image/crystalYellowHover.png");
    this->YellowClicked.load(":/image/image/crystalYellowClicked.png");
    this->Hunter.load(":/image/image/heroPowerHunter.png");
    this->Mage.load(":/image/image/heroPowerMage.png");
    this->Warrior.load(":/image/image/heroPowerWarrior.png");
    this->HunterActive.load(":/image/image/powerClickedHunter.png");
    this->MageActive.load(":/image/image/powerClickedMage.png");
    this->WarriorActive.load(":/image/image/powerClickedWarrior.png");

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
