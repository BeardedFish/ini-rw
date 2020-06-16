// File Name:     cmdfns.cpp
// By:            Darian Benam (GitHub: https://github.com/BeardedFish/)
// Date:          Monday, June 15, 2020

#pragma once

#include "ini-rw/core/Key.hpp"
#include <iostream>
#include <string>
#include <vector>

std::vector<std::string> getStrTokens(const std::string& str);

void printResult(IniRW::Key* key, std::string sectionName, std::string keyName);