/* 
 * File:   EntityEvent.h
 * Author: blax
 *
 * Created on October 22, 2013, 8:54 AM
 */

#ifndef ENTITYEVENT_H
#define	ENTITYEVENT_H

#define EVENT_NAME_LENGTH 12

namespace core{

struct EntityEvent
{
    
    char eventName[EVENT_NAME_LENGTH];
    unsigned int entityTarget;
    unsigned int entityEmitter;
    
};

}

#endif	/* ENTITYEVENT_H */

