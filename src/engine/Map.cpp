#include "Map.h"

Map::Map()
{
    int z =0;
    for(int i=0;i<57;i++)
        for(int j=0;j<80;j++) 
        {
            m_grid[i][j] = new Case(z,j*10,i*10);    
            z++;
        }
}

Map::~Map()
{
    for(int i=0;i<57;i++)
        for(int j=0;j<80;j++) 
        {
            delete m_grid[i][j];
        }
}

void Map::Redraw(RenderTarget& target) const
{
    for(int i=0;i<57;i++)
        for(int j=0;j<80;j++) 
        {
            m_grid[i][j]->Draw(target);
        }

}

