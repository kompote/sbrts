#ifndef UNITAI_H
#define UNITAI_H

#include <map>
#include "entity.h"
#include "personality.h"
#include "knowledges.h"
#include "action.h"
#include "entitymanager.h"
#include <vector>

/*! \addtogroup core 
 *  @{
 */
namespace core{
    
    /*!
     * \enum UnitStatus
     * \brief Enumeration of the different states of a unit.
     * IDLE: The unit as nothing scheduled and was told nothing so far.
     * MOVING: The unit has been asked to go to a precise location.
     * SCHEDULED: The unit is going to realize a specific action on a specific target.
     * OCCUPIED: The unit is currently realizing a specific action on a specific target.
     */
    enum UnitStatus { IDLE, MOVING, SCHEDULED, OCCUPIED };

    
    /*!
     *  \class UnitAI
     *  \brief Unit in the game, able to move, take decisions and act by itself.
     */
    class UnitAI : public Entity
    {
        public:
            
            /*!
            *  \fn UnitAI(std::pair<float,float> position, std::map<std::string, Trait> traits, unsigned int id, EntityManager * entityManager)
            *  \brief Constructor.
            *  \param position Initial position of the unit on the map.
            *  \param traits Map of traits (of personality) indexed by their name.
            *  \param id Unique ID of the unit as an entity.*
            *  \param entityManager Pointer to the entity manager.
            */
            UnitAI(std::pair<float,float> position, std::map<std::string, Trait> traits, unsigned int id, EntityManager * entityManager);
            
            /*!
            *  \fn virtual ~UnitAI()
            *  \brief Destructor.
            */
            virtual ~UnitAI();
            
            /*!
            *  \fn void think()
            *  \brief Allows the unit to react to potential events or decide
            *  what to do next.
            */
            void think();
            
            /*!
            *  \fn void act()
            *  \brief Effectively realize the targeted action or move closer to
            *         the required location.
            */
            void act();

        protected:
        private:
            
        enum UnitStatus m_eStatus;  /*!< Status of the unit (initally IDLE) */
        Action* m_scheduledAction;  /*!< Pointer to the scheduled action (initally NULL)*/
        std::pair<float,float> m_destination; /*!< Target destination coordinates */

        Personality m_personality; /*!< Personality of the unit. */
        Knowledges m_knowledges; /*!< Knowledges of the unit. */
        std::map<std::string, Action> m_actions; /*!< Actions of the unit. */
        std::vector<Action*> m_actionsOrder; /*!< Vector (of pointers) of actions, sorted by efficiency (max first) */
        
        /*!
         *  \fn void updateOrder()
         *  \brief Update m_actionsOrder (sort Actions by efficiency, max first).
         */
        void updateOrder();
        
        /*!
         *  \fn void decide()
         *  \brief Affect an action to be realized (with a target) to the unit.
         */
        void decide();

    };

} /*!< @}*/

#endif // UNITAI_H
