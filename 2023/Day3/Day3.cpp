#include <iostream>
#include <string>
#include <vector>

#include "aoclib.h"
#include "EngineSchematic.h"

// https://adventofcode.com/2023/day/3

int main()
{
    EngineSchematic schematic(aoclib::readInput());
    std::cout << "The missing part number is: " << schematic.calculateMissingPartNumber() << std::endl;
    std::cout << "The faulty gear number is: " << schematic.calculateFaultyGearNumber() << std::endl;
}
