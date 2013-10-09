#include "advMap.h"
#include<iostream>
#include<fstream>
#include<cctype>
#include<string>
#include<vector>

#include "../utils/logger.h"

AdvMap::AdvMap():m_map(), m_tiles(),m_tileTexture()
{}

AdvMap::~AdvMap()
{}

// ------------------------------------------------------------------- LoadMap
// To load a map
// map name = map install folder
// return an error if load failed
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
        m_tiles.setTexture(m_tileTexture);

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

// ----------------------------------------------------------------- redraw
void AdvMap::redraw(RenderTarget& window)
{

    for(unsigned int i = 0; i < m_map.size(); i++)
    {
        for(unsigned int j = 0; j < m_map[i].size(); j++)
        {
            if(m_map[i][j].x != -1 && m_map[i][j].y != -1)
            {
                // offset on unpair
                // position on window
                if(i%2==0)
                    m_tiles.setPosition(j * 30, i * 8);
                else
                    m_tiles.setPosition((j * 30)+15, (i * 8));

                // select tile in tileset
                m_tiles.setTextureRect(sf::IntRect(m_map[i][j].x * 30, m_map[i][j].y * (20+4) , 30, 20));
//              cout<<" coord map : " << j*16 << ":" << i*16 << "   tile coords : " << m_map[i][j].x*32 << ":" <<  m_map[i][j].y*32 << endl;
                window.draw(m_tiles);
            }
        }
    }
}
