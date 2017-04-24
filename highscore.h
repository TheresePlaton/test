#ifndef HIGHSCORE_H
#define HIGHSCORE_H

#include <QMainWindow>
#include <QFile>
#include <QString>
#include <QStringList>
#include <QMap>
#include <QDebug>
#include "overloads.h"
#include "snakewindow.h"
#include "ui_snakewindow.h"

namespace Ui {
class HighScore;
}

class HighScore : public QMainWindow
{
    Q_OBJECT

public:
    explicit HighScore(QWidget *parent = 0);
    ~HighScore();
    void Load();

private slots:


    void on_btnExit_clicked();

    void on_btnPlayAgein_clicked();

private:
    Ui::HighScore *ui;
    QStringList list ={"Name", "Score"};
};

#endif // HIGHSCORE_H
