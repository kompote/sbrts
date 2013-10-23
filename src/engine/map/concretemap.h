#ifndef CONCRETEMAP_H
#define CONCRETEMAP_H
#include <SFML/Graphics.hpp>
#include "abstractmap.h"

class ConcreteMap
{
    private:
        unsigned int m_uiMapH;
        unsigned int m_uiMapW;
        sf::RectangleShape m_oRShape;
        AbstractMap m_oAbstractMap;
    protected:
    public:
        ConcreteMap();
        ~ConcreteMap();

        void draw(sf::RenderTarget& target);

};
#endif
