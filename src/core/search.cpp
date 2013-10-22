#include "search.h"

using namespace core;

Search::Search(Personality * personality, Knowledges * knowledges): Action(personality, knowledges, std::string("Search"))
{
    //ctor
}

void Search::update_efficiency()
{
    
    m_fEfficiency =  (PERSONALITY_COEF*m_personality->getTrait("Intelligence").m_fValue+
            KNOWLEDGES_COEF*m_knowledges->getKnowledge("Research").m_iLevel) /
            (PERSONALITY_COEF*TRAIT_MAX_VALUE+KNOWLEDGES_COEF*KNOWLEDGE_MAX_VALUE);

}

Search::~Search()
{
    //dtor
}
