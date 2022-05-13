#pragma once
// ----------------------------------------------------------------------------------------------
#define SHOPSEARCH TRUE
#include "stdafx.h"
#include "Protocol.h"
#include "Defines.h"
#include "Interface.h"
// ----------------------------------------------------------------------------------------------
#define sub_861420			((int(__thiscall*)(LPVOID This)) 0x861420)
#define sub_668A80			((int(__thiscall*)(LPVOID This)) 0x668A80)
#define pGameIndex    *(DWORD*)0x87935A8

#if(SHOPSEARCH==TRUE)
// ----------------------------------------------------------------------------------------------
struct GC_PersonalShopInfo
{
	WORD aIndex;
	char Name[11];
	char PersonalText[36];
	BYTE Value;
};
// ----------------------------------------------------------------------------------------------
struct CG_PersonalPage
{
	PSBMSG_HEAD h;
	BYTE Page;
};
// ----------------------------------------------------------------------------------------------
struct PMSG_REQ_BUYLIST_FROM_PSHOP
{
	PSBMSG_HEAD header; // C1:3F:05
	BYTE index[2];
	char name[10];	// 6
};
// ----------------------------------------------------------------------------------------------
struct PersonalShop_DATA
{
	WORD aIndex;
	char Name[11];
	char PersonalText[36];
	BYTE Value;
};
// ----------------------------------------------------------------------------------------------
struct PMSG_REQ_BUYITEM_FROM_PSHOP
{
	PSBMSG_HEAD h;
	BYTE index[2];
	char name[10];	// 6
	BYTE slot;	// 10
};
//======================

#pragma pack(push, 1)
struct GC_SendTargetInfo
{
	PSBMSG_HEAD	Head;
	WORD bIndex;
	char Name[11];
};
#pragma pack(pop)


class PersonalShopEx
{
public:
	// -> Load
	void Load();
	void BindImages();
	// Draw Interface
	void Draw();
	// -> Controller
	void Button(DWORD Event);
	// -> Protocol
	void GC_Recv(LPBYTE aRecv);
	void CG_Send();
	// -> Hook
	// -> Other
	int Page;
	int TotalShop;
	int aTargetIndex;
	int bIndex;
	char TargetName[11];
	int ReturnPos();
	void GC_PSRecv(GC_SendTargetInfo* aRecv);

	bool CheckWindowEx2(int WindowID);
	void		OpenWindowEx(int WindowID);
	void		CloseWindowEx(int WindowID);
	bool ButtonEx(DWORD Event, int ButtonID, bool Type);

	bool	CheckStoreWindow() 
	{ 
		return gInterface.Data[ePT_PERSONAL_SEARCH_MAIN].OnShow; 
	};

	void	OpenStoreWindow() 
	{ 
		gInterface.Data[ePT_PERSONAL_SEARCH_MAIN].OnShow = true; 
	};

	void    CloseStoreWindow() 
	{ 
		gInterface.Data[ePT_PERSONAL_SEARCH_MAIN].OnShow = false; 
		pSetCursorFocus = false;
	};
	
	PersonalShop_DATA PShop[10];
	DWORD OpenStoreSearchDelay;
};
extern PersonalShopEx g_PersonalShopEx;
// ----------------------------------------------------------------------------------------------

#endif