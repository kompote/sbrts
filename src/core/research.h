#ifndef RESEARCH_H
#define RESEARCH_H

#include "knowledge.h"

namespace core{

class Research : public Knowledge
{
    public:
        Research(int level = 0);
        virtual ~Research();
    protected:
    private:
};

}

#endif // RESEARCH_H
