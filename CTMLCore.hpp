#pragma once

#include <string>

#include "CTMLGraph.hpp"

class CTMLCore
{
public:
    CTMLCore();
    CTMLCore(const int& startLineIndex, const int& startCharIndex);
    ~CTMLCore();

    void feed(const std::string& line);
    int invoke();

protected:

    enum State : int
    {
        ERROR = -1,
        WORKING = 0,
        WAITING = 1,
        RESULT_READY = 2
    };

    State m_State;

    // extract to language definition
    const std::string CTMLTemplateString = "CTMLTemplate";
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

    InternalState m_internalState;

    // internal counters
    int m_CurLine;
    int m_CurChar;


    // internal buffers
    std::vector<std::string> m_Lines;
    std::string m_CurCTMLKeyword;

    // result buffers
    std::vector<CTMLGraph::CTMLNode> m_nodes;

    void processChar();
};

