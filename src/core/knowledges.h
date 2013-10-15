#ifndef KNOWLEDGES_H
#define KNOWLEDGES_H

#include "knowledge.h"

#include <map>
#include <string>

namespace core{

class Knowledges
{
    public:
        Knowledges(std::map<std::string, Knowledge> knowledges);
        Knowledges();
        virtual ~Knowledges();
    protected:
    private:

    std::map<std::string, Knowledge> m_knowledges;

};

}

#endif // KNOWLEDGES_H
