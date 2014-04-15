#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Sprite.hpp>
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
        void onPositionUpdate(std::shared_ptr<AABB> selfBox);
        void onColliding(const PhysicObject* other, const std::shared_ptr<AABB>& otherBox);
        void draw(sf::RenderTarget& target, sf::RenderStates states)const;
    protected:
        sf::Sprite m_sprite;
        sf::Vector2f m_lastPosition;
        std::shared_ptr<DynamicAABB> m_box;
        bool m_onGround;
};

#endif // PLAYER_HPP
