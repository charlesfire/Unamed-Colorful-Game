#include "DynamicAABB.hpp"
#include <algorithm>

DynamicAABB::DynamicAABB() : AABB(), m_velocity(), m_acceleration()
{
    //ctor
}

DynamicAABB::DynamicAABB(const DynamicAABB& other) : AABB(other), m_velocity(other.m_velocity), m_acceleration(other.m_acceleration)
{

}

DynamicAABB::DynamicAABB(sf::Vector2f position, sf::Vector2f dimension, sf::Vector2f velocity, sf::Vector2f acceleration, CollisionFlags flags) : AABB(position, dimension, flags), m_velocity(velocity), m_acceleration(acceleration)
{

}

DynamicAABB::DynamicAABB(float x, float y, float width, float height, float xVelocity, float yVelocity, float xAcceleration, float yAcceleration, CollisionFlags flags) : AABB(x, y, width, height, flags), m_velocity(xVelocity, yVelocity), m_acceleration(xAcceleration, yAcceleration)
{

}

DynamicAABB::~DynamicAABB()
{
    //dtor
}

void DynamicAABB::moveOut(AABB& other)
{
    sf::Vector2f minimumDisplacement;
    if(m_velocity.x<0.f)
        minimumDisplacement.x=m_position.x-(other.m_position.x+other.m_dimension.x);
    else
        minimumDisplacement.x=-(other.m_position.x-(m_position.x+m_dimension.x));

    if(m_velocity.y<0.f)
        minimumDisplacement.y=m_position.y-(other.m_position.y+other.m_dimension.y);
    else
        minimumDisplacement.y=-(other.m_position.y-(m_position.y+m_dimension.y));

    if(std::abs(minimumDisplacement.y)<=std::abs(minimumDisplacement.x))
        minimumDisplacement.x=0.f;
    else
        minimumDisplacement.y=0.f;

    m_position-=minimumDisplacement;
    m_velocity-=minimumDisplacement;
}
