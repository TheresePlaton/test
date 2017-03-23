#include "highscore.h"
#include "ui_highscore.h"

HighScore::HighScore(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::HighScore)
{
    ui->setupUi(this);
}

HighScore::~HighScore()
{
    delete ui;
}
