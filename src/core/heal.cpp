#include "heal.h"

using namespace core;

Heal::Heal(Personality * npersonality, std::map<std::string, Knowledge> * nknowledges): Action(npersonality, nknowledges, std::string("Heal"))
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
