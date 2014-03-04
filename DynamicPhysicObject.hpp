#ifndef DYNAMICPHYSICOBJECT_HPP
#define DYNAMICPHYSICOBJECT_HPP

#include "AABB.hpp"
#include "PhysicObject.hpp"

class DynamicPhysicObject : public PhysicObject
{
    public:
        DynamicPhysicObject();
        virtual ~DynamicPhysicObject();
        virtual bool isColliding(const AABB& boundingBox)const;
        virtual void moveOut(AABB& boundingBox, const sf::Vector2f& velocity)const;
    protected:
        AABB m_boundingBox;
        sf::Vector2f m_velocity;
        sf::Vector2f m_acceleration;
        sf::Vector2f m_gravityMultiplier;
};

#endif // DYNAMICPHYSICOBJECT_HPP
