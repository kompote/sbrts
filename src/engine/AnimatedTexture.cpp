#include "AnimatedTexture.h"
#include "RessourceManager.h"
#include <iostream>

AnimatedTexture::AnimatedTexture()
{
	this->m_animationTexture = NULL;
}
// ctor needing a reference to the texture, the sizes of the texture's part, the number of frame, the quantity of pixel separating each frame in the texture
// and the time per frame
AnimatedTexture::AnimatedTexture( sf::Texture& animationTexture, int textureWidth, int textureHeight, int nbFrame, int nbPixelFrameSeparation, int timePerFrameUS)
{
    //ctor
	this->m_animationTexture= &animationTexture;
    this->m_iTextureWidth = textureWidth;
    this->m_iTextureHeight = textureHeight;
    this->m_iNbFrame = nbFrame;
    this->m_iNbPixelFrameSeparation = nbPixelFrameSeparation;
    this->m_iTimePerFrameUS = timePerFrameUS;

    this->m_fTextureRotation = 0;
    this->m_iTimePassedUS = 0;
    this->m_bStop = false;
    this->m_bLoop = false;
}
// copy ctor
AnimatedTexture::AnimatedTexture( const AnimatedTexture& copie )
{
    //ctor
	this->m_animationTexture= copie.m_animationTexture;
    this->m_iTextureWidth = copie.m_iTextureWidth;
    this->m_iTextureHeight = copie.m_iTextureHeight;
    this->m_iNbFrame = copie.m_iNbFrame;
    this->m_iNbPixelFrameSeparation = copie.m_iNbPixelFrameSeparation;
    this->m_iTimePerFrameUS = copie.m_iTimePerFrameUS;

    this->m_fTextureRotation = 0;
    this->m_iTimePassedUS = 0;
    this->m_bStop = false;
    this->m_bLoop = false;
}

AnimatedTexture::~AnimatedTexture()
{
    //dtor
}


// draw
// draw the animation by selecting the animation texture's part which must be displayed at this point
// when animation is over, next calling of this function without a reset will do nothing, except if loop is at true
// declared virtual in order to use Sprite::draw behavior
void AnimatedTexture::setTextureRect(sf::Sprite& sprite, int frameDurationUS)
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


        sprite.setTextureRect( sf::IntRect((m_iTextureWidth + m_iNbPixelFrameSeparation )*frameNb, 0, m_iTextureWidth, m_iTextureHeight));
    }
}
sf::Texture& AnimatedTexture::getTexture(){
	return *m_animationTexture;
}
void AnimatedTexture::reset()
{
    m_iTimePassedUS = 0;
    m_bStop = false;
}




const sf::Texture* AnimatedTexture::getAnimationTexture() const {		return m_animationTexture;	}
bool AnimatedTexture::isLoop() const {		return m_bLoop;	}
void AnimatedTexture::setLoop(bool loop) {		m_bLoop = loop;	}
bool AnimatedTexture::isStop() const {		return m_bStop;	}
void AnimatedTexture::setStop(bool stop) {		m_bStop = stop;	}
float AnimatedTexture::getTextureRotation() const {		return m_fTextureRotation;	}
void AnimatedTexture::setTextureRotation(float textureRotation) {		m_fTextureRotation = textureRotation;	}
int AnimatedTexture::getNbFrame() const {		return m_iNbFrame;	}
void AnimatedTexture::setNbFrame(int nbFrame) {		m_iNbFrame = nbFrame;	}
int AnimatedTexture::getNbPixelFrameSeparation() const {		return m_iNbPixelFrameSeparation;	}
void AnimatedTexture::setNbPixelFrameSeparation(int nbPixelFrameSeparation) {		m_iNbPixelFrameSeparation = nbPixelFrameSeparation;	}
int AnimatedTexture::getTextureHeight() const {		return m_iTextureHeight;	}
void AnimatedTexture::setTextureHeight(int textureHeight) {		m_iTextureHeight = textureHeight;	}
int AnimatedTexture::getTextureWidth() const {		return m_iTextureWidth;	}
void AnimatedTexture::setTextureWidth(int textureWidth) {		m_iTextureWidth = textureWidth;	}
int AnimatedTexture::getTimePassedUs() const {		return m_iTimePassedUS;	}
void AnimatedTexture::setTimePassedUs(int timePassedUs) {		m_iTimePassedUS = timePassedUs;	}
int AnimatedTexture::getTimePerFrameUs() const {		return m_iTimePerFrameUS;	}
void AnimatedTexture::setTimePerFrameUs(int timePerFrameUs) {		m_iTimePerFrameUS = timePerFrameUs;	}


