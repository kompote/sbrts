#include "lumber.h"

using namespace core;

Lumber::Lumber(Personality * personality, Knowledges * knowledges): Action(personality, knowledges, std::string("Lumber"))
{
    //ctor
}

void Lumber::update_efficiency()
{
    
    m_fEfficiency =  (PERSONALITY_COEF*m_personality->getTrait("Strength").m_fValue+
            KNOWLEDGES_COEF*m_knowledges->getKnowledge("Lumbering").m_iLevel) /
            (PERSONALITY_COEF*TRAIT_MAX_VALUE+KNOWLEDGES_COEF*KNOWLEDGE_MAX_VALUE);

}

Lumber::~Lumber()
{
    //dtor
}
