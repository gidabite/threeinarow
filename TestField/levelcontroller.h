#ifndef LEVELCONTROLLER_H
#define LEVELCONTROLLER_H
#include <QObject>

#include "field.h"
#include "cellbutton.h"
#include <QLabel>
#include "hero/hero.h"
#include "hero/hunter.h"
#include "hero/mage.h"
#include "hero/warrior.h"
#include "herobutton.h"

class LevelController: public QObject
{
    Q_OBJECT
private:
    int condition;
    int score;
    int CompleteScore;
    int i1, j1, i2, j2;
    CellButton *btn1, *btn2;
    HeroButton* HB;
    QLabel* label1;
    QLabel* labelHero;
    Hero* hero;
public:
    LevelController(int cscore, QWidget* window, int classHero);
    ~LevelController();
    void addCell(CellButton* btn, Field* field);
    int getCondition();
public slots:
    void increaseScore(int score, int type);
    void changeConditionForActivateSkill();

};

#endif // LEVELCONTROLLER_H
