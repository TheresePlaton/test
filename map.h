#ifndef MAP_H
#define MAP_H

#include <QObject>
#include "wall_brick.h"

/**
 * @brief The Map class creates level outline based on a 17x11 matrix
 * where 'w' stands for wall and 'e' means epmty.
 */
class Map
{
public:

    //creating new typedef aliace for convinience
    using mapArray = std::array<std::array<Wall_brick*,17>,11>;
    using levelArray = std::array<std::array<char, 17>, 11>;
    using levelMatrix = std::array<levelArray, 2>;
    Map();

    /**
     * @brief drawMap lays out wall objects at given coordinates
     * using matrix index and size of each wall brick
     */
    void drawMap(int lvl);


    /**
     * @brief getMap
     * @return map
     */
    mapArray& getMap();


    levelArray& getLevel(int lvl){
        return levels[lvl];
    }


private:
    mapArray map;

    //creates a map layout.
    levelArray lvl1 = {{
                           {{'w','w','w','w','w','w','w','w','w','w','w','w','w','w','w','w','w'}},
                           {{'w','e','e','e','e','e','e','e','e','e','e','e','e','e','e','e','w'}},
                           {{'w','e','e','e','e','e','e','e','e','e','e','e','e','e','e','e','w'}},
                           {{'w','e','e','e','e','e','e','e','e','e','e','e','e','e','e','e','w'}},
                           {{'w','e','e','e','e','e','e','e','e','e','e','e','e','e','e','e','w'}},
                           {{'w','e','e','e','e','e','e','e','e','e','e','e','e','e','e','e','w'}},
                           {{'w','e','e','e','e','e','e','e','e','e','e','e','e','e','e','e','w'}},
                           {{'w','e','e','e','e','e','e','e','e','e','e','e','e','e','e','e','w'}},
                           {{'w','e','e','e','e','e','e','e','e','e','e','e','e','e','e','e','w'}},
                           {{'w','e','e','e','e','e','e','e','e','e','e','e','e','e','e','e','w'}},
                           {{'w','w','w','w','w','w','w','w','w','w','w','w','w','w','w','w','w'}}
                       }};

    levelArray lvl2 = {{
                           {{'w','w','w','w','w','w','w','w','w','w','w','w','w','w','w','w','w'}},
                           {{'w','e','e','e','e','e','e','e','e','e','e','e','e','e','e','e','w'}},
                           {{'w','e','e','e','e','e','e','e','e','e','e','e','e','e','e','e','w'}},
                           {{'w','e','e','e','e','e','e','e','e','e','e','e','e','e','e','e','w'}},
                           {{'w','e','e','e','e','e','e','e','e','e','e','e','e','e','e','e','w'}},
                           {{'w','e','e','e','e','e','w','w','w','e','e','e','e','e','e','e','w'}},
                           {{'w','e','e','e','e','e','e','e','e','e','e','e','e','e','e','e','w'}},
                           {{'w','e','e','e','e','e','e','e','e','e','e','e','e','e','e','e','w'}},
                           {{'w','e','e','e','e','e','e','e','e','e','e','e','e','e','e','e','w'}},
                           {{'w','e','e','e','e','e','e','e','e','e','e','e','e','e','e','e','w'}},
                           {{'w','w','w','w','w','w','w','w','w','w','w','w','w','w','w','w','w'}}
                       }};

    levelMatrix levels{{lvl1, lvl2}};
};





#endif // MAP_H
