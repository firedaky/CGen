#pragma once

#include "main.hpp"

#include <string>
#include <iostream>
#include <vector>

#include "CTMLManager.hpp"

int main()
{

    std::string ctmlFolder = "D:/UT/ctml/";

    CTMLManager manager(ctmlFolder);

    system("pause");
    return 0;
}
