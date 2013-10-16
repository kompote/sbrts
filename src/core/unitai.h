#ifndef UNITAI_H
#define UNITAI_H

#include <map>
#include "entity.h"
#include "personality.h"
#include "knowledges.h"
#include "action.h"

namespace core{

    class UnitAI : public Entity
    {
        public:
            UnitAI(std::pair<float,float> position, std::map<std::string, Trait> traits);
            virtual ~UnitAI();

        protected:
        private:

        Personality m_personality;
        Knowledges m_knowledges;
        std::map<std::string, Action> m_actions;

    };

}

#endif // UNITAI_H
