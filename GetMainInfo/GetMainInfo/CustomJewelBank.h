#pragma once

#define MAX_JEWELBANK 11

struct JEWEL_BANK
{
	int Index;
	int ID;
	int ItemID;
	char ItemName[50];
};

class JewelBank
{
public:
	JewelBank();
	virtual ~JewelBank();
	void Init();
	void Load(char* path);
	void SetInfo(JEWEL_BANK info);

public:
	JEWEL_BANK m_JewelBank [MAX_JEWELBANK];

}; extern JewelBank gJewelBank;