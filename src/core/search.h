#ifndef SEARCH_H
#define SEARCH_H

#include "action.h"

namespace core{

class Search : public Action
{
    public:

        Search(Personality * personality, Knowledges * knowledges);
        virtual ~Search();

        void update_efficiency();

    protected:
    private:
};

}

#endif // SEARCH_H
