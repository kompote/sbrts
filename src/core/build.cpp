#include "build.h"

using namespace core;

Build::Build(Personality * npersonality, std::map<std::string, Knowledge> * nknowledges): Action(npersonality, nknowledges, std::string("Build"))
{
    //ctor
}

float Build::update_efficiency()
{
    return 0;
}

Build::~Build()
{
    //dtor
}
