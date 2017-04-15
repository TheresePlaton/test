#include "map.h"


Map::Map()
{

}
/**
 * @brief Map::drawMap iterates through level outline and draws wall objects
 */
void Map::drawMap(int lvl)
{

    levelArray currentLvl = levels[lvl];

    for(int i=0; i<11; ++i)
    {
        for(int j=0; j<17; ++j)
        {
            switch(currentLvl[i][j]){

            case 'w': this->map[i][j]=new Wall_brick((j*40),(i*40)); break;
            default: this->map[i][j]=nullptr; break;
            }
        }
    }
}

Map::mapArray &Map::getMap()
{
    return map;
}


