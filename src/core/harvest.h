#ifndef HARVEST_H
#define HARVEST_H

#include "action.h"

namespace core{

class Harvest : public Action
{
    public:

        Harvest(Personality * personality, Knowledges * knowledges);
        virtual ~Harvest();

        void update_efficiency();

    protected:
    private:
};

}

#endif // HARVEST_H
