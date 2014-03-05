


struct _node {
    unsigned int x;
    unsigned int y;
    unsigned int parent_x;
    unsigned int parent_y;
    unsigned int costToDest;
    unsigned int costFromOrg;
    unsigned int totalCost;
}

class Pathfinder
{
    private:
    protected:
    public:
        int AStar(unsigned int uiFromX, unsigned uiFromY, unsigned int uiToX, unsigned int uiToY);
        int bresenham(unsigned int uiFromX, unsigned uiFromY, unsigned int uiToX, unsigned int uiToY);


};
