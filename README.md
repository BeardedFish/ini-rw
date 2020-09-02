# ⚙️ Ini-Rw
This is an INI reader/writer library programmed entirely in C++.

## Current Features
* Ability to open INI files for either:
    * Reading
    * Writing
* Ability to save changes to INI file if modified

## How To Use
### Opening An INI File
First, you will need to import the `IniSetting.hpp` file:
```cpp
#include "ini-rw/IniSetting.hpp"
```

Once that is imported, you will then have access to the `IniRW::IniSetting` class. To open an INI file, you must pass a string containing the INI file path to the constructor of the `IniRW::IniSetting` class instance that you want to create.
```cpp
IniRW::IniSetting settings(INI_FILE_PATH);
```

To make sure the INI file was opened successfully, check to see if the `IsLoaded()` function returns true.
```cpp
if (settings.IsLoaded())
{
    // Successful open
}
else
{
    // Unsuccessful open
}
```

### Reading An INI File
To get a key under a specific section use the `GetKey()` function. This function takes two string parameters. The first parameter is the section name of where the key is stored and the second parameter is the name of the key. If the key is found in the INI file under that specified section, an `IniRW::IniKey` pointer is returned. To read the value of the key, you must dereference the pointer and use the `GetValue()` function which returns a string. If the key is not found, a null pointer is returned.
```cpp
IniRW::IniKey* key = settings.GetKey(SECTION_NAME, KEY_NAME);

if (key)
{
    std::cout << "The value of the key is: " << key->GetValue() << std::endl;
}
else
{
    std::cout << "Key was not found in the INI file!" << std::endl;
}
```

### Writing An INI File
After opening an INI file successfully, to write a value to it you must use the `WriteKeyValue()` function. This function takes three string parameters. The first parameter is the section name where the key is stored, the second parameter is the name of the key, and the third parameter is the value of the key.
```cpp
settings.WriteKeyValue(SECTION_NAME, KEY_NAME, KEY_VALUE);
```

## Screenshots
Coming soon!
