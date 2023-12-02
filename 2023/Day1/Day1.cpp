#include <cctype>
#include <stdexcept>
#include <iostream>
#include <string>
#include <vector>

#include "aoclib.h"
#include "LiteralNumberBuilder.h"

// https://adventofcode.com/2023/day/1

template <typename Iterator>
int findDigit(const std::string& string, Iterator start, const Iterator end, bool findTypedNumbers, bool reversed)
{
    LiteralNumberBuilder numberBuilder(reversed);

    for (; start != end; start++)
    {
        if (isdigit(*start))
        {
            return (*start) - '0';
        }
        else if (findTypedNumbers && numberBuilder.append(*start))
        {
            return numberBuilder.getCurrentValue();
        }
    }

    throw std::invalid_argument("Could not find digit in string: \"" + string + "\"");
}

int findCalibrationValue(const std::string& string, bool findTypedNumbers)
{
    int value = 0;
    value += findDigit(string, string.begin(), string.end(), findTypedNumbers, false) * 10;
    value += findDigit(string, string.rbegin(), string.rend(), findTypedNumbers, true);
    return value;
}

int main()
{
    const bool part2 = true;
    const std::vector<std::string> input = aoclib::readInput();

    int sum = 0;
    for (const std::string& line : input)
    {
        // Debug :)
        // std::cout << "\"" << line << "\": " << findCalibrationValue(line, part2) << std::endl;
        sum += findCalibrationValue(line, part2);
    }
    std::cout << "Calibration value is: " << sum << std::endl;
}
