#pragma once

#include <string>
#include <vector>


bool ListFilesInDirectory(const std::string& path, std::vector<std::string>& files);


bool HasEnding(const std::string& string, const std::string& ending);
