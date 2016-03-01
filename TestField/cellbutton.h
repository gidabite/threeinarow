#ifndef CELLBUTTON_H
#define CELLBUTTON_H

#include <QWidget>
#include <QPushButton>
#include <imagecontroller.h>

class CellButton : public QPushButton
{
    Q_OBJECT
private:

    int type;
    bool isHover;
    bool isClicked;

public:
    explicit CellButton(QWidget *parent = 0);
    void connnectCell();
    void paintEvent(QPaintEvent *pe);
    void enterEvent(QEvent * event);
    void leaveEvent(QEvent * event);
signals:

public slots:
    void UpdateType(int type);
};

#endif // CELLBUTTON_H
