#ifndef CONCRETEMAP_H
#define CONCRETEMAP_H
#include <SFML/Graphics.hpp>
#include "abstractmap.h"

class ConcreteMap
{
    private:
        unsigned int m_uiMapH;
        unsigned int m_uiMapW;
        unsigned int m_uiViewHeight;
        unsigned int m_uiViewWidth;
        sf::RectangleShape m_oRShape;
        sf::ConvexShape m_oPShape;
        AbstractMap m_oAbstractMap;
    protected:
    public:
        ConcreteMap();
        ~ConcreteMap();

        void draw(sf::RenderTarget& target);
        void setViewSize(unsigned int, unsigned int);
        void drawAbstract(sf::RenderTarget& target, unsigned int fromX, unsigned int fromY);
        void containsTest(unsigned int x, unsigned int y);

};
#endif
