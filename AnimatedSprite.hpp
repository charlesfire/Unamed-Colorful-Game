#ifndef ANIMATEDSPRITE_HPP
#define ANIMATEDSPRITE_HPP

#include <map>
#include <string>
#include <initializer_list>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Transformable.hpp>
#include <SFML/Graphics/vertex.hpp>
#include "Animation.hpp"

namespace sf
{
    class Texture;
}

class AnimatedSprite : public sf::Drawable, public sf::Transformable
{
    public:
        AnimatedSprite();
        AnimatedSprite(const std::string& animationName, const Animation& animation);
        AnimatedSprite(std::initializer_list<std::pair<std::string, Animation>> animationList);
        virtual ~AnimatedSprite();
        bool addAnimation(const std::string& animationName, const Animation& animation);
        void addAnimations(std::initializer_list<std::pair<std::string, Animation>> animationList);
        bool playAnimation(const std::string& animationName, float animationDuration, bool loop=true);
        void play();
        void pause();
        void setLooped(bool loop);
        void setTexture(const sf::Texture& texture);
        bool isPlaying()const;
        bool isLooped()const;
        std::string currentAnimationName()const;
        void update(float elapsedTime);
    protected:
        float m_elapsedTime;
        float m_animationTime;
        bool m_isPlaying;
        bool m_isLooped;
        sf::Uint64 m_currentFrame;
        std::string m_currentAnimationName;
        const Animation* m_currentAnimation;
        const sf::Texture* m_texture;
        sf::Vertex m_vertices[4];
        std::map<std::string, Animation> m_animList;

        void draw(sf::RenderTarget& target, sf::RenderStates states)const;
};

#endif // ANIMATEDSPRITE_HPP
