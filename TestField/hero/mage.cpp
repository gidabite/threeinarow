#include "mage.h"

Mage::Mage(int score, QQuickItem *Root)
{
    this->Root = Root;
    this->heroScore = score;
    name = "Маг";
    typeCrystal = 2;
    this->currentScore = 0;
}

void Mage::heroPower(int i, int j, Field *field)
{
    QVector<Cell*> deleteList(0);
    int color = field->getCell(i,j)->getType();

    for (int k = i - 2; k <= i + 2; k++)
    {
        for (int l = j - 2; l <= j + 2; l++)
        {
            if (field->isCellExist(k,l))
            {
                if (field->getCell(k,l)->getType() == color)
                    deleteList.append(field->getCell(k,l));
            }
        }
    }

    emit field->increaseScore(deleteList.size()*100, deleteList.last()->getType());
    emit destroy(deleteList);

}
