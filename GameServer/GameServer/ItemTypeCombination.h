// SetItemType.h: interface for the CSetItemType class.
//
//////////////////////////////////////////////////////////////////////

#pragma once

#define MAX_ITEM_TYPE_COMBINATION 1000
#define MAX_ITEM_OPTION_INDEX_COMBINATION 1

struct ITEM_TYPE_COMBINATION_INFO
{
	int Index;
	int OptionIndex[MAX_ITEM_TYPE_COMBINATION];
};

class CItemTypeOption
{
public:
	CItemTypeOption();
	virtual ~CItemTypeOption();
	void Init();
	void SetInfo(ITEM_TYPE_COMBINATION_INFO info);
	ITEM_TYPE_COMBINATION_INFO* GetInfo(int index);
	bool CheckItemTypeCombination(int index);
	int GetItemCombinationOptionIndex(int index,int number);
	int GetRandomItemCombination();
	void MakeRandomItemCombination(int aIndex,int map,int x,int y);
private:
	ITEM_TYPE_COMBINATION_INFO m_ItemTypeCombinationInfo[MAX_ITEM_TYPE_COMBINATION];
	int m_count;
};

extern CItemTypeOption gItemTypeOption;
