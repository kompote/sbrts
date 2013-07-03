
#include <iostream>
#include <SFML/Graphics.hpp>
#include <list>
#include "sys/sysinfo.h"
using namespace std;

int main()
{
    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);
    // fps control
    sf::Clock clock;
    std::list<sf::Time> frameTime;
    unsigned int framecount = 0;
    unsigned int fps = 60;
    sf::Time elapsed;
    sf::Time frameDuration = sf::seconds(1/(double)(fps));

    // system info stuff
    // doesnt work, useless, but for futur... maybe
    struct sysinfo memInfo;
    long long physMemUsed = memInfo.totalram - memInfo.freeram;

    while (window.isOpen())
    {
        // keep real frame time
        frameTime.push_back(clock.restart());
        // Event management
        // TODO: A Threader
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        // Clear display
        window.clear();
        // Draw something
        // TODO: a threader, migrer au manager
        window.draw(shape);

        // calcul et ajuste fps
        elapsed = clock.getElapsedTime();
        ++framecount;
        // du temps en plus
        if( elapsed < frameDuration ){
            // sleep until frameDuration reached
            sf::sleep( frameDuration - elapsed );
        }
        // on display apres le sleep, que le thread compute profite du temps restant
        window.display();

        // fps display toutes les 60 frames
        if (framecount > 30)
        {
            sf::Time tmp;
            // moyenne
            for (const auto &it : frameTime)
                tmp += it;
            tmp = tmp/(float)30;
            cout<<flush<< "\r FrameRate : " << int(1/tmp.asSeconds()) << "fps     Memory : " << physMemUsed << "Mb   ";
            frameTime.clear();
            framecount=0;
        }
    }
    return 0;
}

