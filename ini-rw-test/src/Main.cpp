// File Name:     Main.cpp
// By:            Darian Benam (GitHub: https://github.com/BeardedFish/)
// Date:          Sunday, August 30, 2020

#include "ini-rw/inc/IniSetting.hpp"
#include "ini-rw/inc/algorithms/Validation.hpp"
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
#if _DEBUG
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#endif

    std::cout << INI_RW_ACSII_ART << std::endl << std::endl;

    if (argc <= 1)
    {
        std::cerr << "Invalid amount of parameters." << std::endl;
        std::cerr << "Usage: " << (argc == 0 ? "[EXECUTABLE_NAME]" : argv[0]) << " [INI_FILE_PATH]" << std::endl;

        return EXIT_FAILURE;
    }

    IniRW::IniSetting iniSettings(argv[1]);
    
    if (iniSettings) // Alternatively, you could do "iniSettings.IsLoaded()"
    {
        std::cout << "The INI file \"" << argv[1] << "\" was loaded succesfully!" << std::endl << std::endl;
        std::cout << "Type \"help\" for a list of commands." << std::endl << std::endl;

        bool exitLoopFlag = false;
        std::string userInput;

        do
        {
            std::cout << ">> ";
            std::getline(std::cin, userInput);

            if (userInput.length() > 0)
            {
                exitLoopFlag = IniRW::EqualsIgnoreCase(userInput, "quit");

                if (!exitLoopFlag)
                {
                    if (IniRW::EqualsIgnoreCase(userInput, "clrini"))
                    {
                        iniSettings.Clear();

                        std::cout << "The INI file contents were cleared succesfully!";
                    }
                    else if (IniRW::EqualsIgnoreCase(userInput, "contents"))
                    {
                        std::string iniContents = iniSettings.ToString();

                        std::cout << (iniContents.empty() ? "[!] FILE IS EMPTY" : iniContents);
                    }
                    else if (IniRW::EqualsIgnoreCase(userInput, "help"))
                    {
                        std::cout << "clrini - Clears the loaded INI file contents." << std::endl;
                        std::cout << "contents - Prints the contents of the loaded INI file." << std::endl;
                        std::cout << "help - Prints a list of valid commands for this program." << std::endl;
                        std::cout << "iv - Inserts a value to the INI file." << std::endl;
                        std::cout << "rs - Reads a string from the loaded INI file." << std::endl;
                        std::cout << "save - Saves the contents of the INI file to the location it was loaded from.";
                    }
                    else if (IniRW::EqualsIgnoreCase(userInput, "iv") || IniRW::EqualsIgnoreCase(userInput, "rs"))
                    {
                        std::cout << "Section Name: ";
                        std::string sectionName;
                        std::getline(std::cin, sectionName);

                        std::cout << "Key Name: ";
                        std::string keyName;
                        std::getline(std::cin, keyName);

                        if (IniRW::EqualsIgnoreCase(userInput, "iv")) // Insert value into INI file
                        {
                            std::cout << "Key Value: ";
                            std::string keyValue;
                            std::getline(std::cin, keyValue);

                            iniSettings.WriteKeyValue(sectionName, keyName, keyValue);

                            std::cout << std::endl << "Value written succesfully!";
                        }
                        else // Read string value from INI file
                        {
                            IniRW::IniKey* key = iniSettings.GetKey(sectionName, keyName); // Alternatively, you could do: "iniSettings[{sectionName, keyName}]"

                            if (key)
                            {
                                std::cout << std::endl << "The extracted value for the key \"" << keyName << "\" under the section \"" << sectionName << "\" is: \"" << key->GetValue() << "\".";
                            }
                            else
                            {
                                std::cout << std::endl << "The key \"" << keyName << "\" under the section \"" << sectionName << "\" was not found in the INI file!";
                            }
                        }
                    }
                    else if (IniRW::EqualsIgnoreCase(userInput, "save"))
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
        std::cout << "An error occured while trying to load the file \"" << argv[1] << "\". Program will now terminate..." << std::endl;
    }
}