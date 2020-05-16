/*
 * File Name:     Colour.hpp
 * Purpose:       A class for storing a RGB colour.
 * Coder:         Darian Benam (GitHub: https://github.com/BeardedFish/)
 * Date:          Saturday, May 9, 2020
 */

#pragma once

#include <string>

class Colour
{
public:
	unsigned Red;
	unsigned Green;
	unsigned Blue;

	Colour();
	Colour(unsigned r, unsigned g, unsigned b);
	Colour(std::string r, std::string g, std::string b);

	 /*
	  * Function Name:     ToHex()
	  *
	  * Brief:             Converts the RGB colour of the class to its equivalent hex value.
	  *
	  * Parameters:        None.
	  *
	  * Return:            A string of length 6 that represents the hex value of the RGB.
	  */
	std::string ToHex();

private:
	/*
	 * Function Name:     isValidRgb()
	 *
	 * Brief:             Private function that checks to see if a RGB combo of strings is a valid RGB. A valid RGB is a value that is between and
	 *                    including 0 to 255.
	 *
	 * Parameters:        r - The string that represents the value of red.
	 *                    g - The string that represents the value of green.
	 *                    b - The string that represents the value of blue.
	 *
	 * Return:            True if the RGB combo is valid, if not, false.
	 */
	bool isValidRgb(std::string r, std::string g, std::string b);

	/*
	 * Function Name:     numberToHex()
	 *
	 * Brief:             Converts a number between and including 0 to 255 into a hex string.
	 *
	 * Parameters:        num - The number to be converted to hex.
	 *
	 * Return:            A string of length 2 that represents the hex value of the number.
	 */
	std::string numberToHex(unsigned num);
};