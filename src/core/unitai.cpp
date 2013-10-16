#include "unitai.h"

using namespace core;

core::UnitAI::UnitAI(std::pair<float,float> position, std::map<std::string, Trait> traits): Entity(std::string("Unit"), position), m_personality(traits)
{

}

core::UnitAI::~UnitAI()
{
    //dtor
}
