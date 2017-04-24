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

    QString fPath = QGuiApplication::applicationDirPath() + "/resourses/files/save.txt";
    QFile file(fPath);
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

    QString name="";
    int score=0;

    ui->tableWidget->setRowCount(10);
    ui->tableWidget->setColumnCount(2);
    ui->tableWidget->setHorizontalHeaderLabels(list);
    ui->tableWidget->horizontalHeader()->setDefaultAlignment(Qt::AlignLeft);
    int i=0;
    QMapIterator<QString,int> Iter(map);
    while(Iter.hasNext() && (i< 10)){

        Iter.next();
        name=Iter.key();
        score=Iter.value();
        QTableWidgetItem* item1 = new QTableWidgetItem();
        QTableWidgetItem* item2 = new QTableWidgetItem();
        item1->setText(name);
        item2->setText(QString::number(score));
        ui->tableWidget->setItem(i,0,item1);
        ui->tableWidget->setItem(i,1,item2);
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
