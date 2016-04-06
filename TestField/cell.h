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
    QObject* btn;
    bool trap;
    int i;
    int j;
public:
    Cell();
    ~Cell();
    Cell(int i, int j, TypeCell t, QObject* Root);
    TypeCell getType();
    void setType(int type);
    int getI();
    int getJ();
    void clicked();

    void setTrap(bool value);
    
    bool getTrap() const;
    
signals:
    void updateType(int type);
    void clickedButton();
};

#endif // CELL_H
