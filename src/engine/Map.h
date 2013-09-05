#ifndef MAP_H
#define MAP_H

#include "Case.h"

class Map
{
    private:
        // map size
        unsigned int m_iPixelH; // surface height
        unsigned int m_iPixelW; // surface width

        Case* m_grid[60][80];

    public:
        Map();
~Map();

        void Redraw(RenderTarget& target) const;


};
#endif
