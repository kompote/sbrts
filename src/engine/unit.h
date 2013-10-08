#ifndef UNIT_H
#define UNIT_H

#include <SFML/Graphics.hpp>


class Unit// : public sf::Drawable, sf::Transformable
{
 public:
 Unit();
  virtual ~Unit();
  void Redraw(sf::RenderTarget& window);
  sf::Sprite m_tiles;
  sf::Texture m_tileTexture;
 protected:
 private:
   int animFrameN;
};

#endif // UNIT_H
