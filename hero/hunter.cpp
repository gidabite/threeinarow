#include "hunter.h"
#include "cell.h"
#include "QVector"


Hunter::Hunter(int score)
{
    this->heroScore = score;
    name = "Охотник";
    typeCrystal = 1;
    this->currentScore = 0;
}

void Hunter::heroPower(int i, int j, Field *field)
{
    QVector<Cell*> deleteList(0);
    if (field->isCellExist(i - 1, j))
    {
        deleteList.append(field->getCell(i-1,j));
    }
    if (field->isCellExist(i - 2, j))
    {
        deleteList.append(field->getCell(i-2,j));
    }
    if (field->isCellExist(i + 1, j))
    {
        deleteList.append(field->getCell(i+1,j));
    }
    if (field->isCellExist(i + 2, j))
    {
        deleteList.append(field->getCell(i+2,j));
    }
    if (field->isCellExist(i, j - 1))
    {
        deleteList.append(field->getCell(i,j-1));
    }
    if (field->isCellExist(i, j - 2))
    {
        deleteList.append(field->getCell(i,j - 2));
    }
    if (field->isCellExist(i, j + 1))
    {
        deleteList.append(field->getCell(i,j + 1));
    }
    if (field->isCellExist(i, j + 2))
    {
        deleteList.append(field->getCell(i,j + 2));
    }
    deleteList.append(field->getCell(i,j));

    for (int i = 0; i < deleteList.size(); i++)
    {
        deleteList.at(i)->clicked();
    }
    QThread::sleep(1);
    for (int i = 0; i < deleteList.size(); i++)
    {
        deleteList.at(i)->setType(qrand() % 4);
    }
    emit field->increaseScore(deleteList.size()*100, deleteList.last()->getType());
    field->destroy(&deleteList);

}
