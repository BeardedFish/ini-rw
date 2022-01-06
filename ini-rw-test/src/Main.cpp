// File Name:     Main.cpp
// By:            Darian Benam (GitHub: https://github.com/BeardedFish/)
// Date:          Sunday, August 30, 2020

#include "ini-rw/include/IniFile.hpp"
#include "ini-rw/include/algorithms/Validation.hpp"
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
        std::cerr << "Invalid amount of parameters." << '\n';
        std::cerr << "Usage: " << (argc == 0 ? "[EXECUTABLE_NAME]" : argv[0]) << " [INI_FILE_PATH]" << '\n';

        return EXIT_FAILURE;
    }

    inirw::IniFile iniFile(argv[1]);
    
    if (iniFile) // Alternatively, you could do "iniFile.is_loaded()"
    {
        std::cout << "The INI file \"" << argv[1] << "\" was loaded successfully!" << '\n' << '\n';
        std::cout << "Type \"help\" for a list of commands." << '\n' << '\n';

        bool exitLoopFlag = false;
        std::string userInput;

        do
        {
            std::cout << ">> ";
            std::getline(std::cin, userInput);

            if (userInput.length() > 0)
            {
                exitLoopFlag = inirw::equals_ignore_case(userInput, "quit");

                if (!exitLoopFlag)
                {
                    if (inirw::equals_ignore_case(userInput, "clrini"))
                    {
                        iniFile.clear();

                        std::cout << "The INI file contents were cleared successfully!";
                    }
                    else if (inirw::equals_ignore_case(userInput, "contents"))
                    {
                        std::string iniContents = iniFile.to_string();

                        std::cout << (iniContents.empty() ? "[!] FILE IS EMPTY" : iniContents);
                    }
                    else if (inirw::equals_ignore_case(userInput, "help"))
                    {
                        std::cout << "clrini - Clears the loaded INI file contents." << '\n';
                        std::cout << "contents - Prints the contents of the loaded INI file." << '\n';
                        std::cout << "help - Prints a list of valid commands for this program." << '\n';
                        std::cout << "iv - Inserts a value to the INI file." << '\n';
                        std::cout << "rs - Reads a string from the loaded INI file." << '\n';
                        std::cout << "save - Saves the contents of the INI file to the location it was loaded from.";
                    }
                    else if (inirw::equals_ignore_case(userInput, "iv") || inirw::equals_ignore_case(userInput, "rs"))
                    {
                        std::string sectionName, keyName, keyValue;

                        std::cout << "Section Name: ";
                        std::getline(std::cin, sectionName);

                        std::cout << "Key Name: ";
                        std::getline(std::cin, keyName);

                        if (inirw::equals_ignore_case(userInput, "iv")) // Insert value into INI file
                        {
                            std::cout << "Key Value: ";
                            std::getline(std::cin, keyValue);

                            iniFile.write_key_value(sectionName, keyName, keyValue);

                            std::cout << '\n' << "Value written succesfully!";
                        }
                        else // Read string value from INI file
                        {
                            inirw::IniKey* key = iniFile.get_key(sectionName, keyName); // Alternatively, you could do: "iniSettings[{sectionName, keyName}]"

                            if (key)
                            {
                                const inirw::IniValueCommentPair VALUE_COMMENT_PAIR = key->ValueCommentPair;

                                std::cout << '\n' << "The extracted value for the key \"" << keyName << "\" under the section \"" << sectionName << "\" is: \"" << VALUE_COMMENT_PAIR.get_value(true) << "\" (\"" << VALUE_COMMENT_PAIR.get_value() << "\" with leading and trailing whitespace)" << ".";
                            }
                            else
                            {
                                std::cout << '\n' << "The key \"" << keyName << "\" under the section \"" << sectionName << "\" was not found in the INI file!";
                            }
                        }
                    }
                    else if (inirw::equals_ignore_case(userInput, "save"))
                    {
                        bool success = iniFile.save_changes();

                        std::cout << (success ? "The INI file was saved successfully!" : "An error occured while trying to save the INI file.");
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
                std::cout << '\n' << '\n';
            }
        }
        while (!exitLoopFlag);
    }
    else
    {
        std::cout << "An error occured while trying to load the file \"" << argv[1] << "\". Program will now terminate..." << '\n';
    }
}
