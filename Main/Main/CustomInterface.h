#pragma once

enum iInterface
{
   iNewCharacter = 0x7A48,
   iNewInventory = 0x7A49,
   iNewWinpush = 0x7A4A,
   iNewFastMenu = 0x7A4B,
   iNewSkillBox = 0x7A50,
   iNewParty = 0x910,
   iNewGuild = 0x904,
   iNewCashShop = 0x908,
};

#define sub_5B9260		((void(__cdecl*)(float a1, float a2, float a3, float a4, float a5, char a6, char a7)) 0x005B9260)
#pragma once
#define sub_7858700			((void(__thiscall*)(DWORD a1, int a2, int a3, int a4, int a5)) 0x00785870)

#define MAX_WIN_HEIGHT		480
#define pDrawTextBig			((int(__cdecl*)(float, float, int, float)) 0x791000)
#define sub_813DC0		((int(__thiscall*)(DWORD * This, int Skill, float X, float Y, float W, float H)) 0x00813DC0)
#define sub_4C8640			((bool(__thiscall*)(void * This,char a2)) 0x4C8640)
#define pCheckMouseOver		((bool(__cdecl*)(int a1, int a2, int a3, int a4)) 0x00790B10)
#define pSliderSetPosition	((int(__thiscall*)(DWORD This,int X,int Y)) 0x00417EC0) 


char sub_789110(int a1, FARPROC (__stdcall *a2)(HMODULE hModule, LPCSTR lpProcName), int a3, DWORD *a4);
void PetHPBarRemake(signed int x, signed int y, int nameIndex, signed int hp, signed int hpmax, char a9);
void PetSpiritHPBarRemake(signed int x, signed int y, int nameIndex, signed int hp, signed int hpmax, char a9);
int CClassicUICharacterInfoWindow(int a1);
int SetSlidePosition(DWORD This,int X,int Y);; // ok
void SelectServerPosition();

void		InitInter3();