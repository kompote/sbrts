#ifndef UNIT_H
#define UNIT_H

#include "entity.h"

namespace core{

class Unit : public Entity
{
    public:
        Unit(std::pair<float,float> position);
        virtual ~Unit();
    protected:
    private:
};

}

#endif // UNIT_H
