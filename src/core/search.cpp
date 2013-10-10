#include "search.h"

using namespace core;

Search::Search(Personality * npersonality, std::map<std::string, Knowledge> * nknowledges): Action(npersonality, nknowledges, std::string("Search"))
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
