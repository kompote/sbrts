#ifndef INTELLIGENCE_H
#define INTELLIGENCE_H

#include "trait.h"

namespace core{

class Intelligence : public Trait
{
    public:
        Intelligence(float value);
        virtual ~Intelligence();
    protected:
    private:
};

}

#endif // INTELLIGENCE_H
