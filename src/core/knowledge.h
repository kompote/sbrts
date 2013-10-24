#ifndef KNOWLEDGE_H
#define KNOWLEDGE_H

#include <string>

#define KNOWLEDGE_MAX_VALUE 100.0

/*! \addtogroup core 
 *  @{
 */
namespace core{

/*!
 *  \class Knowledge
 *  \brief Base class of a knowledge.
 */
class Knowledge
{
    public:

        /*!
        *  \fn Knowledge(std::string name, int level)
        *  \brief Constructor.
        *  \param name Name of the knowledge.
        *  \param level Level of the unit for this knowledge.
        */
        Knowledge(std::string name, int level);
        
        /*!
        *  \fn virtual ~Knowledge()
        *  \brief Destructor.
        */
        virtual ~Knowledge();

        const std::string m_sName; /*< Name of the knowledge. */
        int m_iLevel; /*< Level of the knowledge. */

    protected:

    private:
};

} /*! @}*/

#endif // KNOWLEDGE_H
