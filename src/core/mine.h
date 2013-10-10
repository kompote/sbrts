#ifndef MINE_H
#define MINE_H

#include "action.h"

namespace core{

class Mine : public Action
{
    public:

        Mine(Personality * npersonality, std::map<std::string, Knowledge> * nknowledges);
        virtual ~Mine();

        float update_efficiency();

    protected:
    private:
};

}

#endif // MINE_H
