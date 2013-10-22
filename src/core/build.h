#ifndef BUILD_H
#define BUILD_H

#include "action.h"

namespace core{

class Build : public Action
{
    public:

        Build(Personality * personality, Knowledges * knowledges);
        virtual ~Build();

        void update_efficiency();

    protected:
    private:
};

}

#endif // BUILD_H
