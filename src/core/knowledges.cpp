#include "knowledges.h"

using namespace core;
using namespace std;

Knowledges::Knowledges(std::map<std::string, Knowledge> knowledges): m_knowledges(knowledges)
{
    //ctor
}

Knowledges::Knowledges()
{
    //ctor
}

Knowledge Knowledges::getKnowledge(std::string name)
{
    
    if(this->m_knowledges.find(name) == this->m_knowledges.end()) return Knowledge(name,0);
    else return this->m_knowledges.at(name);
    
}

void Knowledges::setKnowledge(Knowledge knowledge)
{
    
    if(this->m_knowledges.find(knowledge.m_sName) == this->m_knowledges.end())
        this->m_knowledges.insert(pair<string, Knowledge>(knowledge.m_sName,knowledge));
    else this->m_knowledges.at(knowledge.m_sName).m_iLevel = knowledge.m_iLevel;
    
}

Knowledges::~Knowledges()
{
    //dtor
}
