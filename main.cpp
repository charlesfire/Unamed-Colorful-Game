#include <SFML/Graphics.hpp>
#include "TestingObject.hpp"
#include "PhysicEngine.hpp"
#include "TileMap.hpp"

int main()
{
    PhysicEngine* eng(PhysicEngine::getInstance());
    sf::Clock clock;
    TestingObject obj1(sf::Vector2f(0.f, 0.f), sf::Vector2f(64.f, 64.f), sf::Vector2f(0.f, 0.f), sf::Vector2f(0.f, 156.8f));

    sf::Image tileChart, tiles, compressedMapImage;
    tileChart.loadFromFile("TileChart.png");
    tiles.loadFromFile("Tiles.png");
    compressedMapImage.loadFromFile("Map.png");
    TileMap myMap;
    myMap.buildTileMap(tileChart, tiles, compressedMapImage);

    sf::RenderWindow window(sf::VideoMode(1366, 768), "My window");

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
        clock.restart();

        window.clear(sf::Color::Black);

        window.draw(myMap);
        window.draw(obj1);

        window.display();
    }
    return 0;
}
