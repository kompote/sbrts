#include "heal.h"

using namespace core;

Heal::Heal(Personality * personality, std::map<std::string, Knowledge> * knowledges): Action(personality, knowledges, std::string("Heal"))
{
    //ctor
}

float Heal::update_efficiency()
{
    return 0;
}

Heal::~Heal()
{
    //dtor
}
