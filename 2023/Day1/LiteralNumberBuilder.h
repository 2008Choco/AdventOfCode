#pragma once

#include <string>
#include <vector>

class LiteralNumberBuilder
{
public:
    explicit LiteralNumberBuilder(bool inverse = false)
            : _buffer(""), _inverse(inverse), _currentValue(0) {
        _buffer.reserve(LONGEST_NUMBER_LITERAL);
    }

    const bool append(const char character);
    const unsigned int getCurrentValue() const;

private:
    static const std::vector<std::string> NUMBER_LITERALS;
    static const unsigned int LONGEST_NUMBER_LITERAL = 5;

    std::string _buffer;
    bool _inverse;
    unsigned int _currentValue;
};
