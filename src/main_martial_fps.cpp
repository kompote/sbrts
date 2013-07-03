#include <iostream>
#include <stdlib.h>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

int main()
{
    int fps = 60;
    
    // sfml stuff to open a window
    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
    window.setVerticalSyncEnabled(true);
      
      
    // old sfml tutorial sample code to draw a circle
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    // fps stuff
    sf::Clock c;
    sf::Time elapsed;
    sf::Time frameDuration = sf::seconds(1/(double)(fps));
    
    // other stuff to change circle's color
    sf::Color color = sf::Color::Green;
    
    
    c.restart();
    while (window.isOpen())
    {

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        
        // changing color at each frame
        color.r += 1;
        shape.setFillColor(color);

        // drawing the screen after updates and before looking when we are in the frame duration
        // doesn't matter when we display this, it has to be ASAP and not at the "end" because we will not be precise on the FPS
        // maybe it's not good to display before end of frame duration... i don't know
        window.clear();
        window.draw(shape);
        window.display();
        
        // get elapsed time
        elapsed = c.getElapsedTime();
        // if we have not reached the frameDuration
        if( elapsed < frameDuration ){
            // sleep until frameDuration reached
            sf::sleep( frameDuration - elapsed );
        }
                
        // set clock to 0
        elapsed = c.restart();
        // print the frame duration ( after restarting clock so we don't create imprecision on the fps )
        std::cout << elapsed.asSeconds() << " " << 1/elapsed.asSeconds() << std::endl;

    }

    return EXIT_SUCCESS;
}

