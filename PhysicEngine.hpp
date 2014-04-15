#ifndef PHYSICENGINE_HPP
#define PHYSICENGINE_HPP

#include <map>
#include <memory>
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
        void addDynamicBoxToObject(PhysicObject* object, std::shared_ptr<DynamicAABB> boundingBox);
        void addStaticBoxToObject(PhysicObject* object, std::shared_ptr<AABB> boundingBox);
    protected:
        PhysicEngine();
        std::multimap<PhysicObject*, std::shared_ptr<DynamicAABB>> m_dynamicEntities;
        std::multimap<PhysicObject*, std::shared_ptr<AABB>> m_physicEntities;
};

#endif // PHYSICENGINE_HPP
