#include "Game.hpp"
#include "AABB.hpp"
#include "TileMap.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>

int main()
{
    /*Game* myGame = new Game();
    myGame->Setup();
    myGame->Run();
    return 0;*/

    TileMap myMap;
    sf::Image tileChart, tiles, compressedMapImage;
    tileChart.loadFromFile("TileChart.png");
    tiles.loadFromFile("Tiles.png");
    compressedMapImage.loadFromFile("Antoine.png");
    myMap.buildTileMap(tileChart, tiles, compressedMapImage);

    sf::RenderWindow window(sf::VideoMode(1366, 768), "My window");
    window.setFramerateLimit(30.f);

    sf::RectangleShape staticShape, mouseFolowingShape;
    staticShape.setFillColor(sf::Color::Cyan);
    staticShape.setPosition(window.getSize().x/2, window.getSize().y/2);
    staticShape.setSize(sf::Vector2f(50.f, 50.f));

    mouseFolowingShape.setFillColor(sf::Color::Green);
    mouseFolowingShape.setPosition(window.getSize().x/2, window.getSize().y/2);
    mouseFolowingShape.setSize(sf::Vector2f(75.f, 75.f));

    AABB staticShapeBox(window.getSize().x/2, window.getSize().y/2, 50.f, 50.f);
    AABB mouseFolowingShapeBox(0.f, 0.f, 75.f, 75.f);

    sf::Vector2f lastPos(0.f, 0.f);

    // on fait tourner le programme jusqu'à ce que la fenêtre soit fermée
    while (window.isOpen())
    {
        // on inspecte tous les évènements de la fenêtre qui ont été émis depuis la précédente itération
        sf::Event event;
        while (window.pollEvent(event))
        {
            // évènement "fermeture demandée" : on ferme la fenêtre
            if (event.type == sf::Event::Closed)
                window.close();
        }

        lastPos=mouseFolowingShapeBox.m_position;
        mouseFolowingShapeBox.m_position=(sf::Vector2f)sf::Mouse::getPosition();
        if(mouseFolowingShapeBox.isColliding(staticShapeBox))
        {
            staticShapeBox.getMaximumDisplacement(mouseFolowingShapeBox, mouseFolowingShapeBox.m_position-lastPos);
            mouseFolowingShape.setFillColor(sf::Color::Red);
        }
        else
        {
            mouseFolowingShape.setFillColor(sf::Color::Green);
        }
        mouseFolowingShape.setPosition(mouseFolowingShapeBox.m_position);

        window.clear(sf::Color::Black);

        window.draw(myMap);
        window.draw(staticShape);
        window.draw(mouseFolowingShape);

        window.display();
    }

    return 0;
}
