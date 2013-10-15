#ifndef BUILD_H
#define BUILD_H

#include "action.h"

namespace core{

class Build : public Action
{
    public:

        Build(Personality * personality, std::map<std::string, Knowledge> * knowledges);
        virtual ~Build();

        float update_efficiency();

    protected:
    private:
};

}

#endif // BUILD_H
