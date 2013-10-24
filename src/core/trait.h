#ifndef TRAIT_H
#define TRAIT_H

#include <string>

#define TRAIT_MAX_VALUE 100.0

/*! \addtogroup core 
 *  @{
 */
namespace core{

/*!
 *  \class Trait
 *  \brief Base class of a trait of personality.
 */
class Trait
{
    public:

        /*!
        *  \fn Trait(std::string name, float value = 0)
        *  \brief Constructor.
        *  \param name Name of the trait.
        *  \param level Value of this trait for the unit.
        */
        Trait(std::string name, float value = 0);
        
        /*!
        *  \fn virtual ~Trait()
        *  \brief Destructor.
        */
        virtual ~Trait();
        
        const std::string m_sName; /*< Name of the knowledge. */
        float m_fValue; /*!< Value of the trait. */

    protected:

    private:
};

} /*! @}*/

#endif // TRAIT_H
