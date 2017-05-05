#include "Overloads.h"

QDataStream &operator<<(QDataStream &out, const ScoreUser &scoreUser)
{
    out << scoreUser.getName()<<scoreUser.getScore();

    return out;
}

QDataStream &operator>>(QDataStream &in, ScoreUser &scoreUser)
{
    QString name;
    quint32 score;
    in >> name >> score;
    scoreUser = ScoreUser(score,name);
    return in;
}
