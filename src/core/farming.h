#ifndef FARMING_H
#define FARMING_H

#include "knowledge.h"

namespace core{

class Farming : public Knowledge
{
    public:
        Farming(int level = 0);
        virtual ~Farming();
    protected:
    private:
};

}

#endif // FARMING_H
