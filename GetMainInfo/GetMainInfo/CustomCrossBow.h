#pragma once

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

class cCustomBow
{
public:
	cCustomBow();
	virtual ~cCustomBow();
	void Init();
	void Load(char* path);
	void SetInfo(CUSTOM_BOW_INFO info);
public:
	CUSTOM_BOW_INFO m_CustomBowInfo[MAX_CUSTOM_BOW];
}; extern cCustomBow gCustomCrossBow;