/*
 * File Name:     main.cpp
 * Purpose:       The C++ source file that contains the main entry point of the colour converter program.
 * Coder:         Darian Benam (GitHub: https://github.com/BeardedFish/)
 * Date:          Saturday, May 9, 2020
 */

#include "CommandFns.hpp"
#include "Hex.hpp" // NOTE: Colour.hpp is also included with Hex.hpp
#include <iostream>

/*
 * Function Name:     main()
 *
 * Brief:             The main entry point of the program.
 *
 * Parameters:        argc - Argument count, the amount of arguments available that were passed into the program on execution.
 *                    argv - Argument vector, a pointer to a char array that contains the actual arguments passed into the program.
 *
 * Return:            An int representing the exit code of the program.
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
			Hex::CleanupHexString(secondArgument);

			try
			{

				Colour rgbResult = Hex(secondArgument).ToRgb();
				std::cout << "The hex value #" << secondArgument << " equivalent RGB value is: " << rgbResult.Red << " " << rgbResult.Green << " " << rgbResult.Blue << "." << std::endl;
			}
			catch (const std::exception& ex)
			{
				std::cerr << "ERROR: " << ex.what() << std::endl;

				return EXIT_FAILURE;
			}
		}
	}
	else if (argc == 4) // Convert RGB to hex
	{
		std::string red = argv[1];
		std::string green = argv[2];
		std::string blue = argv[3];

		try
		{
			Colour rgb(red, green, blue);

			std::cout << "The RGB(" << red << ", " << green << ", " << blue << ")" << " hex value is #" << rgb.ToHex() << std::endl;
		}
		catch (const std::exception& ex)
		{
			std::cerr << "ERROR: " << ex.what() << std::endl;

			return EXIT_FAILURE;
		}
	}
	else
	{
		std::cout << "Invalid amount of parameters entered!" << std::endl << std::endl;

		printUsageText(std::cerr, (argc == 0) ? "ColourConverter" : argv[0]);
	}
}