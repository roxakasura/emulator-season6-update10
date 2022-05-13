#include "stdafx.h"
#include "Util.h"
#include "CustomClickNPC.h"

cWinApiHook gWinApiHook;

BOOL (WINAPI *Real_SetCursorPos)(int X,int Y) = SetCursorPos;

BOOL WINAPI cWinApiHook::Mine_SetCursorPos(int X,int Y) 
{ 
	RECT Rect;
	if(GetWindowRect(GetActiveWindow(),&Rect))
	{
		X += Rect.left;
		Y += Rect.top;
	}

	return Real_SetCursorPos(X,Y); 
} 

void cWinApiHook::Load()
{
	if(g_bUseWindowMode)
	{
		// Bypass Window Mode Checks (Move to offset.h)
		MemorySet(0x005A3E31,0x90,2);
		MemorySet(0x0064C3BE,0x90,2);

		DetourTransactionBegin();
		DetourUpdateThread(GetCurrentThread());
		DetourAttach(&(PVOID&)Real_SetCursorPos,gWinApiHook.Mine_SetCursorPos);
		DetourTransactionCommit();
	}
}