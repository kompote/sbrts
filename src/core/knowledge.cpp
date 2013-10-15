#include "knowledge.h"

using namespace core;

Knowledge::Knowledge(std::string name, int level): m_sName(name)
{

    this->level = level;

}

Knowledge::~Knowledge()
{
    //dtor
}
