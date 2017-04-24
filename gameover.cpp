#include "gameover.h"
#include "ui_gameover.h"
#include "snakewindow.h"
#include "ui_snakewindow.h"
#include <QFile>



/**
 * @brief GameOver::GameOver
 * @param parent
 */
GameOver::GameOver(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GameOver)
{
    ui->setupUi(this);
}
/**
 * @brief GameOver::~GameOver
 */
GameOver::~GameOver()
{
    delete ui;
}
/**
 * @brief GameOver::on_retry_btn_clicked
 *
 * user can choose to start a new game, after gameover
 */
void GameOver::on_retry_btn_clicked()
{
    SnakeWindow *retryGame;
    retryGame = new SnakeWindow();
    this->hide();
    retryGame->show();
}

/**
 * @brief GameOver::on_exit_game_Btn_clicked
 * user can choose to exit the game
 */
void GameOver::on_exit_game_Btn_clicked()
{
    HighScore *scoreBoard= new HighScore();
    this->hide();
    scoreBoard->show();

}

void GameOver::on_AddToscoreBoard_clicked()
{
    int score= this->ui->score_Label->text().toInt();
    QString name="";
    name= this->ui->nameOfPlayer->text();
    if(name==""){
        name="anonymous";
    }

    QMap<QString,int> map;


    QString fPath = QGuiApplication::applicationDirPath() + "/resourses/files/save.txt";
    QFile file(fPath);//"resourses/files/save.txt");//saveFilePath);

    if(!file.open(QIODevice::ReadOnly)){
        qDebug()<<"Could not open file hahahahah.";
        qDebug()<<"Error: " << file.errorString();
        return;
    }

    foreach(int item, map.values()){
        qDebug()<<item;
    }

    QDataStream in(&file);
    in.setVersion(QDataStream::Qt_5_8);
    in>>map;

    file.close();

    map.insert(name,score);


    QFile file1(fPath);
    if(!file1.open(QIODevice::WriteOnly)){
        qDebug()<<"Could not open file write.";
        qDebug()<<file1.errorString();
        return;

    }

    QDataStream out(&file1);
    out.setVersion(QDataStream::Qt_5_8);
    out<<map;
    file.flush();
    file.close();

}

void GameOver::setScore(QString score){
    this->ui->score_Label->setText(score);
}
