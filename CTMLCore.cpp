#include "CTMLCore.hpp"

CTMLCore::CTMLCore(const std::string& filepath, const std::vector<std::string>& fileConent)
{
    CTMLGraph::CTMLNode rootNode;
    rootNode.setInline(false);
    rootNode.setName(filepath);
    this->m_Lines = fileConent;

    m_CurLine = new int;
    m_CurCol = new int;

    *m_CurLine = 0;
    *m_CurCol = 0;

    m_InternalState = InternalState::FIND_OPEN_TAG;
    m_State = State::READY;
}

CTMLCore::CTMLCore(int* startLineIndex, int* startCharIndex)
{
    m_CurLine = startLineIndex;
    m_CurCol = startCharIndex;

    m_InternalState = InternalState::FIND_OPEN_TAG;
    m_State = State::READY;
}

CTMLCore::~CTMLCore()
{
    delete m_CurCol;
    delete m_CurLine;
}

void CTMLCore::run()
{
    if (m_State == State::READY)
    {
        m_State = State::WORKING;
    }

    // Main loop
    while (m_State == State::WORKING)
    {
        int temp = step();
    }

    if (m_State == State::ERROR)
    {
        // get error list etc....
        return;
    }
    else if (m_State == State::RESULT_READY)
    {
        return;
    }
}

int CTMLCore::step()
{
    //check if file is empty
    if(m_Lines.size() == 0)
    {
        return 0;
    }

    switch (m_State)
    {
    case State::WORKING:
        {
            // process Char here indices are Valid here (see above)
            processChar();

            // iterate Column
            (*m_CurCol)++;

            // linebreak necesarry?
            while (m_Lines.at(*m_CurLine).size() <= *m_CurCol)
            {
                //linebreak
                (*m_CurLine)++;

                if (m_Lines.size() <= *m_CurLine)
                {
                    // finalize result

                    m_State = State::RESULT_READY;
                }
                else
                {
                    *m_CurCol = 0;
                }
            }

            break;
        }

    default:
        break;
    }



    return 0;
}

void CTMLCore::processChar()
{
    char curChar = m_Lines.at(*m_CurLine).at(*m_CurCol);

    switch (m_InternalState)
    {
    case(InternalState::FIND_OPEN_TAG):
        {
            if (curChar == '<')
            {
                m_InternalState = FIND_CTML_KEYWORD;
                m_CurCTMLKeyword = "";
            }
            else
            {
            }

            break;
        }

    case(InternalState::FIND_CTML_KEYWORD):
        {
            if (isspace(curChar))
            {
            }
            else if (isalnum(curChar))
            {
                m_CurCTMLKeyword += curChar;
                m_InternalState = READ_CTML_KEYWORD;
            }
            else
            {
                m_InternalState = FIND_OPEN_TAG;
                m_CurCTMLKeyword = "";
            }

            break;
        }

    case(InternalState::READ_CTML_KEYWORD):
        {
            if (isalnum(curChar))
            {
                m_CurCTMLKeyword += curChar;
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
                    m_CurCTMLKeyword = "";
                    m_InternalState = InternalState::FIND_OPEN_TAG;
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
