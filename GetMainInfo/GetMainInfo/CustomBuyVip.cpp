// CustomItem.cpp: implementation of the CCustomItem class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "CustomBuyVip.h"
#include "MemScript.h"

CCustomBuyVip gCustomBuyVip;
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CCustomBuyVip::CCustomBuyVip() // OK
{
	this->Init();
}

CCustomBuyVip::~CCustomBuyVip() // OK
{

}

void CCustomBuyVip::Init() // OK
{
	for(int n=0;n < MAX_CUSTOM_BUYVIP;n++)
	{
		this->m_CustomBuyVipInfo[n].Index = -1;
	}
}

void CCustomBuyVip::Load(char* path) // OK
{
	CMemScript* lpMemScript = new CMemScript;

	if(lpMemScript == 0)
	{
		printf(MEM_SCRIPT_ALLOC_ERROR,path);
		return;
	}

	if(lpMemScript->SetBuffer(path) == 0)
	{
		printf(lpMemScript->GetLastError());
		delete lpMemScript;
		return;
	}

	this->Init();

	try
	{
		while(true)
		{
			if(lpMemScript->GetToken() == TOKEN_END)
			{
				break;
			}

			if(strcmp("end",lpMemScript->GetString()) == 0)
			{
				break;
			}

			CUSTOM_BUYVIP_INFO info;

			memset(&info,0,sizeof(info));

			//static int CustomBuyVipIndexCount = 0;

			//info.Index = CustomBuyVipIndexCount++;

			info.Index = lpMemScript->GetNumber();

			info.Exp = lpMemScript->GetAsNumber();

			info.Drop = lpMemScript->GetAsNumber();

			info.Days = lpMemScript->GetAsNumber();

			info.Coin1 = lpMemScript->GetAsNumber();

			info.Coin2 = lpMemScript->GetAsNumber();

			info.Coin3 = lpMemScript->GetAsNumber();

			strcpy_s(info.VipName,lpMemScript->GetAsString());

			this->SetInfo(info);
		}
	}
	catch(...)
	{
		printf(lpMemScript->GetLastError());
	}

	delete lpMemScript;
}

void CCustomBuyVip::SetInfo(CUSTOM_BUYVIP_INFO info) // OK
{
	if(info.Index < 0 || info.Index >= MAX_CUSTOM_BUYVIP)
	{
		return;
	}

	this->m_CustomBuyVipInfo[info.Index] = info;
}
