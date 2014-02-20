#ifndef GAME_HPP
#define GAME_HPP

#include <SFML/Graphics/RenderWindow.hpp>

class Game
{
    public:
        Game();
        virtual ~Game();
        void Setup();
        void Run();
    protected:
        sf::RenderWindow m_window;
};

#endif // GAME_HPP
