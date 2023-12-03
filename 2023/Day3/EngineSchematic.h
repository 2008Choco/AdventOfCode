#pragma once

#include <algorithm>
#include <set>
#include <string>
#include <vector>

class EngineSchematic
{
public:
    explicit EngineSchematic(const std::vector<std::string> lines);

    void addLine(const std::string& line)
    {
        _schematic += line;
        _lineLength = std::max(_lineLength, line.size());
    }

    unsigned int calculateMissingPartNumber() const; // Part 1
    unsigned long long calculateFaultyGearNumber() const; // Part 2

private:
    std::string _schematic;
    size_t _lineLength;

    template <typename T>
    struct SizedValue
    {
        T value;
        size_t size;
    };

    bool isSpecialChar(char character) const;
    const SizedValue<unsigned int> readNumber(size_t index) const;
    bool isValid(size_t index, const SizedValue<unsigned int> value) const;
    std::set<unsigned int> findSurroundingNumbers(size_t index) const;
    unsigned int computeNumberAtIndex(size_t index) const;
};
