/*
 * File Name:     Colour.cpp
 * Purpose:       Refer to Colour.hpp for purpose.
 * Coder:         Darian Benam (GitHub: https://github.com/BeardedFish/)
 * Date:          Saturday, May 9, 2020
 */

#include "Colour.hpp"
#include <assert.h>

Colour::Colour()
{
	Red = 0;
	Green = 0;
	Blue = 0;
}

Colour::Colour(unsigned r, unsigned g, unsigned b)
{
	Red = r;
	Green = g;
	Blue = b;
}

Colour::Colour(std::string r, std::string g, std::string b)
{
	if (!isValidRgb(r, g, b))
	{
		throw std::exception("RGB is invalid.");
	}

	Red = stoi(r);
	Green = stoi(g);
	Blue = stoi(b);
}

std::string Colour::ToHex()
{
	std::string result;

	result.append(numberToHex(Red));
	result.append(numberToHex(Green));
	result.append(numberToHex(Blue));

	return result;
}

bool Colour::isValidRgb(std::string r, std::string g, std::string b)
{
	try
	{
		int red = stoi(r);
		int green = stoi(g);
		int blue = stoi(b);

		return (red >= 0 && red <= 255) && (green >= 0 && green <= 255) && (blue >= 0 && blue <= 255);
	}
	catch (const std::exception&)
	{
		return false;
	}
}

std::string Colour::numberToHex(unsigned num)
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