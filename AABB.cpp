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
