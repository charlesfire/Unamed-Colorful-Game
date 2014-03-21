#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include "PhysicObject.hpp"

class DynamicAABB;

class Player : public sf::Drawable, public PhysicObject
{
    public:
        Player();
        virtual ~Player();
        void update();
    protected:
        sf::Sprite m_sprite;
        DynamicAABB* m_box;
};

#endif // PLAYER_HPP
