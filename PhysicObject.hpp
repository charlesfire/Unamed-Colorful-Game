#ifndef PHYSICOBJECT_HPP
#define PHYSICOBJECT_HPP

#include <string>

class AABB;

class PhysicObject
{
    public:
        PhysicObject();
        virtual ~PhysicObject();
        virtual void onColliding(PhysicObject* other);
        virtual void onPositionUpdate(AABB* selfBox);
};

#endif // PHYSICOBJECT_HPP
