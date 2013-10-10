#ifndef ATTACK_H
#define ATTACK_H

#include "action.h"

namespace core{

class Attack : public Action
{
    public:

        Attack(Personality * npersonality, std::map<std::string, Knowledge> * nknowledges);
        virtual ~Attack();

        float update_efficiency();

    protected:
    private:
};

}

#endif // ATTACK_H
