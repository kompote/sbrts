#ifndef KNOWLEDGE_H
#define KNOWLEDGE_H

#include <string>

namespace core{

class Knowledge
{
    public:

        Knowledge(std::string name, int level);
        virtual ~Knowledge();

        const std::string m_sName;
        int level;

    protected:

    private:
};

}

#endif // KNOWLEDGE_H
