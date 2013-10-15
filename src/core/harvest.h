#ifndef HARVEST_H
#define HARVEST_H

#include "action.h"

namespace core{

class Harvest : public Action
{
    public:

        Harvest(Personality * personality, std::map<std::string, Knowledge> * knowledges);
        virtual ~Harvest();

        float update_efficiency();

    protected:
    private:
};

}

#endif // HARVEST_H
