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

namespace core{

class EntityManager {
public:
    EntityManager();
    EntityManager(const EntityManager& orig);
    
    bool subscribe(unsigned int EntityID, char eventName[]);
    bool unsubscribe(unsigned int EntityID, char eventName[]);
    unsigned int schedule(unsigned int entityID, std::string actionName);
    
    virtual ~EntityManager();
private:

};

}

#endif	/* ENTITYMANAGER_H */

