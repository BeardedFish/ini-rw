// File Name:     ExtractionResult.hpp
// By:            Darian Benam (GitHub: https://github.com/BeardedFish/)
// Date:          Tuesday, June 2, 2020

#pragma once

namespace Ini
{
	template <typename T>
	class ReadResult
	{
	public:
		T ConvertedValue{};
		bool Success = false;
	};
}