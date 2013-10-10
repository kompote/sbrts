#ifndef SEARCH_H
#define SEARCH_H

#include "action.h"

namespace core{

class Search : public Action
{
    public:

        Search(Personality * npersonality, std::map<std::string, Knowledge> * nknowledges);
        virtual ~Search();

        float update_efficiency();

    protected:
    private:
};

}

#endif // SEARCH_H
