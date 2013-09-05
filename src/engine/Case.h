#ifndef CASE_H
#define CASE_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

using namespace sf;
using namespace std;

class Case
{
    private:
        unsigned int m_id;
        string m_texturePath;
        Texture m_texture;
        Transformable m_transform;
        Sprite m_sprite;

    public:
        Case(unsigned int id, unsigned int x, unsigned int y);
        ~Case();
        void Draw(RenderTarget& target) const;

};
#endif
