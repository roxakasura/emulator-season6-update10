// SetItemOption.h: interface for the CSetItemOption class.
//
//////////////////////////////////////////////////////////////////////

#pragma once

#include "Item.h"
#include "User.h"
#include "ItemTypeCombination.h"

#define MAX_ITEM_OPTION_COMBINATION 100
#define MAX_ITEM_OPTION_TABLE_COMBINATION 1
#define MAX_ITEM_FULL_OPTION_TABLE_COMBINATION 5


struct ITEM_OPTION_TABLE_COMBINATION
{
	int Index;
	int Value;
};

struct ITEM_OPTION_COMBINATION_INFO
{
	int Index;
	ITEM_OPTION_TABLE_COMBINATION OptionTable[MAX_ITEM_OPTION_TABLE_COMBINATION];
};

class CItemOptionCombination
{
public:
	CItemOptionCombination();
	virtual ~CItemOptionCombination();
	void Init();
	void Load(char* path);
	void SetInfo(ITEM_OPTION_COMBINATION_INFO info);
	ITEM_OPTION_COMBINATION_INFO* GetInfo(int index);
	int GetItemCombinationMaxOptionCount(int index);
	int GetInventoryItemCombinationOptionCount(LPOBJ lpObj,int index);
	void CalcItemOptionCombination(LPOBJ lpObj,bool flag);
	void InsertOption(LPOBJ lpObj,int index,int value,bool flag);
private:
	ITEM_OPTION_COMBINATION_INFO m_ItemOptionCombinationInfo[MAX_ITEM_OPTION_COMBINATION];
};

extern CItemOptionCombination gItemOptionCombination;
