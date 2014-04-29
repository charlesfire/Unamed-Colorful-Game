#ifndef TILEMAP_HPP
#define TILEMAP_HPP

#include <vector>
#include <array>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/VertexArray.hpp>
#include "PhysicObject.hpp"

namespace sf
{
    class Image;
}

class TileMap : public sf::Drawable, public PhysicObject
{
    public:
        TileMap();
        TileMap(sf::Image& tileChart, sf::Image& tiles, sf::Image& compressedMapImage);
        virtual ~TileMap();
        virtual bool buildTileMap(sf::Image& tileChart, sf::Image& tiles, sf::Image& compressedMapImage);
    protected:
        sf::Texture m_tileTexture;
        sf::VertexArray m_tiles;

        virtual void draw(sf::RenderTarget& target, sf::RenderStates states)const;
};

#endif // TILEMAP_HPP
