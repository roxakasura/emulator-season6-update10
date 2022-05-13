#pragma once

#include "stdafx.h"
#include "Protocol.h"
#include "Interface.h"
#include "Import.h"

class cServerSwitch
{
public:
	cServerSwitch();
	~cServerSwitch();

	void Init();
	void Load();
	void BindImage();
	void Draw();

	int ActivePage;
	int ActiveSend;
	int FreePoint;
	bool Click;
	int PointX;
	bool m_Loaded;

	bool CheckTestWindow()
	{
		return gInterface.Data[eADDPOINT2_MAIN].OnShow;
	};

	void	OpenTestWindow()
	{
		gInterface.Data[eADDPOINT2_MAIN].OnShow = true; pSetCursorFocus = true;
	};

	void    CloseTestWindow()
	{
		gInterface.Data[eADDPOINT2_MAIN].OnShow = false; pSetCursorFocus = false;
	};
	DWORD OpenTestDelay;
};
extern cServerSwitch gServerSwitch;
