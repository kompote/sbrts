#include "Animation.h"
#include <iostream>

// default ctor
Animation::Animation()
{
    //ctor
}
// ctor needing a reference to the texture, the sizes of the texture's part, the number of frame, the quantity of pixel separating each frame in the texture
// and the time per frame
Animation::Animation( sf::Texture& animationTexture, int textureWidth, int textureHeight, int nbFrame, int nbPixelFrameSeparation, int timePerFrameUS)
{
    //ctor
    this->setTexture(animationTexture);
    this->animationTexture = animationTexture;
    this->textureWidth = textureWidth;
    this->textureHeight = textureHeight;
    this->nbFrame = nbFrame;
    this->nbPixelFrameSeparation = nbPixelFrameSeparation;
    this->timePerFrameUS = timePerFrameUS;

    this->timePassedUS = 0;
    this->stop = false;
}
// copy ctor
Animation::Animation( const Animation& copie )
{
    //ctor
    this->setTexture(copie.animationTexture);
    this->animationTexture = copie.animationTexture;
    this->textureWidth = copie.textureWidth;
    this->textureHeight = copie.textureHeight;
    this->nbFrame = copie.nbFrame;
    this->nbPixelFrameSeparation = copie.nbPixelFrameSeparation;
    this->timePerFrameUS = copie.timePerFrameUS;

    this->timePassedUS = 0;
    this->stop = false;
}

Animation::~Animation()
{
    //dtor
}


// draw
// draw the animation by selecting the animation texture's part which must be displayed at this point
// when animation is over, next calling of this function without a reset will do nothing, except if loop is at true
// declared virtual in order to use Sprite::draw behavior
void Animation::draw(sf::RenderTarget& window, int xPos, int yPos, int frameDurationUS)
{
    int frameNb;
    // momerize time passed
    timePassedUS += frameDurationUS;
    // compote the frame number depending on time passed
    frameNb = timePassedUS/timePerFrameUS;

    // if animation is over and loop is false, set stop and draw nothing
    if( frameNb+1 > nbFrame && !loop){
        stop = true;
    }
    // else, draw animation
    else{
        // if end of animation reached and loop is true, reset the animation
        if( loop && frameNb+1 > nbFrame ){
            this->reset();
            frameNb = 0;
        }
        // set the texture's part to display
        this->setTextureRect(
            sf::IntRect(
                (textureWidth+nbPixelFrameSeparation)*frameNb,
                0 ,
                textureWidth,
                textureHeight));
        // set the position of the animation
        this->setPosition(xPos,yPos);
        // draw...
        window.draw( sf::Sprite(*this));
    }
}
bool Animation::isStopped(){
    return stop;
}
void Animation::reset()
{
    timePassedUS = 0;
    stop = false;
}
void Animation::setLoop(bool loop)
{
    this->loop = loop;
}


// setters
void Animation::setAnimationTexture( sf::Texture& animationTexture)
{
    this->setTexture(animationTexture);
}
void Animation::setTextureWidth( int textureWidth)
{
    this->textureWidth = textureWidth;
}
void Animation::setTextureHeight( int textureHeight)
{
    this->textureHeight = textureHeight;
}
void Animation::setNbFrame( int nbFrame )
{
    this->nbFrame = nbFrame;
}
void Animation::setNbPixelFrameSeparation( int nbPixelFrameSeparation )
{
    this->nbPixelFrameSeparation = nbPixelFrameSeparation;
}
void Animation::setTimePerFrameUS( int timePerFrameUS )
{
    this->timePerFrameUS = timePerFrameUS;
}
