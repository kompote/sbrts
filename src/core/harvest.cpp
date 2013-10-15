#include "harvest.h"

using namespace core;

Harvest::Harvest(Personality * personality, std::map<std::string, Knowledge> * knowledges): Action(personality, knowledges, std::string("Harvest"))
{
    //ctor
}

float Harvest::update_efficiency()
{
    return 0;
}

Harvest::~Harvest()
{
    //dtor
}
