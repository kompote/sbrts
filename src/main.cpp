#include <iostream>
#include <SFML/Graphics.hpp>
#include <list>
#include "sys/sysinfo.h"

#include "advMap.h"
using namespace std;

// global vars
sf::RenderWindow mainWindow(sf::VideoMode(800, 600), "SBRTS");    // global main window
AdvMap theMap;

float getFPS(const sf::Time& time) {
         return (1000000.0f / time.asMicroseconds());
}
//float targetFPS = 60.0;
//float targetFrameTime = targetFPS*1000000.0f;
int main()
{
    // fps control
    sf::Clock FPSClock;
    float fps;  
    std::list<float> frameTime;
    unsigned int framecount = 0;
    // Debug stuff
    // TODO : Utility class
    sf::Font _DebugFont;
    _DebugFont.loadFromFile("resources/Aero.ttf");
    sf::Text _DebugFPS("fps", _DebugFont,12);
    _DebugFPS.setPosition(750.0,5.0);

    theMap.loadMap("map01");

    while (mainWindow.isOpen())
    {
        // keep real frame time
        // Event management
        sf::Event event;
        while (mainWindow.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                mainWindow.close();
        }
        // Clear display
        mainWindow.clear(sf::Color(0, 240, 255));
        // Draw something
        theMap.redraw(mainWindow);
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

