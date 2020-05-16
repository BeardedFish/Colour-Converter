/*
 * File Name:     Hex.cpp
 * Purpose:       Refer to Hex.hpp for purpose.
 * Coder:         Darian Benam (GitHub: https://github.com/BeardedFish/)
 * Date:          Saturday, May 9, 2020
 */

#include "Hex.hpp"

Hex::Hex()
{
	SetHex("000000"); // Set the default hex as black
}

Hex::Hex(std::string hex)
{
	if (!IsValidHex(hex))
	{
		throw std::exception("The hex is invalid.");
	}

	SetHex(hex);
}

void Hex::CleanupHexString(std::string& hex)
{
	if (hex.length() >= 1 && hex[0] == '#')
	{
		hex = hex.substr(1, hex.length() - 1);
	}
}

std::string Hex::GetHex()
{
	return hex;
}

void Hex::SetHex(std::string hex)
{
	this->hex = hex;
}

Colour Hex::ToRgb()
{
	Colour result;

	result.Red = hexToNumber(hex.substr(0, 2));
	result.Green = hexToNumber(hex.substr(2, 2));
	result.Blue = hexToNumber(hex.substr(4, 4));

	return result;
}

bool Hex::IsValidHex(const std::string& hex)
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

unsigned Hex::hexToNumber(char hex)
{
	hex = toupper(hex);

	return (hex >= 'A' && hex <= 'F') ? hex - 'A' + 10 : hex - '0';
}

unsigned Hex::hexToNumber(const std::string& hex)
{
	unsigned result = 0;

	for (size_t i = 0; i < hex.length(); i++)
	{
		result += hexToNumber(hex[hex.length() - 1 - i]) * pow(16, i);
	}

	return result;
}