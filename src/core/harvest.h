#ifndef HARVEST_H
#define HARVEST_H

#include "action.h"

namespace core{

class Harvest : public Action
{
    public:

        Harvest(Personality * npersonality, std::map<std::string, Knowledge> * nknowledges);
        virtual ~Harvest();

        float update_efficiency();

    protected:
    private:
};

}

#endif // HARVEST_H
