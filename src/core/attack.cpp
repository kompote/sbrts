#include "attack.h"

using namespace core;

Attack::Attack(Personality * npersonality, std::map<std::string, Knowledge> * nknowledges): Action(npersonality, nknowledges, std::string("Attack"))
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
