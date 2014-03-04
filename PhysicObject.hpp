#ifndef PHYSICOBJECT_HPP
#define PHYSICOBJECT_HPP

#include <SFML/System/Vector2.hpp>

class AABB;

class PhysicObject
{
    public:
        PhysicObject();
        virtual ~PhysicObject();
        virtual bool isColliding(const AABB& boundingBox)const=0;
        virtual void moveOut(AABB& boundingBox, const sf::Vector2f& velocity)const=0;
};

#endif // PHYSICOBJECT_HPP
