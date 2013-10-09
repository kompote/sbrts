#include "RessourceManager.h"

#include<iostream>
#include<fstream>

RessourceManager ressourceManager;
RessourceManager::RessourceManager ()
{
    //ctor
}

RessourceManager::~RessourceManager()
{
    //dtor
}

// getTexture, return a reference to the texture which name is textureName
// each texture works as a singleton: load only one time on demand
sf::Texture& RessourceManager::getTexture(const std::string textureName )
{
    // if texture is not already loaded
    if( textures.find(textureName) == textures.end() ){
        // load texture and stock it in map
        textures[textureName].loadFromFile(ressourcePath + texturePath + textureName);
    }
    // return reference to texture
    return textures[textureName];
}



// getAnimation, return a reference to the animation which name is animationName
// each animation works as a singleton: load only one time on demand
Animation& RessourceManager::getAnimation(const std::string animationName)
{
    // if animation not already loaded
    if( animations.find(animationName) == animations.end() ){
        // open the file describing the animation
        std::ifstream animationFile(ressourcePath + animationPath + animationName);

        if(animationFile.is_open()){
            std::string animationTextureName;
            sf::Texture animationTexture;
            int textureWidth;
            int textureHeight;
            int nbFrame;
            int nbPixelFrameSeparation;
            int timePerFrameUS;

            // extract animation's data
            animationFile >> animationTextureName;
            animationTexture = getTexture( animationTextureName );
            animationFile >> textureWidth;
            animationFile >> textureHeight;
            animationFile >> nbFrame;
            animationFile >> nbPixelFrameSeparation;
            animationFile >> timePerFrameUS;

            // create the animation and stock it in the map
            //animations.insert( std::pair<std::string,Animation>(animationName,  Animation(animationTexture, textureWidth, textureHeight, nbFrame, nbPixelFrameSeparation, timePerFrameUS) ));
            animations[animationName] = Animation(animationTexture, textureWidth, textureHeight, nbFrame, nbPixelFrameSeparation, timePerFrameUS);

        }
    }
    // return reference to the animation
    return animations[animationName];
}
