#pragma once

#include <string>
#include <string_view>
#include <vector>

#define WIN32_LEAN_AND_MEAN // Exclude rarely-used stuff from Windows headers

namespace aoclib
{
    /**
     * Read a newline-delimited file at the given path and return its lines
     * in a std::vector.
     *
     * @param inputFilePath the path to the file from which to read
     *
     * @return the file lines
     *
     * @throws std::invalid_argument if the file stream failed to open
     */
    [[nodiscard]] std::vector<std::string> readInput(const std::string& inputFilePath = "input.txt");

    /**
     * Convert a string to uppercase.
     *
     * @param string the string to convert
     */
    void toUpper(std::string& string);

    /**
     * Copy a string and return it as its uppercase equivalent.
     *
     * @param string the string to convert
     *
     *  @return the uppercased string copy
     */
    std::string toUpper(std::string_view string);

    /**
     * Convert a string to lowercase.
     *
     * @param string the string to convert
     */
    void toLower(std::string& string);

    /**
     * Copy a string and return it as its lowercase equivalent.
     *
     * @param string the string to convert
     *
     *  @return the lowercased string copy
     */
    std::string toLower(std::string_view string);

    /**
     * Eat characters in the provided string until it reaches the specified
     * character and return the characters that were eaten as a string.
     *
     * @param string the input string
     * @param until the character to find at which point eating will stop
     *
     * @return a string containing all the characters that were eaten (excluding
     * the eaten character itself), or the passed string if no characters were
     * eaten because they could not be found in the string
     */
    std::string eat(std::string& string, const char until);

    /**
     * Eat characters in the provided string until it reaches the specified
     * character and return the characters that were eaten as a string.
     *
     * @param string the input string
     * @param until the character to find at which point eating will stop
     *
     * @return a string containing all the characters that were eaten (excluding
     * the eaten character itself), or the passed string if no characters were
     * eaten because they could not be found in the string
     */
    std::string eat(std::string& string, const std::string_view until);

    /**
     * Split the provided string by the provided delimiter and return its separated
     * components in a vector of strings.
     *
     * Say for example the input string is "Hello,world" and the delimiter is ',',
     * the returned vector will contain two strings, { "Hello", "world" }.
     *
     * @param string the input string
     * @param delimiter the delimiter to split by
     *
     * @return the string's components that have been split between the delimiter
     */
    std::vector<std::string> split(const std::string_view string, const char delimiter);

    /**
     * Split the provided string by the provided delimiter and return its separated
     * components in a vector of strings.
     *
     * Say for example the input string is "Hello,world" and the delimiter is ',',
     * the returned vector will contain two strings, { "Hello", "world" }.
     *
     * @param string the input string
     * @param delimiter the delimiter to split by
     *
     * @return the string's components that have been split between the delimiter
     */
    std::vector<std::string> split(const std::string_view string, const std::string_view delimiter);
}
