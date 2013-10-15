#include "search.h"

using namespace core;

Search::Search(Personality * personality, std::map<std::string, Knowledge> * knowledges): Action(personality, knowledges, std::string("Search"))
{
    //ctor
}

float Search::update_efficiency()
{
    return 0;
}

Search::~Search()
{
    //dtor
}
