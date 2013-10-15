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
    protected:
    private:

    std::map<std::string, Trait> m_traits;

};

}

#endif // PERSONALITY_H
