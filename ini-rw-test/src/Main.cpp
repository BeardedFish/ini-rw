// File Name:     Main.cpp
// By:            Darian Benam (GitHub: https://github.com/BeardedFish/)
// Date:          Sunday, August 30, 2020

#include "../inc/InputFns.hpp"
#include "ini-rw/inc/IniSetting.hpp"
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
/// <param name="argc">Argument count, the amount of arguments available that were passed into the program on execution.</param>
/// <param name="argv">Argument vector, a pointer to a char array that contains the actual arguments passed into the program.</param>
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
        std::cout << "Type \"help\" for a list of commands." << std::endl << std::endl;

        bool exitLoopFlag = false;
        std::vector<std::string> userInputTokens;

        do
        {
            std::cout << ">> ";
            userInputTokens = GetTokenizedInput();

            if (userInputTokens.size() > 0)
            {
                exitLoopFlag = userInputTokens[0] == "quit";

                // TODO: Make user input case insensitive...

                if (!exitLoopFlag)
                {
                    if (userInputTokens[0] == "contents")
                    {
                        std::string iniContents = iniSettings.ToString();

                        std::cout << (iniContents.empty() ? "[!] FILE IS EMPTY" : iniContents);
                    }
                    else if (userInputTokens[0] == "help")
                    {
                        std::cout << "contents - Prints the contents of the loaded INI file." << std::endl;
                        std::cout << "help - Prints a list of valid commands for this program." << std::endl;
                        std::cout << "iv - Inserts a value to the INI file." << std::endl;
                        std::cout << "rs - Reads a string from the loaded INI file." << std::endl;
                        std::cout << "save - Saves the contents of the INI file to the location it was loaded from.";
                    }
                    else if (userInputTokens[0] == "iv") // Insert value into INI file
                    {
                        if (userInputTokens.size() >= 4)
                        {
                            std::string keyValue = VectorToString(userInputTokens, 3);
                            iniSettings.WriteKeyValue(userInputTokens[1], userInputTokens[2], keyValue);

                            std::cout << "Value written succesfully!";
                        }
                        else
                        {
                            std::cout << "Insufficient amount of parameters for the \"" << userInputTokens[0] << "\" command!";
                            std::cout << "Usage: iv [SECTION_NAME] [KEY_NAME] [KEY_VALUE]";
                        }
                    }
                    else if ( userInputTokens[0] == "rs") // Read string from INI file
                    {
                        if (userInputTokens.size() >= 3)
                        {
                            IniRW::IniKey* key = iniSettings.GetKey(userInputTokens[1], userInputTokens[2]);

                            if (key)
                            {
                                std::cout << "The extracted value is: \"" << key->GetValue() << "\".";
                            }
                            else
                            {
                                std::cout << "The key was not found in the INI file!";
                            }
                        }
                        else
                        {
                            std::cout << "Insufficient amount of parameters for the \"" << userInputTokens[0] << "\" command!";
                            std::cout << "Usage: iv [SECTION_NAME] [KEY_NAME]";
                        }
                    }
                    else if (userInputTokens[0] == "save")
                    {
                        bool success = iniSettings.SaveChanges();

                        std::cout << (success ? "The INI file was saved succesfully!" : "An error occured while trying to save the INI file.");
                    }
                    else
                    {
                        std::cout << "Invalid command!";
                    }
                }
            }
            else
            {
                std::cout << "Input cannot be empty!";
            }

            if (!exitLoopFlag)
            {
                std::cout << std::endl << std::endl;
            }

        } while (!exitLoopFlag);
    }
    else
    {
        std::cout << "An error occured while trying to load the file \"" << argv[1] << "\". Program will now terminate..." << std::endl << std::endl;
    }
}