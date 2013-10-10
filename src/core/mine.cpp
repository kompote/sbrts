#include "mine.h"

using namespace core;

Mine::Mine(Personality * npersonality, std::map<std::string, Knowledge> * nknowledges): Action(npersonality, nknowledges, std::string("Mine"))
{
    //ctor
}

float Mine::update_efficiency()
{
    return 0;
}

Mine::~Mine()
{
    //dtor
}
