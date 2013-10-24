/* 
 * File:   EntityEvent.h
 * Author: blax
 *
 * Created on October 22, 2013, 8:54 AM
 */

#ifndef ENTITYEVENT_H
#define	ENTITYEVENT_H

#define EVENT_NAME_LENGTH 12

/*! \addtogroup core 
 *  @{
 */
namespace core{

/*!
 *  \struct EntityEvent
 *  \brief Event sent between entities upon doing an action.
 */
struct EntityEvent
{
    
    char eventName[EVENT_NAME_LENGTH]; /*!< Name of the event (Action type). */
    unsigned int entityTarget; /*!< ID of this Action's target Entity */
    unsigned int entityEmitter; /*!< ID of the emitter Entity. */
    
};

}/* @}*/

#endif	/* ENTITYEVENT_H */

