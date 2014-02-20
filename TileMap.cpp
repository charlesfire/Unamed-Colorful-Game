#include "TileMap.hpp"
#include <SFML/Graphics/RenderTarget.hpp>

TileMap::TileMap() : m_tileTexture(), m_tiles(), m_tileCollidingFlag()
{
    //ctor
}

TileMap::TileMap(sf::Image& tileChart, sf::Image& tiles, sf::Image& compressedMapImage) : m_tileTexture(), m_tiles(), m_tileCollidingFlag()
{
    buildTileMap(tileChart, tiles, compressedMapImage);
}

TileMap::~TileMap()
{
    //dtor
}

bool TileMap::buildTileMap(sf::Image& tileChart, sf::Image& tiles, sf::Image& compressedMapImage)
{
    sf::Color colorBuffer;
    sf::Vector2u mapSize(compressedMapImage.getSize());
    sf::Uint64 tileChartSize(tileChart.getSize().x);
    sf::Uint64 tileSize(tiles.getSize().y);

    if(!m_tileTexture.loadFromImage(tiles))
        return false;
    m_tiles.resize(mapSize.x*mapSize.y*4);
    m_tileCollidingFlag.resize(mapSize.x);
    m_tiles.setPrimitiveType(sf::Quads);
    for(unsigned int i(0); i<mapSize.x; i++)
    {
        m_tileCollidingFlag[i].resize(mapSize.y);
        for(unsigned int j(0); j<mapSize.y; j++)
        {
            m_tiles[(i*mapSize.y+j)*4].position=sf::Vector2f(i*tileSize, j*tileSize);
            m_tiles[(i*mapSize.y+j)*4+1].position=sf::Vector2f((i+1)*tileSize, j*tileSize);
            m_tiles[(i*mapSize.y+j)*4+2].position=sf::Vector2f((i+1)*tileSize, (j+1)*tileSize);
            m_tiles[(i*mapSize.y+j)*4+3].position=sf::Vector2f(i*tileSize, (j+1)*tileSize);
            colorBuffer=compressedMapImage.getPixel(i, j);
            m_tileCollidingFlag[i][j]=colorBuffer.a;

            for(unsigned int h(0); h<tileChartSize; h++)
            {
                if(tileChart.getPixel(h, 0)==colorBuffer)
                {
                    m_tiles[(i*mapSize.y+j)*4].texCoords=sf::Vector2f(h*tileSize, 0.f);
                    m_tiles[(i*mapSize.y+j)*4+1].texCoords=sf::Vector2f(h*tileSize+tileSize, 0.f);
                    m_tiles[(i*mapSize.y+j)*4+2].texCoords=sf::Vector2f(h*tileSize+tileSize, tileSize);
                    m_tiles[(i*mapSize.y+j)*4+3].texCoords=sf::Vector2f(h*tileSize, tileSize);
                    break;
                }
            }
        }
    }
    return true;
}

void TileMap::draw(sf::RenderTarget& target, sf::RenderStates states)const
{
    target.draw(m_tiles, &m_tileTexture);
}
