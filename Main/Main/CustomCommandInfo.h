#pragma once
// -------------------------------------------------------------------------------

#include "Protocol.h"
#include "Interface.h"
#include "Import.h"
// -------------------------------------------------------------------------------
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
	~CCustomCommandInfo();

	void Init();
	void Load(CUSTOM_COMMAND_INFO* info);
	void SetInfo(CUSTOM_COMMAND_INFO info);
	CUSTOM_COMMAND_INFO* GetInfo(int index);
	void DrawCommandWindow();
	void OpenCommandWindow();

	bool CheckTestWindow()
	{
		return gInterface.Data[eCommand_MAIN].OnShow;
	};

	void	OpenTestWindow()
	{
		gInterface.Data[eCommand_MAIN].OnShow = true; pSetCursorFocus = true;
	};

	void    CloseTestWindow()
	{
		gInterface.Data[eCommand_MAIN].OnShow = false; pSetCursorFocus = false;
	};
	bool EventCommandWindow_Close(DWORD Event);
	bool CommandNext(DWORD Event);
	bool CommandPrev(DWORD Event);
	// ----
public:
	CUSTOM_COMMAND_INFO m_CustomCommandInfo[MAX_CUSTOM_COMMAND];
	int Page;
	int Count;
	// ----
}; extern CCustomCommandInfo gCustomCommandInfo;
// -------------------------------------------------------------------------------