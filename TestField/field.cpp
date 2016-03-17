#include "field.h"
#include <QDebug>
#include <QThread>

Field::Field()
{

}

Field::Field(int h, int w, QVector<CellButton*>* buttons)
{
    this->height = h;
    this->width = w;
    int r, k = 1;
    bool isChoose = true;
    this->cells = new QVector<Cell*>(0);
    for(int i = 0; i < h; i++)
    {
        for(int j = 0; j < w; j++)
        {
            k = 0;

            do {
                isChoose = true;
                k++;
                r = qrand() % 4;
                isChoose &=!isComboLeft(i,j,r);
                isChoose &=!isComboTop(i,j,r);
            } while (!isChoose);
            this->cells->append(new Cell(i, j, (TypeCell)r, buttons->at(i*w+j)));
        }
    }
}

Cell* Field::getCell(int h, int w)
{
    return this->cells->at(h * this->width + w);
}

int Field::getHeight()
{
    return this->height;
}

int Field::getWidth()
{
    return this->width;
}

bool Field::isCellExist(int h, int w)
{
    return (h >= 0 && h < this->height && w >= 0 && w < this->width);
}

bool Field::isComboLeft(int h, int w, int r)
{
    return isEqualsCellType(h, w-1, r) && isEqualsCellType(h, w-2, r);
}

bool Field::isComboTop(int h, int w, int r)
{
    return isEqualsCellType(h-1, w, r) && isEqualsCellType(h-2, w, r);
}

bool Field::isComboBottom(int h, int w, int r)
{
    return isEqualsCellType(h+1, w, r) && isEqualsCellType(h+2, w, r);
}

bool Field::isComboRight(int h, int w, int r)
{
    return isEqualsCellType(h, w+1, r) && isEqualsCellType(h, w+2, r);
}

bool Field::isEqualsCellType(int h, int w, int r)
{
    return isCellExist(h, w) && (getCell(h,w)->getType() == r);
}

bool Field::isLeft(int i, int j, int r)
{
    return this->isComboLeft(i, j-1, r)||this->isComboBottom(i, j-1, r)||this->isComboTop(i, j-1, r)||
            (this->isEqualsCellType(i-1, j-1, r) && this->isEqualsCellType(i+1, j-1, r));
}

bool Field::isRight(int i, int j, int r)
{
    return this->isComboBottom(i, j+1, r)||this->isComboRight(i, j+1, r)||this->isComboTop(i, j+1, r)||
            (this->isEqualsCellType(i-1, j+1, r) && this->isEqualsCellType(i+1, j+1, r));
}

bool Field::isTop(int i, int j, int r)
{
    return this->isComboRight(i-1, j, r)||this->isComboLeft(i-1, j, r)||this->isComboTop(i-1, j, r)||
            (this->isEqualsCellType(i-1, j-1, r) && this->isEqualsCellType(i-1, j+1, r));
}

bool Field::isBottom(int i, int j, int r)
{
    return this->isComboBottom(i+1, j, r)||this->isComboLeft(i+1, j, r)||this->isComboRight(i+1, j, r)||
            (this->isEqualsCellType(i+1, j-1, r) && this->isEqualsCellType(i+1, j+1, r));
}

QVector<Cell *> *Field::addCellTop(int i, int j, int r)
{
    QVector<Cell *> *c = new QVector<Cell *>(0);
    if (isEqualsCellType(i-1, j, r))
    {
        c->append(getCell(i-1, j));
        if (isEqualsCellType(i-2, j, r))
        {
            c->append(getCell(i-2, j));
        }
    }
    return c;
}

QVector<Cell *> *Field::addCellLeft(int i, int j, int r)
{
    QVector<Cell *> *c = new QVector<Cell *>(0);
    if (isEqualsCellType(i, j-1, r))
    {
        c->append(getCell(i, j-1));
        if (isEqualsCellType(i, j-2, r))
        {
            c->append(getCell(i, j-2));
        }
    }
    return c;
}

QVector<Cell *> *Field::addCellRight(int i, int j, int r)
{
    QVector<Cell *> *c = new QVector<Cell *>(0);
    if (isEqualsCellType(i, j+1, r))
    {
        c->append(getCell(i, j+1));
        if (isEqualsCellType(i, j+2, r))
        {
            c->append(getCell(i, j+2));
        }
    }
    return c;
}

QVector<Cell *>* Field::addCellBottom(int i, int j, int r)
{
    QVector<Cell *> *c = new QVector<Cell *>(0);
    if (isEqualsCellType(i+1, j, r))
    {
        c->append(getCell(i+1, j));
        if (isEqualsCellType(i+2, j, r))
        {
            c->append(getCell(i+2, j));
        }
    }
    return c;
}

void Field::start(int i1, int j1, int i2, int j2)
{
    bool p = false;
    int r1 = this->getCell(i1, j1)->getType();
    int r2 = this->getCell(i2, j2)->getType();
    if (i1 == i2)
    {
        if (j1 < j2)
        {
            if (this->isRight(i1,j1,r1)||
                this->isLeft(i2,j2,r2))
            {
                p = true;
            }
        } else if (this->isRight(i2,j2,r2)||
                   this->isLeft(i1,j1,r1))
               {
                   p = true;
               }
    } else if (i1 < i2)
           {
               if (this->isBottom(i1,j1,r1)||
                   this->isTop(i2,j2,r2))
               {
                   p = true;
               }
           } else if (this->isBottom(i2,j2,r2)||
                      this->isTop(i1,j1,r1))
                  {
                      p = true;
                  }
    if (p)
    {
        this->getCell(i1,j1)->setType(r2);
        this->getCell(i2,j2)->setType(r1);
        this->getCell(i1,j1)->clicked();
        this->getCell(i2,j2)->clicked();
        QVector<Cell*> *cells = new QVector<Cell*>(0);
        cells->append(this->getCell(i1,j1));
        cells->append(this->getCell(i2,j2));
        QThread::sleep(1);
        this->destroy(cells);
        delete cells;
        qDebug() << "YES";
    } else
    {
        this->getCell(i1,j1)->setType(this->getCell(i1,j1)->getType());
        this->getCell(i2,j2)->setType(this->getCell(i2,j2)->getType());
    }
}

void Field::destroy(QVector<Cell*>* cells)
{
    Cell* temp;
    bool p = false;
    QVector<Cell*> *c  = new QVector<Cell*>(0);
    int csize;
    for (int i = 0; i < cells->count(); i++)
    {
        csize = c->size();
        temp = cells->at(i);
        int cellI = temp->getI();
        int cellJ = temp->getJ();
        int cellType = temp->getType();

        p = false;

        if (isComboTop(cellI, cellJ, cellType))
        {
            c->append(getCell(cellI-1, cellJ));
            c->append(getCell(cellI-2, cellJ));
            c->append(*addCellBottom(cellI, cellJ, cellType));
            c->append(*addCellLeft(cellI, cellJ, cellType));
            c->append(*addCellRight(cellI, cellJ, cellType));
            p = true;
        } else
        if (isComboBottom(cellI, cellJ, cellType))
        {
            c->append(getCell(cellI+1, cellJ));
            c->append(getCell(cellI+2, cellJ));
            c->append(*addCellTop(cellI, cellJ, cellType));
            c->append(*addCellLeft(cellI, cellJ, cellType));
            c->append(*addCellRight(cellI, cellJ, cellType));
            p = true;
        } else
        if (isComboLeft(cellI, cellJ, cellType))
        {
            c->append(getCell(cellI,cellJ - 1));
            c->append(getCell(cellI, cellJ - 2));
            c->append(*addCellBottom(cellI, cellJ, cellType));
            c->append(*addCellTop(cellI, cellJ, cellType));
            c->append(*addCellRight(cellI, cellJ, cellType));
            p = true;
        } else
        if (isComboRight(cellI, cellJ, cellType))
        {
            c->append(getCell(cellI, cellJ + 1));
            c->append(getCell(cellI, cellJ + 2));
            c->append(*addCellBottom(cellI, cellJ, cellType));
            c->append(*addCellTop(cellI, cellJ, cellType));
            c->append(*addCellLeft(cellI, cellJ, cellType));
            p = true;
        } else
        if (isEqualsCellType(cellI - 1, cellJ, cellType) &&
            isEqualsCellType(cellI + 1, cellJ, cellType))
        {
            c->append(getCell(cellI - 1, cellJ));
            c->append(getCell(cellI + 1, cellJ));
        } else
            if (isEqualsCellType(cellI, cellJ - 1, cellType) &&
                isEqualsCellType(cellI, cellJ + 1, cellType))
            {
                c->append(getCell(cellI, cellJ - 1));
                c->append(getCell(cellI, cellJ + 1));
            }
        if (p)
        {
            c->append(temp);
            if (c->size() < 10)
                emit this->increaseScore(100*(c->size() - csize), temp->getType());
            else
                emit this->increaseScore(100*(c->size() - csize)*1.05, temp->getType());
        } else temp->setType(temp->getType());
    }
    if (c->count() != 0)
    {
        for (int i = 0; i < c->count(); i++)
        {
            c->at(i)->clicked();
        }
        QThread::sleep(1);
        for (int i = 0; i < c->count(); i++)
        {
            c->at(i)->setType(qrand() % 4);
        }
        destroy(c);
    }
    delete c;
}


