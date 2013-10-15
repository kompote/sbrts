#ifndef REPAIR_H
#define REPAIR_H

#include "action.h"

namespace core{

class Repair : public Action
{
    public:

        Repair(Personality * personality, std::map<std::string, Knowledge> * knowledges);
        virtual ~Repair();

        float update_efficiency();

    protected:
    private:
};

}

#endif // REPAIR_H
