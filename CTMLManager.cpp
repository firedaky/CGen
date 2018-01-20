#include "CTMLManager.hpp"

#include <iostream>
#include <vector>

// Platform dependent
#include <windows.h>

CTMLManager::CTMLManager(const std::string& folder)
{

    std::vector<std::string> v;

    std::string pattern(folder);
    pattern.append("\\*");
    WIN32_FIND_DATA data;
    HANDLE hFind;

    if ((hFind = FindFirstFile(pattern.c_str(), &data)) != INVALID_HANDLE_VALUE)
    {
        do
        {
            v.push_back(data.cFileName);
        }
        while (FindNextFile(hFind, &data) != 0);

        FindClose(hFind);
    }


    for (const auto& foStr : v)
    {
        std::cout << foStr << std::endl;
    }
}

CTMLManager::~CTMLManager()
{
}
