#include "abstractmap.h"
#include "../../utils/logger.h"

void AbstractMap::createTestMap()
{
      
    DBG_WARN("create TEST map");

    polyList.push_back(_polyCase());
    polyList[0] = { {0,0}, {5,33}, {33,30}, {32,3}, true };
    polyList.push_back(_polyCase());
    polyList[1] = { {32,3}, {33,30}, {68,36}, {67,6}, true };
    polyList.push_back(_polyCase());
    polyList[2] = { {67,6}, {68,36}, {92,34}, {99,1}, true };
    polyList.push_back(_polyCase());
    polyList[3] = { {99,1}, {92,34}, {133,30}, {132,3}, true };
    polyList.push_back(_polyCase());
    polyList[4] = { {132,3}, {133,30}, {168,36}, {167,6}, true };
    polyList.push_back(_polyCase());
    polyList[5] = { {167,6}, {168,36}, {192,34}, {199,1}, true };

    polyList.push_back(_polyCase());
    polyList[6] = { {5,33}, {2,60}, {34,66}, {33,30}, true };
    polyList.push_back(_polyCase());
    polyList[7] = { {33,30}, {34,66}, {68,55}, {68,36}, false };
    polyList.push_back(_polyCase());
    polyList[8] = { {68,36}, {68,55}, {92,64}, {92,34}, true };
    polyList.push_back(_polyCase());
    polyList[9] = { {92,34}, {92,64}, {133,66}, {133,30}, false };
    polyList.push_back(_polyCase());
    polyList[10] = { {133,30}, {133,66}, {168,65}, {168,36}, true };
    polyList.push_back(_polyCase());
    polyList[11] = { {168,36}, {168,65}, {192,64}, {192,34}, true };

    polyList.push_back(_polyCase());
    polyList[12] = { {2,60}, {6,90}, {30,93}, {34,66}, true };
    polyList.push_back(_polyCase());
    polyList[13] = { {34,66}, {30,93}, {66,99}, {68,55}, true };
    polyList.push_back(_polyCase());
    polyList[14] = { {68,55}, {66,99}, {93,96}, {92,64}, false };
    polyList.push_back(_polyCase());
    polyList[15] = { {92,64}, {93,96}, {130,96}, {133,66}, true };
    polyList.push_back(_polyCase());
    polyList[16] = { {133,66}, {130,96}, {167,95}, {168,65}, true };
    polyList.push_back(_polyCase());
    polyList[17] = { {168,65}, {167,95}, {190,94}, {192,64}, true };
}

AbstractMap::AbstractMap()
{
    createTestMap();
    /*
    int i = 0;
    for(i = 0; i < 100; i++)
        m_SMapCaseList.push_back(_mapCase());

    cs.x = 30;
    cs.y = 30;
    i = 0;
   for(unsigned int y = 0; y < 10; y++)
      for(unsigned int x = 0; x < 10; x++) 
      {
           // debug("create map case %d,%d", x*cs.x, y*cs.y);
          m_SMapCaseList[i].posX = x*cs.x;
          m_SMapCaseList[i].posY = y*cs.y;
          if (( x == 3 && y == 7) || (x == 5 && y == 5))
             m_SMapCaseList[i].walkable = false; 
        else
              m_SMapCaseList[i].walkable = true; 
        i++;
      }
      */
}

AbstractMap::~AbstractMap()
{}

bool AbstractMap::contains(_polyCase pCase, _coord coord)
{
    bool isIn = false;
    if ( (coord.x >= pCase.topLeft.x) &&
            (coord.x < pCase.topRight.x) &&
            (coord.x >= pCase.botLeft.x) &&
            (coord.x < pCase.botRight.x) &&

            (coord.y >= pCase.topLeft.y) &&
            (coord.y >= pCase.topRight.y) &&
            (coord.y < pCase.botLeft.y) &&
            (coord.y < pCase.botRight.y) )
        isIn = true;

    return isIn;

}

