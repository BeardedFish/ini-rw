// File Name:     main.cpp
// By:            Darian Benam (GitHub: https://github.com/BeardedFish/)
// Date:          Tuesday, June 2, 2020

#include "cmdfns.hpp"
#include "Reader.hpp"
#include <iostream>
#include <sstream>

/**
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
	std::cout << "Ini-Rw Test" << std::endl << std::endl;

	if (argc <= 1)
	{
		std::cerr << "ERROR: Invalid amount of parameters entered into the program." << std::endl;

		return EXIT_FAILURE;
	}

	const std::string iniFilePath = argv[1]; // ".//ExampleData//example1.ini"

	try
	{
		Ini::Reader iniReader(iniFilePath);

		std::cout << "Loaded file \"" << iniFilePath << "\" succesfully!" << std::endl << std::endl;

		std::vector<std::string> cmdTokens;

		std::string userInput;
		while (true)
		{
			std::cout << "Enter a command: ";
			std::getline(std::cin, userInput);

			if (userInput == "exit" || userInput == "quit")
			{
				break;
			}
			else if (userInput == "contents")
			{
				std::cout << std::endl << "=== INI FILE CONTENTS ============" << std::endl;

				std::cout << iniReader.ToString() << std::endl;

				std::cout << "==================================" << std::endl << std::endl;
			}
			else
			{
				cmdTokens = getStrTokens(userInput);

				if (cmdTokens.size() == 3)
				{
					if (cmdTokens[0] == "rs") // Read string
					{
						Ini::ReadResult<std::string> strResult = iniReader.ReadString(cmdTokens[1], cmdTokens[2]);

						if (strResult.Success)
						{
							std::cout << "\"" << strResult.ConvertedValue << "\"" << std::endl;
						}
						else
						{
							std::cout << "Unable to extract the string key value \"" << cmdTokens[2] << "\" from the section \"" << cmdTokens[1] << "\"." << std::endl;
						}
					}
				}
				else
				{
					std::cout << "Invalid amount of command parameters!" << std::endl << std::endl;
				}
			}
		}
	}
	catch (const std::exception& ex)
	{
		std::cerr << "An error occured while trying to open the file \"" << iniFilePath << "\". Error message: " << ex.what() << std::endl;
	}
}