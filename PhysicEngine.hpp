#ifndef PHYSICENGINE_HPP
#define PHYSICENGINE_HPP

#include <map>
#include "Singleton.hpp"

class PhysicObject;
class DynamicAABB;
class AABB;

class PhysicEngine : public Singleton<PhysicEngine>
{
    friend class Singleton<PhysicEngine>;
    public:
        virtual ~PhysicEngine();
        void setup();
        void update(float elapsedTime);
        void addDynamicBoxToObject(PhysicObject* object, DynamicAABB* boundingBox);
        void addStaticBoxToObject(PhysicObject* object, AABB* boundingBox);
    protected:
        PhysicEngine();
        std::multimap<PhysicObject*, DynamicAABB*> m_dynamicEntities;
        std::multimap<PhysicObject*, AABB*> m_physicEntities;
};

#endif // PHYSICENGINE_HPP
