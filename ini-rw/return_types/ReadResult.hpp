// File Name:     ReadResult.hpp
// By:            Darian Benam (GitHub: https://github.com/BeardedFish/)
// Date:          Tuesday, June 16, 2020

#pragma once

namespace IniRW
{
	template <typename T>
	class ReadResult
	{
	public:
		T ConvertedValue{};
		bool Success = false;
	};
}