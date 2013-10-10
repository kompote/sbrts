#include "action.h"

using namespace core;

Action::Action(Personality * npersonality, std::map<std::string, Knowledge> * nknowledges, std::string nname): name(nname)
{

    this->personality = npersonality;
    this->knowledges = nknowledges;

}

Action::~Action()
{
    //dtor
}

float Action::update_efficiency()
{
    return 0;
}
