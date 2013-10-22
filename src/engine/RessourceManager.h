#ifndef RESSOURCE_MANAGER_H
#define RESSOURCE_MANAGER_H

#include <SFML/Graphics.hpp>
#include "AnimatedTexture.h"

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
        AnimatedTexture& getAnimation(const std::string animationName);

    protected:
    private:
        // map containing the textures already loaded
        std::map<std::string,sf::Texture> textures;
        // map containing the animations already loaded
        std::map<std::string,AnimatedTexture> animations;
        // string containing the path to the ressources
        std::string ressourcePath;
        // string containing the path to the textures
        std::string texturePath;
        // string containing the path to the animations
        std::string animationPath;
};

// this class is a singleton, necessary.
extern RessourceManager ressourceManager;

#endif // RESSOURCE_MANAGER_H

