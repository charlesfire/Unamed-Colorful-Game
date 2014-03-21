#ifndef TESTINGOBJECT_HPP
#define TESTINGOBJECT_HPP

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/System/Vector2.hpp>
#include "PhysicObject.hpp"

class DynamicAABB;
class PhysicEngine;

class TestingObject : public PhysicObject, public sf::Drawable
{
    public:
        TestingObject(sf::Vector2f position, sf::Vector2f dimension, sf::Vector2f velocity, sf::Vector2f acceleration);
        virtual ~TestingObject();
        void draw(sf::RenderTarget& target, sf::RenderStates states)const;
        void onPositionUpdate(AABB* selfBox);
        void onColliding(PhysicObject* other);
    protected:
        DynamicAABB* m_box;
        sf::RectangleShape m_shape;
};

#endif // TESTINGOBJECT_HPP
