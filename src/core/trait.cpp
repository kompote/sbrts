#include "trait.h"

using namespace core;

Trait::Trait(std::string name, float value): m_sName(name)
{

    this->m_fValue = value;

}

Trait::~Trait()
{
    //dtor
}
