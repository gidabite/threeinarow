#ifndef CELL_H
#define CELL_H
#include <QObject>
#include "cellbutton.h"

enum TypeCell {RED, GREEN, BLUE, YELLOW};

class Cell: public QObject
{
    Q_OBJECT
private:
    TypeCell type;
    CellButton* btn;
    int i;
    int j;
public:
    Cell();
    Cell(int i, int j, TypeCell t, CellButton* btn);
    ~Cell();
    TypeCell getType();
    void setType(int type);
    int getI();
    int getJ();

signals:
    void updateType(int type);
};

#endif // CELL_H
