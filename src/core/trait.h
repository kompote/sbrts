#ifndef TRAIT_H
#define TRAIT_H

#include <string>

#define TRAIT_MAX_VALUE 100.0

namespace core{

class Trait
{
    public:

        Trait(std::string name, float value = 0);
        virtual ~Trait();
        float m_fValue;
        const std::string m_sName;

    protected:

    private:
};

}

#endif // TRAIT_H
