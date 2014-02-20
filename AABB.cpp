#include <algorithm>
#include "AABB.hpp"

AABB::AABB() : m_position(0.f, 0.f), m_dimension(0.f, 0.f)
{
    //ctor
}

AABB::AABB(sf::Vector2f& position, sf::Vector2f& dimension) : m_position(position), m_dimension(dimension)
{

}

AABB::AABB(float x, float y, float width, float height) : m_position(x, y), m_dimension(width, height)
{

}

AABB::~AABB()
{
    //dtor
}

bool AABB::isColliding(AABB& other)
{
    if((other.m_position.x >= m_position.x + m_dimension.x)
        || (other.m_position.x + other.m_dimension.x <= m_position.x)
        || (other.m_position.y >= m_position.y + m_dimension.y)
        || (other.m_position.y + other.m_dimension.y <= m_position.y))
          return false;
   else
          return true;
}

sf::Vector2f AABB::getMaximumDisplacement(AABB& other, sf::Vector2f displacement)
{
    if(other.m_position.x < m_position.x + m_dimension.x)
        displacement.x-=(m_position.x+m_dimension.x)-other.m_position.x;
    if(other.m_position.x + other.m_dimension.x > m_position.x)
        displacement.x-=m_position.x-(other.m_position.x+other.m_dimension.x);

    if(other.m_position.y < m_position.y + m_dimension.y)
        displacement.y-=(m_position.y+m_dimension.y)-other.m_position.y;
    if(other.m_position.y + other.m_dimension.y > m_position.y)
        displacement.y-=m_position.y-(other.m_position.y+other.m_dimension.y);
    return displacement;
}
