
#include <iostream>
#include <SFML/Graphics.hpp>
#include <list>
#include "sys/sysinfo.h"

#include "Map.h"

#include "advMap.h"
using namespace std;

// global vars
sf::RenderWindow mainWindow(sf::VideoMode(800, 600), "SBRTS");    // global main window
//Map theMap;
AdvMap theMap;
int main()
{

//    sf::CircleShape shape(100.f);
//    shape.setFillColor(sf::Color::Green);


    // fps control
    sf::Clock clock;
    std::list<sf::Time> frameTime;
    unsigned int framecount = 0;
    unsigned int fps = 60;
    sf::Time elapsed;
    sf::Time frameDuration = sf::seconds(1/(double)(fps));

    // system info stuff
    // doesnt work, useless, but for futur... maybe
    //struct sysinfo memInfo;
    //long long physMemUsed = memInfo.totalram - memInfo.freeram;

    theMap.loadMap("map01");

    while (mainWindow.isOpen())
    {
        // keep real frame time
        frameTime.push_back(clock.restart());
        // Event management
        // TODO: A Threader
        sf::Event event;
        while (mainWindow.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                mainWindow.close();
        }
        // Clear display
        mainWindow.clear(sf::Color(0, 240, 255));
        // Draw something
        // TODO: a threader, migrer au manager
    //    mainWindow.draw(shape);
theMap.redraw(mainWindow);
        // calcul et ajuste fps
        elapsed = clock.getElapsedTime();
        ++framecount;
        // du temps en plus
        if( elapsed < frameDuration ){
            // sleep until frameDuration reached
            sf::sleep( frameDuration - elapsed );
        }
        // on display apres le sleep, que le thread compute profite du temps restant
        mainWindow.display();

        // fps display toutes les 60 frames
        if (framecount > 30)
        {
            sf::Time tmp;
            // moyenne
            for (const auto &it : frameTime)
                tmp += it;
            tmp = tmp/(float)30;
            cout<<flush<< "\r FrameRate : " << int(1/tmp.asSeconds()) << "fps"; //     Memory : " << physMemUsed << "Mb   ";
            frameTime.clear();
            framecount=0;
        }
    }
    return 0;
}

