#ifndef PHYSICOBJECT_HPP
#define PHYSICOBJECT_HPP

#include <string>
#include <memory>

class AABB;

class PhysicObject
{
    public:
        PhysicObject();
        virtual ~PhysicObject();
        virtual void onColliding(const PhysicObject* other, const std::shared_ptr<AABB>& otherBox);
        virtual void onPositionUpdate(std::shared_ptr<AABB> selfBox, float elapsedTime);
};

#endif // PHYSICOBJECT_HPP
