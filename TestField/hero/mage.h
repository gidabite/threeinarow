#ifndef MAGE_H
#define MAGE_H
#include "hero.h"
#include "QTime"
#include <QThread>

class Mage : public Hero
{
    Q_OBJECT
public:
    Mage(int score, QQuickItem *Root);
    void heroPower(int i, int j, Field* field);
signals:
    void destroy(QVector<Cell*> deleteList);
};

#endif // MAGE_H
