#include "stdafx.h"
#include "ItemSmoke.h"
#include "Item.h"


cSmokeEffect gSmokeEffect;

cSmokeEffect::cSmokeEffect()
{
	this->Init();
}

cSmokeEffect::~cSmokeEffect()
{
	
}

void cSmokeEffect::Init()
{
	for (int i=0; i<MAX_SMOKE_ITEMS; i++)
	{
		this->m_CustomSmokeEffect[i].Index = -1;
	}
}

void cSmokeEffect::Load(CUSTOM_SMOKEEFFECT* info)
{
	for (int i=0; i<MAX_SMOKE_ITEMS; i++)
	{
		this->SetInfo(info[i]);
	}
}

void cSmokeEffect::SetInfo(CUSTOM_SMOKEEFFECT info)
{
	if(info.Index < 0 || info.Index >= MAX_SMOKE_ITEMS)
	{
		return;
	}
	////console.Log("", "[%d] %f %f %f", info.ItemIndex, info.Red, info.Green, info.Blue);
	this->m_CustomSmokeEffect[info.Index] = info;
}

CUSTOM_SMOKEEFFECT* cSmokeEffect::GetEffect(int ItemID)
{
	for(int n=0;n < MAX_SMOKE_ITEMS;n++)
	{
		CUSTOM_SMOKEEFFECT* lpInfo = this->GetEffectByIndex(n);

		if(lpInfo == 0)
		{
			continue;
		}

		if(GET_ITEM_MODEL(11, lpInfo->ItemIndex) == ItemID)
		{
			return lpInfo;
		}
	}

	return 0;
}

CUSTOM_SMOKEEFFECT* cSmokeEffect::GetEffectByIndex(int index)
{
	if(index < 0 || index >= MAX_SMOKE_ITEMS)
	{
		return 0;
	}

	if(this->m_CustomSmokeEffect[index].Index != index)
	{
		return 0;
	}

	return &this->m_CustomSmokeEffect[index];
}

int cSmokeEffect::GetItemID(int ItemID)
{
	for(int n=0;n < MAX_SMOKE_ITEMS;n++)
	{
		CUSTOM_SMOKEEFFECT* lpInfo = this->GetEffectByIndex(n);

		if(lpInfo == 0)
		{
			continue;
		}

		if(GET_ITEM_MODEL(11, lpInfo->ItemIndex) == ItemID)
		{
			return GET_ITEM_MODEL(11, lpInfo->ItemIndex);
		}
	}

	return -1;
}

float cSmokeEffect::GetRedColor(int ItemID)
{
	for(int n=0;n < MAX_SMOKE_ITEMS;n++)
	{
		CUSTOM_SMOKEEFFECT* lpInfo = this->GetEffectByIndex(n);

		if(lpInfo == 0)
		{
			continue;
		}

		if(GET_ITEM_MODEL(11, lpInfo->ItemIndex) == ItemID)
		{
			return lpInfo->Red;
		}
	}

	return -1;
}

float cSmokeEffect::GetGreenColor(int ItemID)
{
	for(int n=0;n < MAX_SMOKE_ITEMS;n++)
	{
		CUSTOM_SMOKEEFFECT* lpInfo = this->GetEffectByIndex(n);

		if(lpInfo == 0)
		{
			continue;
		}

		if(GET_ITEM_MODEL(11, lpInfo->ItemIndex) == ItemID)
		{
			return lpInfo->Green;
		}
	}

	return -1;
}

float cSmokeEffect::GetBlueColor(int ItemID)
{
	for(int n=0;n < MAX_SMOKE_ITEMS;n++)
	{
		CUSTOM_SMOKEEFFECT* lpInfo = this->GetEffectByIndex(n);

		if(lpInfo == 0)
		{
			continue;
		}

		if(GET_ITEM_MODEL(11, lpInfo->ItemIndex) == ItemID)
		{
			return lpInfo->Blue;
		}
	}

	return -1;
}