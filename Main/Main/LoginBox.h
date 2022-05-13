#pragma once
#define InputBox_GetText					((void(__thiscall*)(int thisa, LPSTR lpString, int nMaxCount)) 0x004217D0)
#define InputBox_SetText					((void(__thiscall*)(int thisa, const char* pszText)) 0x00421830)
#define RequestLogin						((int(__thiscall*)(int This)) 0x0040B7B0)
#define Sprite_SetPosition					((void(__thiscall*)(BYTE * CButton, int cx, int cy, int eChangedPram)) 0x00416640)
#define CUIRenderText_SetFont				((int(__thiscall*)(int This, int a2)) 0x00420120)
#define pTextThis							((LPVOID(*)()) 0x0041FE10)
#define _Instance							((int(*)()) 0x00482B70)
#define SEASON3B_CheckMouseIn				((bool(__cdecl*)(int a1, int a2, int a3, int a4)) 0x00790B10)
#define g_fScreenRate_x						*(float*)0xE7C3D4
#define g_fScreenRate_y						*(float*)0xE7C3D8
#define IsPress								((int(__cdecl*)(int VKBUTTON)) 0x00791070)
#define RenderBitmap						((void(__cdecl*)(int a1, float a2, float a3, float a4, float a5, float a6, float a7, float a8, float a9, char a10, char a11, float a12)) 0x00637C60)
#define PlayBuffer							((signed int(__cdecl*)(int a1, int a2, int a3)) 0x006D6C20)
#define LoginWinCreate						((void(__thiscall*)(int This)) 0x0040AD70)
#define pIsKeyRelease						((bool(__cdecl*)(int)) 0x791050)

bool IsCursorInZone(short x, short y, short x2, short y2);

class cAutoLogin
{
public:
	cAutoLogin();
	~cAutoLogin();
	void Load();
	BOOL savePass;
	char iUser[32];
	char iPassword[32];
private:

};

extern cAutoLogin AutoLogin;

//#pragma once
//
//#define sub_416210                  ((int(__thiscall*)(int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11, char a12, int a13, float a14, float a15)) 0x00416210)
//#define sub_4AC070					((int(__thiscall*)(int This, signed int a2, int a3)) 0x004AC070)
//#define sub_4ABE90                  ((int(__thiscall*)(int a5, int a6, signed int a7, char a8)) 0x004ABE90)
//
//#define InputBox_SetText					((void(__thiscall*)(int thisa, const char* pszText)) 0x00421830)
//#define RequestLogin						((int(__thiscall*)(int This)) 0x0040B7B0)
//#define Sprite_SetPosition					((void(__thiscall*)(BYTE * CButton, int cx, int cy, int eChangedPram)) 0x00416640)
//#define CUIRenderText_SetFont				((int(__thiscall*)(int This, int a2)) 0x00420120)
//#define pTextThis							((LPVOID(*)()) 0x0041FE10)
//#define GetInstance							((int(*)()) 0x00482B70)
//#define SEASON3B_CheckMouseIn				((bool(__cdecl*)(int a1, int a2, int a3, int a4)) 0x00790B10)
//#define g_fScreenRate_x						*(float*)0xE7C3D4
//#define g_fScreenRate_y						*(float*)0xE7C3D8
//#define IsPress								((int(__cdecl*)(int VKBUTTON)) 0x00791070)
//#define RenderBitmap						((void(__cdecl*)(int a1, float a2, float a3, float a4, float a5, float a6, float a7, float a8, float a9, char a10, char a11, float a12)) 0x00637C60)
//#define PlayBuffer							((signed int(__cdecl*)(int a1, int a2, int a3)) 0x006D6C20)
//
//#define TextPositionLoginBox ((int(__fastcall*)(signed int a2)) 0x0040AD70)
//
//void LoadBoxLogin();
//
//class CLoginWin
//{
//public:
//	void Load();
//	static void __thiscall cSetPosition(BYTE* This, int nXCoord, int nYCoord, int eChangedPram);
//
//private:
//
//};
//extern CLoginWin gCLoginWin;