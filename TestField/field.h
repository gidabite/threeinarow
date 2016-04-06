#ifndef FIELD_H
#define FIELD_H
#include "QTime"
#include "cell.h"
#include <QVector>
#include <QThread>

class Field: public QThread
{
    Q_OBJECT
private:
    QVector<Cell*>* cells;
    int height;
    int width;
protected:
      virtual void run();
public:
    Field();
    ~Field();
    Field(int h, int w, QObject* Root);
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
    void exitMe();


public slots:
     void go(int i1, int j1, int i2, int j2);
     void destroy(QVector<Cell*> cells);
signals:
    void increaseScore(int score, int type);
    void clickedCell(int i, int j);
    void decSize(int i, int j);
    void normalSize(int i, int j);
    void swap(int i1, int j1, int i2, int j2);
};

#endif // FIELD_H
