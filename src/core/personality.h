#ifndef PERSONALITY_H
#define PERSONALITY_H

#include <map>
#include "trait.h"

namespace core{

class Personality
{
    public:
        Personality(std::map<std::string, Trait> traits);
        virtual ~Personality();

        Trait getTrait(std::string name);
        void setTrait(Trait trait);

    protected:
    private:

    std::map<std::string, Trait> m_traits;

};

}

#endif // PERSONALITY_H
