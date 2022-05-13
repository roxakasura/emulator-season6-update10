#pragma once
#include "stdafx.h"
#include "Protocol.h"

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

struct PMSG_JEWEL_BANK
{
	PSBMSG_HEAD h;
	BYTE sFlag;
	BYTE tFlag;
	BYTE Source;
	BYTE Target;
};

struct ITEM_JEWEL_BANK
{
	int ItemID[8];
	int ItemLevel[8];
};

class JewelryBank
{
public:
	JewelryBank( );
	~JewelryBank( );
	void InitUserBank(LPOBJ lpObj);
	void SendMeJewelry(int aIndex);
	void RecvSubPacket(int aIndex, PMSG_JEWELBANK_SUB* lpMsg);
	void RecvPacket(int aIndex, PMSG_JEWEL_BANK* lpMsg);
	ITEM_JEWEL_BANK JCModeJewells[10];
};

extern JewelryBank JCBankJewelry;
