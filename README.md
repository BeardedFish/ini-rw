# ini-rw
This is a `.ini` reader/writer library programmed entirely in C++11.

 ⚠ This project is currently work in progress.

## Current Features
* Ability to open `.ini` files for either:
    * Reading
    * Writing
* Ability to save changes to a `.ini` file if modified
* Inline comment support for `.ini` sections and keys

## How To Use
### Opening A `.ini` File
First, you will need to import the `IniSetting.hpp` file:
```cpp
#include "IniSetting.hpp"
```

Once that is imported, you will then have access to the `IniRW::IniSetting` class. To open a `.ini` file, use the `IniRW::IniSetting(INI_FILE_PATH)` constructor.
```cpp
IniRW::IniSetting iniSettings(INI_FILE_PATH);
```

To make sure the `.ini` file was opened successfully, check to see if either the `IniSetting` instance or the `IsLoaded()` function returns true.
```cpp
if (iniSettings) // if (iniSettings.IsLoaded())
{
    // Successful open
}
else
{
    // Unsuccessful open
}
```

### Reading A `.ini` File
To get a key under a specific section use the `GetKey()` function. This function takes two string parameters. The first parameter is the section name of where the key is stored and the second parameter is the name of the key. If the key is found in the `.ini` file under that specified section, an `IniRW::IniKey` pointer is returned. If the key is not found, a null pointer is returned.

To read the value of the key, you must first dereference the pointer and call the `GetValueCommentPair()` function. This function returns a `IniRW::IniValueCommentPair`.  Once that is done, use the `GetValueBeforeComment()` function to read the string value of the INI key.
```cpp
IniRW::IniKey* key = iniSettings.GetKey(SECTION_NAME, KEY_NAME);

if (key)
{
    std::cout << "The value of the key is: " << key->GetValueCommentPair().GetValueBeforeComment()  << std::endl;
}
else
{
    std::cout << "The key was not found in the INI file!" << std::endl;
}
```

### Creating An Empty `.ini` File
```cpp
IniRW::IniSetting iniSettings;
```

### Writing A `.ini` File
#### Writing A `.ini` Comment
```cpp
iniSettings.WriteComment(INDEX, COMMENT_PREFIX, COMMENT_TEXT);
```

The `WriteComment()` function will throw an exception if the index is out of bounds.

#### Writing A `.ini` Key
```cpp
iniSettings.WriteKeyValue(SECTION_NAME, KEY_NAME, KEY_VALUE);
```

#### Saving Changes
To save changes to the original file path that the `.ini` file was loaded from, use the `SaveChanges()` function. For saving changes to a custom file path, use the overloaded function `SaveChanges(CUSTOM_FILE_PATH)` where the `CUSTOM_FILE_PATH` is a string.

Both of these functions return a boolean value that states whether the `.ini` file was saved succesfully or not.

## Screenshots
Coming soon!
