# ini-rw

![Programming language](https://img.shields.io/badge/programming%20language-c%2B%2B17-blue)
![Licence](https://img.shields.io/github/license/BeardedFish/ini-rw)
![Code size](https://img.shields.io/github/languages/code-size/BeardedFish/ini-rw)
![Contributors](https://img.shields.io/github/contributors/BeardedFish/ini-rw)

![ini-rw: A .ini file reader and writer library programmed in C++17.](images/ini-rw-banner.png "ini-rw: A .ini file reader and writer library programmed in C++17.")

## Features

* Ability to open `.ini` files for either:
    * Reading
    * Writing
* Ability to save changes to a `.ini` file if modified
* Inline comment support for `.ini` sections and keys

## Example

```cpp
#include "IniFile.hpp"
#include <iostream>
#include <string>

int main()
{
    inirw::IniFile iniFile("path_to_ini_file");

    if (iniFile) // You could also use iniFile.is_loaded() instead
    {
        inirw::IniKey* iniKey = iniFile.get_key("section_name", "key_name");

        if (iniKey)
        {
            std::cout << "INI key information:\n";
            std::cout << "====================\n";
            std::cout << "Section: " << iniKey->get_section()->get_name() << '\n';
            std::cout << "Value: " << iniKey->ValueCommentPair.get_value() << '\n';
            std::cout << "Comment: " << iniKey->ValueCommentPair.get_comment() << '\n' << '\n';
        }
        else
        {
            std::cout << "The INI key was not found.\n";
        }

        iniFile.write_key_value<std::string>("library", "name", "ini-rw");
        iniFile.write_key_value<int>("library", "cpp_standard", 17);
        iniFile.write_key_value<bool>("library", "is_open_source", true);

        // Insert a pound symbol comment at the top of the loaded INI file
        iniFile.insert_comment(inirw::IniCommentPrefix::Pound, "Hello, World!");

        if (iniFile.save_changes())
        {
            std::cout << "The INI file was saved succesfully!\n";
        }
    }
    else
    {
        std::cout << "Unable to open the INI file.\n";
    }
}
```
