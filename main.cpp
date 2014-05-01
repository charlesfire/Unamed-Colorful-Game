#include <SFML/Graphics.hpp>
//#include <iostream>
//#include <sstream>
#include "TextureManager.hpp"
#include "PhysicEngine.hpp"
#include "TileMap.hpp"
#include "Player.hpp"
#include "Key.hpp"
#include "AnimatedSprite.hpp"

int main()
{
    bool hasFocus(true);
    PhysicEngine* eng(PhysicEngine::getInstance());
    Player myPlayer;
    Key myKey;

    sf::Image tileChart, tiles, compressedMapImage;
    tileChart.loadFromFile("TileChart.png");
    tiles.loadFromFile("Tiles.png");
    compressedMapImage.loadFromFile("Map.png");
    TileMap myMap;
    myMap.buildTileMap(tileChart, tiles, compressedMapImage);

    sf::RenderWindow window(sf::VideoMode(1366, 768), "Unnamed Colorful Game", sf::Style::Fullscreen);
    //window.setFramerateLimit(240.f);
    sf::View myView(window.getDefaultView());

    sf::Clock clock;

    while(window.isOpen()&&hasFocus&&!myPlayer.isDead())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::GainedFocus)
                hasFocus=true;
            else if (event.type == sf::Event::LostFocus)
                hasFocus==false;
            else if (event.type == sf::Event::Closed || (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape))
                window.close();
            else
                myPlayer.handleEvent(event);
        }

        myKey.update(clock.getElapsedTime().asSeconds());
        eng->update(clock.restart().asSeconds());
        //std::stringstream ss;
        //ss<<"Fps: "<<1.f/clock.restart().asSeconds();
        //window.setTitle(ss.str());

        myView.setCenter(myPlayer.getPosition());
        window.setView(myView);

        window.clear(sf::Color::Black);

        window.draw(myMap);
        window.draw(myPlayer);
        window.draw(myKey);

        window.display();
    }
    return 0;
}
