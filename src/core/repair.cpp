#include "repair.h"

using namespace core;

Repair::Repair(Personality * npersonality, std::map<std::string, Knowledge> * nknowledges): Action(npersonality, nknowledges, std::string("Repair"))
{
    //ctor
}

float Repair::update_efficiency()
{
    return 0;
}

Repair::~Repair()
{
    //dtor
}
