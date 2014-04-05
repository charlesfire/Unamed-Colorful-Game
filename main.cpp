#include <SFML/Graphics.hpp>
#include <iostream>
#include "TestingObject.hpp"
#include "PhysicEngine.hpp"
#include "TileMap.hpp"
#include "Player.hpp"

int main()
{
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

    // on fait tourner le programme jusqu'� ce que la fen�tre soit ferm�e
    while (window.isOpen())
    {
        // on inspecte tous les �v�nements de la fen�tre qui ont �t� �mis depuis la pr�c�dente it�ration
        sf::Event event;
        while (window.pollEvent(event))
        {
            // �v�nement "fermeture demand�e" : on ferme la fen�tre
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
