#include "stdafx.h"
#include "CustomBow.h"

CCustomBow gCustomBow;
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CCustomBow::CCustomBow() // OK
{
	this->Init();
}

CCustomBow::~CCustomBow() // OK
{

}

void CCustomBow::Init() // OK
{
	for(int n=0;n < MAX_CUSTOM_BOW;n++)
	{
		this->m_CustomBowInfo[n].Index = -1;
	}
}

void CCustomBow::Load(CUSTOM_BOW_INFO* info) // OK
{
	for(int n=0;n < MAX_CUSTOM_BOW;n++)
	{
		this->SetInfo(info[n]);
	}
}

void CCustomBow::SetInfo(CUSTOM_BOW_INFO info) // OK
{
	if(info.Index < 0 || info.Index >= MAX_CUSTOM_BOW)
	{
		return;
	}

	this->m_CustomBowInfo[info.Index] = info;
}

CUSTOM_BOW_INFO* CCustomBow::GetInfo(int index) // OK
{
	if(index < 0 || index >= MAX_CUSTOM_BOW)
	{
		return 0;
	}

	if(this->m_CustomBowInfo[index].Index != index)
	{
		return 0;
	}

	return &this->m_CustomBowInfo[index];
}

CUSTOM_BOW_INFO* CCustomBow::GetInfoByItem(int ItemIndex) // OK
{
	for(int n=0;n < MAX_CUSTOM_BOW;n++)
	{
		CUSTOM_BOW_INFO* lpInfo = this->GetInfo(n);

		if(lpInfo == 0)
		{
			continue;
		}

		if(lpInfo->ItemIndex == ItemIndex)
		{
			return lpInfo;
		}
	}

	return 0;
}

bool CCustomBow::CheckCustomBow(int ItemIndex) // OK
{
	for (int i=0;i<MAX_CUSTOM_BOW; i++)
	{
		if (ItemIndex == this->m_CustomBowInfo[i].ItemIndex)
		{
			if(this->m_CustomBowInfo[i].ItemType == 0){
				return true;
			}
		}
	}
	return false;
}

bool CCustomBow::CheckCustomCross(int ItemIndex) // OK
{
	for (int i=0;i<MAX_CUSTOM_BOW; i++)
	{
		if (ItemIndex == this->m_CustomBowInfo[i].ItemIndex)
		{
			if(this->m_CustomBowInfo[i].ItemType == 1){
				return true;
			}
		}
	}
	return false;
}
