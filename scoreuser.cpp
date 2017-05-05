#include "scoreuser.h"

ScoreUser::ScoreUser()
{
    myScore=0;
    myName="";
}
ScoreUser::ScoreUser(int score, const QString &name)
{
    myScore=score;
    myName=name;
}

int ScoreUser::getScore()const{
    return myScore;
}
QString ScoreUser::getName()const{
    return myName;
}




void ScoreUser::setName(const QString &name){
    myName=name;
}

void ScoreUser :: setScore(int score){
    myScore=score;
}
