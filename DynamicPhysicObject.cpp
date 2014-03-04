#include <algorithm>
#include "DynamicPhysicObject.hpp"

DynamicPhysicObject::DynamicPhysicObject()
{
    //ctor
}

DynamicPhysicObject::~DynamicPhysicObject()
{
    //dtor
}

bool DynamicPhysicObject::isColliding(const AABB& boundingBox)const
{
    if((boundingBox.m_position.x >= m_boundingBox.m_position.x + m_boundingBox.m_dimension.x)
        || (boundingBox.m_position.x + boundingBox.m_dimension.x <= m_boundingBox.m_position.x)
        || (boundingBox.m_position.y >= m_boundingBox.m_position.y + m_boundingBox.m_dimension.y)
        || (boundingBox.m_position.y + boundingBox.m_dimension.y <= m_boundingBox.m_position.y))
          return false;
   else
          return true;
}

void DynamicPhysicObject::moveOut(AABB& boundingBox, const sf::Vector2f& velocity)const
{
    sf::Vector2f minimumDisplacement;
    if(velocity.x<0)
        minimumDisplacement.x=boundingBox.m_position.x-(m_boundingBox.m_position.x+m_boundingBox.m_dimension.x);
    else
        minimumDisplacement.x=-(m_boundingBox.m_position.x-(boundingBox.m_position.x+boundingBox.m_dimension.x));

    if(velocity.y<0)
        minimumDisplacement.y=boundingBox.m_position.y-(m_boundingBox.m_position.y+m_boundingBox.m_dimension.y);
    else
        minimumDisplacement.y=-(m_boundingBox.m_position.y-(boundingBox.m_position.y+boundingBox.m_dimension.y));

    if(std::abs(minimumDisplacement.x)<std::abs(minimumDisplacement.y))
        minimumDisplacement.y=0.f;
    else
        minimumDisplacement.x=0.f;

    boundingBox.m_position-=minimumDisplacement;
}
