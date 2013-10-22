#ifndef HEAL_H
#define HEAL_H

#include "action.h"

namespace core{

class Heal : public Action
{
    public:

        Heal(Personality * personality, Knowledges * knowledges);
        virtual ~Heal();

        void update_efficiency();

    protected:
    private:
};

}

#endif // HEAL_H
