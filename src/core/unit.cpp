#include "unit.h"

Unit::Unit(std::pair<float,float> position)
{

    Entity::Entity(position, "Unit");

}

Unit::~Unit()
{
    //dtor
}
