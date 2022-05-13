// CustomItem.h: interface for the CCustomItem class.
//
//////////////////////////////////////////////////////////////////////

#pragma once

#define MAX_CUSTOM_COMMAND 100

struct CUSTOM_COMMAND_INFO
{
	int Index;
	int Color;
	char Command[40];
	char Description[40];
};

class CCustomCommandInfo
{
public:
	CCustomCommandInfo();
	virtual ~CCustomCommandInfo();
	void Init();
	void Load(char* path);
	void SetInfo(CUSTOM_COMMAND_INFO info);
public:
	CUSTOM_COMMAND_INFO m_CustomCommandInfo[MAX_CUSTOM_COMMAND];
};

extern CCustomCommandInfo gCustomCommandInfo;