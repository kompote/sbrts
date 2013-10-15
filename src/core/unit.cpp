#include "unit.h"

using namespace core;

core::Unit::Unit(std::pair<float,float> position, std::map<std::string, Trait> traits): Entity(std::string("Unit"), position), m_personality(traits)
{

}

core::Unit::~Unit()
{
    //dtor
}
