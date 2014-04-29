#include "PhysicObject.hpp"

PhysicObject::PhysicObject()
{
    //ctor
}

PhysicObject::~PhysicObject()
{
    //dtor
}

void PhysicObject::onColliding(const PhysicObject* other, const std::shared_ptr<AABB>& otherBox)
{

}

void PhysicObject::onPositionUpdate(std::shared_ptr<AABB> selfBox, float elapsedTime)
{

}
