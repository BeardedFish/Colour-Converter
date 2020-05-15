/*
\file:     Colour.hpp
\author:   Darian Benam
\date:     Saturday, May 9, 2020
\brief:    Header file for the Colour class. This class can contain three values that describe a colour. The three values are red, blue, and green.
*/

#pragma once

#include <string>

class Colour
{
public:
	unsigned Red;
	unsigned Green;
	unsigned Blue;

	// Constructors
	Colour();
	Colour(unsigned r, unsigned g, unsigned b);
	Colour(std::string r, std::string g, std::string b);
	
	/*
	 * Function Name: ToRgb()
	 * Brief:
	 * Parameters:
	 * Return:
	 */
	std::string ToHex();

private:
	bool isValidRgb(std::string r, std::string g, std::string b);
	std::string numberToHex(unsigned num);
};