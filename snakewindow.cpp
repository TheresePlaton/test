#include "snakewindow.h"
#include "ui_snakewindow.h"


SnakeWindow::SnakeWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SnakeWindow)
{
    //sets UI form and scene
    ui->setupUi(this);
    scene = new QGraphicsScene(0,0,680,440);
    scene->setBackgroundBrush(QBrush(QImage(":/images/resourses/images/background1.png")));
    ui->graphicsView_snake->setScene(scene);
     ui->pause_Game_Btn->setVisible(false);

    scene->setFocus();
    //Adds background music and loops it with playlist
    QMediaPlaylist *playlist = new QMediaPlaylist();
    playlist->addMedia(QUrl("qrc:/sounds/resourses/sounds/sonx.wav"));
    playlist->setPlaybackMode(QMediaPlaylist::Loop);

    music = new QMediaPlayer();
    music->setMedia(playlist);
    music->play();

}

SnakeWindow::~SnakeWindow()
{
    delete ui;
}

//opens a new game over screen if head crashes in tail
void SnakeWindow::gameOver()
{
    GameOver *gameOverWindow = new GameOver();
    gameOverWindow->setScore(QString::number(totalScore));
    this->hide();
    gameOverWindow->show();
    this->close();
}

bool SnakeWindow::powerUpIntersects(Consumable *cons, Map *map)
{
    for(int i=0; i<11; i++)
    {
        for(int j=0; j<17; j++)
        {
            auto* ptr = map->getMap()[i][j];
            if(!ptr) continue;
            if(cons->testRect().intersects(ptr->testRect()))
            {
                return true;
            }
        }
    }

    return false;
}

void SnakeWindow::startNewLevel()
{   ui->pause_Game_Btn->setVisible(false);
    disconnect(gameStart, SIGNAL(timeout()), this, SLOT(gameLoop()));
    disconnect(gameStart, SIGNAL(timeout()), this, SLOT(getCrashed()));

    scene->clear();

    //creating head of the snake item
    shead = new Snake(*scene, this);
    scene->addItem(shead);

    //head reacts on key events is true
    shead->setFocus();
    scene->installEventFilter(this);

    level.drawMap(lvl);
    for(int i=0; i<11; ++i){
        for (int j = 0; j < 17; ++j) {
            void* ptr = level.getMap()[i][j];
            if(ptr == nullptr) continue;
            scene->addItem(level.getMap()[i][j]);
        }
    }

    body = new BodyOfSnake();
    body->setPos(40,40);
    scene->addItem(body);
    shead->appendBodies(*body);

    pUp = new Green_powerup();

    //checks location of power up
    while(powerUpIntersects(pUp, &level))
    {
        pUp = new Green_powerup();
    }
    scene->addItem(pUp);

    connect(gameStart, SIGNAL(timeout()), this, SLOT(gameLoop()));
    connect(gameStart, SIGNAL(timeout()), this, SLOT(getCrashed()));
    gameStart->start(150);
}

void SnakeWindow::gameLoop()
{

    if(shead->getGameScore()>=150)
    {
        totalScore=totalScore+shead->getGameScore();
        lvl=1;
        startNewLevel();

    }
    shead->move();
    shead->getSnakeLength();

    //creates new power up upong power up consumption
    if(pUp->getConsumed())
    {
        QTime time = QTime::currentTime();
        qsrand((uint)time.msec());
        int high = 3;
        int low = 1;
        int choice = qrand() % ((high + 1)-low)+low;
        delete pUp;
        pUp = shead->setPowerUp(choice);
        //if new powerup crashes with either head, tail or wall
        //creates a new one and tests it again
        while(shead->collidesWithPwrUp(pUp)||powerUpIntersects(pUp,&level))
        {
           pUp = shead->setPowerUp(choice);
        }
        scene->addItem(pUp);
    }

    //connecting ui progress bar to a score value
    int score = shead->getGameScore();
    this->ui->progress_bar_level->setTextVisible(false);
    this->ui->progress_bar_level->setMaximum(150);
    this->ui->progress_bar_level->setValue(score);

    //connecting score to ui
    this->ui->label_Score->setText(QString::number(score));
    int currentLevel = lvl + 1;
    this->ui->label_Level->setText(QString::number(currentLevel));

    //opens game over screen
    if(isDead)
    {
        disconnect(gameStart, SIGNAL(timeout()), this, SLOT(gameLoop()));
        disconnect(gameStart, SIGNAL(timeout()), this, SLOT(getCrashed()));
        totalScore=totalScore+shead->getGameScore();
        music->stop();
        gameOver();
    }
}

bool SnakeWindow::getCrashed()
{

    isDead=shead->getHead_in_tail();
    return isDead;
}


void SnakeWindow::on_exit_Game_Btn_clicked()
{
    gameIsPaused = !gameIsPaused;

    //pauses and pauses game timer and background music
    if(gameIsPaused){
        disconnect(gameStart, SIGNAL(timeout()), this, SLOT(gameLoop()));
        disconnect(gameStart, SIGNAL(timeout()), this, SLOT(getCrashed()));
        music->setMuted(true);
    }

    QMessageBox quitMsgBox;
    quitMsgBox.setText("Do you really want to quit?");
    quitMsgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
    int ret = quitMsgBox.exec();
    switch(ret){

    case QMessageBox::Yes:
        this->close();
        break;
    case QMessageBox::No:
        quitMsgBox.close();
        connect(gameStart, SIGNAL(timeout()), this, SLOT(gameLoop()));
        connect(gameStart, SIGNAL(timeout()), this, SLOT(getCrashed()));
        gameStart->start(150);
        music->setMuted(false);
        break;
    }

}

void SnakeWindow::on_pause_Game_Btn_clicked()
{
    gameIsPaused = !gameIsPaused;

    //pauses and pauses game timer and background music
    if(gameIsPaused){
        ui->pause_Game_Btn->setText("Resume");
        disconnect(gameStart, SIGNAL(timeout()), this, SLOT(gameLoop()));
        disconnect(gameStart, SIGNAL(timeout()), this, SLOT(getCrashed()));
        music->setMuted(true);
    }
    if(!gameIsPaused){
        connect(gameStart, SIGNAL(timeout()), this, SLOT(gameLoop()));
        connect(gameStart, SIGNAL(timeout()), this, SLOT(getCrashed()));
        gameStart->start(150);
        music->setMuted(false);
        ui->pause_Game_Btn->setText("Pause");

    }
}




void SnakeWindow::on_start_Game_Btn_clicked()
{
     ui->start_Game_Btn->setVisible(false);
      ui->pause_Game_Btn->setVisible(true);
    //creating head of the snake item
    shead = new Snake(*scene, this);
    scene->addItem(shead);

    //head reacts on key events is true
    shead->setFocus();
    scene->installEventFilter(this);

    level.drawMap(lvl);
    for(int i=0; i<11; ++i){
        for (int j = 0; j < 17; ++j) {
            void* ptr = level.getMap()[i][j];
            if(ptr == nullptr) continue;
            scene->addItem(level.getMap()[i][j]);
        }
    }

    body = new BodyOfSnake();
    body->setPos(40,40);
    scene->addItem(body);
    shead->appendBodies(*body);

    pUp = new Green_powerup();

    while(powerUpIntersects(pUp, &level))
    {
        pUp = new Green_powerup();
    }
    scene->addItem(pUp);
    connect(gameStart, SIGNAL(timeout()), this, SLOT(gameLoop()));
    connect(gameStart, SIGNAL(timeout()), this, SLOT(getCrashed()));
    gameStart->start(150);


}
//Set key behaviour
void SnakeWindow::handleKeyPressed(QKeyEvent *event)
{
    //if (!isPause)
    switch (event->key()) {
    case Qt::Key_Left:
        shead->setDirection(Snake::Left);
        break;
    case Qt::Key_Right:
        shead->setDirection(Snake::Right);
        break;
    case Qt::Key_Up:
        shead->setDirection(Snake::Up);
        break;
    case Qt::Key_Down:
        shead->setDirection(Snake::Down);
        break;
    case Qt::Key_Space:
        //pause();
        break;
    }
    //else resume();a
}

bool SnakeWindow::eventFilter(QObject *object, QEvent *event)
{
    if (event->type() == QEvent::KeyPress) {
        handleKeyPressed((QKeyEvent *)event);
        return true;
    } else {
        return QObject::eventFilter(object, event);
    }
}
