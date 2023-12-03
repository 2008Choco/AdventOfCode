#include "EngineSchematic.h"

#include <algorithm>
#include <cctype>
#include <iostream>
#include <sstream>

EngineSchematic::EngineSchematic(const std::vector<std::string> lines)
    : _lineLength(0)
{
    std::stringstream stream;
    for (const auto& line : lines)
    {
        stream << line;
        _lineLength = std::max(_lineLength, line.size());
    }
    stream >> _schematic;
}

unsigned int EngineSchematic::calculateMissingPartNumber() const
{
    unsigned int sum = 0;

    for (size_t i = 0; i < _schematic.length(); ++i)
    {
        char character = _schematic[i];

        if (!isdigit(character))
        {
            continue;
        }

        const auto value = readNumber(i);

        if (isValid(i, value))
        {
            sum += value.value;
        }

        i += value.size;
    }

    return sum;
}

bool EngineSchematic::isSpecialChar(char character) const
{
    return ispunct(character) && character != '.';
}

const EngineSchematic::SizedValue<unsigned int> EngineSchematic::readNumber(size_t index) const
{
    SizedValue<unsigned int> value{0, 0};

    while (isdigit(_schematic[index]))
    {
        value.value *= 10;
        value.value += (_schematic[index++] - '0');
        value.size++;
    }

    return value;
}

bool EngineSchematic::isValid(size_t index, const SizedValue<unsigned int> value) const
{
    // Look before
    if ((index % _lineLength > 0) && isSpecialChar(_schematic[index - 1]))
    {
        return true;
    }

    // Look after
    if (((index + value.size) % _lineLength) < (_lineLength - 1) && isSpecialChar(_schematic[index + value.size]))
    {
        return true;
    }

    // Look above
    if (index >= _lineLength)
    {
        size_t indexAbove = (index - _lineLength);
        size_t size = value.size;

        if (indexAbove > 0)
        {
            indexAbove--;
            size++;
        }

        if ((index + value.size) % _lineLength > 0)
        {
            size++;
        }

        for (int i = 0; i < size; ++i, ++indexAbove)
        {
            if (isSpecialChar(_schematic[indexAbove]))
            {
                return true;
            }
        }
    }

    // Look below
    if ((index + _lineLength) < _schematic.size())
    {
        size_t indexBelow = (index + _lineLength);
        size_t size = value.size;

        if ((indexBelow % _lineLength) > 0)
        {
            indexBelow--;
            size++;
        }

        if ((indexBelow % _lineLength) < (_lineLength + size))
        {
            size++;
        }

        for (int i = 0; i < size; ++i, ++indexBelow)
        {
            if (isSpecialChar(_schematic[indexBelow]))
            {
                return true;
            }
        }
    }

    return false;
}

unsigned long long EngineSchematic::calculateFaultyGearNumber() const
{
    unsigned long long sum = 0;

    for (size_t i = 0; i < _schematic.size(); ++i)
    {
        const char character = _schematic[i];
        if (character != '*')
        {
            continue;
        }

        auto numbers = findSurroundingNumbers(i);
        if (numbers.size() == 2)
        {
            unsigned int product = 1;
            for (auto value : numbers)
            {
                product *= value;
            }
            sum += product;
        }
    }

    return sum;
}

std::set<unsigned int> EngineSchematic::findSurroundingNumbers(size_t index) const
{
    std::set<unsigned int> values;

    // Look before
    if ((index % _lineLength > 0) && isdigit(_schematic[index - 1]))
    {
        values.insert(computeNumberAtIndex(index - 1));
    }

    // Look after
    if (((index + 1) % _lineLength) < (_lineLength - 1) && isdigit(_schematic[index + 1]))
    {
        values.insert(computeNumberAtIndex(index + 1));
    }

    // Look above
    if (index >= _lineLength)
    {
        size_t indexAbove = (index - _lineLength);
        size_t size = 1;

        if (indexAbove > 0)
        {
            indexAbove--;
            size++;
        }

        if ((index + 1) % _lineLength > 0)
        {
            size++;
        }

        for (int i = 0; i < size; ++i, ++indexAbove)
        {
            if (isdigit(_schematic[indexAbove]))
            {
                values.insert(computeNumberAtIndex(indexAbove));
            }
        }
    }

    // Look below
    if ((index + _lineLength) < _schematic.size())
    {
        size_t indexBelow = (index + _lineLength);
        size_t size = 1;

        if ((indexBelow % _lineLength) > 0)
        {
            indexBelow--;
            size++;
        }

        if ((indexBelow % _lineLength) < (_lineLength + size))
        {
            size++;
        }

        for (int i = 0; i < size; ++i, ++indexBelow)
        {
            if (isdigit(_schematic[indexBelow]))
            {
                values.insert(computeNumberAtIndex(indexBelow));
            }
        }
    }

    return values;
}

unsigned int EngineSchematic::computeNumberAtIndex(size_t index) const
{
    // Move to the start of the number
    while ((index % _lineLength > 0) && isdigit(_schematic[--index]));
    if (!isdigit(_schematic[index]))
    {
        index++;
    }

    unsigned int value = 0;
    while ((index % _lineLength < _lineLength) && isdigit(_schematic[index]))
    {
        value *= 10;
        value += (_schematic[index++] - '0');
    }

    return value;
}
