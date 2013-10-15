#include "entity.h"

using namespace core;

Entity::Entity(std::string type, std::pair<float,float> position): m_sType(type)
{

    this->m_position = position;

}

Entity::~Entity()
{



}

std::pair<float,float> Entity::getPosition()
{

    return this->m_position;

}

void Entity::setPosition(std::pair<float,float> position){

    this->m_position = position;

}
