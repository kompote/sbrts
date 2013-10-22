#ifndef ENTITY_H
#define ENTITY_H

#include <string>
#include "entitymanager.h"

#define ENTITY_DEFAULT_TEAM 0

namespace core{

class Entity
{
    public:

        const std::string m_sType;
        const unsigned short int m_usiTeam;
        const unsigned int m_uiID;
        Entity(std::string type, std::pair<float,float> position, unsigned int id, EntityManager * entityManager, unsigned short int team = ENTITY_DEFAULT_TEAM);
        virtual ~Entity();

        std::pair<float,float> getPosition();
        void setPosition(std::pair<float,float> position);

    protected:
    
        EntityManager * m_entityManager;
        
    private:

        std::pair<float,float> m_position;

};

}

#endif
