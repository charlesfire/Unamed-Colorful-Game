#include "Game.hpp"
#include "AABB.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
    /*Game* myGame = new Game();
    myGame->Setup();
    myGame->Run();
    return 0;*/

    sf::RenderWindow window(sf::VideoMode(800, 600), "My window");
    window.setFramerateLimit(15);

    sf::RectangleShape staticShape, mouseFolowingShape;
    staticShape.setFillColor(sf::Color::Cyan);
    staticShape.setPosition(window.getSize().x/2, window.getSize().y/2);
    staticShape.setSize(sf::Vector2f(50.f, 50.f));

    mouseFolowingShape.setFillColor(sf::Color::Green);
    mouseFolowingShape.setPosition(window.getSize().x/2, window.getSize().y/2);
    mouseFolowingShape.setSize(sf::Vector2f(75.f, 75.f));

    AABB staticShapeBox(window.getSize().x/2, window.getSize().y/2, 50.f, 50.f);
    AABB mouseFolowingShapeBox(window.getSize().x/2, 0.f, 75.f, 75.f);

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

        mouseFolowingShapeBox.m_position.y+=2.f;
        if(mouseFolowingShapeBox.isColliding(staticShapeBox))
        {
            mouseFolowingShapeBox.m_position+=staticShapeBox.getMaximumDisplacement(mouseFolowingShapeBox, sf::Vector2f(0.f, 2.f));
            mouseFolowingShapeBox.m_position.y-=2.f;
            mouseFolowingShape.setFillColor(sf::Color::Red);
        }
        else
        {
            mouseFolowingShape.setFillColor(sf::Color::Green);
        }
        mouseFolowingShape.setPosition(mouseFolowingShapeBox.m_position);

        window.clear(sf::Color::Black);

        window.draw(staticShape);
        window.draw(mouseFolowingShape);

        window.display();
    }

    return 0;
}
