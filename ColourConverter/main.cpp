/*
\file:     main.cpp
\author:   Darian Benam
\date:     Saturday, May 9, 2020
\version:  1.0
\brief:    This program takes in a hex string and converts it to its RGB equivalent. This program also converts a RGB
\          combo to its hex string equivalent.
*/

#include <iostream>
#include "programfns.hpp"

/*
\fn:        main()
\brief:     The main entry point of the program.
\param:     argc - Argument count, the amount of arguments available that were passed into the program on execution.
\           argv - Argument vector, a pointer to a char array that contains the actual arguments passed into the program.
\return:    An int representing the exit code of the program.
*/
int main(int argc, char* argv[])
{
	if (argc <= 1)
	{
		std::cerr << "ERROR: No arguments passed to program." << std::endl << std::endl;

		printUsageText(std::cerr, argv[0]);

		return EXIT_FAILURE;
	}

	std::cout << "Colour Converter - By: " << PROGRAM_CREATOR << std::endl << std::endl;

	if (argc == 2)
	{
		std::string secondArgument = argv[1];

		if (isCommand(secondArgument)) // Handle double dash commands
		{
			secondArgument = secondArgument.substr(2, secondArgument.length() - 1);

			handleCommand(secondArgument);
		}
		else // Convert hex to RGB
		{
			cleanupHexString(secondArgument);

			if (!isValidHex(secondArgument))
			{
				std::cerr << "ERROR: Hex is invalid!" << std::endl;

				return EXIT_FAILURE;
			}

			Colour rgbResult = convertHexToRgb(secondArgument);
			std::cout << "The hex value #" << secondArgument << " equivalent RGB value is: " << rgbResult.Red << " " << rgbResult.Green << " " << rgbResult.Blue << "." << std::endl;
		}
	}
	else if (argc == 4) // Convert RGB to hex
	{
		std::string red = argv[1];
		std::string green = argv[2];
		std::string blue = argv[3];

		is_valid_rgb_result_t result = isValidRgb(red, green, blue);

		if (!result.isValidRgb)
		{
			std::cerr << "ERROR: RGB is invalid!" << std::endl;

			return EXIT_FAILURE;
		}

		std::string hexResult = convertRgbToHex(result.rgbColour);
		std::cout << "The RGB(" << red << ", " << green << ", " << blue << ")" <<  " hex value is #" << hexResult << std::endl;
	}
	else
	{
		std::cout << "Invalid amount of parameters entered!" << std::endl << std::endl;

		printUsageText(std::cerr, argv[0]);
	}
}