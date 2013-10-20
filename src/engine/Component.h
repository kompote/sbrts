/*
 * Component.h
 *
 *  Created on: 18 oct. 2013
 *      Author: ijatsu
 */

#ifndef COMPONENT_H_
#define COMPONENT_H_

#include <SFML/Graphics.hpp>

class Component
{
public:
	Component(Component* parent);
	virtual ~Component();

	void setVisible(bool visible);
	bool isVisible() const;

	void update(int gameFps);
	virtual void updateSpecific(int gameFps) = 0;

protected:
	Component* m_parent;

private:

	bool m_bVisible;

};


#endif /* COMPONENT_H_ */
