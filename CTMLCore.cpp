#include "CTMLCore.hpp"

CTMLCore::CTMLCore()
{
    m_CurLine = 0;
    m_CurChar = 0;

    m_internalState = InternalState::FIND_OPEN_TAG;
}

CTMLCore::CTMLCore(const int& startLineIndex, const int& startCharIndex)
{
    m_CurLine = startLineIndex;
    m_CurChar = startCharIndex;

    m_internalState = InternalState::FIND_OPEN_TAG;
}

CTMLCore::~CTMLCore()
{
}

void CTMLCore::feed(const std::string& line)
{
    m_Lines.push_back(line);
}

int CTMLCore::invoke()
{
    char curChar = m_Lines.at(m_CurLine).at(m_CurChar);

    switch (m_State)
    {
    case State::WORKING:
        {

            break;
        }

    default:
        break;
    }

    return 0;
}

void CTMLCore::processChar()
{
    char curChar = m_Lines.at(m_CurLine).at(m_CurChar);

    if (curChar = 0)
    {
        // Newline
    }

    switch (m_internalState)
    {
    case(InternalState::FIND_OPEN_TAG):
        {
            if (curChar == '<')
            {
                m_internalState = FIND_CTML_KEYWORD;
                m_CurCTMLKeyword = "";
                m_CurChar++;
            }
            else
            {
                m_CurChar++;
            }

            break;
        }

    case(InternalState::FIND_CTML_KEYWORD):
        {
            if (isspace(curChar))
            {
                m_CurChar++;
            }
            else if (isalnum(curChar))
            {
                m_CurCTMLKeyword += curChar;
                m_internalState = READ_CTML_KEYWORD;
                m_CurChar++;
            }
            else
            {
                m_internalState = FIND_OPEN_TAG;
                m_CurCTMLKeyword = "";
                m_CurChar++;
            }

            break;
        }

    case(InternalState::READ_CTML_KEYWORD):
        {
            if (isalnum(curChar))
            {
                m_CurCTMLKeyword += curChar;
                m_CurChar++;
            }
            else if (isspace(curChar))
            {
                if (m_CurCTMLKeyword == CTMLTemplateString)
                {
                    CTMLGraph::CTMLNode nuNode();
                }
                else if (m_CurCTMLKeyword == CTMLContentString)
                {

                }
                else if (m_CurCTMLKeyword == CTMLAssertString)
                {

                }
                else
                {

                }

                // check word
            }
        }


    default:
        {
            break;
        }
    }

}
