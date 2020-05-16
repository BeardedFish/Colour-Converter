/*
 * File Name:     Hex.hpp
 * Purpose:       A class for storing a hex colour value of length 6.
 * Coder:         Darian Benam (GitHub: https://github.com/BeardedFish/)
 * Date:          Saturday, May 9, 2020
 */

#pragma once

#include "Colour.hpp"
#include <string>

class Hex
{
public:
	Hex();
	Hex(std::string hex);

	std::string GetHex();
	void SetHex(std::string hex);

	/*
	 * Function Name:     IsValidHex()
	 *
	 * Brief:             Static function that checks if a string is a valid hex string. A valid hex string cam only contain digits from 0 to 9 and also can only
	 *                    contain the characters from A to F.
	 *
	 * Parameters:        hex - The string to be checked if it's a valid hex or not.
	 *
	 * Return:            True if the hex is valid, if not, false.
	 */
	static bool IsValidHex(const std::string& hex);

	/*
	 * Function Name:     CleanupHexString()
	 *
	 * Brief:             Static function that removes a leading pound sign if it exists.
	 *
	 * Parameters:        hex - The hex string to be cleaned up.
	 *
	 * Return:            Nothing.
	 */
	static void CleanupHexString(std::string& hex);

	/*
	 * Function Name:     ToRgb()
	 *
	 * Brief:             Converts the hex value of the class to a RGB colour.
	 *
	 * Parameters:        None.
	 *
	 * Return:            A Colour that is the equivalent to the hex value of this class.
	 */
	Colour ToRgb();
private:
	std::string hex;

	/*
	 * Function Name:     hexToNumber() [OVERLOADED FOR TYPE CHAR]
	 *
	 * Brief:             Converts a hex character to its equivalent number value.
	 *
	 * Parameters:        hex - The hex char to be converted to a number.
	 *
	 * Return:            A number between 0 - 15 which represents the number value of the hex char.
	 */
	unsigned hexToNumber(char hex);

	/*
	 * Function Name:     hexToNumber() [OVERLOADED FOR TYPE STRING]
	 *
	 * Brief:             Converts a hex string of length 2 to its equivalent number value.
	 *
	 * Parameters:        hex - The hex string to be converted to a number.
	 *
	 * Return:            A number between 0 - 255 which represents the number value of the hex string.
	 */
	unsigned hexToNumber(const std::string& hex);
};