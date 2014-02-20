#ifndef AABB_HPP
#define AABB_HPP

#include <SFML/System/Vector2.hpp>
#include <SFML/Config.hpp>

#define MaxIterationCount = 10

enum CollisionFlag : sf::Uint8{solid1, solid2, damage1, damage2};

class AABB
{
    public:
        AABB();
        AABB(sf::Vector2f& position, sf::Vector2f& dimension);
        AABB(float x, float y, float width, float height);
        virtual ~AABB();
        bool isColliding(AABB& other);
        sf::Vector2f getMaximumDisplacement(AABB& other, sf::Vector2f displacement);
        sf::Vector2f m_position, m_dimension;
        CollisionFlag m_flag;
};

#endif // AABB_HPP
