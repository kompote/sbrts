#ifndef UNIT_H
#define UNIT_H

#include <SFML/Graphics.hpp>
#include "AnimatedSprite.h"
#include "ImagedSprite.h"


class Unit// : public sf::Drawable, sf::Transformable
{
 public:
 Unit();
  virtual ~Unit();
  void Redraw(sf::RenderTarget& window);

  AnimatedSprite m_oAnim;
  ImagedSprite m_oSprite;

 protected:
 private:

};

#endif // UNIT_H
