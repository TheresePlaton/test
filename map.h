#ifndef MAP_H
#define MAP_H

#include <QObject>
#include "wall_brick.h"

class Map
{
public:

    using mapArray = std::array<std::array<Wall_brick*,17>,11>;

    Map();

    void drawMap();

    mapArray& getMap();

private:
mapArray map;

const char aMap[11][17] =
{{'w','w','w','w','w','w','w','w','w','w','w','w','w','w','w','w','w'},
 {'w','e','e','e','e','e','e','e','e','e','e','e','e','e','e','e','w'},
 {'w','e','e','e','e','e','e','e','e','e','e','e','e','e','e','e','w'},
 {'w','e','e','e','e','e','e','e','e','e','e','e','e','e','e','e','w'},
 {'w','e','e','e','e','e','e','e','e','e','e','e','e','e','e','e','w'},
 {'w','e','e','e','e','e','e','e','e','e','e','e','e','e','e','e','w'},
 {'w','e','e','e','e','e','e','e','e','e','e','e','e','e','e','e','w'},
 {'w','e','e','e','e','e','e','e','e','e','e','e','e','e','e','e','w'},
 {'w','e','e','e','e','e','e','e','e','e','e','e','e','e','e','e','w'},
 {'w','e','e','e','e','e','e','e','e','e','e','e','e','e','e','e','w'},
 {'w','w','w','w','w','w','w','w','w','w','w','w','w','w','w','w','w'}};
};

#endif // MAP_H
