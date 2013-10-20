/*
 * Component.cpp
 *
 *  Created on: 18 oct. 2013
 *      Author: ijatsu
 */

#include "Component.h"

//Component::Component(Component& parent, sf::Vector2f center, sf::Vector2f position, int width, int height ) {
Component::Component(Component* parent){
	m_parent = parent;
	setVisible(false);
}
Component::~Component() {

}



void Component::setVisible(bool visible){
	m_bVisible = visible;
	if( m_bVisible){
		// suscribing to render manager ect...
	}
	else{
		// unsuscribing to render manager ect...
	}
}
bool Component::isVisible() const{
	return m_bVisible;
}

void Component::update(int gameFps){
	if( isVisible() ){
		this->updateSpecific(gameFps);
	}
}



