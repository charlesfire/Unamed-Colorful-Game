#include <SFML/Graphics.hpp>
#include <iostream>
#include "TestingObject.hpp"
#include "PhysicEngine.hpp"
#include "TileMap.hpp"
#include "Player.hpp"
#include "AABB.hpp"

int main()
{
    /*CollisionFlags flags1, flags2;
    flags1=(CollisionFlags)(CollisionFlags::solidPurple|CollisionFlags::solidGreen);
    flags2=(CollisionFlags)(CollisionFlags::solidPurple|CollisionFlags::solidGreen);
    if((flags1&flags2))
        std::cout<<(int)((flags1&flags2)&CollisionFlags::solidGreen);*/
    PhysicEngine* eng(PhysicEngine::getInstance());
    sf::Clock clock;
    Player myPlayer;

    sf::Image tileChart, tiles, compressedMapImage;
    tileChart.loadFromFile("TileChart.png");
    tiles.loadFromFile("Tiles.png");
    compressedMapImage.loadFromFile("Map.png");
    TileMap myMap;
    myMap.buildTileMap(tileChart, tiles, compressedMapImage);

    sf::RenderWindow window(sf::VideoMode(1200, 600), "My window");
    window.setFramerateLimit(60.f);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            myPlayer.handleEvent(event);
            if (event.type == sf::Event::Closed)
                window.close();
        }

        eng->update(clock.getElapsedTime().asSeconds());
        std::cout<<"fps: "<<1.f/clock.getElapsedTime().asSeconds()<<std::endl;
        clock.restart();

        window.clear(sf::Color::Black);

        window.draw(myMap);
        window.draw(myPlayer);

        window.display();
    }
    return 0;
}
