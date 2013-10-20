/*
 * GameSprite.cpp
 *
 *  Created on: 19 oct. 2013
 *      Author: ijatsu
 */

#include <iostream>
#include "GameSprite.h"

GameSprite::GameSprite(Component* parent, float xCenterPos, float yCenterPos) : Component(parent) {
	setPosition(xCenterPos - m_animations[m_iState].getTextureWidth()/2 , yCenterPos - m_animations[m_iState].getTextureHeight()/2);
	m_iState = 0;
}
GameSprite::~GameSprite() {
}

void GameSprite::draw(sf::RenderTarget& window, int frameDurationUS) {
    // set the texture's part to display
    //setTextureRect( m_animations[m_iState].getTextureRect(frameDurationUS));
	m_animations[m_iState].setTextureRect(*this,frameDurationUS);

    // draw...
    window.draw( *this);
}

void GameSprite::setState(int state) {
	m_iState = state;
	// set the texture depending of the state
	setTexture( *m_animations[m_iState].getAnimationTexture());
}
int GameSprite::getState() {
	return m_iState;
}
