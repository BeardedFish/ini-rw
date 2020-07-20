// File Name:     main.cpp
// By:            Darian Benam (GitHub: https://github.com/BeardedFish/)
// Date:          Saturday, June 13, 2020

#include "cmdfns.hpp"
#include "ini-rw/core/algorithms/KeyAlgorithms.hpp"
#include "ini-rw/IniSettings.hpp"

const char* INI_RW_ACSII_ART = " _            _                              \n"
                               "|_|          |_|                             \n"
                               " _   ______   _           ______   _       _ \n"
                               "| | |  __  | | |         |  __  | | |     | |\n"
                               "| | | |  | | | |  _____  | |  |_| | |  _  | |\n"
                               "| | | |  | | | | |_____| | |      | | | | | |\n"
                               "| | | |  | | | |         | |      | |_| |_| |\n"
                               "|_| |_|  |_| |_|         |_|      |_________|\n\n"
	                           "=============================================";

int main(int argc, char* argv[])
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	std::cout << INI_RW_ACSII_ART << std::endl << std::endl;

	if (argc <= 1)
	{
		std::cerr << "Invalid amount of parameters." << std::endl;
		std::cerr << "Usage: " << (argc == 0 ? "[EXECUTABLE_NAME]" : argv[0]) << " [INI_FILE_PATH]" << std::endl;

		return EXIT_FAILURE;
	}

	IniRW::IniSettings settings(argv[1]);

	if (settings.IsLoaded())
	{
		std::cout << "Ini File \"" << argv[0] << "\" was loaded succesfully!" << std::endl << std::endl;

		std::string cmd;
		while (true)
		{
			std::cout << "Enter a command: ";
			std::getline(std::cin, cmd);

			std::vector<std::string> cmdTokens = getStrTokens(cmd);

			cmdTokens[0] = IniRW::LowercaseValue(cmdTokens[0]);

			if (cmdTokens[0] == "quit")
			{
				break;
			}
			else if (cmdTokens[0] == "contents")
			{
				std::string iniContents = settings.ToString();

				std::cout << "=== INI FILE CONTENTS =====================" << std::endl;
				std::cout << (iniContents.empty() ? "[!] FILE IS EMPTY" : iniContents) << std::endl;
				std::cout << "===========================================";
			}
			else if (cmdTokens[0] == "save")
			{
				bool success = settings.Save();

				std::cout << (success ? "The INI file was saved succesfully!" : "An error occured while trying to save the INI file.");
			}
			else
			{
				if (cmdTokens[0] == "rs" || cmdTokens[0] == "iv")
				{
					if (cmdTokens.size() >= 3)
					{
						if (cmdTokens[0] == "rs")
						{
							IniRW::Key* strResult = settings.GetKey(cmdTokens[1], cmdTokens[2]);

							printResult(strResult, cmdTokens[1], cmdTokens[2]);
						}

						if (cmdTokens[0] == "iv")
						{
							if (cmdTokens.size() == 4)
							{
								settings.WriteKeyValue(cmdTokens[1], cmdTokens[2], cmdTokens[3]);

								std::cout << "Value written succesfully!";
							}
							else
							{
								std::cout << ">> Insufficient amount of parameters for command!";
							}
						}
					}
					else
					{
						std::cout << ">> Insufficient amount of parameters for command!";
					}
				}
				else
				{
					std::cout << ">> Invalid command!";
				}
			}

			std::cout << std::endl << std::endl;
		}
	}
	else
	{
		std::cout << "An error occured while trying to load the file \"" << argv[1] << "\". Program will now terminate..." << std::endl << std::endl;
	}
}