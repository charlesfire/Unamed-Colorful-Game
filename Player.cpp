#include "Player.hpp"
#include <SFML/Window/Keyboard.hpp>
#include "DynamicAABB.hpp"
#include "PhysicEngine.hpp"
#include "TextureManager.hpp"


Player::Player() : m_sprite(), m_box(nullptr)
{
    m_sprite.setTexture(TextureManager::getInstance()->getTexture("Player.png"));
    m_box=new DynamicAABB(0.f, 0.f, 32.f, 64.f, 0.f, 0.f, 0.f, 313.6f);
    PhysicEngine::getInstance()->addDynamicBoxToObject(this, m_box);
}

Player::~Player()
{
    //dtor
}

void Player::update()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        m_box->m_velocity.x=-16.f;
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        m_box->m_velocity.x=16.f;
    else
        m_box->m_velocity.x=0.f;

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)&&m_box->m_velocity.y==0)
        m_box->m_velocity.y+=-200.f;
}
