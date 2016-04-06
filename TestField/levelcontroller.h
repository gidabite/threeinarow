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
#include "QQuickItem"

class LevelController: public QObject
{
    Q_OBJECT
private:
    int condition;
    int score;
    int CompleteScore;
    int i1, j1, i2, j2;

    QQuickItem* Root;
public:
    Hero* hero;
    LevelController(int cscore, QWidget* window, int classHero, QQuickItem* Root);
    ~LevelController();
    void addCell(int i, int j, Field* field);
    int getCondition();
    void changeConditionForActivateSkill();
public slots:
    void increaseScore(int score, int type);

signals:
    void go(int i1, int j1, int i2, int j2);

};

#endif // LEVELCONTROLLER_H
