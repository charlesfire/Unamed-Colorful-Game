#ifndef PHYSICOBJECT_HPP
#define PHYSICOBJECT_HPP

#include <string>

class AABB;

class PhysicObject
{
    public:
        PhysicObject();
        virtual ~PhysicObject();
        virtual void onColliding(const PhysicObject* other, const AABB* otherBox);
        virtual void onPositionUpdate(AABB* selfBox);
};

#endif // PHYSICOBJECT_HPP
