#ifndef ACTION_H
#define ACTION_H

#include "entity.h"
#include "personality.h"
#include "knowledges.h"

#define KNOWLEDGES_COEF 0.5
#define PERSONALITY_COEF 0.5

/*! \addtogroup core 
 *  @{
 */
namespace core{

/*!
 *  \class Action
 *  \brief Action performed by a Unit (base class).
 */
class Action
{
    public:

        /*!
        *  \fn Action(Personality * personality, Knowledges * knowledges, std::string name)
        *  \brief Constructor.
        *  \param personality Pointer to the personality of the unit.
        *  \param knowledges Pointer to the knowledges of the unit.
        *  \param name Name of the action.
        */
        Action(Personality * personality, Knowledges * knowledges, std::string name);
        
        /*!
         *  \fn virtual ~Action()
         *  \brief Destructor.
         */
        virtual ~Action();

        /*!
         *  \fn virtual void update_efficiency()
         *  \brief Update the efficiency of the action
         *         (depends on the personality and the knowledges).
         */
        virtual void update_efficiency();
        
        const std::string m_sName; /*!< Name of the action. */
        
        /*!
         *  \fn float getEfficiency()
         *  \brief Get efficiency score of the action.
         *  \return Efficiency score of the action.
         */
        float getEfficiency();
        
        /*!
         *  \fn virtual bool setTarget(Entity * target)
         *  \brief Set the target of the action.
         *  \param target Pointer to the target (Entity).
         *  \return True if this entity can be targeted by this action
         *          (good type), False otherwise.
         */
        virtual bool setTarget(Entity * target);
        
        /*!
         *  \fn Entity * getTarget()
         *  \brief Get the target entity of the action.
         *  \return Pointer to the target entity.
         */
        Entity * getTarget();

    protected:

        Personality * m_personality; /*!< Pointer to the personality of the unit */
        Knowledges * m_knowledges; /*!< Pointer to the knowledges of the unit. */
        float m_fEfficiency; /*!< Pointer to the efficiency score of the action. */
        Entity * m_target; /*!< Pointer to the targeted entity (NULL by default) */

    private:

};

} /*! @}*/

#endif // ACTION_H
