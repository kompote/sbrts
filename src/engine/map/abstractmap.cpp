#include <stdlib.h>
#include <time.h>
#include "abstractmap.h"
#include "../../utils/logger.h"

void AbstractMap::createTestMap()
{
      
    DBG_WARN("Abstraction map: creating layer 0...");
/*
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
*/
    _coord p1 = {0,0};
    _coord p2 = {0,30};
    _coord p3 = {30,30};
    _coord p4 = {30,0};
    srand(time(NULL));
    std::vector<_polyCase> tmpVect;
    for (int j = 0; j < 100; j++)
    {
        for (int i = 0; i < 100; i++)
        {
            tmpVect.push_back(_polyCase());
            tmpVect[i] = { p1 , p2, p3, p4, rand()%100 < 10 ? false : true };
            p1 = p4;
            p2 = p3;
            p3 = {p2.x + 30, p2.y};
            p4 = {p1.x + 30, p1.y};
        }
        p1 = { 0, p1.y + 30};
        p2 = { 0, p2.y + 30};
        p3 = { 30, p3.y + 30};
        p4 = { 30, p4.y + 30};
        polyList.push_back(tmpVect);
        tmpVect.clear();
    }
    DBG_WARN("Abstraction map: layer 0 done.");
}

AbstractMap::AbstractMap()
{
    createTestMap();
    debug("Abstraction map: layer 0 info : %d (%d Ko)", polyList.size() * polyList[0].size(), polyList.size() * polyList[0].size()  * sizeof(_polyCase) / 1024);
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

