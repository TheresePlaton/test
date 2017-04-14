#include "map.h"


Map::Map()
{
    Wall_brick* map[17][11]={};

    const char aMap[][17][11] =
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



}

void Map::drawMap()
{

    for(int i=0; i<17; ++i)
    {
        for(int j=0; j<11; ++j)
        {
            switch(this->aMap){
            case 'e':
            case 'w': this->map[i][j]=new Wall_brick((i*40),(j*40)); break;

            }
        }
    }
}
