#ifndef RESSOURCE_MANAGER_H
#define RESSOURCE_MANAGER_H

#include <SFML/Graphics.hpp>
#include "Animation.h"

class RessourceManager
{
    public:
        RessourceManager();
        virtual ~RessourceManager();

        // getTexture, return a reference to the texture which name is textureName
        // each texture works as a singleton: load only one time on demand
        sf::Texture& getTexture(const std::string textureName );
        // getAnimation, return a reference to the animation which name is animationName
        // each animation works as a singleton: load only one time on demand
        Animation& getAnimation(const std::string animationName);

    protected:
    private:
        // map containing the textures already loaded
        std::map<std::string,sf::Texture> textures;
        // map containing the animations already loaded
        std::map<std::string,Animation> animations;
        // string containing the path to the ressources
        std::string ressourcePath = "resources//";
        // string containing the path to the textures
        std::string texturePath = "textures//";
        // string containing the path to the animations
        std::string animationPath = "animations//";
};

// this class is a singleton, necessary.
extern RessourceManager ressourceManager;

#endif // RESSOURCE_MANAGER_H

