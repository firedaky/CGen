#pragma once

#include<string>

#include "CTMLGraph.hpp"

class CTMLParser
{
public:

    CTMLParser(CTMLGraph& graph);

    bool parseLine(
        const std::string& line,
        std::string& message);
private:
    CTMLGraph& m_ctmlGraph;

};