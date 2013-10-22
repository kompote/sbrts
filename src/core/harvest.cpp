#include "harvest.h"

using namespace core;

Harvest::Harvest(Personality * personality, Knowledges * knowledges): Action(personality, knowledges, std::string("Harvest"))
{
    //ctor
}

void Harvest::update_efficiency()
{
    
    m_fEfficiency = (PERSONALITY_COEF*m_personality->getTrait("Ability").m_fValue+
            KNOWLEDGES_COEF*m_knowledges->getKnowledge("Farming").m_iLevel) /
            (PERSONALITY_COEF*TRAIT_MAX_VALUE+KNOWLEDGES_COEF*KNOWLEDGE_MAX_VALUE);
    
}

Harvest::~Harvest()
{
    //dtor
}
