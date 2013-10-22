#include "action.h"

using namespace core;

Action::Action(Personality * personality, Knowledges * knowledges, std::string name): m_sName(name)
{

    this->m_personality = personality;
    this->m_knowledges = knowledges;

}

Action::~Action()
{
    //dtor
}

void Action::update_efficiency()
{
    m_fEfficiency = 0;
}

float Action::getEfficiency(){
    
    return m_fEfficiency;
    
}

bool Action::setTarget(Entity * target){
    
    m_target = target;
    return true;
    
}

Entity * Action::getTarget(){
    
    return m_target;
    
}
