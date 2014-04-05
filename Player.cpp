#include "Player.hpp"
#include <iostream>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include "DynamicAABB.hpp"
#include "PhysicEngine.hpp"
#include "TextureManager.hpp"


Player::Player() : m_sprite(), m_box(nullptr), m_onGround(false)
{
    m_sprite.setTexture(TextureManager::getInstance()->getTexture("Player.png"));
    m_box=new DynamicAABB(0.f, 0.f, 32.f, 64.f, 0.f, 0.f, 0.f, 313.6f);
    PhysicEngine::getInstance()->addDynamicBoxToObject(this, m_box);
}

Player::~Player()
{
    //dtor
}

void Player::onPositionUpdate(AABB* selfBox)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        m_box->m_velocity.x=-128.f;
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        m_box->m_velocity.x=128.f;
    else
        m_box->m_velocity.x=0.f;

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::R))
    {
        m_box->m_position.x=0.f;
        m_box->m_position.y=0.f;
        m_box->m_velocity.y=0.f;
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)&&m_onGround==true)
        m_box->m_velocity.y=-400.f;

    m_sprite.setPosition(m_box->m_position);
    m_onGround=false;
}

void Player::onColliding(const PhysicObject* other, const AABB* otherBox)
{
    if(otherBox->getCollisionOrientation(*m_box)==CollisionOrientation::Top)
    {
        m_onGround=true;
        std::cout<<"top!"<<std::endl;
    }
    else if(otherBox->getCollisionOrientation(*m_box)==CollisionOrientation::Bottom)
    {
        m_box->m_velocity.y=0.f;
        std::cout<<"bot!"<<std::endl;
    }
    else if(otherBox->getCollisionOrientation(*m_box)==CollisionOrientation::Right)
        std::cout<<"right!"<<std::endl;
    else if(otherBox->getCollisionOrientation(*m_box)==CollisionOrientation::Left)
        std::cout<<"left!"<<std::endl;

    std::cout<<"x: "<<otherBox->m_position.x<<" y: "<<otherBox->m_position.y<<std::endl<<"---------------"<<std::endl;
}

void Player::draw(sf::RenderTarget& target, sf::RenderStates states)const
{
    target.draw(m_sprite);
}
