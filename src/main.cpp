#include <iostream>

#include <list>

#include "engine/advMap.h"
#include "engine/unit.h"
#include "utils/logger.h"
#include "utils/tools.h"

#include <SFML/Graphics.hpp>

const int TICKS_PER_SECOND = 30;  // game speed
const int SKIP_TICKS = 1000 / TICKS_PER_SECOND; // second ratio
const int MAX_FRAMESKIP = 5;  // max game update without draw

// screensize stuff
const unsigned int HUD_HEIGHT = 150;
unsigned int screenW = 800;
unsigned int screenH = 600;

const int MAP_EDGE_MOUSE_GAP = 20;

// global vars
sf::RenderWindow mainWindow(sf::VideoMode(800, 600), "SBRTS");    // global main window
using namespace engine;
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
    theMap.setViewSize(screenW, screenH);
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
//    DBG_WARN("Starting main");
//    DBG_ERROR("Starting main");
    debug("Game Speed: %u", TICKS_PER_SECOND);



    // Gamespeed control
    sf::Clock GameClock;

    //fps control
    sf::Clock FPSClock;
    std::list<float> frameTime;
    unsigned int framecount = 0;
    // Debug stuff
    // TODO : Utility class
    sf::Font _DebugFont;
    _DebugFont.loadFromFile("resources/fonts/Aero.ttf");
    sf::Text _DebugFPS("fps", _DebugFont,12);
    _DebugFPS.setPosition(750.0,5.0);
    sf::Text _DebugMEM("mem", _DebugFont,12);
    _DebugMEM.setPosition(750.0,20.0);

    // load the map
    theMap.loadMap("map01");
    // set the map view size
    theMap.setViewSize(screenW, screenH);
    // set the displayable map sprite
    sf::Sprite mapSprite;

    // first unit test
    Unit unit(NULL, 200,200);

    // map texture offscreen
    sf::RenderTexture rt;
    rt.create(3450,1800);
    // map display position
    int mapPosX = 0, mapPosY = 0;

    // calculate game next update
    long next_game_tick = GameClock.getElapsedTime().asMilliseconds();

    // selection box origin vector
    sf::Vector2i selRectOrg;
    bool bSelFromSelBox = false; // selection box indicator
    // map edge detection booleans
    bool moveToWest = false; 
    bool moveToEast= false; 
    bool moveToNorth = false; 
    bool moveToSouth = false; 
   
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
                // initiate selection rectangle
                case sf::Event::MouseButtonPressed:
                    if (event.mouseButton.button == sf::Mouse::Left)
                    {
                        selRectOrg.x = event.mouseButton.x + mapPosX;
                        selRectOrg.y = event.mouseButton.y + mapPosY;
                        debug("click mouse in map%d:%d", selRectOrg.x + mapPosX, selRectOrg.y + mapPosY);
                        // one shot selection
                        // create a small rect to detect unit inside
                        // arbitrary values

                        bool sel = sf::IntRect(event.mouseButton.x-3 + mapPosX, event.mouseButton.y-3 + mapPosY,6,6).contains((sf::Vector2i)unit.getPosition());

                        if (sel)
                            unit.select();
                        else
                            unit.unSelect();
                    }
                    break;

                // selection rectangle close
                case sf::Event::MouseButtonReleased:
                    if ( (event.mouseButton.button == sf::Mouse::Left) &&
                            bSelFromSelBox )
                    {

                        bool sel = sf::IntRect(selRectOrg,sf::Vector2i(event.mouseButton.x + mapPosX, event.mouseButton.y + mapPosY) - selRectOrg).contains((sf::Vector2i)unit.getPosition());

                        if (sel)
                            unit.select();
                        bSelFromSelBox = false; 
                    }
                    break;

                // move map on map edge
                case sf::Event::MouseMoved:
                    if (event.mouseMove.x < MAP_EDGE_MOUSE_GAP)
                        moveToWest = true;
                    else
                        moveToWest = false;
                    if (event.mouseMove.x > screenW - MAP_EDGE_MOUSE_GAP)
                        moveToEast = true;
                    else
                        moveToEast = false;
                    if (event.mouseMove.y < MAP_EDGE_MOUSE_GAP)
                        moveToNorth = true;
                    else
                        moveToNorth = false;
                    if (event.mouseMove.y > screenH - MAP_EDGE_MOUSE_GAP)
                        moveToSouth = true;
                    else
                        moveToSouth = false;
                    break;

                // keyboard event
                case sf::Event::KeyPressed:
                    switch(event.key.code)
                    {
                            case sf::Keyboard::F:
                                toggleFullscreen();
                                break;
                            case sf::Keyboard::Q:
                                mainWindow.close();
                                break;
                                /*
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
                                */
                            case sf::Keyboard::L:
                                Log.toggleLogFile();
                                break;
                            default:
                                break;
                    }
                    break;
                default:
                    break;
            }
        }
        //update game state when needed
       if(GameClock.getElapsedTime().asMilliseconds() > next_game_tick)
        {
            // render map
            rt.clear(sf::Color(20,20,20));
            theMap.redraw(rt, mapPosX, mapPosY);
            // render unit
            unit.draw(rt,SKIP_TICKS);
            // bug001
          //  rt.draw(sf::Text("toto",_DebugFont,12)); // if not, bug ??
            // Clear display
            mainWindow.clear(sf::Color(0, 14, 15));

            // render selection rectangle selBox
            if( sf::Mouse::isButtonPressed( sf::Mouse::Left ) )
            {
                sf::RectangleShape selBox = sf::RectangleShape( sf::Vector2f(sf::Mouse::getPosition(mainWindow).x + mapPosX  - selRectOrg.x,
                                                                sf::Mouse::getPosition(mainWindow).y + mapPosY - selRectOrg.y) );
                selBox.setPosition(static_cast<sf::Vector2f>(selRectOrg));
                selBox.setFillColor(sf::Color(100, 150, 100, 150));
                // to tell to button released event we where in selectionbox case
                bSelFromSelBox = true; 
                rt.draw( selBox );
            }
            else
            {
            
            }
            // move map on map edge
            if (moveToWest)
                if (mapPosX>=5)
                    mapPosX -= 5;
            if (moveToEast)
                if (mapPosX<=screenW-5)
                    mapPosX += 5;
            if (moveToNorth)
                if (mapPosY>=5)
                    mapPosY -= 5;
            if (moveToSouth)
                if (mapPosY<=screenH-5)
                    mapPosY += 5;
            // dram map, only displayable part
            mapSprite.setTexture(rt.getTexture());
            mapSprite.setTextureRect(sf::IntRect(mapPosX, mapPosY, screenW, screenH - HUD_HEIGHT));

            mainWindow.draw(mapSprite);
            // draw debug text
            mainWindow.draw(_DebugFPS);
            mainWindow.draw(_DebugMEM);


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
        //
        if (framecount > 30)
        {
            //sf::Time tmp;
            float tmp;
            // moyenne
            for (const auto &it : frameTime)
                tmp += it;
            tmp = tmp/(float)31;
            _DebugFPS.setString(sf::String(to_string((int)tmp) + " fps")) ;
            _DebugMEM.setString(sf::String(to_string(Tools::getRSS()/1000) + " Mo")) ;
            frameTime.clear();
            framecount=0;
        }
    }
    return 0;
}

