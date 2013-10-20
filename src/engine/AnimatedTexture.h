#ifndef ANIMATION_H
#define ANIMATION_H

#include <SFML/Graphics.hpp>

class AnimatedTexture
{
public:
	AnimatedTexture();
	// ctor needing a reference to the texture, the sizes of the texture's part, the number of frame, the quantity of pixel separating each frame in the texture
	// and the time per frame
	AnimatedTexture( sf::Texture& animationTexture, int textureWidth, int textureHeight, int nbFrame, int nbPixelFrameSeparation, int timePerFrameUS);
	// copy ctor
	AnimatedTexture( const AnimatedTexture& copie );
	virtual ~AnimatedTexture();

	// draw
	// draw the animation by selecting the animation texture's part which must be displayed at this point
	// when animation is over, next calling of this function without a reset will do nothing, except if loop is at true
	// declared virtual in order to use Sprite::draw behavior
	void setTextureRect(sf::Sprite& sprite, int frameDurationUS);
	sf::Texture& getTexture();
	void reset();

	const sf::Texture* getAnimationTexture() const;
	bool isLoop() const;
	void setLoop(bool loop);
	bool isStop() const;
	void setStop(bool stop);
	float getTextureRotation() const;
	void setTextureRotation(float textureRotation);
	int getNbFrame() const;
	void setNbFrame(int nbFrame);
	int getNbPixelFrameSeparation() const;
	void setNbPixelFrameSeparation(int nbPixelFrameSeparation);
	int getTextureHeight() const;
	void setTextureHeight(int textureHeight);
	int getTextureWidth() const;
	void setTextureWidth(int textureWidth);
	int getTimePassedUs() const;
	void setTimePassedUs(int timePassedUs);
	int getTimePerFrameUs() const;
	void setTimePerFrameUs(int timePerFrameUs);

protected:
	sf::Texture* m_animationTexture;
	int m_iTextureWidth;
	int m_iTextureHeight;
	int m_iNbFrame;
	int m_iNbPixelFrameSeparation;
	int m_iTimePerFrameUS;
	bool m_bLoop;

	float m_fTextureRotation;
	int m_iTimePassedUS;
	bool m_bStop;

private:
};

#endif // ANIMATION_H
