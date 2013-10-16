#include "knowledge.h"

using namespace core;

Knowledge::Knowledge(std::string name, int level): m_sName(name)
{

    this->m_iLevel = level;

}

Knowledge::~Knowledge()
{
    //dtor
}
