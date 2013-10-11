#include "unit.h"
#include "RessourceManager.h"
#include <iostream>


Unit::Unit()
{
    m_oAnim = Animation(ressourceManager.getAnimation("campfire1"));
    m_oAnim.setLoop(true);
 //ctor
}

Unit::~Unit()
{
 //dtor
}

void Unit::Redraw(sf::RenderTarget& window)
{

    m_oAnim.draw( window, sf::Vector2i(200,100),180,50);
}
