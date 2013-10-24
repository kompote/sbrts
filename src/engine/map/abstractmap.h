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
struct _coord {
    unsigned int x;
    unsigned int y;
};

struct _polyCase {
    _coord topLeft;
    _coord botLeft;
    _coord botRight;
    _coord topRight;
    bool walkable;
};

class AbstractMap
{
    private:
    protected:
    public:
        _caseSize cs;
        std::vector<_mapCase> m_SMapCaseList;
        std::vector<_polyCase> polyList;

        AbstractMap();
        ~AbstractMap();
        void createTestMap();
};
#endif
