#include "unit.h"

using namespace core;

core::Unit::Unit(std::pair<float,float> position): Entity(std::string("Unit"), position)
{

}

core::Unit::~Unit()
{
    //dtor
}
