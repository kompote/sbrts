#include "config.h"
#include <iostream>
#include <SFML/Graphics.hpp>
using namespace std;

int main()
{
    cout << "Version " << test_VERSION_MAJOR << "." << test_VERSION_MINOR << endl;
    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

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
    }

    return 0;
}
