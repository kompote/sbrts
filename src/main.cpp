#include <iostream>

#include <list>

#include "engine/advMap.h"
#include "engine/unit.h"
#include "utils/logger.h"

#include <SFML/Graphics.hpp>

const int TICKS_PER_SECOND = 30;  // game speed
const int SKIP_TICKS = 1000 / TICKS_PER_SECOND; // second ratio
const int MAX_FRAMESKIP = 5;  // max game update without draw

// screensize stuff
const unsigned int HUD_HEIGHT = 150;
unsigned int screenW = 800;
unsigned int screenH = 600;

// global vars
sf::RenderWindow mainWindow(sf::VideoMode(800, 600), "SBRTS");    // global main window
AdvMap theMap;

// ----------------------------------------------------------------- toggleFullscreen
bool bfullscreen = false;
void toggleFullscreen() {
    if (!bfullscreen)
    {
        screenW = VideoMode::getDesktopMode().width;
        screenH = VideoMode::getDesktopMode().height;
    }
    else
    {
        screenW = 800;
        screenH = 600;
    }
    mainWindow.create(sf::VideoMode(screenW, screenH),"SBRTS");
    debug("Switching screen to %d:%d",screenW,screenH);
    bfullscreen = !bfullscreen;
}
// ----------------------------------------------------------------- getFPS
inline float getFPS(const sf::Time& time) {
         return (1000000.0f / time.asMicroseconds());
}
//float targetFPS = 60.0;
//float targetFrameTime = targetFPS*1000000.0f;
// ----------------------------------------------------------------- main
int main()
{

    DBG_INFO("Starting main");
    DBG_WARN("Starting main");
    DBG_ERROR("Starting main");



    // Gamespeed control
    sf::Clock GameClock;

    //fps control
    sf::Clock FPSClock;
    std::list<float> frameTime;
    unsigned int framecount = 0;
    // Debug stuff
    // TODO : Utility class
    sf::Font _DebugFont;
    _DebugFont.loadFromFile("resources/Aero.ttf");
    sf::Text _DebugFPS("fps", _DebugFont,12);
    _DebugFPS.setPosition(750.0,5.0);

    // load the map
    theMap.loadMap("map01");
    sf::Sprite mapSprite;

    // first unit test
    Unit unit;

    // map texture offscreen
    sf::RenderTexture rt;
    rt.create(3450,1800);
    // map display position
    int mapPosX = 0, mapPosY = 0;

    // calculate game next update
    long next_game_tick = GameClock.getElapsedTime().asMilliseconds();

    while (mainWindow.isOpen())
    {
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
                            case sf::Keyboard::L:
                                Log.toggleLogFile();
                            case sf::Keyboard::T:
                                DBG_WARN("Starting main");
                            default:
                                break;
                    }
                    break;
                default:
                    break;
            }
        }
        //update game state when needed
     //  while( GameClock.getElapsedTime().asMilliseconds() > next_game_tick && loops < MAX_FRAMESKIP)
       if(GameClock.getElapsedTime().asMilliseconds() > next_game_tick)
        {
            // render map
            rt.clear(sf::Color(20,20,20));
            theMap.redraw(rt);
            // render unit
            unit.Redraw(rt);
            // bug001
            rt.draw(sf::Text("toto",_DebugFont,12)); // if not, bug ??
            // Clear display
            mainWindow.clear(sf::Color(0, 14, 15));

            // dram map, only displayable part
            mapSprite.setTexture(rt.getTexture());
            mapSprite.setTextureRect(sf::IntRect(mapPosX, mapPosY, screenW, screenH - HUD_HEIGHT));

            mainWindow.draw(mapSprite);
            // draw fps text
            mainWindow.draw(_DebugFPS);

            // set next update tick
            next_game_tick += SKIP_TICKS;
        }

        ++framecount;

        rt.display();
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
            tmp = tmp/(float)31;
            _DebugFPS.setString(sf::String(to_string((int)tmp) + " fps")) ;
            frameTime.clear();
            framecount=0;
        }
    }
    return 0;
}

