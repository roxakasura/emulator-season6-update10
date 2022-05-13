#pragma once

#include "stdafx.h"
#include "Protocol.h"

#define MultiCharacter 1

#define pSetTextColor_P			((int(__thiscall*)(int This, unsigned __int8 r, unsigned __int8 g, unsigned __int8 b, unsigned __int8 h)) 0x00420040)
#define pTextThis_P				((LPVOID(*)()) 0x0041FE10)

#define LoadBitmapA			    ((int(__cdecl*)(char * Folder, int Code, int Arg3, int Arg4, int Arg5, int Arg6)) 0x00772330)
#define pModelThis          	((LPVOID(*)())0x004CDA10)
#define sub_969CA0              ((int(__thiscall*)(void *This, signed int a2, signed int a3)) 0x969CA0)
#define sub_7798F0				((char(__thiscall*)(int This, char a9))0x007798F0)

//#define GetInstance                 (*(void*(__cdecl*)()) 0x00861110)
#define GetInstance					((int(__cdecl*)()) 0x00861110)
#define GetUI_NewCursedTempleWindow ((int(__thiscall*)(int This)) 0x008617C0)
#define CheckInventoryHolyItem      ((bool(__thiscall*)(int a4, int a5)) 0x0086D630)
#define InChaosCastle               ((bool(__cdecl*)(signed int a1)) 0x004E65A0)
#define isBuff                      ((bool(__thiscall*)(DWORD * a4, char a5)) 0x004C8640)

#define sub_416C40                  ((void(__thiscall*)(DWORD a1)) 0x416C40)
#define pGetPosFromAngle_P	    	((int(__cdecl*)(int a1, int *a2, int *a3)) 0x635B00)
#define sub_9CEBF0                  ((signed int(__thiscall*)(double a1)) 0x009CEBF0)
#define sub_416640                  ((int(__fastcall*)(int a1, int a2, signed int a3, signed int a4, char a5)) 0x416640)
#define pSetTextSize_P				((int(__thiscall*)(int This, int a2)) 0x420120)
#define sub_401C20                  ((signed int(__thiscall*)(int This)) 0x401C20)
#define sub_4200F0                  ((int(__thiscall*)(int This, int a2)) 0x4200F0)
#define SetTextColorByHDC_P   		((int(__thiscall*)(int This, int a2)) 0x420080)
#define sub_401C60                  ((signed int(__thiscall*)(int This)) 0x401C60)
#define sub_401C40                  ((signed int(__thiscall*)(int This)) 0x401C40)
#define pDrawText_P 				((int(__thiscall*)(int This, int a2, int a3, int a4, int a5, int a6, int a7, int a8)) 0x00420150)
#define ho                          *(HGDIOBJ*)0x00E8C58C

#define EnableAlphaTest				((void(__cdecl*)(BYTE Mode)) 0x635FD0)
#define Notice                      0x813DDD0

#define SetPlayerStop               ((int(__thiscall*)(DWORD a4)) 0x0054EA80)
#define SetCharacterScale           ((int(__cdecl*)(DWORD a4)) 0x0057F020)
#define Hero                        *(int*)0x7BC4F04
#define CharacterMachine            *(int*)0x8128AC4
#define sub_48F010                  ((int(__cdecl*)(int a1, int a2, int a3)) 0x0048F010)
#define sub_48EFC0                  ((BOOL(__cdecl*)(int a1, int a2)) 0x0048EFC0)
#define sub_558630					((void(__cdecl*)(int a1, int a2, int a3)) 0x00558630)
#define sub_48F0D0                  ((char(__cdecl*)(int a1, int a2, __int16 a3)) 0x0048F0D0)
#define sub_9CF1C0		        	((char(__cdecl*)(char *a1, const void *a2, unsigned int a3)) 0x009CF1C0)
#define sub_48E5C0                  ((int(__thiscall*)(int a2, int a3, int a4)) 0x0048E5C0)
#define CreateBugSub                ((char(__thiscall*)(int a3, int a4, int a5, int a6, int a7)) 0x005013B0)

#define sub_57D9A0					((DWORD(__cdecl*)(DWORD)) 0x57D9A0)
#define CreateJoint                 ((void(__thiscall*)(int a3, int a4, int a5, int a6, int a7, int a8, float a9, __int16 a10, __int16 a11, char a12, int a13, int a14, __int16 a15)) 0x0072D1B0)
#define pCreateEffect               ((void(__thiscall*)(int a4, int a5, int a6, int a7, int a8, int a9, __int16 a10, __int16 a11, __int16 a12, __int16 a13, float a14, __int16 a15)) 0x006D9070)
#define PlayBuffer                  ((signed int(__cdecl*)(int a1, int a2, int a3)) 0x006D6C20)
#define SetAction                   ((__int16(__cdecl*)(int a1, int a2, char a3)) 0x00542310)
#define sub_8613E0                  ((int(__thiscall*)(int This)) 0x008613E0)
#define SetMasterType               ((DWORD(__thiscall*)(int This, char a5)) 0x008199F0)

#define sub_407B20                  ((void*(__thiscall*)()) 0x00407B20)
#define sub_404920                  ((int(__thiscall*)(int This, int a2)) 0x00404920)
#define sub_401210                  ((int(__thiscall*)(int This)) 0x00401210)
#define sub_4011F0                  ((int(__thiscall*)(int This)) 0x004011F0)
#define sub_4ABE90                  ((int(__thiscall*)(int a4, int a5, int a6, signed int a7, char a8)) 0x004ABE90)
#define sub_416210                  ((int(__thiscall*)(int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11, char a12, int a13, float a14, float a15)) 0x00416210)
#define sub_401270                  ((int(__thiscall*)(int This, char a2)) 0x00401270)
#define sub_405240                  ((int(__thiscall*)(int This, char a2, char a3, char a4)) 0x00405240)
#define sub_401370                  ((int(__thiscall*)(int a4, int a5, int a6, int a7, int a8, signed int a9, signed int a10, int a11, int a12, signed int a13, signed int a14, int a15)) 0x00401370)
#define sub_401AE0                  ((char(__thiscall*)(int a3, char *a4, const void *a5)) 0x00401AE0)
#define sub_4AC500                  ((int(__thiscall*)(int a3, int a4, int a5)) 0x004AC500)
#define sub_404900                  ((int(__thiscall*)(int This, char a2)) 0x00404900)
#define sub_403700                  ((__int16(__thiscall*)(int This)) 0x00403700)
#define sub_407B00                  ((void*(__thiscall*)(void * This)) 0x00407B00

class CSelectChar
{
public:
	CSelectChar();
	~CSelectChar();
	// ----
	static void SelectChar();
	void		EventSelectChar(DWORD Event);
	int	m_CharacterEnable;
	// ----
public:
	int m_CharacterPage;	
	// ----
}; extern CSelectChar gSelectCharMulti;