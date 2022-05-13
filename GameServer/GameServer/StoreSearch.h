#pragma once
// ----------------------------------------------------------------------------------------------

#include "StdAfx.h"
#include "Protocol.h"

// ----------------------------------------------------------------------------------------------

#if(CUSTOM_PERSONAL_SHOP==0)

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
#pragma pack(push, 1)
struct GC_SendTargetInfo
{
	PSBMSG_HEAD	Head;
	WORD bIndex;
	char Name[11];
};
#pragma pack(pop)
// ----------------------------------------------------------------------------------------------

class PersonalShopEx
{
public:
	void Init();
	void Load();
	void Read(char* File);

	bool NPC_Dialog(LPOBJ lpObj, LPOBJ lpNpc);
	bool NPCDialog(LPOBJ lpObj);
	
	void Search(int aIndex, CG_PersonalPage* aRecv);

	int NPC_CLASS;
	int NPC_MAP;
	int NPC_X;
	int NPC_Y;
	void SendInfoTarget(int aIndex, int bIndex);
};
extern PersonalShopEx g_PersonalShopEx;
// ----------------------------------------------------------------------------------------------
#endif