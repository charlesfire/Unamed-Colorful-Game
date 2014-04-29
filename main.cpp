#include <SFML/Graphics.hpp>
#include <iostream>
#include <sstream>
#include "TextureManager.hpp"
#include "PhysicEngine.hpp"
#include "TileMap.hpp"
#include "Player.hpp"
#include "AnimatedSprite.hpp"

int main()
{
    /*AnimatedSprite anim("pizza", {sf::IntRect(0, 0, 32, 32), sf::IntRect(32, 0, 32, 32), sf::IntRect(64, 0, 32, 32)});
    anim.playAnimation("pizza", 1);
    anim.setTexture(TextureManager::getInstance()->getTexture("TestAnim.png"));*/

    bool hasFocus(true);
    PhysicEngine* eng(PhysicEngine::getInstance());
    Player myPlayer;

    sf::Image tileChart, tiles, compressedMapImage;
    tileChart.loadFromFile("TileChart.png");
    tiles.loadFromFile("Tiles.png");
    compressedMapImage.loadFromFile("Map.png");
    TileMap myMap;
    myMap.buildTileMap(tileChart, tiles, compressedMapImage);

    sf::RenderWindow window(sf::VideoMode(1200, 600), "My window");
    window.setFramerateLimit(60.f);
    sf::View myView(window.getDefaultView());

    sf::Clock clock;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::GainedFocus)
                hasFocus=true;
            else if (event.type == sf::Event::LostFocus)
                hasFocus==false;
            else if (event.type == sf::Event::Closed)
                window.close();
            else
                myPlayer.handleEvent(event);
        }

        if(hasFocus)
        {
            eng->update(clock.getElapsedTime().asSeconds());
            anim.update(clock.getElapsedTime().asSeconds());
            std::stringstream ss;
            ss<<"Fps: "<<1.f/clock.restart().asSeconds();
            window.setTitle(ss.str());

            myView.setCenter(myPlayer.getPosition());
            window.setView(myView);

            window.clear(sf::Color::Black);

            window.draw(myMap);
            window.draw(myPlayer);
            window.draw(anim);

            window.display();
        }
    }
    return 0;
}
