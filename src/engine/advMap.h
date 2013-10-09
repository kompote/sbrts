#ifndef ADVMAP_H
#define ADVMAP_H

#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;

class AdvMap
{
    public:
        AdvMap();
        ~AdvMap();
        unsigned char loadMap(string filename);
        void redraw(RenderTarget&);
    private:

    std::vector<std::vector<sf::Vector2i> > m_map;
    sf::Sprite m_tiles;
    sf::Texture m_tileTexture;

};

#endif
