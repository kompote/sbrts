
#include <iostream>
#include <SFML/Graphics.hpp>
#include <list>
#include "sys/sysinfo.h"
using namespace std;

int main()
{
    /* cout << "Version " << sbrts_VERSION_MAJOR << "." << sbrts_VERSION_MINOR << endl; */
    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);
    sf::Clock clock;
    std::list<float> frameTime;
    unsigned int framecount = 0;
    struct sysinfo memInfo;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear();
        window.draw(shape);
        window.display();

        frameTime.push_back( 1/clock.restart().asSeconds());
        framecount++;
        if (framecount > 150)
        {

            long long physMemUsed = memInfo.totalram - memInfo.freeram;
                //Multiply in next statement to avoid int overflow on right hand side...
                //    physMemUsed *= memInfo.mem_unit;
            float tmp =0;
            for (const auto &it : frameTime)
                tmp += it;
            tmp = tmp/150;
            cout<<flush<< "\r FrameRate : " << int(tmp) << "fps     Memory : " << physMemUsed << "Mb   ";
            frameTime.clear();
            framecount=0;
        }
    }
    return 0;
}

