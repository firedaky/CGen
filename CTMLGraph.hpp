#pragma once

#include <vector>
#include <memory>


class CTMLGraph
{
public:



    // Nodes
    class CTMLNode
    {
    public:
        CTMLNode();

        void setName(const std::string& name);
        const std::string& getName();

        bool isValid();

    protected:

        bool isInline;
        std::string name;

        // Inline Nodes
        std::vector<std::shared_ptr<CTMLNode>> m_Nodes;

        std::vector<std::pair<int, int>> m_ReplacementSubstrings;
    };


protected:
    std::vector<CTMLNode> m_CTMLRootNodes;
};

