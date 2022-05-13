#pragma once
#include "Interface.h"
#include "Defines.h"
// ---------------------------------------------------------------------------------------------
#define sub_417EC0		((int(__thiscall*)(int a1, int a2, int a3)) 0x00417EC0)
//----- (007889B0) --------------------------------------------------------
#define sub_7889B0		((char (__thiscall*)(MUChat* This)) 0x007889B0)
class CChatClassic
{
public:
	void Load();
	static void		RenderFrame(int This);
	static void 	WhisperPosition();
	static void		WisperButtonOn(DWORD a1, float a2, float a3, float a4, float a5);
	static void		TesteOn(DWORD a1, float a2, float a3, float a4, float a5);
	// ----
private:
	
};
extern CChatClassic gCChatClassic;
// ---------------------------------------------------------------------------------------------