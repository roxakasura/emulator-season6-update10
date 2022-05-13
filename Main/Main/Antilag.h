#pragma once

#include "stdafx.h"
#include "Protocol.h"
#include "Interface.h"
#include "Import.h"

class cAntiLagSystem
{
public:
	cAntiLagSystem();
	~cAntiLagSystem();

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
		return gInterface.Data[eADDPOINT_MAIN].OnShow;
	};

	void	OpenTestWindow()
	{
		gInterface.Data[eADDPOINT_MAIN].OnShow = true; pSetCursorFocus = true;
	};

	void    CloseTestWindow()
	{
		gInterface.Data[eADDPOINT_MAIN].OnShow = false; pSetCursorFocus = false;
	};
	DWORD OpenTestDelay;
	//
	bool		EventUsersPanelAntiLag(DWORD Event);
	bool		EventUsersPanelAntiLag_GLOW(DWORD Event); //glow dos itens
	bool		EventUsersPanelAntiLag_TRANSPARENCE(DWORD Event); //transparence dos itens
	bool		EventUsersPanelAntiLag_INVISIBLY(DWORD Event); //invisibilidade
	bool		EventUsersPanelAntiLag_INVISIBLYWINGS(DWORD Event); //invisibilidade
	bool		EventUsersPanelAntiLag_INVISIBLYWEAPONS(DWORD Event); //invisibilidade
	bool		EventUsersPanelAntiLag_EFFECTDYNAMIC(DWORD Event); //dynamic
	bool        EventUsersPanelAntiLag_EFFECTSTATIC(DWORD Event);
	bool		EventUsersPanelAntiLag_EFFECT15(DWORD Event);
	bool		EventUsersPanelAntiLag_OBJECTS(DWORD Event);
	bool		EventUsersPanelAntiLag_EFFECTEXCELLENT1(DWORD Event);
	bool		EventUsersPanelAntiLag_REMOVELEVELITEM(DWORD Event);
	bool		EventUsersPanelAntiLag_REMOVEZENDROP(DWORD Event);
	bool		EventUsersPanelAntiLag_CLOSE(DWORD Event);

	int         testFunctionInvItem;
	int			testFunctionInvItem2;
	int			testFunctionInvItem3;
	int			testFunctionInvItem4;
	int			testFunctionInvItem5;
	int			testFunctionInvItem6;
	int			testFunctionInvItem7;
	int			testFunctionInvItem8;
	int			testFunctionInvItem9;
	int			testFunctionInvItem10;
	int			testFunctionInvItem11;
};
extern cAntiLagSystem gAntiLagSystem;
