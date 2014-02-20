#ifndef TILEMAP_HPP
#define TILEMAP_HPP

#include <vector>
#include <array>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/VertexArray.hpp>

class TileMap : public sf::Drawable
{
    public:
        TileMap();
        TileMap(sf::Image& tileChart, sf::Image& tiles, sf::Image& compressedMapImage);
        virtual ~TileMap();
        virtual bool buildTileMap(sf::Image& tileChart, sf::Image& tiles, sf::Image& compressedMapImage);
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states)const;
    protected:
        sf::Texture m_tileTexture;
        sf::VertexArray m_tiles;
        std::vector<std::vector<sf::Uint8>> m_tileCollidingFlag;
};

#endif // TILEMAP_HPP
