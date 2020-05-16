/*
 * File Name:     CommandFns.hpp
 * Purpose:       Holds functions that are used for handling commands that are entered through the arguments of the program.
 * Coder:         Darian Benam (GitHub: https://github.com/BeardedFish/)
 * Date:          Saturday, May 9, 2020
 */

#pragma once

#include  <string>

constexpr char PROGRAM_CREATOR[] = "Darian Benam";
constexpr char PROGRAM_VERSION[] = "1.0";
constexpr size_t COMMAND_STR_WIDTH = 15;

/*
 * Function Name:     printUsageText()
 *
 * Brief:             Prints text to a stream that contains the proper usage to use the program via command line.
 *
 * Parameters:        stream - The stream to print the usage text to.
 *                    fileName - The name of the executable file for this program.
 *
 * Return:            Nothing.
 */
void printUsageText(std::ostream& stream, const std::string& fileName);

/*
 * Function Name:     isCommand()
 *
 * Brief:             Checks if a string is a command. A valid command begins with two dashes.
 *
 * Parameters:        cmd - The string to checked if it is a valid command.
 *
 * Return:            True if the command was valid, if not, false.
 */
bool isCommand(const std::string& cmd);

/*
 * Function Name:     lowercaseStr()
 *
 * Brief:             Converts a string to lowercase.
 *
 * Parameters:        str - The string to be converted to lowercase.
 *
 * Return:            A string that was converted to lowercase.
 */
std::string lowercaseStr(std::string str);

/*
 * Function Name:     handleCommand()
 *
 * Brief:             Handles specific commands by executing code for what that command should do (ex: --help prints text on how to use the program).
 *
 * Parameters:        cmd - The string that holds a command to be evaluated.
 *                    fileName - The name of the Colour Converter file currently being executed.
 *
 * Return:            Nothing.
 */
void handleCommand(const std::string& cmd, const std::string& fileName);