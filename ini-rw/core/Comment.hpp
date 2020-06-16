// File Name:     Comment.hpp
// By:            Darian Benam (GitHub: https://github.com/BeardedFish/)
// Date:          Tuesday, June 16, 2020

#pragma once

#include <string>

namespace IniRW
{
	class Comment
	{
	public:
		Comment() = delete;

		static bool IsComment(const std::string& str);
	};
}