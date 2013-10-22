#include "unit.h"
#include "RessourceManager.h"
#include <iostream>

#include "../utils/logger.h"

Unit::Unit(Component* parent, float xCenterPos, float yCenterPos): GameSprite( parent, xCenterPos, yCenterPos)
{
	this->defineAnimations();
	setState(0);
    //m_oAnim = AnimatedTexture(resourceManager.getAnimation("campfire1"));
    //m_oAnim.setLoop(true);
    m_bSelected = false;

 //ctor
}
Unit::~Unit()
{
 //dtor
}

void Unit::defineAnimations(){
	int i=0;

	m_animations[0]= AnimatedTexture(resourceManager.getAnimation("campfire1"));
	m_animations[0].setLoop(true);
}


void Unit::updateSpecific(int gameFps) {
}


void Unit::select()
{
    m_bSelected = true;
    debug("Selected");
}

void Unit::unSelect()
{
    if (m_bSelected)
    {
        debug("Unselected");
        m_bSelected = false;
    }
}

