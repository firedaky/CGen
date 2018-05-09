#pragma once

#include <string>
#include <vector>

bool RecursivelyScanCtml(const std::string& path, std::vector<std::string>& absfiles);

bool ListCtmlFilesInDirectory(const std::string& path, std::vector<std::string>& files);

bool ListSubdirsInDirectory(const std::string& path, std::vector<std::string>& subdirs);

bool HasEnding(const std::string& string, const std::string& ending);
