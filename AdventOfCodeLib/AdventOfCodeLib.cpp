#include "pch.h"
#include "aoclib.h"

#include <fstream>
#include <stdexcept>

namespace aoclib
{
    std::vector<std::string> readInput(const std::string& inputFilePath)
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

    void toUpper(std::string& string)
    {
        for (int i = 0; i < string.size(); i++)
        {
            string[i] = std::toupper(string[i]);
        }
    }

    std::string toUpper(std::string_view string)
    {
        std::string result = std::string(string);
        toUpper(result);
        return result;
    }

    void toLower(std::string& string)
    {
        for (int i = 0; i < string.size(); i++)
        {
            string[i] = std::tolower(string[i]);
        }
    }

    std::string toLower(std::string_view string)
    {
        std::string result = std::string(string);
        toLower(result);
        return result;
    }

    template <typename T>
    std::string eat(std::string& string, const T& until, const size_t untilSize)
    {
        std::string result;

        size_t eatEndIndex = string.find(until);
        if (eatEndIndex == std::string::npos)
        {
            result = string;
            string.erase();
        }
        else
        {
            result = string.substr(0, eatEndIndex);
            string.erase(0, std::min(eatEndIndex + untilSize, string.size()));
        }

        return result;
    }

    std::string eat(std::string& string, const char until)
    {
        return eat(string, until, 1);
    }

    std::string eat(std::string& string, std::string_view until)
    {
        return eat(string, until, until.size());
    }

    template <typename T>
    std::vector<std::string> split(const std::string_view string, const T& delimiter, const size_t delimiterSize)
    {
        std::vector<std::string> components;
        std::string buffer = std::string(string);

        std::string current;
        while (!(current = eat(buffer, delimiter, delimiterSize)).empty())
        {
            components.push_back(current);
        }

        return components;
    }

    std::vector<std::string> split(const std::string_view string, const char delimiter)
    {
        return split(string, delimiter, 1);
    }

    std::vector<std::string> split(const std::string_view string, const std::string_view delimiter)
    {
        return split(string, delimiter, delimiter.size());
    }
}
