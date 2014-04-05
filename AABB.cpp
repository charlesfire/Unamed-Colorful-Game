#include "AABB.hpp"

AABB::AABB() : m_position(0.f, 0.f), m_dimension(0.f, 0.f)
{
    //ctor
}

AABB::AABB(const AABB& other) : m_position(other.m_position), m_dimension(other.m_dimension)
{

}

AABB::AABB(sf::Vector2f position, sf::Vector2f dimension) : m_position(position), m_dimension(dimension)
{

}

AABB::AABB(float x, float y, float width, float height) : m_position(x, y), m_dimension(width, height)
{

}

AABB::~AABB()
{
    //dtor
}

bool AABB::isColliding(const AABB& other)const
{
    if((other.m_position.x >= m_position.x + m_dimension.x)
        || (other.m_position.x + other.m_dimension.x <= m_position.x)
        || (other.m_position.y >= m_position.y + m_dimension.y)
        || (other.m_position.y + other.m_dimension.y <= m_position.y))
          return false;
   else
          return true;
}

CollisionOrientation AABB::getCollisionOrientation(const AABB& other)const
{
    if(other.m_position.x >= m_position.x + m_dimension.x)
        return CollisionOrientation::Right;
    else if(other.m_position.x + other.m_dimension.x <= m_position.x)
        return CollisionOrientation::Left;
    else if(other.m_position.y >= m_position.y + m_dimension.y)
        return CollisionOrientation::Bottom;
    else
        return CollisionOrientation::Top;
}
