#pragma once

#define MAX_CUSTOM_GLOVES	100

struct CUSTOM_RF_GLOVES
{
	int Index;
	int ItemIndex;
	char ModelName[32];
	int TextureLeftIndex;
	char TextureLeftName[32];
	int TextureRightIndex;
	char TextureRightName[32];
	int ColorR;
	int ColorG;
	int ColorB;

};

class CCustomGloves
{
public:
	CCustomGloves();
	virtual ~CCustomGloves();
	void Init();
	void Load(char* path);
	void SetInfo(CUSTOM_RF_GLOVES info);
public:
	CUSTOM_RF_GLOVES m_CustomGlovesInfo[MAX_CUSTOM_GLOVES];
};

extern CCustomGloves gCustomGloves;
