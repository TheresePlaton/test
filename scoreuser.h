#ifndef SCOREUSER_H
#define SCOREUSER_H
#include <QString>

class ScoreUser
{
public:
    ScoreUser();
    ScoreUser(int score, const QString &name);
    QString getName()const;
    int getScore()const;
    void setName(const QString &name);
    void setScore(int score);
    int myScore;

private:

    QString myName;
};

#endif // SCOREUSER_H
