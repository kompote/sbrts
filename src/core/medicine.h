#ifndef MEDICINE_H
#define MEDICINE_H

#include "knowledge.h"

namespace core{

class Medicine : public Knowledge
{
    public:
        Medicine(int level = 0);
        virtual ~Medicine();
    protected:
    private:
};

}

#endif // MEDICINE_H
