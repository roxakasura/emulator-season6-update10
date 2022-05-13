#pragma once
#include "stdafx.h"
#include "Protocol.h"
#define MAX_PLAYER_SLOT	5
#define TypeSelectChar	2

#define JCSetModelCoord					((int(__cdecl*)(BYTE slot, int iclass, char a3, float UbicacionX, float UbicacionY, float Rotacion)) 0x00586DA0)
#define SelectedHero					*(int*)0xE60B4C
#define SelectedCharacter				*(int*)0xE61730
#define sub_63CB40						((int(*)(void)) 0x0063CB40)
#define sub_4D5130						((DWORD(__cdecl*)(char a1)) 0x004D5130)
#define sub_9CF1C0						((char *(__cdecl*)(char *a1, const void *a2, unsigned int a3)) 0x009CF1C0)
#define dword_87935A4					*(int*)0x87935A4
#define sub_861110						((int(__cdecl*)()) 0x00861110)
#define sub_861A80						((int(__thiscall*)(DWORD)) 0x00861A80)
#define sub_856BD0						((DWORD(__thiscall*)(char a1)) 0x00856BD0)
#define dword_E8CB30					*(int*)0xE8CB30
#define sub_57D760						((void(__cdecl*)(int a4)) 0x0057D760)
#define sub_668520						((int(__thiscall*)(char *a1)) 0x00668520)
#define sub_4057B0						((int(__thiscall*)(char *a1)) 0x004057B0)
#define sub_402AD0						((int(__thiscall*)(char *a1)) 0x00402AD0)
#define sub_484A10						((int(__thiscall*)(int This, int a2, char *a3)) 0x00484A10)
#define sub_587380						((DWORD(__cdecl*)(unsigned __int8 a1)) 0x587380)
#define sub_482B70						((int(*)()) 0x00482B70)
#define sub_587620						((int(__cdecl*)(char a1)) 0x00587620)
#define sub_586DA0						((int(__cdecl*)(int a1, int a2, char a3, float x, float y, float z)) 0x586DA0)
#define sub_63D130						((DWORD(__cdecl*)(int a1)) 0x63D130)
#define sub_5977E0						((int(*)(void)) 0x005977E0)
#define sub_4849A0						((int(__thiscall*)(DWORD)) 0x004849A0)
#define sub_5BB0B0						((int(*)()) 0x005BB0B0)
#define sub_4D5C60						((int(*)()) 0x004D5C60)
#define sub_482B70						((int(*)()) 0x00482B70)
#define sub_483B20						((int(__thiscall*)(int a1,int a2)) 0x00483B20)
#define RenderCryingWolf2ndObjectVisual	((void(__cdecl*)(int a1, int a2)) 0x008D1C00)
#define JGConnectPlayerSend				((int(__thiscall*)(char type)) 0x004D6A60)
#define JGDelectPlayerSend				((int(__thiscall*)( )) 0x00405B10)
#define sub_749250						((void(__cdecl*)(int a1, int a2, float a3, float a4, float a5, float a6, float a7, float a8)) 0x00749250)
#define sub_4AC070						((int(__thiscall*)(int This, signed int a2, int a3)) 0x004AC070)
#define PlayBuffer						((signed int(__cdecl*)(int a1, int a2, int a3)) 0x006D6C20)
#define pCheckMouseOver					((bool(__cdecl*)(int a1, int a2, int a3, int a4)) 0x00790B10)
#define sub_9CF1C0						((char *(__cdecl*)(char *a1, const void *a2, unsigned int a3)) 0x009CF1C0)
#define JCSpiriteSetPosition			((int(__fastcall*)(int Button, int This, signed int x, signed int y, char type)) 0x00416640)
#define LoadBitmapA						((int(__cdecl*)(char * Folder, int Code, int Arg3, int Arg4, int Arg5, int Arg6)) 0x00772330)

int GetClassnameIndex (unsigned __int8 a4);
char CGetCharacterClass(unsigned __int8 a1);

struct PMSG_CHARACTER_LIST
{
	BYTE slot;
	char Name[10];
	WORD Level;
	WORD CharSetClass;
	BYTE CtlCode;
	BYTE CharSet[18];
	BYTE GuildStatus;
};

struct PMSG_CHARACTER_CREATE_RECV
{
	PSBMSG_HEAD header; // C1:F3:01
	BYTE result;
	char name[10];
	BYTE slot;
	WORD level;
	BYTE Class;
	BYTE equipment[24];
};

struct PMSG_VIEWPORT_SEND
{
	PWMSG_HEAD header; // C2:[12:13:1F:20:45:65:68]
	BYTE count;
};

void SelectCharacterPosition();
void CharacterSelect360S13();

struct PMSG_VIEWPORT_PLAYER
{
	BYTE index[2];
	BYTE x;
	BYTE y;
	BYTE CharSet[18];
	char name[10];
	BYTE tx;
	BYTE ty;
	BYTE DirAndPkLevel;
	BYTE count;
	WORD CharSetClass;
};

class GCCharacterS13
{
public:
	GCCharacterS13( );
	~GCCharacterS13( );
	void initCharacter( );
	void JGPlayerHide( );
	int JPlayerList( PMSG_CHARACTER_LIST_RECV * lpMsg );
	int JPlayerAddList( PMSG_CHARACTER_CREATE_RECV * lpMsg );
	void GCPlayerInfo( );
	static void OpenCharacterScene();
	//Denis
	static void SelectChar();
	void SelectCharButton(DWORD Event);

public:
	std::map<int, PMSG_CHARACTER_LIST> lpInfoPlayer;
};
extern GCCharacterS13 JGetPlayer;
