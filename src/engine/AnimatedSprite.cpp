#include "AnimatedSprite.h"
#include "RessourceManager.h"
#include <iostream>

// default ctor
AnimatedSprite::AnimatedSprite() : sf::Sprite()
{
    //ctor
}
// ctor needing a reference to the texture, the sizes of the texture's part, the number of frame, the quantity of pixel separating each frame in the texture
// and the time per frame
AnimatedSprite::AnimatedSprite( sf::Texture& animationTexture, int textureWidth, int textureHeight, int nbFrame, int nbPixelFrameSeparation, int timePerFrameUS) : sf::Sprite()
{
    //ctor
    this->setTexture(animationTexture);
    this->m_iTextureWidth = textureWidth;
    this->m_iTextureHeight = textureHeight;
    this->m_iNbFrame = nbFrame;
    this->m_iNbPixelFrameSeparation = nbPixelFrameSeparation;
    this->m_iTimePerFrameUS = timePerFrameUS;

    this->m_iTimePassedUS = 0;
    this->m_bStop = false;
}
// copy ctor
AnimatedSprite::AnimatedSprite( const AnimatedSprite& copie ) : sf::Sprite()
{
    //ctor
    this->setTexture(*copie.getTexture());
    this->m_iTextureWidth = copie.m_iTextureWidth;
    this->m_iTextureHeight = copie.m_iTextureHeight;
    this->m_iNbFrame = copie.m_iNbFrame;
    this->m_iNbPixelFrameSeparation = copie.m_iNbPixelFrameSeparation;
    this->m_iTimePerFrameUS = copie.m_iTimePerFrameUS;

    this->m_iTimePassedUS = 0;
    this->m_bStop = false;
}

AnimatedSprite::~AnimatedSprite()
{
    //dtor
}


// draw
// draw the animation by selecting the animation texture's part which must be displayed at this point
// when animation is over, next calling of this function without a reset will do nothing, except if loop is at true
// declared virtual in order to use Sprite::draw behavior
void AnimatedSprite::draw(sf::RenderTarget& window, sf::Vector2i center, float rotation, int frameDurationUS)
{
    int frameNb;
    // momerize time passed
    m_iTimePassedUS += frameDurationUS;
    // compote the frame number depending on time passed
    frameNb = m_iTimePassedUS/m_iTimePerFrameUS;

    // if animation is over and loop is false, set stop and draw nothing
    if( frameNb+1 > m_iNbFrame && !m_bLoop){
        m_bStop = true;
    }
    // else, draw animation
    else{
        // if end of animation reached and loop is true, reset the animation
        if( m_bLoop && frameNb+1 > m_iNbFrame ){
            this->reset();
            frameNb = 0;
        }
        // set the texture's part to display
        this->setTextureRect(
            sf::IntRect(
                (m_iTextureWidth+m_iNbPixelFrameSeparation)*frameNb,
                0 ,
                m_iTextureWidth,
                m_iTextureHeight));
        // set the position of the animation
        this->setRotation(rotation);
        this->setPosition( center.x - m_iTextureWidth/2 ,center.y - m_iTextureHeight/2);
        // draw...
        window.draw( *this);
    }
}
bool AnimatedSprite::isStopped(){
    return m_bStop;
}
void AnimatedSprite::reset()
{
    m_iTimePassedUS = 0;
    m_bStop = false;
}
void AnimatedSprite::setLoop(bool loop)
{
    this->m_bLoop = loop;
}

