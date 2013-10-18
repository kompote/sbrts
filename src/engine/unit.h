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
  sf::Vector2i& getPosition();
  void setPosition(sf::Vector2i position);
  void select();
  void unSelect();


 protected:
 private:
  AnimatedSprite m_oAnim;
  sf::Vector2i m_vPosition;
  bool m_bSelected;

};

#endif // UNIT_H
