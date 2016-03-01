#ifndef HERO_H
#define HERO_H

#include <QObject>

class Hero : public QObject
{
    Q_OBJECT
public:
    explicit Hero(QObject *parent = 0);
    int heroScore;
    QString name;

    virtual void heroPower(){}

signals:

public slots:
};

#endif // HERO_H
