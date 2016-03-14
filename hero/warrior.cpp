#include "warrior.h"

Warrior::Warrior(int score)
{
    this->heroScore = score;
    name = "Воин";
    typeCrystal = 0;
    this->currentScore = 0;
}

void Warrior::heroPower(int i, int j, Field *field)
{
    QVector<Cell*> deleteList(0);
    int color = field->getCell(i,j)->getType();

    for (int k = i - 1; k <= i + 1; k++)
    {
        for (int l = j - 1; l <= j + 1; l++)
        {
            if (field->isCellExist(k,l))
            {
                deleteList.append(field->getCell(k,l));
            }
        }
    }
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
