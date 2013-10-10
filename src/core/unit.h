#ifndef UNIT_H
#define UNIT_H

#include <map>
#include "entity.h"
#include "personality.h"
#include "knowledge.h"
#include "action.h"

namespace core{

    class Unit : public Entity
    {
        public:
            Unit(std::pair<float,float> position, std::map<std::string, Trait> traits);
            virtual ~Unit();
        protected:
        private:

        Personality personality;
        std::map<std::string, Knowledge> knowledges;
        std::map<std::string, Action> actions;

    };

}

#endif // UNIT_H
