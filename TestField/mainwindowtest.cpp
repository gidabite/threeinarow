#include "mainwindowtest.h"
#include "ui_mainwindowtest.h"

#include "cellbutton.h"
#include <QLabel>
#include <QDebug>
MainWindowTest::MainWindowTest(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindowTest)
{
    ui->setupUi(this);
    this->heightField = 15;
    this->widthField = 15;
    this->buttons = new QVector<CellButton*>(0);
    for (int i = 0; i < this->heightField; i++)
    {
        for (int j = 0; j < this->widthField; j++)
        {
            buttons->append(new CellButton(this));
            buttons->last()->setGeometry(QRect(j*96.6+450, i*70, 96.6,70));
            buttons->last()->setAccessibleName(QString::number(i*this->widthField+j));
            QWidget::connect(buttons->last(), SIGNAL(clicked()), this, SLOT(eventClick()));
        }
    }
    QTime midnight(0,0,0);
    qsrand(midnight.secsTo(QTime::currentTime()));
    this->field = new Field(this->heightField, this->widthField, this->buttons);
    this->levelController = new LevelController(50000, this, 0);
    QObject::connect(this->field, SIGNAL(increaseScore(int,int)), this->levelController, SLOT(increaseScore(int,int)));
}

MainWindowTest::~MainWindowTest()
{
    delete this->field;
    delete this->levelController;
    delete this->buttons;
    delete ui;
}

void MainWindowTest::paintEvent(QPaintEvent *pe)
{
   QPainter painter(this);
   painter.drawPixmap(0,0,this->width()*0.2343,this->height(),ImageController::init()->back1);
   painter.drawPixmap(this->width()*0.2343,0,this->width()*0.7656,this->height(),ImageController::init()->back2);
}


void MainWindowTest::eventClick()
{
    CellButton *btn = qobject_cast<CellButton*>(sender());
    int i = btn->accessibleName().toInt();
    int j = i % this->widthField;
    i /= this->widthField;
    this->levelController->addCell(btn, this->field);
    qDebug() << i << " " << j;
}

void MainWindowTest::on_pushButton_clicked()
{
    qApp->quit();
}
