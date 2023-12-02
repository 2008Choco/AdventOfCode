#include "Cube.h"

const std::unordered_map<std::string, Cube::Color> Cube::CUBE_COLORS_BY_NAME = {
    { "red", Cube::Color::Red },
    { "blue", Cube::Color::Blue },
    { "green", Cube::Color::Green }
};
