#pragma once

#include <string>

#include "CTMLGraph.hpp"

// escape &quot; in attributes

class CTMLCore
{
public:
    // Main Constructor
    CTMLCore(const std::string& filepath, const std::vector<std::string>& fileConent);
    ~CTMLCore();

    void run();
    int step();

protected:

    // SubConstructor
    CTMLCore(int* startLineIndex, int* startCharIndex);

    enum State : int
    {
        ERROR = -1,
        WORKING = 0,
        READY = 1,
        RESULT_READY = 2
    };

    State m_State;

    // extract to language definition
    const std::string CTMLTemplateString = "CGenTemplates";
    const std::string CTMLContentString = "CGenContent";
    const std::string CTMLAssertString = "CGenAssert"; // wip

    const std::string CTMLLegalTemplateAttributeName = "name";

    const std::string CTMLLegalContentAttributeName = "type";


    enum InternalState : int
    {
        FIND_OPEN_TAG = 1,
        FIND_CTML_KEYWORD = 2,
        READ_CTML_KEYWORD = 3, // ?
        FINDING_ATTRIBUTES = 4,
        FINDING_ATTRIBUTE_NAME = 5,
        FINDING_ATTRIBUTE_VALUE = 6
    };

    InternalState m_InternalState;

    // internal counters
    int* m_CurLine;
    int* m_CurCol;


    // internal buffers
    std::vector<std::string> m_Lines;
    std::string m_CurCTMLKeyword;

    // result buffers
    std::vector<CTMLGraph::CTMLNode> m_nodes;

    void processChar();
};

