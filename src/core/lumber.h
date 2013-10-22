#ifndef LUMBER_H
#define LUMBER_H

#include "action.h"

namespace core{

class Lumber : public Action
{
    public:

        Lumber(Personality * personality, Knowledges * knowledges);
        virtual ~Lumber();

        void update_efficiency();

    protected:
    private:
};

}

#endif // LUMBER_H
