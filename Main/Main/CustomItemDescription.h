#pragma once

#define MAX_CUSTOM_DESCRIPTION 1000
#define MAX_CUSTOM_DESCRIPTION_LINES 10

#include "Object.h"

struct CUSTOM_DESCRIPTION_INFO
{
	int Index;
	int ItemIndex;
	int Line;
	int Color;
	int Border;
	CHAR Description[128];
};

class CCustomItemDescription
{
public:
	CCustomItemDescription();
	virtual ~CCustomItemDescription();
	void Load(CUSTOM_DESCRIPTION_INFO* info);
	void SetInfo(CUSTOM_DESCRIPTION_INFO info);
	CUSTOM_DESCRIPTION_INFO* GetInfo(int index);
	CUSTOM_DESCRIPTION_INFO* GetInfoByItem(int ItemIndex);
	short CheckItemDescriptionByItem(int ItemIndex);
	char* GetDescription(int ItemIndex);
	void AddText(char* Text,int Color,int Weight);
	void Init();
	static void SetOptionText(lpItemObj lpItem, int Line, WORD OptionID, bool Arg4, int Arg5);
public:
	CUSTOM_DESCRIPTION_INFO m_Info[MAX_CUSTOM_DESCRIPTION];
};
extern CCustomItemDescription gCustomItemDescription;