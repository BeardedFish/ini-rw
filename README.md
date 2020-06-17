# ⚙️ Ini-Rw
This is an INI reader/writer library programmed in C++.

## Current Features
* Ability to open INI files for either:
  * Reading
  * Writing
* Ability to save changes to INI file if modified

## How To Use
### Opening An INI File
Opening an INI file using this library is very simple. First, you will need to import the **IniSettings.hpp** file:
```cpp
#include "ini-rw/IniSettings.hpp"
```

Once that is imported, you will then have access to the **IniSettings** class. In order to open an INI file, you must pass a string which contains the path to INI file to the constructor of the **IniSettings** class instance that you want to create.
```cpp
IniRW::IniSettings settings(INI_FILE_PATH);
```

In order to make sure the INI file was opened succesfully, check to see if the **IsLoaded()** function returns true.
```cpp
if (settings.IsLoaded())
{
    // Do something with the INI file
}
else
{
    // Handle unsuccessful open
}
```

### Reading An INI File
Coming soon!

### Writing An INI File
Coming soon!

## Screenshots
Coming soon!
