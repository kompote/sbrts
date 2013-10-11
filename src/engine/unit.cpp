#include "unit.h"
#include "RessourceManager.h"
#include <iostream>


Unit::Unit()
{
    m_oAnim = AnimatedSprite(ressourceManager.getAnimation("campfire1"));
    m_oAnim.setLoop(true);
    m_oSprite.setTexture(ressourceManager.getTexture("campfire1.png"));
 //ctor
}

Unit::~Unit()
{
 //dtor
}

void Unit::Redraw(sf::RenderTarget& window)
{

    m_oAnim.draw( window, sf::Vector2i(200,100),180,50);
    m_oSprite.draw( window, sf::Vector2i(300,200), 90,50);
}
