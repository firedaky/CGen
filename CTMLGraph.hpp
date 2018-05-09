#pragma once

#include <vector>



class CTMLGraph
{
public:



protected:

    // Nodes
    class CTMLNode
    {


    protected:
        // Inline Nodes
        std::vector<CTMLNode> m_inlineTemplates;
    };



    std::vector<CTMLNode> m_CTMLTemplates;
};

