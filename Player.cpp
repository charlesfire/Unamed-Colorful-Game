#include "Player.hpp"
#include <iostream>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include "DynamicAABB.hpp"
#include "PhysicEngine.hpp"
#include "TextureManager.hpp"


Player::Player() : m_sprite(), m_box(new DynamicAABB(0.f, 0.f, 32.f, 64.f, 0.f, 0.f, 0.f, 900.f, (CollisionFlags)(CollisionFlags::solidGreen))), m_onGround(false)
{
    m_sprite.setTexture(TextureManager::getInstance()->getTexture("Player.png"));
    PhysicEngine::getInstance()->addDynamicBoxToObject(this, m_box);
}

Player::~Player()
{
    //dtor
}

void Player::handleEvent(const sf::Event& event)
{
    if(event.type == sf::Event::KeyPressed)
    {
        std::cout<<"Key handled..."<<std::endl;
        if(event.key.code == sf::Keyboard::Space)
        {
            std::cout<<"Space handled..."<<std::endl;
            m_box->m_flags=m_box->m_flags==CollisionFlags::solidGreen ? CollisionFlags::solidPurple : CollisionFlags::solidGreen;
        }
    }
}

void Player::onPositionUpdate(std::shared_ptr<AABB> selfBox, float elapsedTime)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        //if(m_box->m_velocity.x>-350.f)
            //m_box->m_acceleration.x=-2048.f;
        //else
            m_box->m_velocity.x=-350.f;
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        //if(m_box->m_velocity.x<350.f)
            //m_box->m_acceleration.x=2048.f;
        //else
            m_box->m_velocity.x=350.f;
    }
    else
    {
        m_box->m_velocity.x=0.f;
        //m_box->m_acceleration.x=0.f;
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::R))
    {
        std::cout<<m_box->m_velocity.y<<std::endl;
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)&&m_onGround==true)
        m_box->m_velocity.y=-500.f;

    m_sprite.setPosition(m_box->m_position);
    m_onGround=false;
}

void Player::onColliding(const PhysicObject* other, const std::shared_ptr<AABB>& otherBox)
{
    if(otherBox->getCollisionOrientation(*m_box)==CollisionOrientation::Top)
    {
        m_onGround=true;
        m_box->m_velocity.y=0.f;
    }
    else if(otherBox->getCollisionOrientation(*m_box)==CollisionOrientation::Bottom)
        m_box->m_velocity.y=0.f;
    else
        m_box->m_velocity.x=0.f;
}

void Player::draw(sf::RenderTarget& target, sf::RenderStates states)const
{
    target.draw(m_sprite);
}

sf::Vector2f Player::getPosition()const
{
    return m_box->m_position;
}
