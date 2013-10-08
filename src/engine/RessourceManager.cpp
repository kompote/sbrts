#include "RessourceManager.h"


RessourceManager ressourceManager;
RessourceManager::RessourceManager ()
{
    //ctor
}

RessourceManager::~RessourceManager()
{
    //dtor
}

sf::Texture RessourceManager::getTexture(const std::string textureName )
{
    if( textures.find(textureName) == textures.end() ){
        textures[textureName].loadFromFile(ressourcePath + texturePath + textureName);
    }
    return textures[textureName];
}
