#include "entity.h"

using namespace core;

Entity::Entity(std::string ntype, std::pair<float,float> position): type(ntype)
{

    this->position = position;

}

Entity::~Entity()
{



}

std::pair<float,float> Entity::getPosition()
{

    return this->position;

}

void Entity::setPosition(std::pair<float,float> position){

    this->position = position;

}
