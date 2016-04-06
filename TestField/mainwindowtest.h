#ifndef MAINWINDOWTEST_H
#define MAINWINDOWTEST_H

#include <QVector>
#include <QMainWindow>
#include <QPainter>
#include <QPixmap>

#include "field.h"
#include "levelcontroller.h"
#include "cellbutton.h"
#include "imagecontroller.h"

#include <QtQuick/QQuickView>
#include <QGraphicsObject>
#include <QtGui>
#include <QtQml/QQmlContext>
#include "QQuickItem"

namespace Ui {
class MainWindowTest;
}

class MainWindowTest : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindowTest(QWidget *parent = 0);
    Q_INVOKABLE void eventClick(int i, int j);
    Q_INVOKABLE void changeConditionForActivateSkill();
    Q_INVOKABLE void loadLevel();
    Q_INVOKABLE void closeLevel();
    Q_INVOKABLE void on_pushButton_clicked();
    ~MainWindowTest();
private:
    int heightField, widthField;
    QVector<QObject*>* buttons;
    Field* field;
    LevelController* levelController;
    QQuickView* ui;
    QQuickItem *Root;


signals:
     void clickedCell(int i, int j);
public slots:
     void clickCell(int i, int j);
     void decSize(int i, int j);
     void normalSize(int i, int j);
     void swap(int i1, int j1, int i2, int j2);
};
#endif // MAINWINDOWTEST_H
