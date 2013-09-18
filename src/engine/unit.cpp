#include "unit.h"

Unit::Unit()
{
  m_tileTexture.loadFromFile("resources/campfire1.png");
  m_tiles.setTexture(m_tileTexture);
  animFrameN = 0;
  m_tiles.setPosition(200, 200);
 //ctor
}

Unit::~Unit()
{
 //dtor
}

void Unit::Redraw(sf::RenderTarget& window)
{
  m_tiles.setTextureRect(sf::IntRect(34*animFrameN++,0 , 33, 37));
  if (animFrameN > 3)
    animFrameN = 0;
  window.draw(m_tiles);

}
