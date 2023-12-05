#include <iostream>
#include <numeric>
#include <set>
#include <string>
#include <map>
#include <vector>

#include "aoclib.h"
#include "Card.h"

// https://adventofcode.com/2023/day/4

template <typename T>
T parseNumbers(const std::string& string)
{
    T numbers{};

    for (const auto& numberString : aoclib::split(aoclib::trim(string), std::regex("\\s+")))
    {
        numbers.insert(numbers.end(), std::stoi(numberString));
    }

    return numbers;
}

auto parseCards(const std::vector<std::string>&& input)
{
    std::map<Card, size_t> cards;

    for (std::string line : input) // Intentional copy
    {
        aoclib::eat(line, "Card "); // Drop "Card "
        unsigned int cardId = std::stoi(aoclib::eat(line, std::regex(":\\s+")));

        std::vector<std::string> numberComponents = aoclib::split(line, " | ");
        auto winningNumbers = parseNumbers<std::set<unsigned int>>(numberComponents.at(0));
        auto numbers = parseNumbers<std::vector<unsigned int>>(numberComponents.at(1));

        cards.insert({ Card(cardId, winningNumbers, numbers), 1 });
    }

    return cards;
}

int main()
{
    std::map<Card, size_t> cards = parseCards(aoclib::readInput());

    // Part 1
    unsigned int score = 0;
    for (const auto& entry : cards)
    {
        score += entry.first.getScore();
    }

    // Part 2
    for (auto iterator = cards.begin(); iterator != cards.end(); iterator++)
    {
        const Card& card = (*iterator).first;
        const size_t count = (*iterator).second;

        const unsigned int matchingNumbers = card.getMatchingNumberCount();
        if (matchingNumbers == 0)
        {
            continue;
        }

        for (size_t i = 0; i < matchingNumbers; i++)
        {
            (*(++iterator)).second += count;
        }

        for (size_t i = 0; i < matchingNumbers; i++, --iterator);
    }

    size_t totalCardCount = std::accumulate(cards.begin(), cards.end(), 0, [](size_t current, const auto& entry)
        {
            return current + entry.second;
        });

    std::cout << "The total score on all cards is: " << score << std::endl; // Part 1
    std::cout << "There are " << totalCardCount << " total cards." << std::endl; // Part 2
}
