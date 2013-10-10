#ifndef HEAL_H
#define HEAL_H

#include "action.h"

namespace core{

class Heal : public Action
{
    public:

        Heal(Personality * npersonality, std::map<std::string, Knowledge> * nknowledges);
        virtual ~Heal();

        float update_efficiency();

    protected:
    private:
};

}

#endif // HEAL_H
