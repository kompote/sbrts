#include "heal.h"

using namespace core;

Heal::Heal(Personality * personality, Knowledges * knowledges): Action(personality, knowledges, std::string("Heal"))
{
    //ctor
}

void Heal::update_efficiency()
{
    
    m_fEfficiency = (PERSONALITY_COEF*m_personality->getTrait("Intelligence").m_fValue+
            KNOWLEDGES_COEF*m_knowledges->getKnowledge("Medicine").m_iLevel) /
            (PERSONALITY_COEF*TRAIT_MAX_VALUE+KNOWLEDGES_COEF*KNOWLEDGE_MAX_VALUE);
    
}

Heal::~Heal()
{
    //dtor
}
