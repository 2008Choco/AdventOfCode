#pragma once

#include <string>
#include <vector>

#define WIN32_LEAN_AND_MEAN             // Exclude rarely-used stuff from Windows headers

namespace aoclib
{
    const std::vector<std::string> readInput(const std::string& inputFilePath);
}
