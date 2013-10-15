#ifndef UNIT_H
#define UNIT_H

#include <map>
#include "entity.h"
#include "personality.h"
#include "knowledges.h"
#include "action.h"

namespace core{

    class Unit : public Entity
    {
        public:
            Unit(std::pair<float,float> position, std::map<std::string, Trait> traits);
            virtual ~Unit();
        protected:
        private:

        Personality m_personality;
        Knowledges m_knowledges;
        std::map<std::string, Action> m_actions;

    };

}

#endif // UNIT_H
