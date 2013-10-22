#ifndef ATTACK_H
#define ATTACK_H

#include "action.h"

namespace core{

class Attack : public Action
{
    public:

        Attack(Personality * personality, Knowledges * knowledges);
        virtual ~Attack();

        void update_efficiency();
        bool setTarget(Entity * target);

    protected:
    private:
};

}

#endif // ATTACK_H
