#include "attack.h"

using namespace core;

Attack::Attack(Personality * personality, std::map<std::string, Knowledge> * knowledges): Action(personality, knowledges, std::string("Attack"))
{
    //ctor
}

float Attack::update_efficiency()
{
    return 0;
}

Attack::~Attack()
{
    //dtor
}
