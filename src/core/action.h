#ifndef ACTION_H
#define ACTION_H

#include "entity.h"
#include "personality.h"
#include "knowledges.h"

#define KNOWLEDGES_COEF 0.5
#define PERSONALITY_COEF 0.5

namespace core{

class Action
{
    public:

        Action(Personality * personality, Knowledges * knowledges, std::string name);
        virtual ~Action();

        virtual void update_efficiency();
        const std::string m_sName;
        float getEfficiency();
        virtual bool setTarget(Entity * target);
        Entity * getTarget();

    protected:

        Personality * m_personality;
        Knowledges * m_knowledges;
        float m_fEfficiency;
        Entity * m_target;

    private:

};

}

#endif // ACTION_H
