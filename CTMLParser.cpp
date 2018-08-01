#include "CTMLParser.hpp"

CTMLParser::CTMLParser(CTMLGraph& graph) :
    m_ctmlGraph(graph)
{
}

bool CTMLParser::parseLine(const std::string& p_Line, std::string& p_Message)
{
    m_lineBuffer.push_back(p_Line);

    return true;
}

bool CTMLParser::startFile(const std::string& name)
{
    m_lineBuffer.push_back("###START " + name);

    return true;
}

bool CTMLParser::endFile(const std::string& name)
{
    m_lineBuffer.push_back("###END " + name);

    return true;
}

void CTMLParser::print()
{
    for (const std::string& l_Line : m_lineBuffer)
    {
        printf((l_Line + "\n").c_str());
    }
}
