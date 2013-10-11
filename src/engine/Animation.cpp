#include "Animation.h"
#include <iostream>

// default ctor
Animation::Animation() : sf::Sprite()
{
    //ctor
}
// ctor needing a reference to the texture, the sizes of the texture's part, the number of frame, the quantity of pixel separating each frame in the texture
// and the time per frame
Animation::Animation( sf::Texture& animationTexture, int textureWidth, int textureHeight, int nbFrame, int nbPixelFrameSeparation, int timePerFrameUS) : sf::Sprite()
{
    //ctor
    this->setTexture(animationTexture);
    this->m_animationTexture = animationTexture;
    this->m_iTextureWidth = textureWidth;
    this->m_iTextureHeight = textureHeight;
    this->m_iNbFrame = nbFrame;
    this->m_iNbPixelFrameSeparation = nbPixelFrameSeparation;
    this->m_iTimePerFrameUS = timePerFrameUS;

    this->m_iTimePassedUS = 0;
    this->m_bStop = false;
}
// copy ctor
Animation::Animation( const Animation& copie ) : sf::Sprite()
{
    //ctor
    this->setTexture(copie.m_animationTexture);
    this->m_animationTexture = copie.m_animationTexture;
    this->m_iTextureWidth = copie.m_iTextureWidth;
    this->m_iTextureHeight = copie.m_iTextureHeight;
    this->m_iNbFrame = copie.m_iNbFrame;
    this->m_iNbPixelFrameSeparation = copie.m_iNbPixelFrameSeparation;
    this->m_iTimePerFrameUS = copie.m_iTimePerFrameUS;

    this->m_iTimePassedUS = 0;
    this->m_bStop = false;
}

Animation::~Animation()
{
    //dtor
}


// draw
// draw the animation by selecting the animation texture's part which must be displayed at this point
// when animation is over, next calling of this function without a reset will do nothing, except if loop is at true
// declared virtual in order to use Sprite::draw behavior
void Animation::draw(sf::RenderTarget& window, sf::Vector2i center, float rotation, int frameDurationUS)
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
bool Animation::isStopped(){
    return m_bStop;
}
void Animation::reset()
{
    m_iTimePassedUS = 0;
    m_bStop = false;
}
void Animation::setLoop(bool loop)
{
    this->m_bLoop = loop;
}


// setters
void Animation::setAnimationTexture( sf::Texture& animationTexture)
{
    this->setTexture(animationTexture);
}
void Animation::setTextureWidth( int textureWidth)
{
    this->m_iTextureWidth = textureWidth;
}
void Animation::setTextureHeight( int textureHeight)
{
    this->m_iTextureHeight = textureHeight;
}
void Animation::setNbFrame( int nbFrame )
{
    this->m_iNbFrame = nbFrame;
}
void Animation::setNbPixelFrameSeparation( int nbPixelFrameSeparation )
{
    this->m_iNbPixelFrameSeparation = nbPixelFrameSeparation;
}
void Animation::setTimePerFrameUS( int timePerFrameUS )
{
    this->m_iTimePerFrameUS = timePerFrameUS;
}
