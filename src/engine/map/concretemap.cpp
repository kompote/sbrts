#include "concretemap.h"
#include "abstractmap.h"
#include "../../utils/logger.h"

ConcreteMap::ConcreteMap() : m_oRShape(), m_oAbstractMap()
{
    m_uiMapH = 10;
    m_uiMapW = 10;
    m_oRShape.setSize(sf::Vector2f(30,30));
    m_oRShape.setOutlineColor(sf::Color(150,150,150,255));
    m_oRShape.setFillColor(sf::Color(250,250,250,200));
    m_oRShape.setOutlineThickness(2.0);
}


ConcreteMap::~ConcreteMap()
{}

void ConcreteMap::draw(sf::RenderTarget& target)
{
    int i = 20;
    for(const auto& it: m_oAbstractMap.m_SMapCaseList)
        {
            m_oRShape.setPosition(it.posX, it.posY);
            if(!it.walkable)
                m_oRShape.setFillColor(sf::Color(120,120,120,255));
            else
                m_oRShape.setFillColor(sf::Color(250,250,250,200));
            target.draw(m_oRShape);
        }

}
