/* 
 * File:   EntityManager.h
 * Author: blax
 *
 * Created on October 21, 2013, 11:24 AM
 */

#ifndef ENTITYMANAGER_H
#define	ENTITYMANAGER_H

#include <string>
#include "entityevent.h"

/*! \addtogroup core 
 *  @{
 */
namespace core{

/*!
 *  \class EntityManager
 *  \brief Manager to handle publication and reception of
 *         events between units.
 */
class EntityManager {
    
public:
    
    /*!
     *  \fn EntityManager()
     *  \brief Constructor.
     */
    EntityManager();
    
    /*!
     *  \fn EntityManager()
     *  \brief Copy constructor.
     */
    EntityManager(const EntityManager& orig);
    
    /*!
     *  \fn void subscribe(unsigned int EntityID, char eventName[])
     *  \brief Called by an entity to subscribe to a specific type of event (EntityEvent).
     *  \param entityID ID of the subscribing entity.
     *  \param eventName Type of event to subscribe to.
     */
    void subscribe(unsigned int entityID, char eventName[]);
    
    /*!
     *  \fn void unsubscribe(unsigned int EntityID, char eventName[])
     *  \brief Called by an entity to unsubscribe from a specific type of event (EntityEvent).
     *  \param entityID ID of the unsubscribing entity.
     *  \param eventName Type of event to unsubscribe from.
     */
    void unsubscribe(unsigned int entityID, char eventName[]);
    
    /*!
     *  \fn unsigned int schedule(unsigned int entityID, std::string actionName)
     *  \brief Called by an entity to find and set a target for an action.
     *  \param entityID ID of the calling entity.
     *  \param actionName Type of action to schedule for the entity.
     *  \return true if a target has been set for this action, false otherwise.
     */
    bool schedule(unsigned int entityID, std::string actionName);
    
    /*!
     *  \fn virtual ~EntityManager()
     *  \brief Destructor.
     */
    virtual ~EntityManager();
    
private:

};

} /* @}*/

#endif	/* ENTITYMANAGER_H */

