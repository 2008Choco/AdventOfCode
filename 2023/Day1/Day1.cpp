#include <cctype>
#include <stdexcept>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "LiteralNumberBuilder.h"

/*
--- Day 1: Trebuchet?! ---
Something is wrong with global snow production, and you've been selected to take a look.
The Elves have even given you a map; on it, they've used stars to mark the top fifty
locations that are likely to be having problems.

You've been doing this long enough to know that to restore snow operations, you need to
check all fifty stars by December 25th.

Collect stars by solving puzzles. Two puzzles will be made available on each day in the
Advent calendar; the second puzzle is unlocked when you complete the first. Each puzzle
grants one star. Good luck!

You try to ask why they can't just use a weather machine ("not powerful enough") and where
they're even sending you ("the sky") and why your map looks mostly blank ("you sure ask a
lot of questions") and hang on did you just say the sky ("of course, where do you think
snow comes from") when you realize that the Elves are already loading you into a trebuchet
("please hold still, we need to strap you in").

As they're making the final adjustments, they discover that their calibration document
(your puzzle input) has been amended by a very young Elf who was apparently just excited to
show off her art skills. Consequently, the Elves are having trouble reading the values on
the document.

The newly-improved calibration document consists of lines of text; each line originally
contained a specific calibration value that the Elves now need to recover. On each line, the
calibration value can be found by combining the first digit and the last digit (in that
order) to form a single two-digit number.

For example:
1abc2
pqr3stu8vwx
a1b2c3d4e5f
treb7uchet

In this example, the calibration values of these four lines are 12, 38, 15, and 77. Adding
these together produces 142.

Consider your entire calibration document. What is the sum of all of the calibration values?

--- Part Two ---
Your calculation isn't quite right. It looks like some of the digits are actually spelled
out with letters: one, two, three, four, five, six, seven, eight, and nine also count as valid
"digits".

Equipped with this new information, you now need to find the real first and last digit on each
line. For example:

two1nine
eightwothree
abcone2threexyz
xtwone3four
4nineeightseven2
zoneight234
7pqrstsixteen

In this example, the calibration values are 29, 83, 13, 24, 42, 14, and 76. Adding these together
produces 281.

What is the sum of all of the calibration values?
*/

const std::vector<std::string> readInput()
{
    std::vector<std::string> result;
    std::ifstream input("input.txt");

    std::string line;
    while (std::getline(input, line))
    {
        result.push_back(line);
    }

    input.close();
    return result;
}

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
    const std::vector<std::string> input = readInput();

    int sum = 0;
    for (const std::string& line : input)
    {
        // Debug :)
        // std::cout << "\"" << line << "\": " << findCalibrationValue(line, part2) << std::endl;
        sum += findCalibrationValue(line, part2);
    }
    std::cout << "Calibration value is: " << sum << std::endl;
}