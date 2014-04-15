#include "Game.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/System/Vector2.hpp>

Game::Game() : m_window()
{
    //ctor
}

Game::~Game()
{
    //dtor
}

void Game::Setup()
{
    m_window.create(sf::VideoMode(256, 128, 32), "Unnamed Color Game", sf::Style::None);
    sf::Texture splashScreenTexture;
    if(!splashScreenTexture.loadFromFile("Ressources/Images/splashscreen.png"))
        return;
    sf::Sprite splashScreenSprite;
    splashScreenSprite.setTexture(splashScreenTexture);
    m_window.draw(splashScreenSprite);
    m_window.display();
    m_window.setSize(sf::Vector2u(640, 320));
}

void Game::Run()
{
    while (m_window.isOpen())
    {
        sf::Event event;
        while (m_window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                m_window.close();
        }
        m_window.clear();
        m_window.display();
    }
}
