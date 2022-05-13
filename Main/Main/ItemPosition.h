#pragma once

#include "Object.h"

class cItemPosition
{
public:
	void Load();
	static void __cdecl SetPosition(signed int a1, signed int a2, int a3, int a4, VAngle *a5, int a6, char a7);
}; extern cItemPosition gItemPosition;