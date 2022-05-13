#pragma once

#define MAIN_WINDOW 0x00E8C578
#define MAIN_LANGUAGE 0x00E8C5C4
#define MAIN_CONNECTION_STATUS 0x08793704
#define MAIN_SCREEN_STATE 0x00E609E8
#define MAIN_CHARACTER_STRUCT 0x08128AC8
#define MAIN_VIEWPORT_STRUCT 0x07BC4F04
#define MAIN_PACKET_SERIAL 0x08793700
#define MAIN_HELPER_STRUCT 0x00E8CB7C
#define MAIN_FONT_SIZE 0x081C0380
#define MAIN_RESOLUTION 0x00E8C240
#define MAIN_RESOLUTION_X 0x00E61E58
#define MAIN_RESOLUTION_Y 0x00E61E5C
#define MAIN_PARTY_MEMBER_COUNT 0x081F6B6C

#define ProtocolCore ((BOOL(*)(DWORD,BYTE*,DWORD,DWORD))0x00663B20)
#define DrawInterface ((void(*)(DWORD,float,float,float,float))0x00790B50)
#define DrawInterfaceText ((void(*)(char*,int,int,int,int,int,int,int))0x007D04D0)
#define pMultiLineTooltip			((void(__cdecl*) (int PosX, int PosY, int LineCount, int, int, int, int)) 0x005BF700)

//-- itemposition
#define sub_959A60_Addr		((int(__cdecl*)(int a1, float a2, int a3, int a4)) 0x959A60)
#define sub_4E1250_Addr		((int(__cdecl*)(int a1, char a2)) 0x4E1250)
#define sub_4CDA10_Addr		((int(*)()) 0x4CDA10)
#define sub_969C50_Addr		((int(__thiscall*)(int This, signed int a2)) 0x969C50)
#define sub_5C9370_Addr		((bool(__cdecl*)(signed int a1, int a2)) 0x5C9370)
#define sub_5440B0_Addr		((int(__fastcall*)(int a1, int a2, int a3, float a4, float a5, __int16 a6, int a7, int a8, char a9, char a10)) 0x5440B0)
#define sub_4CC650_Addr		((char *(__thiscall*)(int This)) 0x4CC650)
#define sub_5F58E0_Addr		((int(__cdecl*)(ObjectModel * a1)) 0x5F58E0)
#define sub_635B00_Addr		((int(__cdecl*)(int a1, int a2, int a3)) 0x635B00)
#define sub_861110_Addr		((void *(*)()) 0x861110)
#define sub_861900_Addr		((int(__thiscall*)(int This)) 0x861900)
#define sub_943A20_Addr		((int(__stdcall*)(float a1, float a2)) 0x943A20)
#define sub_5D65E0_Addr		((double(__thiscall*)(int This)) 0x5D65E0)
#define sub_4CC720_Addr		((int(__thiscall*)(int This)) 0x4CC720)
#define sub_5CA0D0_Addr		((void(__cdecl*)(signed int a1, signed int a2, int a3, int a4, int a5, int a6, char a7)) 0x5CA0D0)
#define sub_60FC70_Addr				((void (__cdecl*)(int a1, int a2, int a3, int a4, float a5, int a6, int a7, int a8, char a9, char a10, char a11, int a12, int a13)) 0x60FC70)
//--
#define pSetFont				((int(__thiscall*)(LPVOID This, int a2)) 0x420120)
#define pSetBkColor				((int(__thiscall*)(LPVOID This, BYTE red, BYTE green, BYTE blue, BYTE alpha)) 0x4200B0)
#define pSetTexture				((void(__cdecl*)(int a1)) 0x00635CF0)//sub_635CF0(a1)
#define	pFontNormal				*(HGDIOBJ*)0x00E8C588
#define pFontBold				*(HGDIOBJ*)0x00E8C58C
#define pFontBigBold			*(HGDIOBJ*)0x00E8C590
#define pFontNormal2			*(HGDIOBJ*)0x00E8C594

//CashShop
#define	sub_944E50_Addr		((char(*)()) 0x944E50)
#define	sub_93F370_Addr		((void*(*)()) 0x93F370)
#define sub_93FCA0_Addr		((bool(__thiscall*)(int a1)) 0x93FCA0)
#define sub_93F600_Addr		((char(__thiscall*)(char* a1)) 0x93F600)
#define sub_93FD10_Addr		((bool(__thiscall*)(int a1)) 0x93FD10)
#define sub_93F950_Addr		((char(__thiscall*)(char* a1)) 0x93F950)
#define sub_941030_Addr		((int(__thiscall*)(BYTE* a1)) 0x941030)
#define sub_941000_Addr		((int(__thiscall*)(BYTE* a1)) 0x941000)
#define sub_944FE0_Addr		((void(__thiscall*)(BYTE *This, int a2, BYTE *a3)) 0x944FE0)
#define sub_9406C0_Addr		((char(__thiscall*)(BYTE* a1)) 0x9406C0)
#define sub_9406A0_Addr		((BYTE*(__thiscall*)(BYTE* a1, char a2)) 0x9406A0)
#define sub_8611E0_Addr		((int(__thiscall*)(DWORD* a1)) 0x8611E0)
#define sub_815130_Addr		((int(__thiscall*)(char *This, int a2, char a3)) 0x815130)
#define sub_861900_Addr		((int(__thiscall*)(int This)) 0x861900)

//Click Right items
#define pChaosBoxState *(BYTE*)(*(DWORD*)(0x98670C4) + 0xC8)