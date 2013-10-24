#ifndef PERSONALITY_H
#define PERSONALITY_H

#include <map>
#include "trait.h"

/*! \addtogroup core 
 *  @{
 */
namespace core{

/*!
 *  \class Knowledges
 *  \brief Container for the traits of a Unit.
 */
class Personality
{
    public:
        
        /*!
        *  \fn Personality(std::map<std::string, Trait> traits)
        *  \brief Constructor using an initial traits map.
        *  \param traits Initial map of traits of the unit.
        */
        Personality(std::map<std::string, Trait> traits);
        
        /*!
        *  \fn virtual ~Personality()
        *  \brief Destructor.
        */
        virtual ~Personality();

        /*!
        *  \fn Trait getTrait(std::string name)
        *  \brief Get a trait by its name.
        *  \param name Name of the trait to get.
        *  \return Trait of this name.
        */
        Trait getTrait(std::string name);
        
        /*!
        *  \fn void setTrait(Trait trait)
        *  \brief Set a trait.
        *  \param Trait to set.
        */
        void setTrait(Trait trait);

    protected:
        
    private:

    std::map<std::string, Trait> m_traits; /*!< Map of traits, each trait is indexed by its name. */

};

}/*! @}*/

#endif // PERSONALITY_H
