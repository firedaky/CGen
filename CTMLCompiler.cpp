#include "CTMLCompiler.hpp"
#include "CTMLCore.hpp"

CTMLCompiler::CTMLCompiler(CTMLGraph& graph) :
    m_ctmlGraph(graph)
{
}

bool CTMLCompiler::compileFile(const std::string& fp, const std::vector<std::string>& fileLines)
{
    CTMLCore core(fp, fileLines);

    core.run();

    return true;
}

