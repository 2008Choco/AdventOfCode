#pragma once

#include <iostream>
#include <string>
#include <unordered_map>

#include "aoclib.h"

class Cube
{
public:
    enum Color
    {
        Red,
        Green,
        Blue
    };

    Cube() = delete;

    friend std::ostream& operator<<(std::ostream& out, const Cube::Color& color)
    {
        switch (color)
        {
        case Red: out << "red"; break;
        case Green: out << "green"; break;
        case Blue: out << "blue"; break;
        }
        return out;
    }

    static inline Cube::Color getByName(const std::string& name)
    {
        return CUBE_COLORS_BY_NAME.at(aoclib::toLower(name));
    }

private:
    static const std::unordered_map<std::string, Cube::Color> CUBE_COLORS_BY_NAME;
};
