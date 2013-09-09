#include <iostream>
#include <SFML/Graphics.hpp>
#include <list>
#include "sys/sysinfo.h"

#include "engine/advMap.h"
using namespace std;

// global vars
sf::RenderWindow mainWindow(sf::VideoMode(800, 600), "SBRTS");    // global main window
AdvMap theMap;

bool bfullscreen = false;
void toggleFullscreen() {
    if (!bfullscreen)
        mainWindow.create(VideoMode::getDesktopMode(),"SBRTS");
    else
        mainWindow.create(sf::VideoMode(800,600),"SBRTS");
    bfullscreen = !bfullscreen;

}
float getFPS(const sf::Time& time) {
         return (1000000.0f / time.asMicroseconds());
}
//float targetFPS = 60.0;
//float targetFrameTime = targetFPS*1000000.0f;
int main()
{
    // fps control
    sf::Clock FPSClock;
//    float fps;
    std::list<float> frameTime;
    unsigned int framecount = 0;
    // Debug stuff
    // TODO : Utility class
    sf::Font _DebugFont;
    _DebugFont.loadFromFile("resources/Aero.ttf");
    sf::Text _DebugFPS("fps", _DebugFont,12);
    _DebugFPS.setPosition(750.0,5.0);

    theMap.loadMap("map01");
    sf::Sprite mapSprite;

   // map texture offscreen
    sf::RenderTexture rt;
    rt.create(1800,1600);
    int mapPosX = 0, mapPosY = 0;

    while (mainWindow.isOpen())
    {
        // keep real frame time
        // Event management
        sf::Event event;
        while (mainWindow.pollEvent(event))
        {
            switch(event.type)
            {
                case sf::Event::Closed:
                    mainWindow.close();
                    break;
                case sf::Event::KeyPressed:
                    switch(event.key.code)
                    {
                            case sf::Keyboard::F:
                                toggleFullscreen();
                                break;
                            case sf::Keyboard::Q:
                                mainWindow.close();
                                break;
                            case sf::Keyboard::Up:
                                if (mapPosY<597)
                                    mapPosY +=3;
                                break;
                            case sf::Keyboard::Down:
                                if (mapPosY>3)
                                    mapPosY -=3;
                                break;
                            case sf::Keyboard::Left:
                                if (mapPosX<770)
                                    mapPosX +=3;
                                break;
                            case sf::Keyboard::Right:
                                if (mapPosX>3)
                                    mapPosX -=3;
                                break;
                            default:
                                break;
                    }
                    break;
            }
        }

        // render map
        rt.clear(sf::Color(20,20,20));
        theMap.redraw(rt);
        rt.draw(sf::Text("toto",_DebugFont,12)); // if not, bug ??
        rt.display();
        // Clear display
        mainWindow.clear(sf::Color(0, 140, 155));
        // dram map, just a part
        // TODO : fulscreen
        mapSprite.setTexture(rt.getTexture());
        mapSprite.setTextureRect(sf::IntRect(mapPosX,mapPosY,800,500));
        mainWindow.draw(mapSprite);

        // draw fps text
        mainWindow.draw(_DebugFPS);

        ++framecount;

        mainWindow.display();

        frameTime.push_back(getFPS(FPSClock.restart()));
        //no limit
        //if(fps > targetFPS)
        //    sf::sleep( sf::microseconds(targetFrameTime - fps*1000000.0f) );

        // fps display toutes les 60 frames
        if (framecount > 30)
        {
            //sf::Time tmp;
            float tmp;
            // moyenne
            for (const auto &it : frameTime)
                tmp += it;
            tmp = tmp/(float)30;
            _DebugFPS.setString(sf::String(to_string((int)tmp) + " fps")) ;
            frameTime.clear();
            framecount=0;
        }
    }
    return 0;
}

