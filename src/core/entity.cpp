#include "entity.h"

using namespace core;

Entity::Entity(std::string type,
        std::pair<float,float> position,
        unsigned int id,
        EntityManager * entityManager,
        unsigned short int team): m_sType(type), m_uiID(id), m_entityManager(entityManager), m_usiTeam(team)
{

    this->m_position = position;

}

Entity::~Entity()
{



}

std::pair<float,float> Entity::getPosition()
{

    return this->m_position;

}

void Entity::setPosition(std::pair<float,float> position){

    this->m_position = position;

}

void Entity::pushEvent(EntityEvent entityEvent)
{
    
    m_entityEvents.push_back(entityEvent);
    
}