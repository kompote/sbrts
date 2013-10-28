#include "concretemap.h"
#include "abstractmap.h"
#include "../../utils/logger.h"

ConcreteMap::ConcreteMap() : m_oRShape(), m_oAbstractMap(), m_oPShape()
{
    m_uiMapH = 10;
    m_uiMapW = 10;
    m_oRShape.setSize(sf::Vector2f(30,30));
    m_oRShape.setOutlineColor(sf::Color(150,150,150,255));
    m_oRShape.setFillColor(sf::Color(250,250,250,200));
    m_oRShape.setOutlineThickness(2.0);

    m_oPShape.setOutlineColor(sf::Color(150,150,150,255));
    m_oPShape.setFillColor(sf::Color(250,250,250,200));
    m_oPShape.setOutlineThickness(1.0);
    m_oPShape.setPointCount(4);
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

// ----------------------------------------------------------------- setViewSize
void ConcreteMap::setViewSize(unsigned int viewX, unsigned int viewY)
{
    m_uiViewWidth = viewX;
    m_uiViewHeight = viewY;
}

void ConcreteMap::drawAbstract(sf::RenderTarget& target, unsigned int fromX, unsigned int fromY)
{
    // compute draw needin size
    unsigned int maxW = ((fromX + m_uiViewWidth)/30) + 2;
    unsigned int maxH = ((fromY + m_uiViewHeight)/30) + 2;
    int startX = (fromX / 30) - 2;
    int startY = (fromY / 30 ) - 2;

    // limit to map size
    if ( maxH > m_oAbstractMap.polyList.size() )
        maxH = m_uiViewHeight;
    if ( maxW > m_oAbstractMap.polyList[0].size() )
        maxW = m_uiViewWidth;
    if (startX < 0)
        startX = 0;
    if (startY < 0)
        startY = 0;

    for(unsigned int i = startY; i < maxH; i++)
    {
        for(unsigned int j = startX; j < maxW; j++)
        {
            m_oPShape.setPoint(0,sf::Vector2f(m_oAbstractMap.polyList[i][j].topLeft.x, m_oAbstractMap.polyList[i][j].topLeft.y));
            m_oPShape.setPoint(1,sf::Vector2f(m_oAbstractMap.polyList[i][j].botLeft.x, m_oAbstractMap.polyList[i][j].botLeft.y));
            m_oPShape.setPoint(2,sf::Vector2f(m_oAbstractMap.polyList[i][j].botRight.x, m_oAbstractMap.polyList[i][j].botRight.y));
            m_oPShape.setPoint(3,sf::Vector2f(m_oAbstractMap.polyList[i][j].topRight.x, m_oAbstractMap.polyList[i][j].topRight.y));
            if(!m_oAbstractMap.polyList[i][j].walkable)
                m_oPShape.setFillColor(sf::Color(120,120,120,255));
            else
                m_oPShape.setFillColor(sf::Color(250,250,250,200));

            target.draw(m_oPShape);
        }
    }
}

void ConcreteMap::containsTest(unsigned int x, unsigned int y)
{
    
    for(const auto& itY: m_oAbstractMap.polyList)
    {
        for(const auto& it: itY)
        {
        if(m_oAbstractMap.contains(it, {x,y}))
            DBG_WARN(" CONTAINS ");
        }
    } 
}
