#pragma once

#include <algorithm>
#include <unordered_map>
#include <vector>

#include "Cube.h"
#include "Handful.h"

class Game
{
public:
    explicit Game(int id)
        : _id(id) {}

    unsigned int getId() const
    {
        return _id;
    }

    void addHandful(const Handful& handful);

    inline bool isPossible() const
    {
        return std::all_of(_handfuls.begin(), _handfuls.end(), [](const Handful& handful) { return handful.isPossible(); });
    }

    unsigned int getPowerOfMinimumCubes() const;

private:
    const unsigned int _id;
    std::vector<Handful> _handfuls;
    std::unordered_map<Cube::Color, unsigned int> _minimumCubesByColor;
};
