#ifndef KNOWLEDGES_H
#define KNOWLEDGES_H

#include "knowledge.h"

#include <map>
#include <string>

/*! \addtogroup core 
 *  @{
 */
namespace core{

 /*!
 *  \class Knowledges
 *  \brief Container for the knowledges of a Unit.
 */
class Knowledges
{
    public:
        
        /*!
        *  \fn Knowledges(std::map<std::string, Knowledge> knowledges)
        *  \brief Constructor using an initial knowledge map.
        *  \param knowledges Initial map of knowledges of the unit.
        */
        Knowledges(std::map<std::string, Knowledge> knowledges);
        
        /*!
        *  \fn Knowledges()
        *  \brief Constructor.
        */
        Knowledges();
        
        /*!
        *  \fn ~Knowledges()
        *  \brief Destructor.
        */
        virtual ~Knowledges();
        
        /*!
        *  \fn Knowledge getKnowledge(std::string name)
        *  \brief Get a knowledge by its name.
        *  \param name Name of the knowledge to get.
        *  \return Knowledge of this name.
        */
        Knowledge getKnowledge(std::string name);
        
        /*!
        *  \fn void setKnowledge(Knowledge knowledge)
        *  \brief Set a knowledge.
        *  \param Knowledge to set.
        */
        void setKnowledge(Knowledge knowledge);
        
    protected:
    private:

    std::map<std::string, Knowledge> m_knowledges; /*!< Map of knowledges, each knowledge is indexed by its name. */

};

}/*! @}*/

#endif // KNOWLEDGES_H
