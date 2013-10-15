#include "advMap.h"
#include<iostream>
#include<fstream>
#include<cctype>
#include<string>
#include<vector>

#include "../utils/logger.h"

AdvMap::AdvMap():m_map(), m_tile(),m_tileTexture(),
                 m_uiViewWidth(0),
                 m_uiViewHeight(0)
{}

AdvMap::~AdvMap()
{}

// ------------------------------------------------------------------- LoadMap
unsigned char AdvMap::loadMap(string mapName)
{
    // construct path
    // TODO : global path define
    string path = "maps/"+ mapName + "/map";

    DBG_INFO("Loading " + path + "... ");
    std::ifstream openfile(path);

    // map representation
    std::vector<sf::Vector2i> tempMap;

    if(openfile.is_open())
    {
        // load tileset
        std::string tileLocation;
        openfile >> tileLocation;
        m_tileTexture.loadFromFile(path+tileLocation);
        m_tile.setTexture(m_tileTexture);

        // read map file
        while(!openfile.eof())
        {
            // load tiles coordinates
            std::string str;
            openfile >> str;
            char x = str[0], y = str[2];
            if(!isdigit(x) || !isdigit(y))
                tempMap.push_back(sf::Vector2i(-1, -1));
            else
                // hack to translate char to int
                tempMap.push_back(sf::Vector2i(x - '0', y - '0'));

            // next line
            if(openfile.peek() == '\n')
            {
                m_map.push_back(tempMap);
                tempMap.clear();
            }
        }
        m_map.push_back(tempMap);

        DBG_INFO("Done.");
        return (unsigned char)0;
    }
    DBG_ERROR("Falied.");
    return (unsigned char)1;
}

// ----------------------------------------------------------------- setViewSize
void AdvMap::setViewSize(unsigned int viewX, unsigned int viewY)
{
    m_uiViewWidth = viewX;
    m_uiViewHeight = viewY;
}

// ----------------------------------------------------------------- redraw
void AdvMap::redraw(RenderTarget& window, unsigned int fromX, unsigned int fromY )
{
    // compute draw needin size
    // 30 & 8 come from tile size. Will be soon in map definition
    unsigned int maxW = ((fromX + m_uiViewWidth)/30) + 2;
    unsigned int maxH = ((fromY + m_uiViewHeight)/8) + 2;
    int startX = (fromX / 30) - 2;
    int startY = (fromY / 8 ) - 2;

    // limit to map size
    if ( maxH > m_map.size() )
        maxH = m_uiViewHeight;
    if ( maxW > m_map[0].size() )
        maxW = m_uiViewWidth;
    if (startX < 0)
        startX = 0;
    if (startY < 0)
        startY = 0;

    debug(" start : %d:%d\n", startX, startY);
    for(unsigned int i = startY; i < maxH; i++)
    {
        for(unsigned int j = startX; j < maxW; j++)
        {
            if(m_map[i][j].x != -1 && m_map[i][j].y != -1)
            {
                // offset on unpair
                // position on window
                if(i%2==0)
                    m_tile.setPosition(j * 30, i * 8);
                else
                    m_tile.setPosition((j * 30)+15, (i * 8));

                // select tile in tileset
                m_tile.setTextureRect(sf::IntRect(m_map[i][j].x * 30, m_map[i][j].y * (20+4) , 30, 20));
                // draw tile
                window.draw(m_tile);
            }
        }
    }
}
