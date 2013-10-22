/* 
 * File:   CoreLoop.cpp
 * Author: blax
 * 
 * Created on October 20, 2013, 8:14 AM
 */

#include "coreloop.h"

using namespace core;

CoreLoop::CoreLoop()
{
    
}

CoreLoop::CoreLoop(const CoreLoop& orig)
{
    
}

CoreLoop::~CoreLoop()
{
    
}

void CoreLoop::run()
{
 
    while(true){
    
        for(int i=0; i < m_units.size(); i++) m_units[i].think();
    
        for(int i=0; i < m_units.size(); i++) m_units[i].act();

    }
    
}

