// File Name:     main.cpp
// By:            Darian Benam (GitHub: https://github.com/BeardedFish/)
// Date:          Tuesday, June 2, 2020

#include <iostream>
#include "Reader.hpp"

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
		Ini::Reader myReader(iniFilePath);

		std::cout << "Loaded file \"" << iniFilePath << "\ succesfully!" << std::endl;

		std::string userInput;
		while (true)
		{
			std::cout << "Enter a command:";
			std::cin >> userInput;

			// TODO: Implement code here that will take commands from the user to read section/key values.
		}
	}
	catch (const std::exception& ex)
	{
		std::cerr << "An error occured while trying to open the file \"" << iniFilePath << "\". Error message: " << ex.what() << std::endl;
	}
}