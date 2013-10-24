#ifndef ENTITY_H
#define ENTITY_H

#include <string>
#include <list>
#include "entitymanager.h"
#include "entityevent.h"

#define ENTITY_DEFAULT_TEAM 0

/*! \addtogroup core 
 *  @{
 */
namespace core{

/*!
 *  \class Entity
 *  \brief Entity in the game, an entity is an actor in the game
 *         that can interact with other entities and react to events.
 */
class Entity
{
    public:

        const std::string m_sType; /*!< Type of the entity (depends on the class derived of Entity) */
        const unsigned short int m_usiTeam /*!< Team of the entity (faction to which the entity belongs) */;
        const unsigned int m_uiID; /*!< ID of the entity (unique for each entity) */
        
        /*!
         *  \fn Entity(std::string type, std::pair<float,float> position, unsigned int id, EntityManager * entityManager, unsigned short int team = ENTITY_DEFAULT_TEAM)
         *  \brief Constructor.
         *  \param type Type of the entity.
         *  \param position Position of the entity (on the map).
         *  \param id ID of the entity (unique).
         *  \param entityManager Pointer to the Entity Manager.
         *  \param team Team of the entity.
         */
        Entity(std::string type, std::pair<float,float> position, unsigned int id, EntityManager * entityManager, unsigned short int team = ENTITY_DEFAULT_TEAM);
        
        /*!
         *  \fn virtual ~Entity()
         *  \brief Destructor.
         */
        virtual ~Entity();

        /*!
         *  \fn std::pair<float,float> getPosition()
         *  \brief Get position of the entity on the map.
         *  \return Position of the entity on the map.
         */
        std::pair<float,float> getPosition();
        
        /*!
         *  \fn void setPosition(std::pair<float,float> position)
         *  \brief Set position of the entity on the map.
         *  \param position Position of the entity on the map.
         */
        void setPosition(std::pair<float,float> position);
        
        /*!
         *  \fn void pushEvent(EntityEvent entityEvent)
         *  \brief Push an event for this entity.
         *  \param entityEvent Event to be pushed.
         */
        void pushEvent(EntityEvent entityEvent);

    protected:
    
        EntityManager * m_entityManager; /*!< Pointer to the Entity Manager. */
        std::list<EntityEvent> m_entityEvents; /*!< List of events received by the entity. */
        
    private:

        std::pair<float,float> m_position; /*!< Position of the entity (on the map). */

};

} /*! @}*/

#endif
