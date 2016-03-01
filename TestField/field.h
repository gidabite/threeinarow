#ifndef FIELD_H
#define FIELD_H
#include "QTime"
#include "cell.h"
#include <QVector>

class Field
{
private:
    QVector<Cell*>* cells;
    int height;
    int width;
public:
    Field();
    Field(int h, int w, QVector<CellButton*>* buttons);
    Cell* getCell(int h, int w);
    int getHeight();
    int getWidth();

    bool isCellExist(int h, int w);

    bool isComboLeft(int h, int w, int r);
    bool isComboTop(int h, int w, int r);
    bool isComboBottom(int h, int w, int r);
    bool isComboRight(int h, int w, int r);

    bool isEqualsCellType(int h, int w, int r);

    bool isLeft(int i, int j, int r);
    bool isRight(int i, int j, int r);
    bool isTop(int i, int j, int r);
    bool isBottom(int i, int j, int r);

    QVector<Cell*>* addCellBottom(int i, int j, int r);
    QVector<Cell*>* addCellTop(int i, int j, int r);
    QVector<Cell*>* addCellLeft(int i, int j, int r);
    QVector<Cell*>* addCellRight(int i, int j, int r);

    void start(int i1, int j1, int i2, int j2);
    void destroy(QVector<Cell*>* cells);
};

#endif // FIELD_H
