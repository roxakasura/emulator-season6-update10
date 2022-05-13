#pragma once
// -------------------------------------------------------------------------------

#include "Protocol.h"
// -------------------------------------------------------------------------------
#define MAX_CUSTOM_BUYVIP 3

struct BUYPREMIUM_REQ
{
	PSBMSG_HEAD h;
	int	VipType;
};
// -------------------------------------------------------------------------------

struct CUSTOM_BUYVIP_INFO
{
	int Index;
	int Exp;
	int Drop;
	int Days;
	int Coin1;
	int Coin2;
	int Coin3;
	char VipName[32];
};

class CCustomBuyVip
{
public:
	CCustomBuyVip();
	~CCustomBuyVip();

	void Init();
	void Load(CUSTOM_BUYVIP_INFO* info);
	void SetInfo(CUSTOM_BUYVIP_INFO info);
	CUSTOM_BUYVIP_INFO* GetInfo(int index);
	// ----
	void BuyStatus(int VipType);
public:
	CUSTOM_BUYVIP_INFO m_CustomBuyVipInfo[MAX_CUSTOM_BUYVIP];
	// ----
}; extern CCustomBuyVip gCustomBuyVip;
// -------------------------------------------------------------------------------