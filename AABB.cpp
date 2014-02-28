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
    float x, y;
    if(displacement.x<0)
        x=other.m_position.x-(m_position.x+m_dimension.x);
    else
        x=-(m_position.x-(other.m_position.x+other.m_dimension.x));

    if(displacement.y<0)
        y=other.m_position.y-(m_position.y+m_dimension.y);
    else
        y=-(m_position.y-(other.m_position.y+other.m_dimension.y));

    sf::Vector2f vec(0.f, 0.f);

    if(std::abs(x)<std::abs(y))
        vec.x=x;
    else
        vec.y=y;

    other.m_position-=vec;
    return vec;
}
