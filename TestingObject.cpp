#include "TestingObject.hpp"

#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/RenderStates.hpp>
#include "PhysicEngine.hpp"
#include "DynamicAABB.hpp"

TestingObject::TestingObject(sf::Vector2f position, sf::Vector2f dimension, sf::Vector2f velocity, sf::Vector2f acceleration) : m_shape(dimension), m_box(nullptr)
{
    m_shape.setPosition(position);
    m_shape.setFillColor(sf::Color::Blue);
    m_box=new DynamicAABB(position, dimension, velocity, acceleration);
    PhysicEngine::getInstance()->addDynamicBoxToObject(this, m_box);
}

TestingObject::~TestingObject()
{
    //dtor
}

void TestingObject::draw(sf::RenderTarget& target, sf::RenderStates states)const
{
    target.draw(m_shape);
}

void TestingObject::onPositionUpdate(AABB* selfBox)
{
    m_shape.setPosition(selfBox->m_position);
}

void TestingObject::onColliding(PhysicObject* other)
{
    m_box->m_velocity=sf::Vector2f(30.f, 0.f);
}
