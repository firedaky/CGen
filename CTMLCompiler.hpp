#pragma once

#include<string>

#include "CTMLGraph.hpp"

class CTMLCompiler
{
public:

    CTMLCompiler(CTMLGraph& graph);

    bool compileFile(const std::string& fp, const std::vector<std::string>& fileLines);

protected:
    CTMLGraph& m_ctmlGraph;

};