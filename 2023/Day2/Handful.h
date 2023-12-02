#pragma once

#include <algorithm>
#include <unordered_map>

#include "Cube.h"

class Handful
{
public:
    static const std::unordered_map<Cube::Color, unsigned int> MAX_CUBE_COUNT;

    void setCubes(const Cube::Color cube, const unsigned int count)
    {
        _cubes[cube] = count;
    }

    unsigned int getCubes(const Cube::Color cube) const
    {
        return _cubes.at(cube);
    }

    const std::unordered_map<Cube::Color, unsigned int> getCubes() const
    {
        return _cubes;
    }

    inline bool isPossible() const
    {
        return std::all_of(_cubes.begin(), _cubes.end(), [](const auto& entry) {
            return entry.second <= MAX_CUBE_COUNT.at(entry.first);
        });
    }

private:
    std::unordered_map<Cube::Color, unsigned int> _cubes;
};
