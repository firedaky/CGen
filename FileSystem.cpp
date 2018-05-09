#include "FileSystem.hpp"

// Platform dependent
#include <windows.h>

bool RecursivelyScanCtml(const std::string& path, std::vector<std::string>& absfiles)
{
    std::vector<std::string> ctmlFiles;
    ListCtmlFilesInDirectory(path, ctmlFiles);

    for (const std::string& file : ctmlFiles)
    {
        absfiles.push_back(path + "/" + file);
    }

    std::vector<std::string> subdirs;
    ListSubdirsInDirectory(path, subdirs);

    for (const std::string& dir : subdirs)
    {
        RecursivelyScanCtml(path + "/" + dir, absfiles);
    }

    return true;
}

bool ListCtmlFilesInDirectory(const std::string& path, std::vector<std::string>& files)
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
            if (HasEnding(data.cFileName, "ctml"))
            {
                files.push_back(data.cFileName);
            }
        }
        while (FindNextFile(hFind, &data) != 0);

        FindClose(hFind);
    }

    return true;
}

bool ListSubdirsInDirectory(const std::string& path, std::vector<std::string>& subdirs)
{
    subdirs.clear();

    std::string pattern(path);
    pattern.append("\\*");
    WIN32_FIND_DATA data;
    HANDLE hFind;

    if ((hFind = FindFirstFile(pattern.c_str(), &data)) != INVALID_HANDLE_VALUE)
    {
        do
        {
            bool isDirectory = (data.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) != 0;
            bool notPoint = data.cFileName[0] != '.' && data.cFileName[1] != '\0';
            bool notPointPoint = data.cFileName[0] != '.' && data.cFileName[1] != '.' &&
                                 data.cFileName[2] != '\0';

            // check if handle is a directory
            if(isDirectory && notPoint && notPointPoint)
            {
                subdirs.push_back(data.cFileName);
            }
        }
        while (FindNextFile(hFind, &data) != 0);

        FindClose(hFind);
    }

    return true;
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
