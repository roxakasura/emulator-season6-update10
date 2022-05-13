#pragma once
//----
#include "stdafx.h"
#include "User.h"
#include "Protocol.h"
//----
#define MAX_CUSTOM_BANK 11

struct BANKEX_GD_SAVE_POINT
{
	PSBMSG_HEAD	h;
	// ----
	WORD	UserIndex;
	char	AccountID[11];
	long	Money;
	long	Bless;
	long	Soul;
	long	Chaos;
	long	Creation;
	long	Life;
	long	Harmony;
	long	Guardian;
	long	Gemstone;
	long	LowRefine;
	long	HigRefine;
	//customs
	long	Custom001;
	long	Custom002;
	long	Custom003;
	long	Custom004;
	long	Custom005;
	long	Custom006;
	long	Custom007;
	long	Custom008;
	long	Custom009;
	long	Custom010;
	long	Custom011;
};
// -------------------------------------------------------------------------------

struct BANKEX_GD_REQ_POINT
{
	PSBMSG_HEAD	h;
	// ----
	WORD	UserIndex;
	char	AccountID[11];
};
// -------------------------------------------------------------------------------

struct BANKEX_DG_GET_POINT
{
	PSBMSG_HEAD	h;
	// ----
	WORD	UserIndex;
	long	Money;
	long	Bless;
	long	Soul;
	long	Chaos;
	long	Creation;
	long	Life;
	long	Harmony;
	long	Guardian;
	long	Gemstone;
	long	LowRefine;
	long	HigRefine;
	//customs
	long	Custom001;
	long	Custom002;
	long	Custom003;
	long	Custom004;
	long	Custom005;
	long	Custom006;
	long	Custom007;
	long	Custom008;
	long	Custom009;
	long	Custom010;
	long	Custom011;
};

struct PMSG_BANKEX_UPDATE_SEND
{
	PSBMSG_HEAD header;
	long	Money;
	long	Bless;
	long	Soul;
	long	Chaos;
	long	Creation;
	long	Life;
	long	Harmony;
	long	Guardian;
	long	Gemstone;
	long	LowRefine;
	long	HigRefine;
	int		MaxWarehouse;
	//customs
	long	Custom001;
	long	Custom002;
	long	Custom003;
	long	Custom004;
	long	Custom005;
	long	Custom006;
	long	Custom007;
	long	Custom008;
	long	Custom009;
	long	Custom010;
	long	Custom011;
};

struct PMSG_JEWELBANK
{
	PBMSG_HEAD2 h;
	int Result;
};
// -------------------------------------------------------------------------------
struct JEWEL_BANK
{
	int Index;
	int ID;
	int ItemID;
	char ItemName[50];
};

enum eBankExType
{
	BANKEX_BLESS = 0,
	BANKEX_SOUL = 1,
	BANKEX_CHAOS = 2,
	BANKEX_CREATION = 3,
	BANKEX_LIFE = 4,
	BANKEX_HARMONY = 5,
	BANKEX_GUARDIAN = 6,
	BANKEX_GEMSTONE = 7,
	BANKEX_LOWERREF = 8,
	BANKEX_HIGHREF = 9,
};

class CBankEx
{
public:
	CBankEx();
	virtual ~CBankEx();
	void Init();
	void Load(char* path);
	void SetInfo(JEWEL_BANK info);
	void InitUser(LPOBJ lpObj);
	void GDSavePoint(int aIndex);
	void GDReqPoint(int aIndex);
	void DGGetPoint(BANKEX_DG_GET_POINT * aRecv);
	void GCUpdateBankEx(int aIndex);
	//
	void CheckOpenInterface(LPOBJ lpObj);
	void CheckUserState(LPOBJ lpObj);
	void Packet(int aIndex, PMSG_JEWELBANK* lpMsg);
	void sendzen(LPOBJ lpObj, int Count);
	void recvzen(LPOBJ lpObj, int Count);
	void sendchaosbank(LPOBJ lpObj, int Count);
	void recvchaosbank(LPOBJ lpObj, int Count);
	void sendblessbank(LPOBJ lpObj, int Count);
	void recvblessbank(LPOBJ lpObj, int Count);
	void sendsoulbank(LPOBJ lpObj, int Count);
	void recvsoulbank(LPOBJ lpObj, int Count);
	void sendlifebank(LPOBJ lpObj, int Count);
	void recvlifebank(LPOBJ lpObj, int Count);
	void sendcreationbank(LPOBJ lpObj, int Count);
	void recvcreationbank(LPOBJ lpObj, int Count);
	void sendharmonybank(LPOBJ lpObj, int Count);
	void recvharmonybank(LPOBJ lpObj, int Count);
	void sendguardianbank(LPOBJ lpObj, int Count);
	void recvguardianbank(LPOBJ lpObj, int Count);
	void sendgemstonebank(LPOBJ lpObj, int Count);
	void recvgemstonebank(LPOBJ lpObj, int Count);
	void sendlowstonebank(LPOBJ lpObj, int Count);
	void recvlowstonebank(LPOBJ lpObj, int Count);
	void sendhigstonebank(LPOBJ lpObj, int Count);
	void recvhigstonebank(LPOBJ lpObj, int Count);
private:
	JEWEL_BANK m_JewelBank[MAX_CUSTOM_BANK];
}
; extern CBankEx gBankEx;