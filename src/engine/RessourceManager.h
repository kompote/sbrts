#ifndef RESSOURCE_MANAGER_H
#define RESSOURCE_MANAGER_H

#include <SFML/Graphics.hpp>


class RessourceManager
{
    public:
        RessourceManager();
        virtual ~RessourceManager();
        sf::Texture getTexture(const std::string textureName );

    protected:
    private:
        std::map<std::string,sf::Texture> textures;
        std::string ressourcePath = "resources//";
        std::string texturePath = "textures//";
        std::string animationPath = "animations//";
};


extern RessourceManager ressourceManager;

#endif // RESSOURCE_MANAGER_H

