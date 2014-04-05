#include "PhysicEngine.hpp"

#include <SFML/System/Vector2.hpp>
#include <iostream>
#include "PhysicObject.hpp"
#include "DynamicAABB.hpp"

PhysicEngine::PhysicEngine() : m_dynamicEntities(), m_physicEntities()
{
    //ctor
}

PhysicEngine::~PhysicEngine()
{
    //dtor
}

void PhysicEngine::setup()
{

}

void PhysicEngine::update(float elapsedTime)
{
    std::map<float, std::pair<PhysicObject*, AABB*>> collisionList;
    #ifdef __DEBUG__
        int nbrOfCollision(0);
    #endif
    for(std::map<PhysicObject*, DynamicAABB*>::iterator it(m_dynamicEntities.begin()); it!=m_dynamicEntities.end(); ++it)
    {
        //update position
        it->second->m_position.x+=(it->second->m_velocity.x*elapsedTime)+(0.5f*it->second->m_acceleration.x*elapsedTime*elapsedTime);
        it->second->m_position.y+=(it->second->m_velocity.y*elapsedTime)+(0.5f*it->second->m_acceleration.y*elapsedTime*elapsedTime);
        //update velocity
        it->second->m_velocity.x+=it->second->m_acceleration.x*elapsedTime;
        it->second->m_velocity.y+=it->second->m_acceleration.y*elapsedTime;

        //collision testing
        collisionList.clear();
        for(std::map<PhysicObject*, AABB*>::iterator it2(m_physicEntities.begin()); it2!=m_physicEntities.end(); ++it2)
        {
            if((it->second!=it2->second)&&(it->second->isColliding(*it2->second)))
            {
                #ifdef __DEBUG__
                    nbrOfCollision++;
                #endif
                collisionList.insert(std::pair<float, std::pair<PhysicObject*, AABB*>>((it->second->m_position.x-it2->second->m_position.x)*(it->second->m_position.x-it2->second->m_position.x)+(it->second->m_position.y-it2->second->m_position.y)*(it->second->m_position.y-it2->second->m_position.y), *it2));
            }
        }
        for(std::map<float, std::pair<PhysicObject*, AABB*>>::iterator it2(collisionList.begin()); it2!=collisionList.end(); ++it2)
        {
            if((it->second->isColliding(*it2->second.second)))
            {
                it->second->moveOut(*it2->second.second);
                it->first->onColliding(it2->second.first, it2->second.second);
                it2->second.first->onColliding(it->first, it->second);
            }
        }
        //update visual position
        it->first->onPositionUpdate(it->second);
    }
    #ifdef __DEBUG__
        std::cout<<"nbr of collisions: "<<nbrOfCollision<<std::endl;
    #endif
}

void PhysicEngine::addDynamicBoxToObject(PhysicObject* object, DynamicAABB* boundingBox)
{
    addStaticBoxToObject(object, boundingBox);
    m_dynamicEntities.insert(std::pair<PhysicObject*, DynamicAABB*>(object, boundingBox));
}

void PhysicEngine::addStaticBoxToObject(PhysicObject* object, AABB* boundingBox)
{
    m_physicEntities.insert(std::pair<PhysicObject*, AABB*>(object, boundingBox));
}
