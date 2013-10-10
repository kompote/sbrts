#ifndef ACTION_H
#define ACTION_H

#include "personality.h"
#include "knowledge.h"

namespace core{

class Action
{
    public:

        Action(Personality * personality, std::map<std::string, Knowledge> * knowledges, std::string name);
        virtual ~Action();

        virtual float update_efficiency();
        const std::string name;

    protected:

        Personality * personality;
        std::map<std::string, Knowledge> * knowledges;
        float efficiency;

    private:

};

}

#endif // ACTION_H
