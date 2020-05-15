/*
 * File Name: Hex.hpp
 * Purpose: A public function that converts the hex value to a RGB colour.
 * Coder: Darian Benam (GitHub: https://github.com/BeardedFish/)
 * Date:
 */

#pragma once

#include "Colour.hpp"
#include <string>

class Hex
{
public:
	// Constructors
	Hex();
	Hex(std::string hex);

	std::string GetHex();
	void SetHex(std::string hex);

	/*
	 * Function Name: IsValidHex()
	 * Brief: A public function that converts the hex value to a RGB colour.
	 * Parameters: None.
	 * Return: A Colour that is the equivalent colour for the hex value.
	 */
	static bool IsValidHex(const std::string& hex);

	/*
	 * Function Name: CleanupHexString()
	 * Brief: A public function that cleans up a hex string by removing the prefix pound symbol if it exists.
	 * Parameters: hex - The hex string to be cleaned up.
	 * Return: Nothing. Works on the actual reference passed to the parameters of the function.
	 */
	static void CleanupHexString(std::string& hex);

	/*
	 * Function Name: ToRgb()
	 * Brief: A public function that converts the hex value to a RGB colour.
	 * Parameters: None.
	 * Return: A Colour that is the equivalent colour for the hex value.
	 */
	Colour ToRgb();
private:
	std::string hex;

	/*
	 * Function Name: hexToNumber()
	 * Brief: A private function that converts a hex character to its equivalent number value.
	 * Parameters: hex - The hex char to be converted to a number.
	 * Return: A number between 0 - 15 which represents the number value of the hex char.
	 */
	unsigned hexToNumber(char hex);

	/*
	 * Function Name: hexToNumber()
	 * Brief: A private function that converts a hex string of length 2 to its equivalent number value.
	 * Parameters: hex - The hex string to be converted to a number.
	 * Return: A number between 0 - 255 which represents the number value of the hex string.
	 */
	unsigned hexToNumber(const std::string& hex);
};