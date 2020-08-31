// File Name:     IniKeyAlgorithms.cpp
// By:            Darian Benam (GitHub: https://github.com/BeardedFish/)
// Date:          Monday, August 31, 2020

#include "IniKeyAlgorithms.hpp"

namespace IniRW
{
	bool IsValidIniKey(const std::string& str)
	{
		return str.length() >= 3 && str.find_first_of('=') != std::string::npos;
	}
}