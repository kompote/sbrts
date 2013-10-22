#ifndef REPAIR_H
#define REPAIR_H

#include "action.h"

namespace core{

class Repair : public Action
{
    public:

        Repair(Personality * personality, Knowledges * knowledges);
        virtual ~Repair();

        void update_efficiency();

    protected:
    private:
};

}

#endif // REPAIR_H
