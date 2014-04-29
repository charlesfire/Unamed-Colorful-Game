#ifndef ANIMATION_HPP
#define ANIMATION_HPP

#include <vector>
#include <initializer_list>
#include <SFML/Graphics/Rect.hpp>

class Animation
{
    public:
        Animation();
        Animation(const sf::IntRect& frame);
        Animation(std::initializer_list<sf::IntRect> frameList);
        virtual ~Animation();
        void addFrame(const sf::IntRect& frame);
        void addFrames(std::initializer_list<sf::IntRect> frameList);
        sf::IntRect getFrame(unsigned int frameNumber)const;
        unsigned int getNumberOfFrames()const;
    protected:
        std::vector<sf::IntRect> m_frames;
};

#endif // ANIMATION_HPP
