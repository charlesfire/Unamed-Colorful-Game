#include "Animation.hpp"

Animation::Animation() : m_frames()
{
    //ctor
}

Animation::Animation(const sf::IntRect& frame) : m_frames()
{
    m_frames.push_back(frame);
}

Animation::Animation(std::initializer_list<sf::IntRect> frameList) : m_frames(frameList)
{

}

Animation::~Animation()
{
    //dtor
}

void Animation::addFrame(const sf::IntRect& frame)
{
    m_frames.push_back(frame);
}

void Animation::addFrames(std::initializer_list<sf::IntRect> frameList)
{
    m_frames.insert(m_frames.end(), frameList);
}

sf::IntRect Animation::getFrame(unsigned int frameNumber)const
{
    return m_frames.at(frameNumber);
}

unsigned int Animation::getNumberOfFrames()const
{
    return m_frames.size();
}
