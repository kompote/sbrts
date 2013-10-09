#ifndef UNIT_H
#define UNIT_H

#include <SFML/Graphics.hpp>
#include "Animation.h"


class Unit// : public sf::Drawable, sf::Transformable
{
 public:
 Unit();
  virtual ~Unit();
  void Redraw(sf::RenderTarget& window);

  Animation m_oAnim;

 protected:
 private:

};

#endif // UNIT_H
