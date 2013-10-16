#include "personality.h"

using namespace core;
using namespace std;

Personality::Personality(std::map<std::string, Trait> traits): m_traits(traits)
{
    //ctor
}

Personality::~Personality()
{
    //dtor
}

Trait Personality::getTrait(std::string name)
{

    if(this->m_traits.find(name) == this->m_traits.end()) return Trait(name,0);
    else return this->m_traits.at(name);

}

void Personality::setTrait(Trait trait)
{

    if(this->m_traits.find(trait.m_sName) == this->m_traits.end())
        this->m_traits.insert(pair<string, Trait>(trait.m_sName,trait));
    else this->m_traits.at(trait.m_sName).m_fValue = trait.m_fValue;

}
