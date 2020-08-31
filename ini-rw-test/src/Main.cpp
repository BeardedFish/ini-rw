// File Name:     Main.cpp
// By:            Darian Benam (GitHub: https://github.com/BeardedFish/)
// Date:          Sunday, August 30, 2020

#include "ini-rw/IniSetting.hpp"
#include <iostream>

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
/// <returns>An integer that represents the exit code status of the program.</returns>
int main()
{
	std::cout << INI_RW_ACSII_ART << std::endl;

	IniRW::IniSetting iniSettings("..\\example-ini-files\\example1.ini");
    
    if (iniSettings.IsLoaded())
    {
        std::cout << iniSettings.ToString() << std::endl;
    }
    else
    {
        std::cout << "Fail";
    }
}