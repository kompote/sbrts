#ifndef ANIMATION_H
#define ANIMATION_H

#include <SFML/Graphics.hpp>

class Animation : public sf::Sprite
{
    public:
        // default ctor, necessary.
        Animation();
        // ctor needing a reference to the texture, the sizes of the texture's part, the number of frame, the quantity of pixel separating each frame in the texture
        // and the time per frame
        Animation( sf::Texture& animationTexture, int textureWidth, int textureHeight, int nbFrame, int nbPixelFrameSeparation, int timePerFrameUS);
        // copy ctor
        Animation( const Animation& copie );
        virtual ~Animation();

        // draw
        // draw the animation by selecting the animation texture's part which must be displayed at this point
        // when animation is over, next calling of this function without a reset will do nothing, except if loop is at true
        // declared virtual in order to use Sprite::draw behavior
        virtual void draw(sf::RenderTarget& window, sf::Vector2i center, float rotation, int frameDurationUS);
        bool isStopped();
        void reset();
        void setLoop(bool m_bLoop);

        // setters
        void setAnimationTexture( sf::Texture& animationTexture);
        void setTextureWidth( int textureWidth);
        void setTextureHeight( int textureHeight);
        void setNbFrame( int nbFrame );
        void setNbPixelFrameSeparation( int nbPixelFrameSeparation );
        void setTimePerFrameUS( int timePerFrameUS );

    protected:
        sf::Texture m_animationTexture;
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
