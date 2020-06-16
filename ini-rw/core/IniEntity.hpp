// File Name:     IniEntity.cpp
// By:            Darian Benam (GitHub: https://github.com/BeardedFish/)
// Date:          Sunday, June 14, 2020

#pragma once

#include "../enums/IniEntityType.hpp"

namespace IniRW
{
	class IniEntity
	{
	private:
		IniEntityType type;
		void* data;

	public:
		IniEntity();
		IniEntity(IniEntityType type);
		IniEntity(IniEntityType type, void* data);

		void* GetData();

		IniEntityType GetType();
	};
} // End IniRW namespace