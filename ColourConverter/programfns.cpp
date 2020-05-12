/*
\file:     programfns.cpp
\author:   Darian Benam
\date:     Saturday, May 9, 2020
\brief:
*/

#include <assert.h>
#include <iomanip>
#include <iostream>
#include <sstream>
#include "programfns.hpp"

is_valid_rgb_result_t::is_valid_rgb_result_t()
{
	isValidRgb = false;
}

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

bool isValidHex(const std::string& hex)
{
	for (size_t i = 0; i < hex.length(); i++)
	{
		if (!isxdigit(hex[i]))
		{
			return false;
		}
	}

	return hex.length() == 6; // A colour hex has a length of 6
}

void cleanupHexString(std::string& hex)
{
	if (hex.length() >= 1 && hex[0] == '#')
	{
		hex = hex.substr(1, hex.length() - 1);
	}
}

std::string decimalToHex(unsigned num)
{
	std::string result = num == 0 ? "00" : "";

	unsigned remainder;
	while (num > 0)
	{
		remainder = num % 16;
		
		// Find the hexadecimal character that matches the remainder and append it to the beginning of the result string
		char appendChar = (remainder >= 0 && remainder < 10) ? '0' + remainder : 'A' + remainder - 10;
		result.insert(0, 1, appendChar);

		num /= 16;
	}

	if (result.length() == 1)
	{
		result.insert(0, 1, '0');
	}

	return result;
}

unsigned hexToDecimal(char hex)
{
	assert(isxdigit(hex));

	hex = toupper(hex);

	return (hex >= 'A' && hex <= 'F') ? hex - 'A' + 10 : hex - '0';
}

unsigned hexToDecimal(std::string hex)
{
	unsigned result = 0;

	for (size_t i = 0; i < hex.length(); i++)
	{
		result += hexToDecimal(hex[hex.length() - 1 - i]) * pow(16, i);
	}

	return result;
}

Colour convertHexToRgb(std::string hex)
{
	assert(hex.length() == 6);

	Colour result;

	result.Red = hexToDecimal(hex.substr(0, 2));
	result.Green = hexToDecimal(hex.substr(2, 2));
	result.Blue = hexToDecimal(hex.substr(4, 4));

	return result;
}

is_valid_rgb_result_t isValidRgb(const std::string& r, const std::string& g, const std::string& b)
{
	is_valid_rgb_result_t result;

	try
	{
		int red = stoi(r);
		int green = stoi(g);
		int blue = stoi(b);

		// Strings were converted successfully, check that they are in range, if they are, it's valid
		if ((red >= 0 && red <= 255) && (green >= 0 && green <= 255) && (blue >= 0 && blue <= 255))
		{
			Colour rgb((unsigned)red, (unsigned)green, (unsigned)blue);

			result.isValidRgb = true;
			result.rgbColour = rgb;
		}
	}
	catch (const std::exception&)
	{
		result.isValidRgb = false;
	}

	return result;
}

std::string convertRgbToHex(Colour colour)
{
	std::string result;

	result.append(decimalToHex(colour.Red));
	result.append(decimalToHex(colour.Green));
	result.append(decimalToHex(colour.Blue));

	return result;
}