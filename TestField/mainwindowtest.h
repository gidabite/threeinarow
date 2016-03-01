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

namespace Ui {
class MainWindowTest;
}

class MainWindowTest : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindowTest(QWidget *parent = 0);
    ~MainWindowTest();
private:
    int heightField, widthField;
    QVector<CellButton*>* buttons;
    Field* field;
    LevelController* levelController;
    Ui::MainWindowTest *ui;
    void paintEvent(QPaintEvent *pe);

public slots:
     void eventClick();
signals:
     void updateType(int i, int j, int type);
private slots:
     void on_pushButton_clicked();
};
#endif // MAINWINDOWTEST_H
