#pragma once

#include "stdafx.h"
#include "Protocol.h"
#include "Interface.h"
#include "Import.h"

class cBuyVip
{
public:
	cBuyVip();
	~cBuyVip();

	void Init();
	void Load();
	void Draw();

	bool		EventVipWindow_Main(DWORD Event);
	bool		EventVipWindow_Close(DWORD Event);
	bool		EventVipWindow_Bronze(DWORD Event);
	bool		EventVipWindow_Silver(DWORD Event);
	bool		EventVipWindow_Gold(DWORD Event);

	int ActivePage;
	int ActiveSend;
	int FreePoint;
	bool Click;
	int PointX;
	bool m_Loaded;

	bool CheckTestWindow()
	{
		return gInterface.Data[eVip_MAIN].OnShow;
	};

	void	OpenTestWindow()
	{
		gInterface.Data[eVip_MAIN].OnShow = true; pSetCursorFocus = true;
	};

	void    CloseTestWindow()
	{
		gInterface.Data[eVip_MAIN].OnShow = false; pSetCursorFocus = false;
	};
	DWORD OpenTestDelay;
};
extern cBuyVip gBuyVip;
