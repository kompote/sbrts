#include "build.h"

using namespace core;

Build::Build(Personality * personality, std::map<std::string, Knowledge> * knowledges): Action(personality, knowledges, std::string("Build"))
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
