#include "Card.h"

#include <cmath>

unsigned int Card::getScore() const {
    unsigned int count = getMatchingNumberCount();
    return (count <= 1) ? count : static_cast<unsigned int>(std::pow(2, count - 1));
}

unsigned int Card::getMatchingNumberCount() const
{
    unsigned int count = 0;

    for (const auto number : _numbers)
    {
        if (_winningNumbers.find(number) != _winningNumbers.end())
        {
            count++;
        }
    }

    return count;
}
