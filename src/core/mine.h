#ifndef MINE_H
#define MINE_H

#include "action.h"

namespace core{

class Mine : public Action
{
    public:

        Mine(Personality * personality, Knowledges * knowledges);
        virtual ~Mine();

        void update_efficiency();

    protected:
    private:
};

}

#endif // MINE_H
