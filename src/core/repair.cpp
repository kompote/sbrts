#include "repair.h"

using namespace core;

Repair::Repair(Personality * personality, std::map<std::string, Knowledge> * knowledges): Action(personality, knowledges, std::string("Repair"))
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
