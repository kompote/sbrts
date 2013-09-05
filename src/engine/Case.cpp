#include "Case.h"

Case::Case(unsigned int id, unsigned int x, unsigned int y)
{
    m_texturePath = "resources/case.png";
    m_texture.loadFromFile(m_texturePath);
    m_sprite.setTexture(m_texture);
    m_id = id;
    m_transform.setPosition(x,y);
//    printf(" Create case %d", id);
}


Case::~Case()
{
}

void Case::Draw(RenderTarget& target) const
{
      target.draw(m_sprite, m_transform.getTransform());
}
