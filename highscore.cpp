#include "highscore.h"
#include "ui_highscore.h"
#include "snakewindow.h"
#include "ui_snakewindow.h"

HighScore::HighScore(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::HighScore)
{
    ui->setupUi(this);

    Load();
}

HighScore::~HighScore()
{
    delete ui;
}

void HighScore::Load(){

    QMap<QString,int> map;

    QFile file("C:/Users/Tess/Documents/prosjektoppgave/test/save.txt");
    if(!file.open(QIODevice::ReadOnly)){
        qDebug()<<"Could not open file.";
        return;
    }

    foreach(int item, map.values()){
      qDebug()<<item;
    }

    QDataStream in(&file);
    in.setVersion(QDataStream::Qt_5_8);
    in>>map;
    file.close();
    int i =1;
    QString name="";
    int score=0;
    QMapIterator<QString,int> Iter(map);
    while(Iter.hasNext()){
        Iter.next();
        name=Iter.key();
        score=Iter.value();
        ui->list->addItem(QString::number(i)+ ".\t " +name +" " + QString::number(score));
        i++;
}
}

void HighScore::on_btnExit_clicked()
{
    this->close();
}



void HighScore::on_btnPlayAgein_clicked()
{
    SnakeWindow *retryGame;
    retryGame = new SnakeWindow();
    this->hide();
    retryGame->show();
}
