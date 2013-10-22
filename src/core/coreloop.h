/* 
 * File:   CoreLoop.h
 * Author: blax
 *
 * Created on October 20, 2013, 8:14 AM
 */

#ifndef CORELOOP_H
#define	CORELOOP_H

#include <vector>
#include "unitai.h"
#include "entitymanager.h"

namespace core{

class CoreLoop {
public:
    CoreLoop();
    CoreLoop(const CoreLoop& orig);
    virtual ~CoreLoop();
    
    std::vector<UnitAI> m_units;
    
    void run();
    
private:

};

}

#endif	/* CORELOOP_H */

