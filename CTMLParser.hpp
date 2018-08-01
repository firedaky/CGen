#pragma once

#include<string>

#include "CTMLGraph.hpp"

class CTMLParser
{
public:

    CTMLParser(CTMLGraph& graph);

    bool parseLine(
        const std::string& p_Line,
        std::string& p_Message);

    bool startFile(const std::string& name);
    bool endFile(const std::string& name);

    void print();

protected:
    CTMLGraph& m_ctmlGraph;

    std::vector<std::string> m_lineBuffer;
};