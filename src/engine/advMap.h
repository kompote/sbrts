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

        // ------------------------------------------------------------------- loadMap
        // To load a map
        // filename = map name = map install folder
        // return an error if load failed
        unsigned char loadMap(string filename);

        // ------------------------------------------------------------------- redraw
        // To redraw the map to the target
        // fromX, fromY : from where map must be draw, in pixel
        void redraw(RenderTarget&, unsigned int fromX, unsigned int fromY);

        // ------------------------------------------------------------------- setViewSize
        // To set the size of the map view
        // viewX, viewY : the width and height of the view, in pixel
        void setViewSize(unsigned int viewX, unsigned int viewY);
    private:

        // map definition matrix
        std::vector<std::vector<sf::Vector2i> > m_map;
        // working tile
        sf::Sprite m_tile;
        // working texture
        sf::Texture m_tileTexture;

        // map view size infos
        unsigned int m_uiViewWidth;
        unsigned int m_uiViewHeight;

};

#endif
