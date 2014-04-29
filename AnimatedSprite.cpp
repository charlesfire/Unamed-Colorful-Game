#include "AnimatedSprite.hpp"
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/RenderStates.hpp>
#include <iostream>

AnimatedSprite::AnimatedSprite() : m_elapsedTime(0.f), m_animationTime(0.f), m_isPlaying(false), m_isLooped(false), m_currentFrame(0), m_currentAnimationName(), m_currentAnimation(nullptr), m_texture(nullptr), m_vertices(), m_animList()
{
    //ctor
}

AnimatedSprite::AnimatedSprite(const std::string& animationName, const Animation& animation) : m_elapsedTime(0.f), m_animationTime(0.f), m_isPlaying(false), m_isLooped(false), m_currentFrame(0), m_currentAnimationName(), m_currentAnimation(nullptr), m_texture(nullptr), m_vertices(), m_animList()
{
    m_animList.insert(std::pair<std::string, Animation>(animationName, animation));
}

AnimatedSprite::AnimatedSprite(std::initializer_list<std::pair<std::string, Animation>> animationList) : m_elapsedTime(0.f), m_animationTime(0.f), m_isPlaying(false), m_isLooped(false), m_currentFrame(0), m_currentAnimationName(), m_currentAnimation(nullptr), m_texture(nullptr), m_vertices(), m_animList()
{
    m_animList.insert(animationList.begin(), animationList.end());
}

AnimatedSprite::~AnimatedSprite()
{
    //dtor
}

bool AnimatedSprite::addAnimation(const std::string& animationName, const Animation& animation)
{
    if(m_animList.insert(std::pair<std::string, Animation>(animationName, animation)).second)
        return true;
    return false;
}

void AnimatedSprite::addAnimations(std::initializer_list<std::pair<std::string, Animation>> animationList)
{
    m_animList.insert(animationList.begin(), animationList.end());
}

bool AnimatedSprite::playAnimation(const std::string& animationName, float animationDuration, bool loop)
{
    std::map<std::string, Animation>::iterator it;
    if((it=m_animList.find(animationName))!=m_animList.end())
    {
        m_currentAnimationName=it->first;
        m_currentAnimation=&it->second;
        m_animationTime=animationDuration;
        m_elapsedTime=0.f;
        m_isLooped=loop;
        m_isPlaying=true;
        return true;
    }
    return false;
}

void AnimatedSprite::play()
{
    if(m_currentAnimation)
        m_isPlaying=true;
}

void AnimatedSprite::pause()
{
    m_isPlaying=false;
}

void AnimatedSprite::setLooped(bool loop)
{
    m_isLooped=loop;
}

void AnimatedSprite::setTexture(const sf::Texture& texture)
{
    m_texture=&texture;
}

bool AnimatedSprite::isPlaying()const
{
    return m_isPlaying;
}

bool AnimatedSprite::isLooped()const
{
    return m_isLooped;
}

std::string AnimatedSprite::currentAnimationName()const
{
    return m_currentAnimationName;
}

void AnimatedSprite::update(float elapsedTime)
{
    if(m_isPlaying&&m_currentAnimation)
    {
        m_elapsedTime+=elapsedTime;
        while(m_elapsedTime>=m_animationTime/m_currentAnimation->getNumberOfFrames())
        {
            m_elapsedTime-=m_animationTime/m_currentAnimation->getNumberOfFrames();
            if(m_currentFrame+1<m_currentAnimation->getNumberOfFrames())
                m_currentFrame++;
            else
                m_currentFrame=0;

            if(!m_isLooped)
                m_isPlaying=false;

            sf::IntRect rect(m_currentAnimation->getFrame(m_currentFrame));
            m_vertices[0].position=sf::Vector2f(0.f, 0.f);
            m_vertices[1].position=sf::Vector2f(0.f, rect.height);
            m_vertices[2].position=sf::Vector2f(rect.width, rect.height);
            m_vertices[3].position=sf::Vector2f(rect.width, 0.f);

            m_vertices[0].texCoords=sf::Vector2f(rect.left, rect.top);
            m_vertices[1].texCoords=sf::Vector2f(rect.left, rect.top+rect.height);
            m_vertices[2].texCoords=sf::Vector2f(rect.left+rect.width, rect.top+rect.height);
            m_vertices[3].texCoords=sf::Vector2f(rect.left+rect.width, rect.top);
        }
    }
}

void AnimatedSprite::draw(sf::RenderTarget& target, sf::RenderStates states)const
{
    if(m_currentAnimation&&m_texture)
    {
        states.transform=this->getTransform();
        states.texture=m_texture;
        target.draw(m_vertices, 4, sf::Quads, states);
    }
}
