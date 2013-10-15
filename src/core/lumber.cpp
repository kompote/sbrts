#include "lumber.h"

using namespace core;

Lumber::Lumber(Personality * personality, std::map<std::string, Knowledge> * knowledges): Action(personality, knowledges, std::string("Lumber"))
{
    //ctor
}

float Lumber::update_efficiency()
{
    return 0;
}

Lumber::~Lumber()
{
    //dtor
}
