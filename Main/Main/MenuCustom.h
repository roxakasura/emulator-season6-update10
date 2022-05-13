#pragma once

#include "stdafx.h"
#include "Protocol.h"
#include "Interface.h"
#include "Import.h"

class cCustomMenu
{
public:
	cCustomMenu();
	~cCustomMenu();

	void Init();
	void Load();
	void Draw();
	bool EventMenuCustomWindow_Close(DWORD Event);
	int ActivePage;
	int ActiveSend;
	int FreePoint;
	bool Click;
	int PointX;
	bool m_Loaded;

	bool CheckTestWindow()
	{
		return gInterface.Data[eADDPOINT5_MAIN].OnShow;
	};

	void	OpenTestWindow()
	{
		gInterface.Data[eADDPOINT5_MAIN].OnShow = true; pSetCursorFocus = true;
	};

	void    CloseTestWindow()
	{
		gInterface.Data[eADDPOINT5_MAIN].OnShow = false; pSetCursorFocus = false;
	};

	DWORD OpenTestDelay;
};
extern cCustomMenu gCustomMenu;
