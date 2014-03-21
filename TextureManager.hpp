#ifndef TEXTUREMANAGER_HPP
#define TEXTUREMANAGER_HPP

#include <map>
#include <string>
#include "Singleton.hpp"

namespace sf
{
    class Texture;
}

class TextureManager : public Singleton<TextureManager>
{
    friend class Singleton<TextureManager>;
    public:
        sf::Texture& getTexture(const std::string& link);
        bool deleteTexture(const std::string& link);
        void deleteAll();
    private:
        TextureManager();
        virtual ~TextureManager();
        std::map<std::string, sf::Texture*> m_textureList;
        inline bool SearchTexture(const std::string& link);
};

#endif // TEXTUREMANAGER_HPP
