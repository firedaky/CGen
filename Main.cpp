#pragma once

#include "main.hpp"

#include <string>
#include <iostream>
#include <vector>

#include "CTMLManager.hpp"
#include "FileReader.hpp"

int main()
{
    // Open precompiled CSV file
    const std::string l_csvPath =
        "D:/Projekte/201X_Unitheater/201X_Website/CGen/precompiles/";
    const std::string l_csv_file = "index.csv";
    FileReader l_fr(l_csvPath + l_csv_file);
    std::vector<std::string> l_Lines;
    l_fr.read(l_Lines);

    for (const std::string& line : l_Lines)
    {
        printf((line + "\n").c_str());
    }

    // ready with csv



    // ctml part
    std::string l_ctmlFolder =
        "D:/Projekte/201X_Unitheater/201X_Website/CGen/ctml/UniTheaterDesignTemplates";

    CTMLManager manager(l_ctmlFolder);

    return EXIT_SUCCESS;

    //---------------------------------------------------------------


    system("pause");
    return 0;
}
