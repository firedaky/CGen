#include "CTMLGraph.hpp"

CTMLGraph::CTMLNode::CTMLNode()
{
}

void CTMLGraph::CTMLNode::setName(const std::string& name)
{
    m_Name = name;
}

const std::string& CTMLGraph::CTMLNode::getName()
{
    return m_Name;
}

void CTMLGraph::CTMLNode::setInline(const bool& isInline)
{
    m_IsInline = isInline;
}

bool CTMLGraph::CTMLNode::isInline()
{
    return m_IsInline;
}
