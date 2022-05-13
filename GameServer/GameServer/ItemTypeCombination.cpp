// SetItemType.cpp: implementation of the CItemTypeOption class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "ItemTypeCombination.h"
#include "DSProtocol.h"
#include "ItemManager.h"
#include "ItemOptionRate.h"
#include "MemScript.h"
#include "ServerInfo.h"
#include "Util.h"

CItemTypeOption gItemTypeOption;
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CItemTypeOption::CItemTypeOption() // OK
{
	this->Init();
}

CItemTypeOption::~CItemTypeOption() // OK
{

}

void CItemTypeOption::Init() // OK
{
	for(int n=0;n < MAX_ITEM_TYPE_COMBINATION;n++)
	{
		this->m_ItemTypeCombinationInfo[n].Index = -1;
	}

	this->m_count = 0;
}

void CItemTypeOption::SetInfo(ITEM_TYPE_COMBINATION_INFO info) // OK
{
	if(this->m_count < 0 || this->m_count >= MAX_ITEM_TYPE_COMBINATION)
	{
		return;
	}

	this->m_ItemTypeCombinationInfo[this->m_count++] = info;
}

ITEM_TYPE_COMBINATION_INFO* CItemTypeOption::GetInfo(int index) // OK
{
	for(int n=0;n < this->m_count;n++)
	{
		if(this->m_ItemTypeCombinationInfo[n].Index == -1)
		{
			continue;
		}

		if(this->m_ItemTypeCombinationInfo[n].Index == index)
		{
			return &this->m_ItemTypeCombinationInfo[n];
		}
	}
	
	return 0;
}

bool CItemTypeOption::CheckItemTypeCombination(int index) // OK
{
	return ((this->GetInfo(index)==0)?0:1);
}

int CItemTypeOption::GetItemCombinationOptionIndex(int index,int number) // OK
{
	ITEM_TYPE_COMBINATION_INFO* lpInfo = this->GetInfo(index);

	if(lpInfo == 0)
	{
		return -1;
	}

	if(number < 0 || number >= MAX_ITEM_OPTION_INDEX_COMBINATION)
	{
		return -1;
	}

	return lpInfo->OptionIndex[number];
}

int CItemTypeOption::GetRandomItemCombination() // OK
{
	int IndexTable[MAX_ITEM_TYPE_COMBINATION],IndexTableCount=0;

	for(int n=0;n < this->m_count;n++)
	{
		ITEM_INFO ItemInfo;

		if(gItemManager.GetInfo(this->m_ItemTypeCombinationInfo[n].Index,&ItemInfo) != 0 && ItemInfo.DropItem != 0)
		{
			IndexTable[IndexTableCount++] = ItemInfo.Index;
		}
	}

	return ((IndexTableCount==0)?-1:IndexTable[GetLargeRand()%IndexTableCount]);
}

void CItemTypeOption::MakeRandomItemCombination(int aIndex,int map,int x,int y) // OK
{
	WORD ItemIndex = this->GetRandomItemCombination();

	if(ItemIndex == -1)
	{
		return;
	}

	BYTE ItemLevel = 0;
	BYTE ItemOption1 = 0;
	BYTE ItemOption2 = 0;
	BYTE ItemOption3 = 0;
	BYTE ItemNewOption = 0;
	BYTE ItemSetOption = 0;
	BYTE ItemSocketOption[MAX_SOCKET_OPTION] = {0xFF,0xFF,0xFF,0xFF,0xFF};

	gItemOptionRate.GetItemOption0(2,&ItemLevel);

	gItemOptionRate.GetItemOption1(2,&ItemOption1);

	gItemOptionRate.GetItemOption2(2,&ItemOption2);

	gItemOptionRate.GetItemOption3(2,&ItemOption3);

	gItemOptionRate.GetItemOption4(2,&ItemNewOption);

	gItemOptionRate.GetItemOption5(2,&ItemSetOption);

	gItemOptionRate.GetItemOption6(2,&ItemSocketOption[0]);

	gItemOptionRate.MakeNewOption(ItemIndex,ItemNewOption,&ItemNewOption);

	gItemOptionRate.MakeSetOption(ItemIndex,ItemSetOption,&ItemSetOption);

	gItemOptionRate.MakeSocketOption(ItemIndex,ItemSocketOption[0],&ItemSocketOption[0]);

	GDCreateItemSend(aIndex,map,x,y,ItemIndex,ItemLevel,0,ItemOption1,ItemOption2,ItemOption3,aIndex,ItemNewOption,ItemSetOption,0,0,ItemSocketOption,0xFF,0);
}
