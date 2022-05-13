#pragma once
#include "stdafx.h"
#include "protocol.h"
#include "Interface.h"
#include <vector>



#define JCGetKeyState					((int(__cdecl*)(int VKBUTTON)) 0x00791070)
#define JCGetDrawMouse					((int(__cdecl*)(int VKBUTTON)) 0x00791090)
#define sub_4D5B70						((char(__cdecl*)(signed int a1)) 0x004D5B70)
#define GetInstance						((int(__cdecl*)()) 0x00861110)
#define sub_7C1C80						((int(__thiscall*)(int This, int a6))0x007C1C80)
#define sub_7798F0						((char(__thiscall*)(int This, char a9))0x007798F0)
#define sub_779740						((int(__thiscall*)(int This, int a5, int a6))0x00779740)
#define pDrawPuntero					((int(__thiscall*)(int This, char a5, int a6, char a7, char a8, char a9))0x00779350)
#define ChangeButtonInfo				((int(__thiscall*)(char *This, int X, int Y, int Width, int Height)) 0x00779410)
#define pCheckMouseOver					((bool(__cdecl*)(int a1, int a2, int a3, int a4)) 0x00790B10)
#define sub_7E3E30_Addr				((signed int(__fastcall*)(int a1, char a2, Coord a3, int a4, int a5, int a6, int a7)) 0x7E3E30)
#define MAX_ITEM_INFO 12
#define MAX_JEWEL_SHOW 5

#define pGetItemBmdStruct(ItemId)   (ItemBmdStruct*)(*(DWORD*)0x8128AC0 + sizeof(ItemBmdStruct) * ItemId)
#define SET_ITEMOPT_LEVEL(x)  (x << 3)

enum Jewelry
{
	JEWELRY_CHAOS = 0,
	JEWELRY_BLESS = 1,
	JEWELRY_SOUL = 2,
	JEWELRY_LIFE = 3,
	JEWELRY_CREATION = 4,
	JEWELRY_STONE = 5,
	JEWELRY_GUARDYAN = 6,
	JEWELRY_HARMONY = 7,
	JEWELRY_LOWER = 8,
	JEWELRY_HIGHER = 9,
};

struct PMSG_JEWEL_BANK
{
	PSBMSG_HEAD h;
	BYTE sFlag;
	BYTE tFlag;
	BYTE Source;
	BYTE Target;
};

struct PMSG_JEWELSBANK
{
	PSBMSG_HEAD h;
	int Chaos;
	int Bless;
	int Soul;
	int Life;
	int CreateonBank;
	int GemStoneBank;
	int GuardianBank;
	int HarmonyBank;
	int LowStoneBank;
	int HighStoneBank;
};

struct PMSG_JEWELBANK_SUB
{
	PSBMSG_HEAD h;
	BYTE Type;
	BYTE Mode;
};

void JCLineBack(int m, int Item, float x, float y, float w, float h, char * count);
void JCImagesBack(int Item, float x, float y, float w, float h, char * count);

class JewelBank
{
public:
	JewelBank();
	virtual ~JewelBank();
	void Bind();
	void DrawJewelBank();
	void DrawJewelBank803();
	void DrawItem(int ItemType, int ItemIndex, int ItemLevel);
	void DrawItemIMG(float x, float y, float Width, float Height, int ItemID, int Level, int Excl, int Anc, bool OnMouse);
	bool JewelBankEvent(DWORD Event);
	void LoadInfoBank(PMSG_JEWELSBANK * aRecv);
	
	bool	CheckJewelWindow() 
	
	{ 
		return gInterface.Data[eJEWELBANK_MAIN].OnShow; 
	};

	void	OpenJewelWindow() 
	{ 
		gInterface.Data[eJEWELBANK_MAIN].OnShow = true; 
	};

	void    CloseJewelWindow() 
	{ 
		gInterface.Data[eJEWELBANK_MAIN].OnShow = false; 
		pSetCursorFocus = false;
	};

	bool    EventJewelWindows_Close(DWORD Event);
	DWORD OpenJewelBankDelay;
	int Pagina;
	int ItemJewelry[15];
	int BankJewelry[15];
};
extern JewelBank gJewelBank;