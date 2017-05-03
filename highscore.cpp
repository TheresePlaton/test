#include "highscore.h"
#include "ui_highscore.h"



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
    QList<ScoreUser> userList;

    QString fPath = QGuiApplication::applicationDirPath() + "/resourses/files/save.txt";
    QFile file(fPath);
    if(!file.open(QIODevice::ReadOnly)){

        return;
    }


    QDataStream in(&file);
    in.setVersion(QDataStream::Qt_5_8);
    ScoreUser scoreUser;
    while(!in.atEnd()){
        in >> scoreUser;
        userList.append(scoreUser);

    }

    file.close();
    if(userList.size()>1){
        for(int k = 1; k < (userList.size()); k++){

            for(int i=0 ;i <(userList.size()-1);i++ ){

                if(userList.at(i).myScore < userList.at(i+1).myScore){
                    userList.swap(i,i+1);
                }

            }
        }
    }
    int row =10;
    if(userList.size()<row){
        row =userList.size();
    }


    ui->tableWidget->setRowCount(row);
    ui->tableWidget->setColumnCount(2);
    ui->tableWidget->setHorizontalHeaderLabels(list);
    ui->tableWidget->horizontalHeader()->setDefaultAlignment(Qt::AlignLeft);



    for(int i =0;i<row;i++){
        QTableWidgetItem* item1 = new QTableWidgetItem();
        QTableWidgetItem* item2 = new QTableWidgetItem();
        item1->setText(userList.at(i).getName());
        item2->setText(QString::number(userList.at(i).myScore));
        ui->tableWidget->setItem(i,0,item1);
        ui->tableWidget->setItem(i,1,item2);
    }

    ui->tableWidget->setEditTriggers( QAbstractItemView::NoEditTriggers );

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
    this->close();
}
