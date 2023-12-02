#include <iostream>
#include <string>
#include <vector>

#include "aoclib.h"
#include "Game.h"

// https://adventofcode.com/2023/day/2

std::vector<Game> parseGames(const std::vector<std::string>& input)
{
    static const std::string gameIdDelimiter = ": ";
    static const std::string handfulDelimiter = "; ";
    static const std::string cubeDelimiter = ", ";

    std::vector<Game> games;

    for (std::string line : input) // Intentional element copy
    {
        aoclib::eat(line, ' '); // Drop "Game "
        unsigned int gameId = std::stoi(aoclib::eat(line, gameIdDelimiter));

        Game& game = games.emplace_back(gameId);

        for (const std::string& handfulString : aoclib::split(line, handfulDelimiter))
        {
            Handful handful;

            for (std::string& cubeString : aoclib::split(handfulString, cubeDelimiter))
            {
                unsigned int amount = std::stoi(aoclib::eat(cubeString, ' '));
                Cube::Color cube = Cube::getByName(cubeString);

                handful.setCubes(cube, amount);
            }

            game.addHandful(handful);
        }
    }

    return games;
}

int main()
{
    const std::vector<std::string> input = aoclib::readInput();
    const std::vector<Game> games = parseGames(input);

    unsigned int possibleGameIdSum = 0, totalPower = 0;
    for (const Game& game : games)
    {
        if (game.isPossible())
        {
            possibleGameIdSum += game.getId();
        }

        totalPower += game.getPowerOfMinimumCubes();
    }

    std::cout << "The sum of ids of all possible games is " << possibleGameIdSum << "." << std::endl;
    std::cout << "The sum of all game power is " << totalPower << "." << std::endl;
}
