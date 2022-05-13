// CustomItem.h: interface for the CCustomItem class.
//
//////////////////////////////////////////////////////////////////////

#pragma once

#define MAX_DESCRIPTION_ITEM 1000

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
	void Init();
	void Load(char* path);
	void SetInfo(CUSTOM_DESCRIPTION_INFO info);
public:
	CUSTOM_DESCRIPTION_INFO m_Info[MAX_DESCRIPTION_ITEM];
};

extern CCustomItemDescription gCustomItemDescription;
