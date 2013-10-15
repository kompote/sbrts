#ifndef MINING_H
#define MINING_H

#include "knowledge.h"

namespace core{

class Mining : public Knowledge
{
    public:
        Mining(int level = 0);
        virtual ~Mining();
    protected:
    private:
};

}

#endif // MINING_H
