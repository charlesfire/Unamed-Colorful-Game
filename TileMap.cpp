#include "TileMap.hpp"
#include <SFML/Graphics/RenderTarget.hpp>
#include "PhysicEngine.hpp"
#include "AABB.hpp"

TileMap::TileMap() : m_tileTexture(), m_tiles()
{
    //ctor
}

TileMap::TileMap(sf::Image& tileChart, sf::Image& tiles, sf::Image& compressedMapImage) : m_tileTexture(), m_tiles()
{
    buildTileMap(tileChart, tiles, compressedMapImage);
}

TileMap::~TileMap()
{
    //dtor
}

bool TileMap::buildTileMap(sf::Image& tileChart, sf::Image& tiles, sf::Image& compressedMapImage)
{
    PhysicEngine* engine(PhysicEngine::getInstance());
    sf::Color colorBuffer;
    sf::Vector2u mapSize(compressedMapImage.getSize());
    sf::Uint64 tileChartSize(tileChart.getSize().x);
    sf::Uint64 tileSize(tiles.getSize().y);
    m_tiles.resize(mapSize.x*mapSize.y*4);
    m_tiles.setPrimitiveType(sf::Quads);

    if(!m_tileTexture.loadFromImage(tiles))
        return false;
    for(unsigned int i(0); i<mapSize.x; i++)
    {
        for(unsigned int j(0); j<mapSize.y; j++)
        {
            m_tiles[(i*mapSize.y+j)*4].position=sf::Vector2f(i*tileSize, j*tileSize);
            m_tiles[(i*mapSize.y+j)*4+1].position=sf::Vector2f((i+1)*tileSize, j*tileSize);
            m_tiles[(i*mapSize.y+j)*4+2].position=sf::Vector2f((i+1)*tileSize, (j+1)*tileSize);
            m_tiles[(i*mapSize.y+j)*4+3].position=sf::Vector2f(i*tileSize, (j+1)*tileSize);

            colorBuffer=compressedMapImage.getPixel(i, j);

            if(colorBuffer!=sf::Color(0.f, 0.f, 0.f, 0.f))
            {
                if(colorBuffer.a!=0.f)
                    engine->addStaticBoxToObject(this, std::shared_ptr<AABB>(new AABB(sf::Vector2f(i*tileSize, j*tileSize), sf::Vector2f(tileSize, tileSize), (CollisionFlags)colorBuffer.a)));
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
            else
            {
                m_tiles[(i*mapSize.y+j)*4].color=sf::Color(0.f, 0.f, 0.f, 0.f);
                m_tiles[(i*mapSize.y+j)*4+1].color=sf::Color(0.f, 0.f, 0.f, 0.f);
                m_tiles[(i*mapSize.y+j)*4+2].color=sf::Color(0.f, 0.f, 0.f, 0.f);
                m_tiles[(i*mapSize.y+j)*4+3].color=sf::Color(0.f, 0.f, 0.f, 0.f);
            }
        }
    }
    return true;
}

void TileMap::draw(sf::RenderTarget& target, sf::RenderStates states)const
{
    target.draw(m_tiles, &m_tileTexture);
}
