#ifndef AABB_HPP
#define AABB_HPP

#include <SFML/System/Vector2.hpp>
#include <SFML/Config.hpp>

enum CollisionFlags : sf::Uint8{noCollision=0, solidGreen=64, solidPurple=128};

enum CollisionOrientation{Top, Bottom, Right, Left};

class AABB
{
    public:
        AABB();
        AABB(const AABB& other);
        AABB(sf::Vector2f position, sf::Vector2f dimension, CollisionFlags flags=CollisionFlags::noCollision);
        AABB(float x, float y, float width, float height, CollisionFlags flags=CollisionFlags::noCollision);
        virtual ~AABB();
        bool isColliding(const AABB& boundingBox)const;
        CollisionOrientation getCollisionOrientation(const AABB& other)const;

        sf::Vector2f m_position, m_dimension;
        CollisionFlags m_flags;
};

#endif // AABB_HPP
