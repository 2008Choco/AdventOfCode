#pragma once

#include <set>
#include <vector>

class Card
{
public:
    Card(const unsigned int id, const std::set<unsigned int>& winningNumbers, const std::vector<unsigned int>& numbers)
        : _id(id), _winningNumbers(winningNumbers), _numbers(numbers) {}

    unsigned int getId() const { return _id; }
    unsigned int getScore() const;
    unsigned int getMatchingNumberCount() const;

    bool operator<(const Card& other) const
    {
        return _id < other._id;
    }

private:
    unsigned int _id;
    std::set<unsigned int> _winningNumbers;
    std::vector<unsigned int> _numbers;
};
