#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Sprite.hpp>
//#include "AnimatedSprite.hpp"
#include "PhysicObject.hpp"

class DynamicAABB;
namespace sf
{
    class Event;
}

class Player : public sf::Drawable, public PhysicObject
{
    public:
        Player();
        virtual ~Player();
        void handleEvent(const sf::Event& event);
        void onPositionUpdate(std::shared_ptr<AABB> selfBox, float elapsedTime);
        void onColliding(const PhysicObject* other, const std::shared_ptr<AABB>& otherBox);
        sf::Vector2f getPosition()const;
        bool isDead()const;
    protected:
        //AnimatedSprite m_sprite;
        sf::Sprite m_sprite;
        std::shared_ptr<DynamicAABB> m_box;
        bool m_onGround;
        bool m_isPurple;
        bool m_isMovingRight;
        bool m_isDead;

        void draw(sf::RenderTarget& target, sf::RenderStates states)const;
};

#endif // PLAYER_HPP
