#ifndef MILITARY_H
#define MILITARY_H

#include "knowledge.h"

namespace core{

class Military : public Knowledge
{
    public:
        Military(int level = 0);
        virtual ~Military();
    protected:
    private:
};

}

#endif // MILITARY_H
