#include "PhysicObject.hpp"

PhysicObject::PhysicObject()
{
    //ctor
}

PhysicObject::~PhysicObject()
{
    //dtor
}

void PhysicObject::onColliding(const PhysicObject* other, const AABB* otherBox)
{

}

void PhysicObject::onPositionUpdate(AABB* selfBox)
{

}
