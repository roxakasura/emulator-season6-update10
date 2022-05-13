#include "stdafx.h"
#include "Interface.h"
#include "BuyVip.h"
#include "Item.h"
#include "User.h"
#include "Util.h"
#include "Object.h"
#include "Defines.h"
#include "ConnectServer.h"
#include "SwitchServer.h"
#include "NewFont.h"
#include "NewInterface.h"
#include "CustomWindow.h"
#include "CMacroUIEx.h"
#include "CustomMessage.h"
#include "CustomBuyVip.h"
#include "Protect.h"
#include "Central.h"

cBuyVip gBuyVip;

cBuyVip::cBuyVip()
{
	this->Init();
}

cBuyVip::~cBuyVip()
{
}

void cBuyVip::Init()
{
	this->Click = false;
}

void cBuyVip::Load()
{

}

void cBuyVip::Draw()
{
	if (gProtect.m_MainInfo.CustomInterfaceType != 3)
	{
		if (!gInterface.Data[eVip_MAIN].OnShow)
		{
			return;
		}

		if (gProtect.m_MainInfo.EnableVipShop != 1)
		{
			this->CloseTestWindow();
			return;
		}

		if (gInterface.CheckWindow(ObjWindow::MoveList) || gInterface.CheckWindow(ObjWindow::CashShop) || gInterface.CheckWindow(ObjWindow::SkillTree) || gInterface.CheckWindow(ObjWindow::FullMap)
			|| (gInterface.CheckWindow(Inventory)
				&& gInterface.CheckWindow(ExpandInventory)
				&& gInterface.CheckWindow(Store))
			|| (gInterface.CheckWindow(Inventory)
				&& gInterface.CheckWindow(Warehouse)
				&& gInterface.CheckWindow(ExpandWarehouse)))
		{
			this->CloseTestWindow();
			return;
		}

		pSetCursorFocus = true;

		// ----
		float MainWidth = 230.0;
		float MainHeight = 180.0;
		float StartBody = 40.0;
		float StartY = 40.0;
		float StartX = (MAX_WIN_WIDTH / 2) - (MainWidth / 2);
		float MainCenter = StartX + (MainWidth / 3);
		float ButtonX = MainCenter - (float)(29.0 / 2);
		// ----
		gInterface.DrawGUI(eVip_MAIN, StartX, StartY + (float)2.0);
		gInterface.DrawGUI(eVip_TITLE, StartX, StartY);
		StartY = gInterface.DrawRepeatGUI(eVip_FRAME, StartX, StartY + (float)15.0, 13);
		gInterface.DrawGUI(eVip_FOOTER, StartX, StartY);
		gInterface.DrawGUI(eVip_CLOSE, StartX + MainWidth - gInterface.Data[eVip_CLOSE].Width, StartBody);

		// ----
		if (gInterface.IsWorkZone(eVip_CLOSE))
		{
			DWORD Color = eGray100;
			// ----
			if (gInterface.Data[eVip_CLOSE].OnClick)
			{
				Color = eGray150;
			}
			// ----
			gInterface.DrawColoredGUI(eVip_CLOSE, gInterface.Data[eVip_CLOSE].X, StartBody, Color);
			gInterface.DrawToolTip((int)gInterface.Data[eVip_CLOSE].X + 5, StartBody + 25, "Close");
		}
		// ----
		gInterface.DrawFormat(eGold, (int)StartX + 10, (int)StartBody + 10, 210, 3, gCustomMessage.GetMessage(5));
		int LineY = gInterface.DrawFormat(eWhite, (int)StartX + 30, (int)StartBody + 35, 210, 1, gCustomMessage.GetMessage(6), gObjUser.lpPlayer->Name);
		LineY = gInterface.DrawFormat(eGold, (int)StartX + 30, (int)LineY, 210, 1, gCustomMessage.GetMessage(14));
		LineY = gInterface.DrawFormat(eWhite, (int)StartX + 30, (int)LineY, 210, 1, gCustomMessage.GetMessage(7));
		LineY = gInterface.DrawFormat(eWhite, (int)StartX + 30, (int)LineY, 210, 1, gCustomMessage.GetMessage(8));
		// ----
		gInterface.DrawGUI(eVip_DIV, StartX, StartBody + 70);
		gInterface.DrawFormat(eGold, (int)StartX + 30, (int)StartBody + 95 - 2, 210, 1, "Plan");
		gInterface.DrawFormat(eGold, (int)StartX + 80, (int)StartBody + 95 - 2, 210, 1, "Exp");
		gInterface.DrawFormat(eGold, (int)StartX + 130, (int)StartBody + 95 - 2, 210, 1, "Drop");
		gInterface.DrawFormat(eGold, (int)StartX + 170, (int)StartBody + 95 - 2, 210, 1, "Time");
		// ----

		if (gProtect.m_MainInfo.VipTypes < 1 || gProtect.m_MainInfo.VipTypes > 3)
		{
			gProtect.m_MainInfo.VipTypes = 3;
		}

		for (int i = 0; i < gProtect.m_MainInfo.VipTypes; i++)
		{
			gInterface.DrawFormat(eWhite, (int)StartX + 30, (int)StartBody + 110 + (12 * i) - 5, 210, 1, gCustomBuyVip.m_CustomBuyVipInfo[i].VipName);
			// ----
			gInterface.DrawFormat(eWhite, (int)StartX + 80, (int)StartBody + 110 + (12 * i) - 5, 210, 1, "+%d%%", gCustomBuyVip.m_CustomBuyVipInfo[i].Exp);
			// ----
			gInterface.DrawFormat(eWhite, (int)StartX + 130, (int)StartBody + 110 + (12 * i) - 5, 210, 1, "+%d%%", gCustomBuyVip.m_CustomBuyVipInfo[i].Drop);
			// ----
			gInterface.DrawFormat(eWhite, (int)StartX + 170, (int)StartBody + 110 + (12 * i) - 5, 210, 1, "%d day(s)", gCustomBuyVip.m_CustomBuyVipInfo[i].Days);

			pDrawGUI(0x7B5E, StartX + 30, StartBody + 110 + (12 * i) + 9 - 5, 82.0, 2.0);
			pDrawGUI(0x7B5E, StartX + 30 + 82, StartBody + 110 + (12 * i) + 9 - 5, 82.0, 2.0);
		}

		if (gProtect.m_MainInfo.VipTypes > 0)
		{
			// ---- bronze start 
			if (gInterface.IsWorkZone(eVip_BRONZE))
			{
				if (gInterface.Data[eVip_BRONZE].OnClick)
					gInterface.DrawButton(eVip_BRONZE, StartX + 64, 195, 0, 58);
				else
					gInterface.DrawButton(eVip_BRONZE, StartX + 64, 195, 0, 29);
				// ----
				gInterface.DrawFormat(eGold, (int)StartX + 30, (int)StartBody + 142, 210, 1, gCustomMessage.GetMessage(10));
				gInterface.DrawFormat(eGold, (int)StartX + 70, (int)StartBody + 142, 210, 1, gCustomMessage.GetMessage(11), gCustomBuyVip.m_CustomBuyVipInfo[0].Coin1);
				gInterface.DrawFormat(eGold, (int)StartX + 120, (int)StartBody + 142, 210, 1, gCustomMessage.GetMessage(12), gCustomBuyVip.m_CustomBuyVipInfo[0].Coin2);
				gInterface.DrawFormat(eGold, (int)StartX + 160, (int)StartBody + 142, 210, 1, gCustomMessage.GetMessage(13), gCustomBuyVip.m_CustomBuyVipInfo[0].Coin3);
			}
			else
				gInterface.DrawButton(eVip_BRONZE, StartX + 64, 195, 0, 0);
			// ----
			gInterface.DrawFormat(eWhite, (int)StartX + 90, 195 + 9, 160, 1, gCustomMessage.GetMessage(9), gCustomBuyVip.m_CustomBuyVipInfo[0].VipName);
			// ---- bronze end ------------------------------------
		}

		if (gProtect.m_MainInfo.VipTypes > 1)
		{
			// ---- Silver start ------------------------------------
			if (gInterface.IsWorkZone(eVip_SILVER))
			{
				if (gInterface.Data[eVip_SILVER].OnClick)
					gInterface.DrawButton(eVip_SILVER, StartX + 64, 225, 0, 58);
				else
					gInterface.DrawButton(eVip_SILVER, StartX + 64, 225, 0, 29);
				// ----
				gInterface.DrawFormat(eGold, (int)StartX + 30, (int)StartBody + 142, 210, 1, gCustomMessage.GetMessage(10));
				gInterface.DrawFormat(eGold, (int)StartX + 70, (int)StartBody + 142, 210, 1, gCustomMessage.GetMessage(11), gCustomBuyVip.m_CustomBuyVipInfo[1].Coin1);
				gInterface.DrawFormat(eGold, (int)StartX + 120, (int)StartBody + 142, 210, 1, gCustomMessage.GetMessage(12), gCustomBuyVip.m_CustomBuyVipInfo[1].Coin2);
				gInterface.DrawFormat(eGold, (int)StartX + 160, (int)StartBody + 142, 210, 1, gCustomMessage.GetMessage(13), gCustomBuyVip.m_CustomBuyVipInfo[1].Coin3);
			}
			else
				gInterface.DrawButton(eVip_SILVER, StartX + 64, 225, 0, 0);

			gInterface.DrawFormat(eWhite, (int)StartX + 90, 225 + 9, 160, 1, gCustomMessage.GetMessage(9), gCustomBuyVip.m_CustomBuyVipInfo[1].VipName);
			// ---- silver end ------------------------------------
		}

		if (gProtect.m_MainInfo.VipTypes > 2)
		{
			// ---- gold start ------------------------------------
			if (gInterface.IsWorkZone(eVip_GOLD))
			{
				if (gInterface.Data[eVip_GOLD].OnClick)
					gInterface.DrawButton(eVip_GOLD, StartX + 64, 255, 0, 58);
				else
					gInterface.DrawButton(eVip_GOLD, StartX + 64, 255, 0, 29);
				// ----
				gInterface.DrawFormat(eGold, (int)StartX + 30, (int)StartBody + 142, 210, 1, gCustomMessage.GetMessage(10));
				gInterface.DrawFormat(eGold, (int)StartX + 70, (int)StartBody + 142, 210, 1, gCustomMessage.GetMessage(11), gCustomBuyVip.m_CustomBuyVipInfo[2].Coin1);
				gInterface.DrawFormat(eGold, (int)StartX + 120, (int)StartBody + 142, 210, 1, gCustomMessage.GetMessage(12), gCustomBuyVip.m_CustomBuyVipInfo[2].Coin2);
				gInterface.DrawFormat(eGold, (int)StartX + 160, (int)StartBody + 142, 210, 1, gCustomMessage.GetMessage(13), gCustomBuyVip.m_CustomBuyVipInfo[2].Coin3);
			}
			else
				gInterface.DrawButton(eVip_GOLD, StartX + 64, 255, 0, 0);

			gInterface.DrawFormat(eWhite, (int)StartX + 90, 255 + 9, 160, 1, gCustomMessage.GetMessage(9), gCustomBuyVip.m_CustomBuyVipInfo[2].VipName);
			// ---- gold end ------------------------------------
		}
	}
	else
	{
		if (!gInterface.Data[eVip_MAIN].OnShow)
		{
			return;
		}

		if (gProtect.m_MainInfo.EnableVipShop != 1)
		{
			this->CloseTestWindow();
			return;
		}

		if (gInterface.CheckWindow(ObjWindow::MoveList) || gInterface.CheckWindow(ObjWindow::CashShop) || gInterface.CheckWindow(ObjWindow::SkillTree) || gInterface.CheckWindow(ObjWindow::FullMap)
			|| (gInterface.CheckWindow(Inventory)
				&& gInterface.CheckWindow(ExpandInventory)
				&& gInterface.CheckWindow(Store))
			|| (gInterface.CheckWindow(Inventory)
				&& gInterface.CheckWindow(Warehouse)
				&& gInterface.CheckWindow(ExpandWarehouse)))
		{
			this->CloseTestWindow();
			return;
		}

		pSetCursorFocus = true;

		// ----
		float MainWidth = 230.0;
		float MainHeight = 320.0;
		float StartBody = ((MAX_WIN_HEIGHT - 51) / 2) - (MainHeight / 2);
		float StartY = ((MAX_WIN_HEIGHT - 51) / 2) - (MainHeight / 2);
		float StartX = (MAX_WIN_WIDTH / 2) - (MainWidth / 2);
		float MainCenter = StartX + (MainWidth / 3);
		float ButtonX = MainCenter - (float)(29.0 / 2);
		// ----
		gCentral.PrintDropBox(StartX, StartY, MainWidth, MainHeight, 0, 0);
		// ----
		gInterface.DrawFormat(eGold, (int)StartX + 10, (int)StartBody + 10, 210, 3, gCustomMessage.GetMessage(5));
		int LineY = gInterface.DrawFormat(eWhite, (int)StartX + 30, (int)StartBody + 35, 210, 1, gCustomMessage.GetMessage(6), gObjUser.lpPlayer->Name);
		LineY = gInterface.DrawFormat(eGold, (int)StartX + 30, (int)LineY, 210, 1, gCustomMessage.GetMessage(14));
		LineY = gInterface.DrawFormat(eWhite, (int)StartX + 30, (int)LineY, 210, 1, gCustomMessage.GetMessage(7));
		LineY = gInterface.DrawFormat(eWhite, (int)StartX + 30, (int)LineY, 210, 1, gCustomMessage.GetMessage(8));
		//--
		pDrawGUI(71520, StartX + (MainWidth / 2) - (200 / 2), StartBody + 85, 200, 1); //-- Divisor
		//--
		gInterface.DrawFormat(eGold, (int)StartX + 30, (int)StartBody + 95 - 2, 210, 1, "Plan");
		gInterface.DrawFormat(eGold, (int)StartX + 80, (int)StartBody + 95 - 2, 210, 1, "Exp");
		gInterface.DrawFormat(eGold, (int)StartX + 130, (int)StartBody + 95 - 2, 210, 1, "Drop");
		gInterface.DrawFormat(eGold, (int)StartX + 170, (int)StartBody + 95 - 2, 210, 1, "Time");
		// ----

		if (gProtect.m_MainInfo.VipTypes < 1 || gProtect.m_MainInfo.VipTypes > 3)
		{
			gProtect.m_MainInfo.VipTypes = 3;
		}

		for (int i = 0; i < (int)gProtect.m_MainInfo.VipTypes; i++)
		{
			gInterface.DrawFormat(eWhite, (int)StartX + 30, (int)StartBody + 110 + (12 * i) - 5, 210, 1, gCustomBuyVip.m_CustomBuyVipInfo[i].VipName);
			// ----
			gInterface.DrawFormat(eWhite, (int)StartX + 80, (int)StartBody + 110 + (12 * i) - 5, 210, 1, "+%d%%", gCustomBuyVip.m_CustomBuyVipInfo[i].Exp);
			// ----
			gInterface.DrawFormat(eWhite, (int)StartX + 130, (int)StartBody + 110 + (12 * i) - 5, 210, 1, "+%d%%", gCustomBuyVip.m_CustomBuyVipInfo[i].Drop);
			// ----
			gInterface.DrawFormat(eWhite, (int)StartX + 170, (int)StartBody + 110 + (12 * i) - 5, 210, 1, "%d day(s)", gCustomBuyVip.m_CustomBuyVipInfo[i].Days);

			pDrawGUI(0x7B5E, StartX + 30, StartBody + 110 + (12 * i) + 9 - 5, 82.0, 2.0);
			pDrawGUI(0x7B5E, StartX + 30 + 82, StartBody + 110 + (12 * i) + 9 - 5, 82.0, 2.0);
		}

		if (gProtect.m_MainInfo.VipTypes > 0)
		{
			// ---- bronze start 
			if (gInterface.IsWorkZone(eVip_BRONZE))
			{
				if (gInterface.Data[eVip_BRONZE].OnClick)
					gInterface.DrawButton(eVip_BRONZE, StartX + (MainWidth / 2) - (108 / 2), StartY + 165.0f, 0, 0.0f);
				else
					gInterface.DrawButton(eVip_BRONZE, StartX + (MainWidth / 2) - (108 / 2), StartY + 165.0f, 0, 0.0f);
				// ----
				gInterface.DrawFormat(eGold, (int)StartX + 30, (int)StartBody + 142, 210, 1, gCustomMessage.GetMessage(10));
				gInterface.DrawFormat(eGold, (int)StartX + 70, (int)StartBody + 142, 210, 1, gCustomMessage.GetMessage(11), gCustomBuyVip.m_CustomBuyVipInfo[0].Coin1);
				gInterface.DrawFormat(eGold, (int)StartX + 120, (int)StartBody + 142, 210, 1, gCustomMessage.GetMessage(12), gCustomBuyVip.m_CustomBuyVipInfo[0].Coin2);
				gInterface.DrawFormat(eGold, (int)StartX + 160, (int)StartBody + 142, 210, 1, gCustomMessage.GetMessage(13), gCustomBuyVip.m_CustomBuyVipInfo[0].Coin3);
			}
			else
				gInterface.DrawButton(eVip_BRONZE, StartX + (MainWidth / 2) - (108 / 2), StartY + 165.0f, 0, 30.5f);
			// ----
			gInterface.DrawFormat(eWhite, (int)StartX + 86, 220 + 9, 160, 1, gCustomMessage.GetMessage(9), gCustomBuyVip.m_CustomBuyVipInfo[0].VipName);
			// ---- bronze end ------------------------------------
		}

		if (gProtect.m_MainInfo.VipTypes > 1)
		{
			// ---- Silver start ------------------------------------
			if (gInterface.IsWorkZone(eVip_SILVER))
			{
				if (gInterface.Data[eVip_SILVER].OnClick)
					gInterface.DrawButton(eVip_SILVER, StartX + (MainWidth / 2) - (108 / 2), StartY + 196.0f, 0, 0.0f);
				else
					gInterface.DrawButton(eVip_SILVER, StartX + (MainWidth / 2) - (108 / 2), StartY + 196.0f, 0, 0.0f);
				// ----
				gInterface.DrawFormat(eGold, (int)StartX + 30, (int)StartBody + 142, 210, 1, gCustomMessage.GetMessage(10));
				gInterface.DrawFormat(eGold, (int)StartX + 70, (int)StartBody + 142, 210, 1, gCustomMessage.GetMessage(11), gCustomBuyVip.m_CustomBuyVipInfo[1].Coin1);
				gInterface.DrawFormat(eGold, (int)StartX + 120, (int)StartBody + 142, 210, 1, gCustomMessage.GetMessage(12), gCustomBuyVip.m_CustomBuyVipInfo[1].Coin2);
				gInterface.DrawFormat(eGold, (int)StartX + 160, (int)StartBody + 142, 210, 1, gCustomMessage.GetMessage(13), gCustomBuyVip.m_CustomBuyVipInfo[1].Coin3);
			}
			else
				gInterface.DrawButton(eVip_SILVER, StartX + (MainWidth / 2) - (108 / 2), StartY + 196.0f, 0, 30.5f);

			gInterface.DrawFormat(eWhite, (int)StartX + 86, 250 + 9, 160, 1, gCustomMessage.GetMessage(9), gCustomBuyVip.m_CustomBuyVipInfo[1].VipName);
			// ---- silver end ------------------------------------
		}

		if (gProtect.m_MainInfo.VipTypes > 2)
		{
			// ---- gold start ------------------------------------
			if (gInterface.IsWorkZone(eVip_GOLD))
			{
				if (gInterface.Data[eVip_GOLD].OnClick)
					gInterface.DrawButton(eVip_GOLD, StartX + (MainWidth / 2) - (108 / 2), StartY + 226.0f, 0, 0.0f);
				else
					gInterface.DrawButton(eVip_GOLD, StartX + (MainWidth / 2) - (108 / 2), StartY + 226.0f, 0, 0.0f);
				// ----
				gInterface.DrawFormat(eGold, (int)StartX + 30, (int)StartBody + 142, 210, 1, gCustomMessage.GetMessage(10));
				gInterface.DrawFormat(eGold, (int)StartX + 70, (int)StartBody + 142, 210, 1, gCustomMessage.GetMessage(11), gCustomBuyVip.m_CustomBuyVipInfo[2].Coin1);
				gInterface.DrawFormat(eGold, (int)StartX + 120, (int)StartBody + 142, 210, 1, gCustomMessage.GetMessage(12), gCustomBuyVip.m_CustomBuyVipInfo[2].Coin2);
				gInterface.DrawFormat(eGold, (int)StartX + 160, (int)StartBody + 142, 210, 1, gCustomMessage.GetMessage(13), gCustomBuyVip.m_CustomBuyVipInfo[2].Coin3);
			}
			else
				gInterface.DrawButton(eVip_GOLD, StartX + (MainWidth / 2) - (108 / 2), StartY + 226.0f, 0, 30.5f);

			gInterface.DrawFormat(eWhite, (int)StartX + 86, 280 + 9, 160, 1, gCustomMessage.GetMessage(9), gCustomBuyVip.m_CustomBuyVipInfo[2].VipName);
			// ---- gold end ------------------------------------
		}

		pDrawGUI(71520, StartX + (MainWidth / 2) - (200 / 2), 280 + 55, 200, 1); //-- Divisor
	}

}

bool cBuyVip::EventVipWindow_Close(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - gInterface.Data[eVip_CLOSE].EventTick);
	// ----
	if (!gInterface.Data[eVip_MAIN].OnShow || !gInterface.IsWorkZone(eVip_CLOSE))
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		gInterface.Data[eVip_CLOSE].OnClick = true;
		return true;
	}
	// ----
	gInterface.Data[eVip_CLOSE].OnClick = false;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	// ----
	gInterface.Data[eVip_CLOSE].EventTick = GetTickCount();
	this->CloseTestWindow();
	// ----
	return false;
}
// ----------------------------------------------------------------------------------------------

bool cBuyVip::EventVipWindow_Bronze(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - gInterface.Data[eVip_BRONZE].EventTick);
	// ----
	if (!gInterface.Data[eVip_MAIN].OnShow || !gInterface.IsWorkZone(eVip_BRONZE))
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		gInterface.Data[eVip_BRONZE].OnClick = true;
		return true;
	}
	// ----
	gInterface.Data[eVip_BRONZE].OnClick = false;;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	// ----
	gInterface.Data[eVip_BRONZE].EventTick = GetTickCount();
	gCustomBuyVip.BuyStatus(1);
	this->CloseTestWindow();
	// ----
	return false;
}
// ----------------------------------------------------------------------------------------------

bool cBuyVip::EventVipWindow_Silver(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - gInterface.Data[eVip_SILVER].EventTick);
	// ----
	if (!gInterface.Data[eVip_MAIN].OnShow || !gInterface.IsWorkZone(eVip_SILVER))
	{
		return false;
	}
	if (gProtect.m_MainInfo.VipTypes < 2)
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		gInterface.Data[eVip_SILVER].OnClick = true;
		return true;
	}
	// ----
	gInterface.Data[eVip_SILVER].OnClick = false;;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	// ----
	gInterface.Data[eVip_SILVER].EventTick = GetTickCount();
	gCustomBuyVip.BuyStatus(2);
	this->CloseTestWindow();
	// ----
	return false;
}

// ----------------------------------------------------------------------------------------------
bool cBuyVip::EventVipWindow_Gold(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - gInterface.Data[eVip_GOLD].EventTick);
	// ----
	if (!gInterface.Data[eVip_MAIN].OnShow || !gInterface.IsWorkZone(eVip_GOLD))
	{
		return false;
	}
	if (gProtect.m_MainInfo.VipTypes < 3)
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		gInterface.Data[eVip_GOLD].OnClick = true;
		return true;
	}
	// ----
	gInterface.Data[eVip_GOLD].OnClick = false;;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	// ----
	gInterface.Data[eVip_GOLD].EventTick = GetTickCount();
	gCustomBuyVip.BuyStatus(3);
	this->CloseTestWindow();
	// ----
	return false;
}
// ----------------------------------------------------------------------------------------------

bool cBuyVip::EventVipWindow_Main(DWORD Event)
{
	this->EventVipWindow_Close(Event);
	this->EventVipWindow_Bronze(Event);
	this->EventVipWindow_Silver(Event);
	this->EventVipWindow_Gold(Event);
	// ----
	return true;
}