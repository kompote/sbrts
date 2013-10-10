#ifndef LUMBER_H
#define LUMBER_H

#include "action.h"

namespace core{

class Lumber : public Action
{
    public:

        Lumber(Personality * npersonality, std::map<std::string, Knowledge> * nknowledges);
        virtual ~Lumber();

        float update_efficiency();

    protected:
    private:
};

}

#endif // LUMBER_H
