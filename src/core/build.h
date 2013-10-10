#ifndef BUILD_H
#define BUILD_H

#include "action.h"

namespace core{

class Build : public Action
{
    public:

        Build(Personality * npersonality, std::map<std::string, Knowledge> * nknowledges);
        virtual ~Build();

        float update_efficiency();

    protected:
    private:
};

}

#endif // BUILD_H
