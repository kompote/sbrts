#include "attack.h"
#include "unitai.h"

using namespace core;
using namespace std;

Attack::Attack(Personality * personality, Knowledges * knowledges): Action(personality, knowledges, std::string("Attack"))
{
    //ctor
}

void Attack::update_efficiency()
{
    
    m_fEfficiency = (PERSONALITY_COEF*m_personality->getTrait("Strength").m_fValue+
            KNOWLEDGES_COEF*m_knowledges->getKnowledge("Military").m_iLevel) /
            (PERSONALITY_COEF*TRAIT_MAX_VALUE+KNOWLEDGES_COEF*KNOWLEDGE_MAX_VALUE);
    
}

Attack::~Attack()
{
    //dtor
}

bool Attack::setTarget(Entity * target){
    
    Action::setTarget(target);
    if( dynamic_cast<UnitAI*>(target) == NULL ) return false;
    else return true;
    
}
