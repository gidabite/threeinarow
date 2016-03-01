#include <QTime>

int rand_me()
{
    QTime midnight(0,0,0);
    qsrand(midnight.secsTo(QTime::currentTime()));
    return qrand();
}
