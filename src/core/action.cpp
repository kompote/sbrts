#include "action.h"

using namespace core;

Action::Action(Personality * personality, std::map<std::string, Knowledge> * knowledges, std::string name): m_sName(name)
{

    this->m_personality = personality;
    this->m_knowledges = knowledges;

}

Action::~Action()
{
    //dtor
}

float Action::update_efficiency()
{
    return 0;
}
