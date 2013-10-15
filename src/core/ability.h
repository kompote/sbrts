#ifndef ABILITY_H
#define ABILITY_H

#include "trait.h"

namespace core{

class Ability : public Trait
{
    public:
        Ability(float value);
        virtual ~Ability();
    protected:
    private:
};

}

#endif // ABILITY_H
