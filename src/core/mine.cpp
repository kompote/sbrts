#include "mine.h"

using namespace core;

Mine::Mine(Personality * personality, Knowledges * knowledges): Action(personality, knowledges, std::string("Mine"))
{
    //ctor
}

void Mine::update_efficiency()
{
        
    m_fEfficiency =  (PERSONALITY_COEF*m_personality->getTrait("Strength").m_fValue+
            KNOWLEDGES_COEF*m_knowledges->getKnowledge("Mining").m_iLevel) /
            (PERSONALITY_COEF*TRAIT_MAX_VALUE+KNOWLEDGES_COEF*KNOWLEDGE_MAX_VALUE);

}

Mine::~Mine()
{
    //dtor
}
