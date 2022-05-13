#pragma once

#define MAX_CUSTOMMONSTER 100

struct CUSTOMMONSTER_DATA
{
	int Index;
	WORD ID;
	BYTE Type;
	char Name[25];
	char Dir[50];
	char Folder[50];
	char BMDFile[50];
	float Size;
};

class cCustomMonsters
{
public:
	cCustomMonsters();
	virtual ~cCustomMonsters();
	void Init();
	void Load(char* path);
	void SetInfo(CUSTOMMONSTER_DATA info);
public:
	CUSTOMMONSTER_DATA m_Monsters[MAX_CUSTOMMONSTER];
}; extern cCustomMonsters gMonsters;