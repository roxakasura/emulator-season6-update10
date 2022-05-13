#pragma once
#include "Interface.h"
#include "Defines.h"
#include "Object.h"

#define LoadBitmapA			((int(__cdecl*)(char * Folder, int Code, int Arg3, int Arg4, int Arg5, int Arg6)) 0x00772330)
#define RenderBitmap		((void(__cdecl*)(int a1, float a2, float a3, float a4, float a5, float a6, float a7, float a8, float a9, char a10, char a11, float a12)) 0x00637C60)
#define PlayBuffer			((signed int(__cdecl*)(int a1, int a2, int a3)) 0x006D6C20)
#define sub_7889B0		((char (__thiscall*)(MUChat* This)) 0x007889B0)

enum CChatExButton{
	ButtonHideChat,
	CGris       = Color4f(150, 150, 150, 255),
};

class CNewUIChat
{
public:
	void Load();
	static void		LoadImages();
	static void		RenderFrame(int This);
	static void		RenderButtons01(DWORD a1, float a2, float a3, float a4, float a5);
	static void		RenderButtons02(DWORD a1, float a2, float a3, float a4, float a5);
	static void		RenderButtons03(DWORD a1, float a2, float a3, float a4, float a5);
	static void		RenderButtons04(DWORD a1, float a2, float a3, float a4, float a5);
	static void		RenderButtons05(DWORD a1, float a2, float a3, float a4, float a5);
	void			ButtonHide01();
	bool			ButtonHide02(DWORD Event);
	static void		Hide1Teste();
private:
};
extern CNewUIChat gCChatEx;