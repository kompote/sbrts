#include "repair.h"

using namespace core;

Repair::Repair(Personality * personality, Knowledges * knowledges): Action(personality, knowledges, std::string("Repair"))
{
    //ctor
}

void Repair::update_efficiency()
{
    
    m_fEfficiency =  (PERSONALITY_COEF*m_personality->getTrait("Ability").m_fValue+
            KNOWLEDGES_COEF*m_knowledges->getKnowledge("Engineering").m_iLevel) /
            (PERSONALITY_COEF*TRAIT_MAX_VALUE+KNOWLEDGES_COEF*KNOWLEDGE_MAX_VALUE);
}

Repair::~Repair()
{
    //dtor
}
