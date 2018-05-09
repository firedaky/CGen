#include "CTMLManager.hpp"

#include <iostream>
#include <vector>

#include <boost/algorithm/string/predicate.hpp>

#include "FileSystem.hpp"
#include "FileReader.hpp"

#include "CTMLParser.hpp"


CTMLManager::CTMLManager(const std::string& folder)
{
    // 1. read folder content

    std::vector<std::string> absCtmlFiles;
    RecursivelyScanCtml(folder, absCtmlFiles);

    std::vector<std::vector<std::string>> fileContents(absCtmlFiles.size());

    // read files
    for (size_t ctmlFileCnt = 0; ctmlFileCnt < absCtmlFiles.size(); ctmlFileCnt++)
    {
        FileReader fr(absCtmlFiles.at(ctmlFileCnt));

        fr.read(fileContents.at(ctmlFileCnt));
    }


    CTMLGraph ctmlGraph;
    CTMLParser parser(ctmlGraph);

    for (size_t fileCnt = 0; fileCnt < fileContents.size(); fileCnt++)
    {
        const auto& curFile = fileContents.at(fileCnt);

        for (size_t lineCnt = 0; fileCnt < fileContents.size(); fileCnt++)
        {
            const auto& curLine = curFile.at(fileCnt);

            std::string message;

            parser.parseLine(curLine, message);

        }
    }
}

CTMLManager::~CTMLManager()
{
}
