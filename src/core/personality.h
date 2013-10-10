#ifndef PERSONALITY_H
#define PERSONALITY_H

#include <map>
#include "trait.h"

namespace core{

class Personality
{
    public:
        Personality(std::map<std::string, Trait> ntraits);
        virtual ~Personality();
    protected:
    private:

    std::map<std::string, Trait> traits;

};

}

#endif // PERSONALITY_H
