#include "lumber.h"

using namespace core;

Lumber::Lumber(Personality * npersonality, std::map<std::string, Knowledge> * nknowledges): Action(npersonality, nknowledges, std::string("Lumber"))
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
