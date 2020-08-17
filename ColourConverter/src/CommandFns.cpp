/*
 * File Name:     CommandFns.hpp
 * Purpose:       Refer to CommandFns.hpp for purpose.
 * Coder:         Darian Benam (GitHub: https://github.com/BeardedFish/)
 * Date:          Saturday, May 9, 2020
 */

#include "../includes/CommandFns.hpp"
#include <iomanip>
#include <iostream>
#include <sstream>

void printUsageText(std::ostream& stream, const std::string& fileName)
{
	stream << "Usage:" << std::endl;
	stream << fileName << " [hex]" << std::endl;
	stream << fileName << " [r] [g] [b]" << std::endl;
}

bool isCommand(const std::string& cmd)
{
	return cmd.length() >= 2 && cmd[0] == '-' && cmd[1] == '-';
}

std::string lowercaseStr(std::string str)
{
	for (size_t i = 0; i < str.length(); i++)
	{
		str[i] = tolower(str[i]);
	}

	return str;
}

void handleCommand(const std::string& cmd, const std::string& fileName)
{
	std::string lowerCmd = lowercaseStr(cmd);

	if (cmd == "help")
	{
		std::cout << "Colour Converter - By: " << PROGRAM_CREATOR << " | Version: " << PROGRAM_VERSION << std::endl << std::endl;

		printUsageText(std::cout, fileName);

		std::cout << std::endl << "Commands:" << std::endl;
		std::cout << std::left << std::setw(COMMAND_STR_WIDTH) << "--help" << "Provides text that shows how to use the program." << std::endl;
		std::cout << std::left << std::setw(COMMAND_STR_WIDTH) << "--version" << "Displays the version of the program." << std::endl;
	}
	else if (cmd == "version")
	{
		std::cout << "Program Version: " << PROGRAM_VERSION << std::endl;
	}
	else
	{
		std::cout << "The command --" << cmd << " is invalid!" << std::endl;
	}
}