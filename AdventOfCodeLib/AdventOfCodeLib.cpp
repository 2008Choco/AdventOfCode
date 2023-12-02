#include "pch.h"
#include "aoclib.h"

#include <fstream>
#include <stdexcept>

namespace aoclib
{
    const std::vector<std::string> readInput(const std::string& inputFilePath)
    {
        std::vector<std::string> result;
        std::ifstream input(inputFilePath);

        if (!input)
        {
            throw std::invalid_argument("Cannot find file at path: \"" + inputFilePath + "\"");
        }

        std::string line;
        while (std::getline(input, line))
        {
            result.push_back(line);
        }

        input.close();
        return result;
    }
}
