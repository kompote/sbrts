#ifndef ABSTRACTMAP_H
#define ABSTRACTMAP_H
#include <vector>

struct _mapCase {
    unsigned int posX;
    unsigned int posY;
    bool walkable;
};

struct _caseSize {
    unsigned int x;
    unsigned int y;
};

class AbstractMap
{
    private:
    protected:
    public:
        _caseSize cs;
        std::vector<_mapCase> m_SMapCaseList;

        AbstractMap();
        ~AbstractMap();
};
#endif
