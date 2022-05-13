#pragma once

#define MaxLine 3000

struct nInformation
{
	int ItemIndex;
	//--
	char OptionName[32];
	int OptionColor;
	//--
	int TextIndex[15];
	int TextColor[15];
};

struct nText
{
	int Index;
	char Text[254];
};

class nCInfo
{
public:
	nCInfo();
	virtual ~nCInfo();
	void Init();
	void Load(char* path);
	void Load2(char* path); // OK
	void SetInfo1(nInformation info, int CustomItemIndexCount);
	void SetInfo2(nText info, int CustomItemIndexCount);
public:
	nInformation n_TRSTooltipData[MaxLine];
	nText n_TRSTooltipText[MaxLine];
};

extern nCInfo GInfo;