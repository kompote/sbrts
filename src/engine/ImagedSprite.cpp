#include "ImagedSprite.h"
#include <iostream>

// default ctor
ImagedSprite::ImagedSprite() : sf::Sprite()
{
    //ctor
}
// ctor needing a reference to the texture, the sizes of the texture's part, the number of frame, the quantity of pixel separating each frame in the texture
// and the time per frame
ImagedSprite::ImagedSprite( sf::Texture& animationTexture) : sf::Sprite()
{
    //ctor
    this->setTexture(animationTexture);
}
ImagedSprite::~ImagedSprite()
{
    //dtor
}


// draw
// draw the sprite by selecting the sprite texture's part which must be displayed at this point
// when sprite is over, next calling of this function without a reset will do nothing, except if loop is at true
// declared virtual in order to use Sprite::draw behavior
void ImagedSprite::draw(sf::RenderTarget& window, sf::Vector2i center, float rotation, int frameDurationUS)
{
    sf::Vector2u textureSize = getTexture()->getSize();
    // set the position of the sprite
    this->setRotation(rotation);
    this->setPosition( center.x - textureSize.x/2 ,center.y - textureSize.y/2);
    // draw...
    window.draw( *this);

}
