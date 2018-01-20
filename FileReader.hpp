#pragma once

#include<string>
#include<fstream>
#include<vector>

/// Class to encapsule file input functionality from fstream usage.
///
/// Reads text files linewise.
class FileReader
{
public:

    /// Creates a FileReader Object to
    FileReader(const std::string& path);

    /// Closes filestream
    ~FileReader();

    /// Reads contents from file linewise
    bool read(std::vector<std::string>& content);

protected:
    std::ifstream m_file;
};

