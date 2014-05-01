#include "Key.hpp"
#include <fstream>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/RenderStates.hpp>
#include "PhysicEngine.hpp"
#include "AABB.hpp"
#include "TextureManager.hpp"

Key::Key() : m_sprite()
{
    std::ifstream myFile;
    myFile.open("Key.txt", std::ios::in);
    if(myFile.is_open())
    {
        std::string xPosText, yPosText;
        getline(myFile, xPosText);
        getline(myFile, yPosText);

        PhysicEngine::getInstance()->addStaticBoxToObject(this, std::shared_ptr<AABB>(new AABB(::atof(xPosText.c_str()), ::atof(yPosText.c_str()), 32.f, 64.f, CollisionFlags::endGame)));
        m_sprite.setTexture(TextureManager::getInstance()->getTexture("Key.png"));
        Animation anim;
        for(unsigned i(0); i<23; i++)
        {
            anim.addFrame(sf::IntRect(i*32, 0, 32, 64));
        }
        m_sprite.addAnimation("rotate", anim);
        m_sprite.setPosition(::atof(xPosText.c_str()), ::atof(yPosText.c_str()));
        m_sprite.playAnimation("rotate", 1.f);
    }
}

Key::~Key()
{
    //dtor
}

void Key::update(float elapsedTime)
{
    m_sprite.update(elapsedTime);
}

void Key::draw(sf::RenderTarget &target, sf::RenderStates states)const
{
    target.draw(m_sprite);
}
