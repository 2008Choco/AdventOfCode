#include "LiteralNumberBuilder.h"

#include <iostream>
#include <stdexcept>

const std::vector<std::string> LiteralNumberBuilder::NUMBER_LITERALS = {
    "one",
    "two",
    "three",
    "four",
    "five",
    "six",
    "seven",
    "eight",
    "nine"
};

const bool LiteralNumberBuilder::append(const char character)
{
    if (_buffer.size() == LONGEST_NUMBER_LITERAL)
    {
        _buffer.erase((_inverse ? LONGEST_NUMBER_LITERAL - 1 : 0), 1);
    }

    if (_inverse)
    {
        _buffer.insert(0, 1, std::tolower(character));
    }
    else
    {
        _buffer.push_back(std::tolower(character));
    }

    // Try to find a literal number in the buffer
    for (int i = 0; i < NUMBER_LITERALS.size(); i++)
    {
        const std::string& literal = NUMBER_LITERALS[i];
        if (_buffer.find(literal) != std::string::npos)
        {
            _currentValue = (i + 1);
            return true;
        }
    }

    _currentValue = 0;
    return false;
}

const unsigned int LiteralNumberBuilder::getCurrentValue() const
{
    if (_currentValue == 0)
    {
        throw std::runtime_error("no value in current buffer");
    }

    return _currentValue;
}
