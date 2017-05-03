#include "gameover.h"
#include "ui_gameover.h"
#include "snakewindow.h"
#include "ui_snakewindow.h"
#include "overloads.h"
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
 * @brief GameOver::EnterScoreBoard
 */
void GameOver::EnterScoreBoard()
{
    HighScore *scoreBoard= new HighScore();
    this->hide();
    scoreBoard->show();
    this->close();

}

void GameOver::on_AddToscoreBoard_clicked()
{
    int score= this->ui->score_Label->text().toInt();
    QString name="";
    name= this->ui->nameOfPlayer->text();
    if(name==""){
        name="anonymous";
    }
    ScoreUser user1(score,name);
    QString fPath = QGuiApplication::applicationDirPath() + "/resourses/files/save.txt";
    QFile file(fPath);
    //"resourses/files/save.txt");//saveFilePath);
    if(!file.open(QIODevice::Append)){
        qDebug()<<"Could not open file write.";
        qDebug()<<file.errorString();
        return;

    }

    QDataStream out(&file);
    out.setVersion(QDataStream::Qt_5_8);
    out<<user1;
    file.flush();
    file.close();
    EnterScoreBoard();
}

void GameOver::setScore(QString score){
    this->ui->score_Label->setText(score);
}
