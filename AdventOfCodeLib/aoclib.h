#pragma once

#include <string>
#include <vector>

#define WIN32_LEAN_AND_MEAN // Exclude rarely-used stuff from Windows headers

namespace aoclib
{
    /**
     * Read a newline-delimited file at the given path and return its lines
     * in a std::vector.
     *
     * @param inputFilePath the path to the file from which to read
     *
     * @return the file lines
     *
     * @throws std::invalid_argument if the file stream failed to open
     */
    [[nodiscard]] const std::vector<std::string> readInput(const std::string& inputFilePath);
}
