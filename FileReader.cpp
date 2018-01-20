#include "FileReader.hpp"

#include<sstream>

/// Instanciates an object and checks if file exists and is readable.
FileReader::FileReader(const std::string& path)
{
    m_file.open(path);
}

FileReader::~FileReader()
{

}

bool FileReader::read(std::vector<std::string>& content)
{
    std::string curLine;

    while (std::getline(m_file, curLine))
    {
        content.push_back(curLine);
    }

    return true;
}
