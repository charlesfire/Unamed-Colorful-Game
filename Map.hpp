#ifndef MAP_HPP
#define MAP_HPP

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Image.hpp>
#include <SFML/System/String.hpp>
#include "TileMap.hpp"

class Map : public sf::Drawable
{
    public:
        Map();
        virtual ~Map();
        //virtual bool LoadFromFile(sf::String& fileName);
    protected:
        TileMap m_tileMap;
};

#endif // MAP_HPP
