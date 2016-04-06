#include "mainwindowtest.h"
#include "ui_mainwindowtest.h"

#include "cellbutton.h"
#include <QLabel>
#include <QDebug>
MainWindowTest::MainWindowTest(QWidget *parent) :
    QMainWindow(parent),
    ui(new QQuickView)
{
    qRegisterMetaType< QVector<Cell*> >("QVector<Cell*>");

    ui->setSource(QUrl("qrc:/Field.qml"));
    QWidget *container = QWidget::createWindowContainer(ui);
    this->setCentralWidget(container);
    ui->setResizeMode(QQuickView::SizeRootObjectToView);

    ui->rootContext()->setContextProperty("windowsField", this);

}
void MainWindowTest::clickCell(int i, int j)
{
    QMetaObject::invokeMethod(this->buttons->at(i*this->widthField+j), "clickedButton");
}

void MainWindowTest::decSize(int i, int j)
{
    QMetaObject::invokeMethod(this->buttons->at(i*this->widthField+j), "decSize");
}

void MainWindowTest::normalSize(int i, int j)
{
    QMetaObject::invokeMethod(this->buttons->at(i*this->widthField+j), "normalSize");
}
MainWindowTest::~MainWindowTest()
{
   // delete this->field;
   // delete this->levelController;
   // delete this->buttons;
    // delete ui;
}



void MainWindowTest::eventClick(int i, int j)
{

    this->levelController->addCell(i, j, this->field);
    qDebug() << i << " " << j;
}

void MainWindowTest::changeConditionForActivateSkill()
{
    this->levelController->changeConditionForActivateSkill();
}

void MainWindowTest::loadLevel()
{
    Root = ui->rootObject()->findChild<QQuickItem*>("mainField");
    this->heightField = 15;
    this->widthField = 15;
    this->buttons = new QVector<QObject*>(0);
    QMetaObject::invokeMethod(Root, "createField", Q_ARG(QVariant, this->heightField), Q_ARG(QVariant,this->widthField));

    for (int i = 0; i < this->heightField; i++)
    {
        for (int j = 0; j < this->widthField; j++)
        {
            buttons->append(Root->findChild<QObject*>("cell_" + QString::number(i) + "_" +  QString::number(j)));
        }
    }

    QTime midnight(0,0,0);
    qsrand(midnight.secsTo(QTime::currentTime()));
    this->field = new Field(this->heightField, this->widthField, Root);
    for (int i = 0; i < 20; i++)
    {
        int w = rand() % (this->widthField);
        int h = rand() % (this->heightField);
        if (!this->field->getCell(h,w)->getTrap())
        {
            this->field->getCell(h,w)->setTrap(true);
        } else i--;
    }
    QObject::connect(this->field, SIGNAL(clickedCell(int,int)), this, SLOT(clickCell(int,int)));
    QObject::connect(this->field, SIGNAL(decSize(int,int)), this, SLOT(decSize(int,int)));
    QObject::connect(this->field, SIGNAL(normalSize(int,int)), this, SLOT(normalSize(int,int)));
    QObject::connect(this->field, SIGNAL(swap(int,int,int,int)), this, SLOT(swap(int,int,int,int)));
    this->levelController = new LevelController(50000, this, 0, Root);
    QObject::connect(this->levelController->hero, SIGNAL(destroy(QVector<Cell*>)), this->field, SLOT(destroy(QVector<Cell*>)));

    QObject::connect(this->levelController, SIGNAL(go(int,int,int,int)), this->field, SLOT(go(int,int,int,int)));
    this->field->start();
    field->moveToThread(field);
    QObject::connect(this->field, SIGNAL(increaseScore(int,int)), this->levelController, SLOT(increaseScore(int,int)));

}

void MainWindowTest::closeLevel()
{
    field->terminate();
    delete field;
    Root = NULL;
    delete levelController;
    buttons = NULL;
}

void MainWindowTest::on_pushButton_clicked()
{
    qApp->quit();
}

void MainWindowTest::swap(int i1, int j1, int i2, int j2)
{
    QMetaObject::invokeMethod(Root, "swap", Q_ARG(QVariant, i1), Q_ARG(QVariant,j1), Q_ARG(QVariant, i2), Q_ARG(QVariant,j2));
}
