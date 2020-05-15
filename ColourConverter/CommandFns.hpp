/*
\file:     programfns.hpp
\author:   Darian Benam
\date:     Saturday, May 9, 2020
\brief:    The header file that contains constants and function declarations that will be used in the Colour Converter program.
*/

#pragma once

#include  <string>

constexpr char PROGRAM_CREATOR[] = "Darian Benam";
constexpr char PROGRAM_VERSION[] = "1.0";

/*struct is_valid_rgb_result_t
{
	bool isValidRgb;
	Colour rgbColour;

	is_valid_rgb_result_t();
};*/

/* --- BEGIN FUNCTION DECLARATIONS --- */

/*
\fn:        printUsageText()
\brief:     Prints text to a stream that contains the proper usage to use the program via command line.
\param:     stream - The stream to print the usage text to.
\           fileName - The name of the executable file for this program.
\return:    Nothing.
*/
void printUsageText(std::ostream& stream, const std::string& fileName);

/*
\fn:        isCommand()
\brief:     Checks if a string is a valid command. A valid command begins with two dashes.
\param:     cmd - The string to checked if it is a valid command.
\return:    A boolean of value true if it is a valid command, else false.
*/
bool isCommand(const std::string& cmd);

/*
\fn:        handleCommand()
\brief:     Handles specific commands by executing code for what that command should do (ex: --help prints text on how to use the program).
\param:     cmd - The string that holds a command to be evaluated.
\return:    Nothing.
*/
void handleCommand(const std::string& cmd);

/*
\fn:        isValidHex()
\brief:     Checks if a string is a valid hex string. A valid hex string cam only contain digits from 0 to 9 and also can only
\           contain the characters from A to F.
\param:     hex - The string to be checked if it's a valid hex or not.
\return:    A boolean of value true if it's a valid hex, else false.
*/
//bool isValidHex(const std::string& hex);

/*
\fn:        cleanupHexString()
\brief:     Cleans up a hex string by removing a leading pound sign if it exists.
\param:     hex - The hex string to be cleaned up.
\return:    Nothing.
*/
//void cleanupHexString(std::string& hex);

/*
\fn:        numberToHex()
\brief:     
\param:     hex - The char that contains the hexadecimal value.
\return:
*/
//std::string numberToHex(unsigned num);

/*
\fn:        hexToNumber()
\brief:     Converts a hexadecimal character to its number value.
\param:     hex - The char that contains the hexadecimal value.
\return:    
*/
//unsigned hexToNumber(char hex);

/*
\fn:        hexToNumber()
\brief:     Converts a hexadecimal string to its number value.
\param:     hex - 
\return:    Nothing.
*/
//unsigned hexToNumber(const std::string& hex);

/*
\fn:        convertHexToRgb()
\brief:     Converts a hex colour string to its RGB colour equivalent.
\param:     hex - The hex string to be converted to a RGB colour.
\return:    A 'Colour' class which contains the RGB values of the hex colour.
*/
//Colour convertHexToRgb(std::string hex);

/*
\fn:        isValidRgb()
\brief:     Checks to see if three strings contain valid RGB values. Valid RGB values are numbers that are >= 0 and <= 255.
\param:     r - The string that holds the value of red.
\           g - The string that holds the value of green.
\           b - The string that holds the value of blue.
\return:    
*/
//is_valid_rgb_result_t isValidRgb(const std::string& r, const std::string& g, const std::string& b);

/*
\fn:        convertRgbToHex()
\brief:     Converts a RGB colour to it's equivalent hex value.
\param:     colour - The RGB colour to be converted to hex.
\return:    A string that represents the hex equivalent of the RGB colour.
*/
//std::string convertRgbToHex(Colour colour);

/* ---  END FUNCTION DECLARATIONS  --- */