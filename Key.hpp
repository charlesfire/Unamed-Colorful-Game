#ifndef KEY_HPP
#define KEY_HPP

#include <SFML/Graphics/Drawable.hpp>
#include "PhysicObject.hpp"
#include "AnimatedSprite.hpp"

class Key : public sf::Drawable, public PhysicObject
{
    public:
        Key();
        virtual ~Key();
        void update(float elapsedTime);
        virtual void draw(sf::RenderTarget &target, sf::RenderStates states)const;
    protected:
        AnimatedSprite m_sprite;
};

#endif // KEY_HPP
