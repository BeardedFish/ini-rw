// File Name:     Main.cpp
// By:            Darian Benam (GitHub: https://github.com/BeardedFish/)
// Date:          Sunday, August 30, 2020

#include "ini-rw/inc/IniSetting.hpp"
#include "ini-rw/inc/algorithms/Validation.hpp"
#include <iostream>
#include <string>

int main(int argc, char* argv[])
{
#if _DEBUG
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#endif

    std::cout << " _            _                              \n"
                 "|_|          |_|                             \n"
                 " _   ______   _           ______   _       _ \n"
                 "| | |  __  | | |         |  __  | | |     | |\n"
                 "| | | |  | | | |  _____  | |  |_| | |  _  | |\n"
                 "| | | |  | | | | |_____| | |      | | | | | |\n"
                 "| | | |  | | | |         | |      | |_| |_| |\n"
                 "|_| |_|  |_| |_|         |_|      |_________|\n\n";

    if (argc <= 1)
    {
        std::cerr << "Invalid amount of parameters." << std::endl;
        std::cerr << "Usage: " << (argc == 0 ? "[EXECUTABLE_NAME]" : argv[0]) << " [INI_FILE_PATH]" << std::endl;

        return EXIT_FAILURE;
    }

    IniRW::IniSetting iniSettings(argv[1]);
    
    if (iniSettings) // Alternatively, you could do "iniSettings.is_loaded()"
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
                exitLoopFlag = IniRW::equals_ignore_case(userInput, "quit");

                if (!exitLoopFlag)
                {
                    if (IniRW::equals_ignore_case(userInput, "clrini"))
                    {
                        iniSettings.clear();

                        std::cout << "The INI file contents were cleared succesfully!";
                    }
                    else if (IniRW::equals_ignore_case(userInput, "contents"))
                    {
                        std::string iniContents = iniSettings.to_string();

                        std::cout << (iniContents.empty() ? "[!] FILE IS EMPTY" : iniContents);
                    }
                    else if (IniRW::equals_ignore_case(userInput, "help"))
                    {
                        std::cout << "clrini - Clears the loaded INI file contents." << std::endl;
                        std::cout << "contents - Prints the contents of the loaded INI file." << std::endl;
                        std::cout << "help - Prints a list of valid commands for this program." << std::endl;
                        std::cout << "iv - Inserts a value to the INI file." << std::endl;
                        std::cout << "rs - Reads a string from the loaded INI file." << std::endl;
                        std::cout << "save - Saves the contents of the INI file to the location it was loaded from.";
                    }
                    else if (IniRW::equals_ignore_case(userInput, "iv") || IniRW::equals_ignore_case(userInput, "rs"))
                    {
                        std::string sectionName, keyName, keyValue;

                        std::cout << "Section Name: ";
                        std::getline(std::cin, sectionName);

                        std::cout << "Key Name: ";
                        std::getline(std::cin, keyName);

                        if (IniRW::equals_ignore_case(userInput, "iv")) // Insert value into INI file
                        {
                            std::cout << "Key Value: ";
                            std::getline(std::cin, keyValue);

                            iniSettings.write_key_value(sectionName, keyName, keyValue);

                            std::cout << std::endl << "Value written succesfully!";
                        }
                        else // Read string value from INI file
                        {
                            IniRW::IniKey* key = iniSettings.get_key(sectionName, keyName); // Alternatively, you could do: "iniSettings[{sectionName, keyName}]"

                            if (key)
                            {
                                const IniRW::IniValueCommentPair VALUE_COMMENT_PAIR = key->ValueCommentPair;

                                std::cout << std::endl << "The extracted value for the key \"" << keyName << "\" under the section \"" << sectionName << "\" is: \"" << VALUE_COMMENT_PAIR.get_value_before_comment(true) << "\" (\"" << VALUE_COMMENT_PAIR.get_value_before_comment() << "\" with leading and trailing whitespace)" << "."; 
                            }
                            else
                            {
                                std::cout << std::endl << "The key \"" << keyName << "\" under the section \"" << sectionName << "\" was not found in the INI file!";
                            }
                        }
                    }
                    else if (IniRW::equals_ignore_case(userInput, "save"))
                    {
                        bool success = iniSettings.save_changes();

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
        }
        while (!exitLoopFlag);
    }
    else
    {
        std::cout << "An error occured while trying to load the file \"" << argv[1] << "\". Program will now terminate..." << std::endl;
    }
}
