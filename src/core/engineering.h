#ifndef ENGINEERING_H
#define ENGINEERING_H

#include "knowledge.h"

namespace core{

class Engineering : public Knowledge
{
    public:
        Engineering(int level = 0);
        virtual ~Engineering();
    protected:
    private:
};

}

#endif // ENGINEERING_H
