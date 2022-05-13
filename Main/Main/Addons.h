#pragma once

#define pSliderSetPosition	((int(__thiscall*)(DWORD This,int X,int Y)) 0x00417EC0) 
#define pChatDrawOpen		((char(__thiscall*)(int This)) 0x0078A720)
#define pChatDrawClose		((int(__thiscall*)(int This)) 0x0078A700)
#define sub_791000		((double(__stdcall*)(float a4, float a5, int a6, float a7)) 0x00854FE0)
#define sub_790B10		((bool(__cdecl*)(int a1, int a2, int a3, int a4)) 0x00790B10)

class CAddons
{
public:
	void Load();

	static int __fastcall SetPosition(DWORD This,int X, int Y);
	static int BowsText(int X, int Y, LPCTSTR Text);
	static void DrawExpBar();
	DWORD gLevelExperience[1001];
	QWORD m_MasterLevelExperienceTable[1001];
};

extern CAddons gAddons;