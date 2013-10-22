#include "build.h"

using namespace core;

Build::Build(Personality * personality, Knowledges * knowledges): Action(personality, knowledges, std::string("Build"))
{
    //ctor
}

void Build::update_efficiency()
{
    
    m_fEfficiency =  (PERSONALITY_COEF*m_personality->getTrait("Strength").m_fValue+
            KNOWLEDGES_COEF*m_knowledges->getKnowledge("Engineering").m_iLevel) /
            (PERSONALITY_COEF*TRAIT_MAX_VALUE+KNOWLEDGES_COEF*KNOWLEDGE_MAX_VALUE);
    
}

Build::~Build()
{
    //dtor
}
