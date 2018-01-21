#include "FileSystem.hpp"

// Platform dependent
#include <windows.h>

bool ListFilesInDirectory(const std::string& path, std::vector<std::string>& files)
{
    files.clear();

    std::string pattern(path);
    pattern.append("\\*");
    WIN32_FIND_DATA data;
    HANDLE hFind;

    if ((hFind = FindFirstFile(pattern.c_str(), &data)) != INVALID_HANDLE_VALUE)
    {
        do
        {
            files.push_back(data.cFileName);
        }
        while (FindNextFile(hFind, &data) != 0);

        FindClose(hFind);
    }

    return false;
}

bool HasEnding(const std::string& string, const std::string& ending)
{
    if (string.length() >= ending.length())
    {
        return (0 == string.compare(string.length() - ending.length(), ending.length(), ending));
    }
    else
    {
        return false;
    }


}
