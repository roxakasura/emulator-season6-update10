#include "stdafx.h"
#include "CustomItemPosition.h"
#include "Item.h"


cCustomPosition gCustomPosition;

cCustomPosition::cCustomPosition() // OK
{
	this->Init();
}

cCustomPosition::~cCustomPosition() // OK
{

}

void cCustomPosition::Init() // OK
{
	for (int n = 0; n < MAX_POSITION_ITEM; n++)
	{
		this->m_CustomPositionInfo[n].Index = -1;
	}
}

void cCustomPosition::Load(CUSTOM_POSITION_INFO* info) // OK
{
	for (int n = 0; n < MAX_POSITION_ITEM; n++)
	{
		this->SetInfo(info[n]);
	}
}

void cCustomPosition::SetInfo(CUSTOM_POSITION_INFO info) // OK
{
	if (info.Index < 0 || info.Index >= MAX_POSITION_ITEM)
	{
		return;
	}

	this->m_CustomPositionInfo[info.Index] = info;
}

CUSTOM_POSITION_INFO* cCustomPosition::GetInfo(int index) // OK
{

	if(index < 0 || index >= MAX_POSITION_ITEM)
	{
		return 0;
	}

	if(this->m_CustomPositionInfo[index].Index != index)
	{
		return 0;
	}

	return &this->m_CustomPositionInfo[index];

}

CUSTOM_POSITION_INFO* cCustomPosition::GetInfoByItem(int ItemIndex) // OK
{

	for(int n=0;n < MAX_POSITION_ITEM;n++)
	{
		CUSTOM_POSITION_INFO* lpInfo = this->GetInfo(n);

		if(lpInfo != 0)
		{
			if(lpInfo->ItemIndex == ItemIndex)
			{
				return lpInfo;
			}
		}		
	}

	return 0;
}
bool cCustomPosition::CheckPosition(int ItemIndex) // OK
{
	for (int i=0;i<MAX_POSITION_ITEM; i++)
	{
		if (ItemIndex == this->m_CustomPositionInfo[i].ItemIndex)
		{
			return true;
		}
	}
	return false;
}