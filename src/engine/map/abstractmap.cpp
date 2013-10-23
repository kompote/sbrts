#include "abstractmap.h"
#include "../../utils/logger.h"

AbstractMap::AbstractMap()
{
    int i = 0;
    for(i = 0; i < 100; i++)
        m_SMapCaseList.push_back(_mapCase());

    cs.x = 30;
    cs.y = 30;
i = 0;
   for(unsigned int y = 0; y < 10; y++)
      for(unsigned int x = 0; x < 10; x++) 
      {
            debug("create map case %d,%d", x*cs.x, y*cs.y);
          m_SMapCaseList[i].posX = x*cs.x;
          m_SMapCaseList[i].posY = y*cs.y;
          if (( x == 3 && y == 7) || (x == 5 && y == 5))
             m_SMapCaseList[i].walkable = false; 
        else
              m_SMapCaseList[i].walkable = true; 
i++;
      }

}

AbstractMap::~AbstractMap()
{}
