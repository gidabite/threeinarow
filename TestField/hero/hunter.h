#ifndef HUNTER_H
#define HUNTER_H
#include "hero.h"
#include "QTime"
#include <QThread>
#include "QVector"

class Hunter : public Hero
{
    Q_OBJECT
public:
    Hunter(int score, QQuickItem *Root);
    void heroPower(int i, int j, Field* field);
signals:
    void destroy(QVector<Cell*> deleteList);
};

#endif // HUNTER_H
