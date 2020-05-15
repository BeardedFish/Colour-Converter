/*
\file:     programfns.cpp
\author:   Darian Benam
\date:     Saturday, May 9, 2020
\brief:
*/

#include "programfns.hpp"
#include <iostream>

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

void handleCommand(const std::string& cmd) // TODO: Finish this part
{
	if (cmd == "help")
	{
		std::cout << "Commands" << std::endl << std::endl;

		std::cout << "--help" << std::endl;
		std::cout << "--version" << std::endl;
	}
	else if (cmd == "version")
	{
		std::cout << "Program Version: " << PROGRAM_VERSION << std::endl;
	}
	else
	{
		std::cout << "Invalid command" << std::endl;
	}
}