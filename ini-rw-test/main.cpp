// File Name:     main.cpp
// By:            Darian Benam (GitHub: https://github.com/BeardedFish/)
// Date:          Saturday, June 13, 2020

#include "cmdfns.hpp"
#include "IniSettings.hpp"
#include <iostream>

int main(int argc, char* argv[])
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	if (argc <= 1)
	{
		std::cerr << "Invalid amount of parameters." << std::endl;
		std::cerr << "Usage: " << (argc == 0 ? "[EXECUTABLE_NAME]" : argv[0]) << " [INI_FILE_PATH]" << std::endl;

		return EXIT_FAILURE;
	}

	std::cout << "Ini-RW Test" << std::endl << std::endl;

	IniRW::IniSettings settings(argv[1]);

	if (settings.IsLoaded())
	{
		std::cout << "Ini File \"" << argv[0] << "\" was loaded succesfully!" << std::endl << std::endl;

		std::string cmd;
		while (true)
		{
			std::cout << "Enter a command: ";
			std::getline(std::cin, cmd);

			if (cmd == "quit")
			{
				break;
			}
			
			std::vector<std::string> cmdTokens = getStrTokens(cmd);

			if (cmdTokens[0] == "rs")
			{
				if (cmdTokens.size() == 3)
				{
					if (cmdTokens[0] == "rs")
					{
						std::string strResult = settings.GetKeyValue(cmdTokens[1], cmdTokens[2]);

						std::cout << strResult << std::endl;
					}
				}
				else
				{
					std::cout << "Insufficient amount of parameters for command!" << std::endl;
				}
			}
			else
			{
				std::cout << "Invalid command!" << std::endl << std::endl;
			}
		}
	}
	else
	{
		std::cout << "An error occured while trying to load the file \"" << argv[1] << "\". Program will now terminate..." << std::endl << std::endl;
	}
}