#include "stdafx.h"
#include "Interface.h"
#include "MenuCustom.h"
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
#include "User.h"
#include "Central.h"
#include "PrintPlayer.h"

cCustomMenu gCustomMenu;

cCustomMenu::cCustomMenu()
{
	this->Init();
}

cCustomMenu::~cCustomMenu()
{
}

void cCustomMenu::Init()
{
	this->Click = false;
}

void cCustomMenu::Load()
{

}

void cCustomMenu::Draw()
{
	if (gProtect.m_MainInfo.CustomInterfaceType != 3 || gProtect.m_MainInfo.CustomInterfaceType == 4)
	{
		if (!gInterface.Data[eADDPOINT5_MAIN].OnShow)
		{
			return;
		}

		pSetCursorFocus = true;

		float MainWidth = 230.0;
		float MainHeight = 130.0;
		float StartBody = 30.0;
		float StartY = 30.0;
		float StartX = (MAX_WIN_WIDTH / 2) - (MainWidth / 2);
		float MainCenter = StartX + (MainWidth / 3);
		float ButtonX = MainCenter - (float)(29.0 / 2);

		gInterface.DrawGUI(eADDPOINT5_MAIN, StartX, StartY + (float)2.0);
		gInterface.DrawGUI(eADDPOINT5_TITLE, StartX, StartY);
		StartY = gInterface.DrawRepeatGUI(eADDPOINT5_FRAME, StartX, StartY + (float)20.0, 12);
		gInterface.DrawGUI(eADDPOINT5_FOOTER, StartX, StartY);
		gInterface.DrawGUI(eADDPOINT5_CLOSE, StartX + MainWidth - gInterface.Data[eADDPOINT5_CLOSE].Width, StartBody);
		// ----
		if (gInterface.IsWorkZone(eADDPOINT5_CLOSE))
		{
			DWORD Color = eGray100;
			// ----
			if (gInterface.Data[eADDPOINT5_CLOSE].OnClick)
			{
				Color = eGray150;
			}
			// ----
			gInterface.DrawColoredGUI(eADDPOINT5_CLOSE, gInterface.Data[eADDPOINT5_CLOSE].X, StartBody, Color);
			gInterface.DrawToolTip((int)gInterface.Data[eADDPOINT5_CLOSE].X + 5, StartBody + 25, "Close");
		}

		gInterface.DrawFormat(eGold, (int)StartX + 10, (int)StartBody + 10, 210, 3, "Menu");

		gInterface.DrawFormat(eGold, (int)StartX + 10, (int)StartBody + 45, 210, 3, gCustomMessage.GetMessage(54));

		gInterface.DrawGUI(eVip_DIV, StartX, StartBody + 60);

		int BtCount = 0;
		int BtStart = StartBody + 78;
		int BtDistance = 33;

		if (gProtect.m_MainInfo.EnableEventTimeButton == 1)
		{
			BtCount++;
		}
		else
		{
			BtStart -= 33;
		}
		if (gProtect.m_MainInfo.EnableVipShopButton == 1)
		{
			BtCount++;
		}
		if (gProtect.m_MainInfo.EnableRankingButton == 1)
		{
			BtCount++;
		}
		if (gProtect.m_MainInfo.EnableCommandButton == 1)
		{
			BtCount++;
		}
		if (gProtect.m_MainInfo.EnableOptionButton == 1)
		{
			BtCount++;
		}

		if (BtCount == 4)
		{
			BtStart += 15;
		}
		if (BtCount == 3)
		{
			BtStart += 30;
		}
		if (BtCount == 2)
		{
			BtStart += 45;
		}
		if (BtCount == 1)
		{
			BtStart += 60;
		}

		//Horario eventos
		if (gProtect.m_MainInfo.EnableEventTimeButton == 1)
		{

			if (gInterface.IsWorkZone(eMenu_OPT1))
			{
				if (gInterface.Data[eMenu_OPT1].OnClick)
					gInterface.DrawButton(eMenu_OPT1, StartX + 64, BtStart, 0, 58);
				else
					gInterface.DrawButton(eMenu_OPT1, StartX + 64, BtStart, 0, 29);
				// ----
			}
			else
				gInterface.DrawButton(eMenu_OPT1, StartX + 64, BtStart, 0, 0);

			gInterface.DrawFormat(eWhite, (int)StartX + 64, BtStart + 9, 108, 3, gCustomMessage.GetMessage(25));
		}

		//Comprar vip
		if (gProtect.m_MainInfo.EnableVipShopButton == 1)
		{

			BtStart += BtDistance;

			if (gInterface.IsWorkZone(eMenu_OPT2))
			{
				if (gInterface.Data[eMenu_OPT2].OnClick)
					gInterface.DrawButton(eMenu_OPT2, StartX + 64, BtStart, 0, 58);
				else
					gInterface.DrawButton(eMenu_OPT2, StartX + 64, BtStart, 0, 29);
				// ----
			}
			else
				gInterface.DrawButton(eMenu_OPT2, StartX + 64, BtStart, 0, 0);

			gInterface.DrawFormat(eWhite, (int)StartX + 64, BtStart + 9, 108, 3, gCustomMessage.GetMessage(26));
		}

		//Ranking
		if (gProtect.m_MainInfo.EnableRankingButton == 1)
		{
			BtStart += BtDistance;

			if (gInterface.IsWorkZone(eMenu_OPT3))
			{
				if (gInterface.Data[eMenu_OPT3].OnClick)
					gInterface.DrawButton(eMenu_OPT3, StartX + 64, BtStart, 0, 58);
				else
					gInterface.DrawButton(eMenu_OPT3, StartX + 64, BtStart, 0, 29);
				// ----
			}
			else
				gInterface.DrawButton(eMenu_OPT3, StartX + 64, BtStart, 0, 0);

			gInterface.DrawFormat(eWhite, (int)StartX + 64, BtStart + 9, 108, 3, gCustomMessage.GetMessage(27));
		}

		if (gProtect.m_MainInfo.EnableCommandButton == 1)
		{
			//Commandos
			BtStart += BtDistance;

			if (gInterface.IsWorkZone(eMenu_OPT4))
			{
				if (gInterface.Data[eMenu_OPT4].OnClick)
					gInterface.DrawButton(eMenu_OPT4, StartX + 64, BtStart, 0, 58);
				else
					gInterface.DrawButton(eMenu_OPT4, StartX + 64, BtStart, 0, 29);
				// ----
			}
			else
				gInterface.DrawButton(eMenu_OPT4, StartX + 64, BtStart, 0, 0);

			gInterface.DrawFormat(eWhite, (int)StartX + 64, BtStart + 9, 108, 3, gCustomMessage.GetMessage(28));
		}

		if (gProtect.m_MainInfo.EnableOptionButton == 1)
		{
			//Opções
			BtStart += BtDistance;

			if (gInterface.IsWorkZone(eMenu_OPT20))
			{
				if (gInterface.Data[eMenu_OPT20].OnClick)
					gInterface.DrawButton(eMenu_OPT20, StartX + 64, BtStart, 0, 58);
				else
					gInterface.DrawButton(eMenu_OPT20, StartX + 64, BtStart, 0, 29);
				// ----
			}
			else
				gInterface.DrawButton(eMenu_OPT20, StartX + 64, BtStart, 0, 0);

			gInterface.DrawFormat(eWhite, (int)StartX + 64, BtStart + 9, 108, 3, gCustomMessage.GetMessage(44));
		}
	}
	//Season 8
	else
	{
		if (gProtect.m_MainInfo.CustomMenuSwitch != 1 || !gInterface.Data[eADDPOINT5_MAIN].OnShow || pCheckWindow(pWindowThis(), 35))
		{
			return;
		}

		float MainWidth = 230.0;
		float MainHeight = 270.0;
		float StartY = ((MAX_WIN_HEIGHT - 51) / 2) - (MainHeight / 2);
		float StartX = (MAX_WIN_WIDTH / 2) - (MainWidth / 2);
		float MainCenter = StartX + (MainWidth / 3);
		float ButtonX = MainCenter - (float)(29.0 / 2);
		//--
		gInterface.Data[eADDPOINT5_MAIN].MaxX = StartX + MainWidth;
		gInterface.Data[eADDPOINT5_MAIN].MaxY = StartY + MainHeight;

		gCentral.PrintDropBox(StartX, StartY, MainWidth, MainHeight, 0, 0);

		gInterface.DrawFormat(eGold, (int)StartX + 10, (int)StartY + 10, 210, 3, "Menu");

		if (gProtect.m_MainInfo.EnableCoinStatus == 1)
		{
			gInterface.DrawFormat(eGold, (int)StartX + 10, (int)StartY + 35, 210, 3, gCustomMessage.GetMessage(50));

			gInterface.DrawFormat(eWhite, (int)StartX + 25, (int)StartY + 55, 40, 1, gCustomMessage.GetMessage(51));
			gInterface.DrawFormat(eGold, (int)StartX + 50, (int)StartY + 55, 40, 1, "%d", Coin1);

			gInterface.DrawFormat(eWhite, (int)StartX + 90, (int)StartY + 55, 40, 1, gCustomMessage.GetMessage(52));
			gInterface.DrawFormat(eGold, (int)StartX + 115, (int)StartY + 55, 40, 1, "%d", Coin2);

			gInterface.DrawFormat(eWhite, (int)StartX + 153, (int)StartY + 55, 40, 1, gCustomMessage.GetMessage(53));
			gInterface.DrawFormat(eGold, (int)StartX + 176, (int)StartY + 55, 40, 1, "%d", Coin3);
		}
		else
		{
			gInterface.DrawFormat(eGold, (int)StartX + 10, (int)StartY + 45, 210, 3, gCustomMessage.GetMessage(54));
		}

		pDrawGUI(71520, StartX + (MainWidth / 2) - (200 / 2), StartY + 75, 200, 1); //-- Divisor

		float CurrentMove;
		int BtCount = -1;
		int BtStart = StartY + 88;

		int ObjectIDs[4] =
		{
			eMenu_OPT1,
			eMenu_OPT2,
			eMenu_OPT3,
			eMenu_OPT4,
		};

		for (int n = 0; n < 4; n++)
		{
			BtCount++;

			CurrentMove = 0.0;
			if (gInterface.IsWorkZone(ObjectIDs[n]))
			{
				if (gInterface.Data[ObjectIDs[n]].OnClick)
				{
					PlayBuffer(25, 0, 0);
					CurrentMove = 30.5f;
				}
			}
			gInterface.DrawButton(ObjectIDs[n], StartX + (MainWidth / 2) - (108 / 2), BtStart + (33.0f * BtCount), 0, CurrentMove);
			gInterface.DrawFormat(eWhite, StartX + (MainWidth / 2) - (108 / 2), BtStart + (33.0f * BtCount) + 9, 108, 3,
				gCustomMessage.GetMessage((n == 4) ? 44 : 25 + n));
		}

		pDrawGUI(71520, StartX + (MainWidth / 2) - (200 / 2), StartY + MainHeight - 40, 200, 1); //-- Divisor

		if (gInterface.IsWorkZone(eMenu_CLOSE))
		{
			if (gInterface.Data[eMenu_CLOSE].OnClick)
			{
				PlayBuffer(25, 0, 0);
				gInterface.DrawButtonRender(eMenu_CLOSE, StartX + (MainWidth / 2) - (59 / 2), StartY + MainHeight - 32, 0, 28);
			}
			else
			{
				gInterface.DrawButtonRender(eMenu_CLOSE, StartX + (MainWidth / 2) - (59 / 2), StartY + MainHeight - 32, 0, 0);
			}
		}
		else
		{
			gInterface.DrawButtonRender(eMenu_CLOSE, StartX + (MainWidth / 2) - (59 / 2), StartY + MainHeight - 32, 0, 0);
		}
		gInterface.DrawFormat(eWhite, StartX + (MainWidth / 2) - (59 / 2), StartY + MainHeight - 25, 59, 3, "Close");
	}
}

bool cCustomMenu::EventMenuCustomWindow_Close(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - gInterface.Data[eADDPOINT5_CLOSE].EventTick);
	// ----
	if (!gInterface.Data[eADDPOINT5_MAIN].OnShow || !gInterface.IsWorkZone(eADDPOINT5_CLOSE))
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		gInterface.Data[eADDPOINT5_CLOSE].OnClick = true;
		return true;
	}
	// ----
	gInterface.Data[eADDPOINT5_CLOSE].OnClick = false;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	// ----
	gInterface.Data[eADDPOINT5_CLOSE].EventTick = GetTickCount();
	this->CloseTestWindow();
	// ----
	return false;
}
// ----------------------------------------------------------------------------------------------