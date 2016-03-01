#ifndef LEVELCONTROLLER_H
#define LEVELCONTROLLER_H

#include "field.h"
#include "cellbutton.h"

class LevelController
{
private:
    int condition;
    int score;
    int CompleteScore;
    int i1, j1, i2, j2;
    CellButton *btn1, *btn2;
public:
    LevelController(int cscore);
    ~LevelController();
    void addCell(CellButton* btn, Field* field);
    int getCondition();

};

#endif // LEVELCONTROLLER_H
