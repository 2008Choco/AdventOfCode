#include "Game.h"

void Game::addHandful(const Handful& handful)
{
    _handfuls.push_back(handful);

    for (const auto& entry : handful.getCubes())
    {
        unsigned int& value = _minimumCubesByColor[entry.first];
        value = std::max(value, entry.second);
    }
}

unsigned int Game::getPowerOfMinimumCubes() const
{
    unsigned int power = 1;

    for (const auto& entry : _minimumCubesByColor)
    {
        power *= entry.second;
    }

    return power;
}
