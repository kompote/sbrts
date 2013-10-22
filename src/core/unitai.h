#ifndef UNITAI_H
#define UNITAI_H

#include <map>
#include "entity.h"
#include "personality.h"
#include "knowledges.h"
#include "action.h"
#include "entitymanager.h"
#include <vector>

namespace core{
    
    enum UnitStatus { IDLE, MOVING, SCHEDULED, OCCUPIED };

    class UnitAI : public Entity
    {
        public:
            UnitAI(std::pair<float,float> position, std::map<std::string, Trait> traits, unsigned int id, EntityManager * entityManager);
            virtual ~UnitAI();
            
            void think();
            void act();

        protected:
        private:
            
        enum UnitStatus m_eStatus;  // TODO make sure it is initialized to IDLE state in the implementation
        Action* m_scheduledAction;  // TODO make sure it is initialized to NULL in the implementation
        std::pair<float,float> m_destination;

        Personality m_personality;
        Knowledges m_knowledges;
        std::map<std::string, Action> m_actions;
        std::vector<Action*> m_actionsOrder;
        
        void updateOrder();
        void decide();

    };

}

#endif // UNITAI_H
