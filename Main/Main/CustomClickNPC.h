#pragma once

#include "stdafx.h"

#define g_bUseWindowMode *(DWORD*)0xE60974

class cWinApiHook
{
public:
	void Load();

	static BOOL WINAPI Mine_SetCursorPos(int X,int Y);
};

extern cWinApiHook gWinApiHook;