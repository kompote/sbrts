#include "unitai.h"

#include "attack.h"
#include "build.h"
#include "harvest.h"
#include "heal.h"
#include "lumber.h"
#include "mine.h"
#include "repair.h"
#include "search.h"

#include <algorithm>
#include <vector>

using namespace core;
using namespace std;

bool sortActionsByEfficiency(Action * a, Action * b){
    
    return (a->getEfficiency() > b->getEfficiency());
    
}

UnitAI::UnitAI(std::pair<float,float> position, std::map<std::string, Trait> traits, unsigned int id, EntityManager * entityManager): Entity(std::string("Unit"), position, id, entityManager), m_personality(traits)
{

    m_actions.insert(pair<string,Action>("Attack", Attack(&m_personality,&m_knowledges)));
    m_actions.insert(pair<string,Action>("Build", Build(&m_personality,&m_knowledges)));
    m_actions.insert(pair<string,Action>("Harvest", Harvest(&m_personality,&m_knowledges)));
    m_actions.insert(pair<string,Action>("Heal", Heal(&m_personality,&m_knowledges)));
    m_actions.insert(pair<string,Action>("Lumber", Lumber(&m_personality,&m_knowledges)));
    m_actions.insert(pair<string,Action>("Mine", Mine(&m_personality,&m_knowledges)));
    m_actions.insert(pair<string,Action>("Repair", Repair(&m_personality,&m_knowledges)));
    m_actions.insert(pair<string,Action>("Search", Search(&m_personality,&m_knowledges)));
    
    m_actionsOrder.push_back(&(m_actions.at("Attack")));
    m_actionsOrder.push_back(&(m_actions.at("Build")));
    m_actionsOrder.push_back(&(m_actions.at("Harvest")));
    m_actionsOrder.push_back(&(m_actions.at("Heal")));
    m_actionsOrder.push_back(&(m_actions.at("Lumber")));
    m_actionsOrder.push_back(&(m_actions.at("Mine")));
    m_actionsOrder.push_back(&(m_actions.at("Repair")));
    m_actionsOrder.push_back(&(m_actions.at("Search")));
    
}

UnitAI::~UnitAI()
{
    //dtor
}

void UnitAI::updateOrder(){
    
    sort(m_actionsOrder.begin(),m_actionsOrder.end(),sortActionsByEfficiency);
    
}

void UnitAI::think(){
    
    switch(m_eStatus){
        
        case IDLE:
            
            decide();
            
        break;
        
        case MOVING:
            
            
            
        break;
        
        case SCHEDULED:
            
            
            
        break;
        
        case OCCUPIED:
            
            
            
        break;
        
    }
    
}

void UnitAI::act(){
    
}

void UnitAI::decide(){
    
    int i=0;
    bool done = false;
    
    while( i < m_actionsOrder.size() && !done){
        
        if(m_entityManager->schedule(this->m_uiID, m_actionsOrder[i]->m_sName)){
            
            m_scheduledAction = m_actionsOrder[i];
            m_destination = m_actionsOrder[i]->getTarget()->getPosition();
            m_eStatus = SCHEDULED;
            done = true;
            
        }
        
        i++;
        
    }
    
}