#ifndef ENTITY_H
#define ENTITY_H

#include <string>

namespace core{

class Entity
{
    public:

        const std::string type;
        Entity(std::string ntype, std::pair<float,float> position);
        ~Entity();

        std::pair<float,float> getPosition();
        void setPosition(std::pair<float,float> position);

    private:

    std::pair<float,float> position;

};

}

#endif
