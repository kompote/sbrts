/*
 * GameSprite.h
 *
 *  Created on: 19 oct. 2013
 *      Author: ijatsu
 */

#ifndef GAMESPRITE_H_
#define GAMESPRITE_H_

#include <SFML/Graphics.hpp>
#include <map>
#include "Component.h"
#include "AnimatedTexture.h"

class GameSprite : public sf::Sprite, public Component {
public:
	GameSprite(Component* parent, float xCenterPos, float yCenterPos);
	virtual ~GameSprite();

	void draw(sf::RenderTarget& window, int frameDurationUS);
	virtual void defineAnimations() = 0;

	void setState(int state);
	int getState();

protected:
	int m_iState;
	std::map<int,AnimatedTexture> m_animations;
private:
};

#endif /* GAMESPRITE_H_ */
