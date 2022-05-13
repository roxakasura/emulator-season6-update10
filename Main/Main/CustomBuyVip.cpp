#include "StdAfx.h"
#include "CustomBuyVip.h"
#include "User.h"
#include "Protocol.h"
// -------------------------------------------------------------------------------

CCustomBuyVip gCustomBuyVip;
// -------------------------------------------------------------------------------

CCustomBuyVip::CCustomBuyVip()
{
	this->Init();
}
// -------------------------------------------------------------------------------

CCustomBuyVip::~CCustomBuyVip()
{
	// ----
}
// -------------------------------------------------------------------------------

void CCustomBuyVip::Init() // OK
{
	for(int n=0;n < MAX_CUSTOM_BUYVIP;n++)
	{
		this->m_CustomBuyVipInfo[n].Index = -1;
	}
}

void CCustomBuyVip::Load(CUSTOM_BUYVIP_INFO* info) // OK
{
	for(int n=0;n < MAX_CUSTOM_BUYVIP;n++)
	{
		this->SetInfo(info[n]);
	}
}

void CCustomBuyVip::SetInfo(CUSTOM_BUYVIP_INFO info) // OK
{
	if(info.Index < 0 || info.Index >= MAX_CUSTOM_BUYVIP)
	{
		return;
	}

	this->m_CustomBuyVipInfo[info.Index] = info;
}

CUSTOM_BUYVIP_INFO* CCustomBuyVip::GetInfo(int index) // OK
{
	if(index < 0 || index >= MAX_CUSTOM_BUYVIP)
	{
		return 0;
	}

	if(this->m_CustomBuyVipInfo[index].Index != index)
	{
		return 0;
	}

	return &this->m_CustomBuyVipInfo[index];
}

void CCustomBuyVip::BuyStatus(int VipType)
{
	BUYPREMIUM_REQ pRequest;
	pRequest.h.set(0xF3,0xF0, sizeof(pRequest));
	pRequest.VipType = VipType;
	DataSend((LPBYTE)&pRequest, pRequest.h.size);
}
// -------------------------------------------------------------------------------
