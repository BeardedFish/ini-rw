// File Name:     Main.cpp
// By:            Darian Benam (GitHub: https://github.com/BeardedFish/)
// Date:          Sunday, August 30, 2020

#include "ini-rw/IniSetting.hpp"
#include <iostream>
#include <string>

const char* INI_RW_ACSII_ART = " _            _                              \n"
                               "|_|          |_|                             \n"
                               " _   ______   _           ______   _       _ \n"
                               "| | |  __  | | |         |  __  | | |     | |\n"
                               "| | | |  | | | |  _____  | |  |_| | |  _  | |\n"
                               "| | | |  | | | | |_____| | |      | | | | | |\n"
                               "| | | |  | | | |         | |      | |_| |_| |\n"
                               "|_| |_|  |_| |_|         |_|      |_________|\n\n"
                               "=============================================";

/// <summary>
/// Main entry point of the program.
/// </summary>
/// <param name="argc"></param>
/// <param name="argv"></param>
/// <returns>An integer that represents the exit code status of the program.</returns>
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

    IniRW::IniSetting iniSettings(argv[1]);

    if (iniSettings.IsLoaded())
    {
        std::cout << "The INI file \"" << argv[1] << "\" was loaded succesfully!" << std::endl << std::endl;

        bool exitLoopFlag = false;
        std::string userInput;

        do
        {
            std::cout << ">> ";
            std::getline(std::cin, userInput);

            exitLoopFlag = userInput == "quit";

            // TODO: Make user input case insensitive...

            if (userInput != "quit")
            {
                if (userInput == "contents")
                {
                    std::string iniContents = iniSettings.ToString();

                    std::cout << (iniContents.empty() ? "[!] FILE IS EMPTY" : iniContents);
                }
                else if (userInput == "save")
                {
                    bool success = iniSettings.SaveChanges();

                    std::cout << (success ? "The INI file was saved succesfully!" : "An error occured while trying to save the INI file.");
                }
                else
                {
                    std::cout << "Invalid command!";
                }

                std::cout << std::endl << std::endl;
            }
        } while (!exitLoopFlag);
    }
    else
    {
        std::cout << "An error occured while trying to load the file \"" << argv[1] << "\". Program will now terminate..." << std::endl << std::endl;
    }
}