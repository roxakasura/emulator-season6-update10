#pragma once
#include "stdafx.h"
#include "protocol.h"
#include "Interface.h"
#include <vector>

#define MAX_JEWELBANK 11

#define pGetItemBmdStruct(ItemId)   (ItemBmdStruct*)(*(DWORD*)0x8128AC0 + sizeof(ItemBmdStruct) * ItemId)
#define SET_ITEMOPT_LEVEL(x)  (x << 3)

struct PMSG_JEWELBANK
{
	PBMSG_HEAD2 h;
	int Result;
};

struct JEWEL_BANK
{
	int Index;
	int ID;
	int ItemID;
	char ItemName[50];
};

class JewelBank
{
public:
	JewelBank();
	virtual ~JewelBank();
	void Load(JEWEL_BANK * info);
	void Bind();
	void DrawJewelBank();
	void DrawJewelBank803();
	void DrawLine(int ItemType, int ItemIndex, int ItemLevel, float DrawX, float DrawY, char * ItemName, int Count);
	void DrawInfo(float InfoDrawX, float InfoDrawY, char* Text, bool Type, int Count);
	void DrawItem(int ItemType, int ItemIndex, int ItemLevel);
	bool JewelBankEvent(DWORD Event);
	bool JewelBankNext(DWORD Event);
	bool JewelBankPrev(DWORD Event);
	void JewelBankButton(DWORD key);
	void JewelBankPacket(int number);
	
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
private:
	int Page;
public:
	std::vector<JEWEL_BANK> m_JewelBank;
};
extern JewelBank gJewelBank;