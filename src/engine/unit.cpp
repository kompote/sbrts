#include "unit.h"
#include "RessourceManager.h"
#include <iostream>

#include "../utils/logger.h"

Unit::Unit():
    m_vPosition()
{
    m_oAnim = AnimatedSprite(ressourceManager.getAnimation("campfire1"));
    m_oAnim.setLoop(true);

    m_bSelected = false;
 //ctor
}

Unit::~Unit()
{
 //dtor
}

void Unit::Redraw(sf::RenderTarget& window)
{
    m_oAnim.draw( window, m_vPosition, 0, 50);
}

sf::Vector2i& Unit::getPosition()
{
    return m_vPosition;
}

void Unit::setPosition(sf::Vector2i position)
{
    m_vPosition = position;
}

void Unit::select()
{
    m_bSelected = true;
    debug("Selected");
}

void Unit::unSelect()
{
    if (m_bSelected)
    {
        debug("Unselected");
        m_bSelected = false;
    }
}
