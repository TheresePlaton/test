#ifndef OVERLOADS_H
#define OVERLOADS_H
#include"scoreuser.h"
#include <QtCore>

QDataStream &operator<<(QDataStream &out, const ScoreUser &scoreUser);
QDataStream &operator>>(QDataStream &in, ScoreUser &ScoreUser);


#endif // OVERLOADS_H
