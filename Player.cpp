#include "Player.hpp"
#include <iostream>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include "DynamicAABB.hpp"
#include "PhysicEngine.hpp"
#include "TextureManager.hpp"

Player::Player() : m_sprite(), m_box(new DynamicAABB(0.f, 0.f, 32.f, 64.f, 0.f, 0.f, 0.f, 1000.f, (CollisionFlags)(CollisionFlags::solidGreen))), m_onGround(false), m_isPurple(true), m_isMovingRight(true), m_isDead(false)
{
    m_sprite.setTexture(TextureManager::getInstance()->getTexture("Player.png"));

    /*m_sprite.addAnimation("standRightPurple", {sf::IntRect(0, 0, 32, 64)});
    m_sprite.addAnimation("moveRightPurple", {{sf::IntRect(32, 0, 32, 64), sf::IntRect(64, 0, 32, 64), sf::IntRect(96, 0, 32, 64)}});
    m_sprite.addAnimation("inTheAirRightPurple", {sf::IntRect(128, 0, 32, 64)});

    m_sprite.addAnimation("standRightGreen", {sf::IntRect(0, 64, 32, 64)});
    m_sprite.addAnimation("moveRightGreen", {{sf::IntRect(32, 64, 32, 64), sf::IntRect(64, 64, 32, 64), sf::IntRect(96, 64, 32, 64)}});
    m_sprite.addAnimation("inTheAirRightGreen", {sf::IntRect(128, 64, 32, 64)});

    m_sprite.addAnimation("standLeftPurple", {sf::IntRect(288, 0, 32, 64)});
    m_sprite.addAnimation("moveLeftPurple", {{sf::IntRect(256, 0, 32, 64), sf::IntRect(224, 0, 32, 64), sf::IntRect(192, 0, 32, 64)}});
    m_sprite.addAnimation("inTheAirLeftPurple", {sf::IntRect(160, 0, 32, 64)});

    m_sprite.addAnimation("standLeftGreen", {sf::IntRect(288, 64, 32, 64)});
    m_sprite.addAnimation("moveLeftGreen", {{sf::IntRect(256, 64, 32, 64), sf::IntRect(224, 64, 32, 64), sf::IntRect(192, 64, 32, 64)}});
    m_sprite.addAnimation("inTheAirLeftGreen", {sf::IntRect(160, 64, 32, 64)});

    m_sprite.playAnimation("standRightPurple", 0.375f);*/
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
        if(event.key.code == sf::Keyboard::Space)
        {
            m_box->m_flags=m_box->m_flags==CollisionFlags::solidGreen ? CollisionFlags::solidPurple : CollisionFlags::solidGreen;
            m_isPurple!=m_isPurple;
        }
    }
}

void Player::onPositionUpdate(std::shared_ptr<AABB> selfBox, float elapsedTime)
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        m_box->m_velocity.x=-350.f;

        /*if(m_isMovingRight)
        {
            if(m_isPurple)
                m_sprite.playAnimation("moveLeftPurple", 0.375f);
            else
                m_sprite.playAnimation("moveLeftGreen", 0.375f);
        }
        m_isMovingRight=false;*/
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        m_box->m_velocity.x=350.f;

        /*if(!m_isMovingRight)
        {
            if(m_isPurple)
                m_sprite.playAnimation("moveRightPurple", 0.375f);
            else
                m_sprite.playAnimation("moveRightGreen", 0.375f);
        }
        m_isMovingRight=true;*/
    }
    else
    {
        m_box->m_velocity.x=0.f;

        /*if(m_onGround && m_isMovingRight)
        {
            if(m_isPurple)
                m_sprite.playAnimation("standRightPurple", 0.01f);
            else
                m_sprite.playAnimation("standRightGreen", 0.01f);
        }
        else if(m_onGround && !m_isMovingRight)
        {
            if(m_isPurple)
                m_sprite.playAnimation("standLeftPurple", 0.01f);
            else
                m_sprite.playAnimation("standLeftGreen", 0.01f);
        }*/
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        if(m_onGround)
            m_box->m_velocity.y=-550.f;
    }

    /*if(!m_onGround)
    {
        if(!m_isMovingRight)
        {
            if(m_isPurple)
                m_sprite.playAnimation("inTheAirLeftPurple", 0.01f);
            else
                m_sprite.playAnimation("inTheAirLeftGreen", 0.01f);
        }
        else if(m_isMovingRight)
        {
            if(m_isPurple)
                m_sprite.playAnimation("inTheAirRightPurple", 0.01f);
            else
                m_sprite.playAnimation("inTheAirRightGreen", 0.01f);
        }
    }*/

    m_sprite.setPosition(m_box->m_position);
    //m_sprite.update(elapsedTime);
    m_onGround=false;
}

void Player::onColliding(const PhysicObject* other, const std::shared_ptr<AABB>& otherBox)
{
    if((otherBox->m_flags&CollisionFlags::hurtWhenPurple)&&(m_box->m_flags&CollisionFlags::solidPurple)||(otherBox->m_flags&CollisionFlags::hurtWhenGreen)&&(m_box->m_flags&CollisionFlags::solidGreen))
        m_isDead=true;
    else if(otherBox->m_flags&CollisionFlags::endGame)
        m_isDead=true;

    if(otherBox->getCollisionOrientation(*m_box)==CollisionOrientation::Top && (((otherBox->m_flags&CollisionFlags::solidGreen)&m_box->m_flags)
        || ((otherBox->m_flags&CollisionFlags::solidPurple)&m_box->m_flags)))
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

bool Player::isDead()const
{
    return m_isDead;
}
