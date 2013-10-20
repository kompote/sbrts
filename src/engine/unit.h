#ifndef UNIT_H
#define UNIT_H

#include <SFML/Graphics.hpp>
#include "AnimatedTexture.h"
#include "GameSprite.h"


class Unit : public GameSprite
{
 public:
	Unit(Component* parent, float xCenterPos, float yCenterPos);
	virtual ~Unit();

	void defineAnimations();

	void updateSpecific(int gameFps);

	void select();
	void unSelect();


 protected:
 private:
	bool m_bSelected;

};

#endif // UNIT_H
