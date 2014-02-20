#pragma once
#include <SFML/System/String.hpp>

class BigFile;

class VirtualFile
{
    public:
        VirtualFile();
        virtual ~VirtualFile();
        VirtualFile(const VirtualFile& other);
    protected:
        sf::String fileName;
        sf::Uint64 m_fileStart, m_fileEnd, m_currentPos;
        BigFile* m_fileSource;
};
