#include "harvest.h"

using namespace core;

Harvest::Harvest(Personality * npersonality, std::map<std::string, Knowledge> * nknowledges): Action(npersonality, nknowledges, std::string("Harvest"))
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
