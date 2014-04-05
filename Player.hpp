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
        void onPositionUpdate(AABB* selfBox);
        void onColliding(const PhysicObject* other, const AABB* otherBox);
        void draw(sf::RenderTarget& target, sf::RenderStates states)const;
    protected:
        sf::Sprite m_sprite;
        DynamicAABB* m_box;
        bool m_onGround;
};

#endif // PLAYER_HPP
