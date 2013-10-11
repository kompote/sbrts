#ifndef SPRITE_H
#define SPRITE_H

#include <SFML/Graphics.hpp>

class ImagedSprite : public sf::Sprite
{
    public:
        // default ctor, necessary.
        ImagedSprite();
        // ctor needing a reference to the texture, the sizes of the texture's part, the number of frame, the quantity of pixel separating each frame in the texture
        // and the time per frame
        ImagedSprite( sf::Texture& texture);
        virtual ~ImagedSprite();

        // draw
        // draw the sprite by selecting the sprite texture's part which must be displayed at this point
        // when sprite is over, next calling of this function without a reset will do nothing, except if loop is at true
        // declared virtual in order to use Sprite::draw behavior
        virtual void draw(sf::RenderTarget& window, sf::Vector2i center, float rotation, int frameDurationUS);


    protected:
    private:
};

#endif // SPRITE_H

