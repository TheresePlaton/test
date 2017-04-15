#ifndef MAP_H
#define MAP_H

#include <QObject>
#include "wall_brick.h"

class Map
{
public:

    //creating new typedef aliace for convinience
    using mapArray = std::array<std::array<Wall_brick*,17>,11>;

    Map();

    /**
     * @brief drawMap lays out wall objects at given coordinates
     * using matrix index and size of each wall brick
     */
    void drawMap();

    /**
     * @brief getMap
     * @return map
     */
    mapArray& getMap();

private:
mapArray map;

//creates a map layout.
const char aMap1[11][17] =
{{'w','w','w','w','w','w','w','w','w','w','w','w','w','w','w','w','w'},
 {'w','e','e','e','e','e','e','e','e','e','e','e','e','e','e','e','w'},
 {'w','e','e','e','e','e','e','e','e','e','e','e','e','e','e','e','w'},
 {'w','e','e','e','e','e','e','e','e','e','e','e','e','e','e','e','w'},
 {'w','e','e','e','e','e','e','e','e','e','e','e','e','e','e','e','w'},
 {'w','e','e','e','e','e','e','w','w','w','w','e','e','e','e','e','w'},
 {'w','e','e','e','e','e','e','e','e','e','e','e','e','e','e','e','w'},
 {'w','e','e','e','e','e','e','e','e','e','e','e','e','e','e','e','w'},
 {'w','e','e','e','e','e','e','e','e','e','e','e','e','e','e','e','w'},
 {'w','e','e','e','e','e','e','e','e','e','e','e','e','e','e','e','w'},
 {'w','w','w','w','w','w','w','w','w','w','w','w','w','w','w','w','w'}};
};

#endif // MAP_H
