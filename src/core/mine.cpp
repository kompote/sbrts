#include "mine.h"

using namespace core;

Mine::Mine(Personality * personality, std::map<std::string, Knowledge> * knowledges): Action(personality, knowledges, std::string("Mine"))
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
