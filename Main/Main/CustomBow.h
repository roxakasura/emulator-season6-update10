#pragma once

#include "stdafx.h"

#define MAX_CUSTOM_BOW 200

struct CUSTOM_BOW_INFO
{
	int Index;
	int ItemIndex;
	char ModelName[32];
	int ItemType;
	int SkillShot;
	int ColorR;
	int ColorG;
	int ColorB;
};

class CCustomBow
{
public:
	CCustomBow();
	virtual ~CCustomBow();
	void Init();
	void Load(CUSTOM_BOW_INFO* info);
	void SetInfo(CUSTOM_BOW_INFO info);
	CUSTOM_BOW_INFO* GetInfo(int index);
	CUSTOM_BOW_INFO* GetInfoByItem(int ItemIndex);
	bool CheckCustomBow(int ItemIndex);
	bool CheckCustomCross(int ItemIndex);
public:
	CUSTOM_BOW_INFO m_CustomBowInfo[MAX_CUSTOM_BOW];
};

extern CCustomBow gCustomBow;