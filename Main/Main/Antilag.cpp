#include "stdafx.h"
#include "Antilag.h"
#include "User.h"
#include "Interface.h"
#include "User.h"
#include "Protocol.h"
#include "TMemory.h"
#include "Defines.h"
#include "Common.h"
#include "Util.h"
#include "Performance.h"
#include "WingInvisible.h"
#include "Protect.h"
#include "Central.h"

cAntiLagSystem gAntiLagSystem;

cAntiLagSystem::cAntiLagSystem()
{
	this->Init();
}

cAntiLagSystem::~cAntiLagSystem()
{
}

void cAntiLagSystem::Init()
{
	this->Click = false;
}

void cAntiLagSystem::Load()
{

}

void cAntiLagSystem::BindImage()
{
	gInterface.BindObject(eADDPOINT_MAIN, 0x7A5A, 222, 290, -1, -1);
	gInterface.BindObject(eADDPOINT_TITLE, 0x7A63, 230, 67, -1, -1);
	gInterface.BindObject(eADDPOINT_FRAME, 0x7A58, 230, 15, -1, -1);
	gInterface.BindObject(eADDPOINT_FOOTER, 0x7A59, 230, 50, -1, -1);
	gInterface.BindObject(eADDPOINT_DIV, 0x7A62, 223, 21, -1, -1);
	gInterface.BindObject(eADDPOINT_CLOSE, 71555, 19, 19, -1, -1);
	
	//op new menu -> Button

	gInterface.BindObject(eUSERSPANEL_FOG, 0x9991, 15, 15, -1, -1);
	gInterface.BindObject(eUSERSPANEL_MINIMAP, 0x9991, 15, 15, -1, -1);
	gInterface.BindObject(eUSERSPANEL_TIME, 0x9991, 15, 15, -1, -1);
	gInterface.BindObject(eUSERSPANEL_GLOW, 0x9991, 15, 15, -1, -1);
	gInterface.BindObject(eUSERSPANEL_FPS, 0x9991, 15, 15, -1, -1);
	gInterface.BindObject(eUSERSPANEL_CHAT, 0x9991, 15, 15, -1, -1);
	gInterface.BindObject(eUSERSPANEL_DRAGON, 0x9991, 15, 15, -1, -1);
	gInterface.BindObject(eUSERSPANEL_INVIS1, 0x9991, 15, 15, -1, -1);
	gInterface.BindObject(eUSERSPANEL_INVIS2, 0x9991, 15, 15, -1, -1);
	gInterface.BindObject(eUSERSPANEL_INVIS3, 0x9991, 15, 15, -1, -1);
	gInterface.BindObject(eUSERSPANEL_INVIS4, 0x9991, 15, 15, -1, -1);
	gInterface.BindObject(eUSERSPANEL_INVIS5, 0x9991, 15, 15, -1, -1);
	gInterface.BindObject(eUSERSPANEL_INVIS6, 0x9991, 15, 15, -1, -1);
	gInterface.BindObject(eUSERSPANEL_INVIS7, 0x9991, 15, 15, -1, -1);
	gInterface.BindObject(eCheck, 0x9991, 15, 15, -1, -1);
	gInterface.BindObject(eUnCheck, 0x9992, 15, 15, -1, -1);
}

void cAntiLagSystem::Draw()
{
	if (gProtect.m_MainInfo.CustomInterfaceType != 3)
	{
		if (!gInterface.Data[eADDPOINT_MAIN].OnShow)
		{
			return;
		}

		pSetCursorFocus = true;

		float MainWidth, MainHeight;
		MainWidth = 230.0;
		MainHeight = 283.0;
		float StartBody = 30.0;
		float StartY = 60;
		float StartX = (MAX_WIN_WIDTH / 2) - (MainWidth / 2);
		float MainCenter = StartX + (MainWidth / 3);
		float ButtonX = MainCenter - (float)(29.0 / 2);

		gInterface.DrawWindow(eADDPOINT_MAIN, eADDPOINT_TITLE, eADDPOINT_FRAME, eADDPOINT_FOOTER, 14, StartX, StartY, "Painel AntiLag");

		gInterface.DrawGUI(eADDPOINT_CLOSE, StartX + MainWidth - gInterface.Data[eADDPOINT_CLOSE].Width - 7.0, StartBody + 44);

		if (gInterface.IsWorkZone(eADDPOINT_CLOSE))
		{
			DWORD Color = eGray100;

			if (gInterface.Data[eADDPOINT_CLOSE].OnClick)
			{
				Color = eGray150;
			}

			gInterface.DrawColoredGUI(eADDPOINT_CLOSE, gInterface.Data[eADDPOINT_CLOSE].X, gInterface.Data[eADDPOINT_CLOSE].Y, Color);
			gInterface.DrawToolTip((int)gInterface.Data[eADDPOINT_CLOSE].X + 5, gInterface.Data[eADDPOINT_CLOSE].Y + 25, "Close");
		}

		float opLine, opStart, opSO, opTxt, CustomY;
		opSO = ButtonX + 110;
		opStart = StartX + 35;
		opLine = StartX + 35;
		opTxt = StartX + 50;
		CustomY = -23; //Y CUSTOM PARA TODOS!
		// ---- Inicio Glow

		gInterface.DrawGUI(eUSERSPANEL_GLOW, opSO, gInterface.Data[eADDPOINT_MAIN].Y + 62 + CustomY);
		gInterface.DrawGUI(eUSERSPANEL_OPTION, opStart, gInterface.Data[eADDPOINT_MAIN].Y + 63 + CustomY);
		gInterface.DrawGUI(eUSERSPANEL_LINE, opLine, gInterface.Data[eADDPOINT_MAIN].Y + 80 + CustomY);
		gInterface.DrawFormat(eAncient, opTxt, gInterface.Data[eADDPOINT_MAIN].Y + 65 + CustomY, +125, 1, "Glow Effect");
		{
			if (DisableGlowEffect == 1)
			{
			}
			else
			{
				gInterface.DrawGUI(eUnCheck, opSO, gInterface.Data[eADDPOINT_MAIN].Y + 62 + CustomY);
			}
		}
		// ---- Fin Glow
		// ---- Inicio MiniMap
		gInterface.DrawGUI(eUSERSPANEL_MINIMAP, opSO, gInterface.Data[eADDPOINT_MAIN].Y + 82 + CustomY);
		gInterface.DrawGUI(eUSERSPANEL_OPTION, opStart, gInterface.Data[eADDPOINT_MAIN].Y + 83 + CustomY);
		gInterface.DrawGUI(eUSERSPANEL_LINE, opLine, gInterface.Data[eADDPOINT_MAIN].Y + 100 + CustomY);
		gInterface.DrawFormat(eAncient, opTxt, gInterface.Data[eADDPOINT_MAIN].Y + 85 + CustomY, +125, 1, "Effect Dynamic");
		{
			if (testFunctionInvItem3 == 1)
			{
			}
			else
			{
				gInterface.DrawGUI(eUnCheck, opSO, gInterface.Data[eADDPOINT_MAIN].Y + 82 + CustomY);
			}
		}
		// ---- Inicio static
		gInterface.DrawGUI(eUSERSPANEL_FPS, opSO, gInterface.Data[eADDPOINT_MAIN].Y + 102 + CustomY);
		gInterface.DrawGUI(eUSERSPANEL_OPTION, opStart, gInterface.Data[eADDPOINT_MAIN].Y + 103 + CustomY);
		gInterface.DrawGUI(eUSERSPANEL_LINE, opLine, gInterface.Data[eADDPOINT_MAIN].Y + 120 + CustomY);
		gInterface.DrawFormat(eAncient, opTxt, gInterface.Data[eADDPOINT_MAIN].Y + 105 + CustomY, +125, 1, "Effect Static");
		{
			if (testFunctionInvItem4 == 1)
			{
			}
			else
			{
				gInterface.DrawGUI(eUnCheck, opSO, gInterface.Data[eADDPOINT_MAIN].Y + 102 + CustomY);
			}
		}
		// ---- Fin MiniMap
		// ---- Inicio Time
		gInterface.DrawGUI(eUSERSPANEL_TIME, opSO, gInterface.Data[eADDPOINT_MAIN].Y + 122 + CustomY);
		gInterface.DrawGUI(eUSERSPANEL_OPTION, opStart, gInterface.Data[eADDPOINT_MAIN].Y + 123 + CustomY);
		gInterface.DrawGUI(eUSERSPANEL_LINE, opLine, gInterface.Data[eADDPOINT_MAIN].Y + 140 + CustomY);
		gInterface.DrawFormat(eAncient, opTxt, gInterface.Data[eADDPOINT_MAIN].Y + 125 + CustomY, +125, 1, "Invisibility");
		{
			if (testFunctionInvItem2 == 1)
			{
			}
			else
			{
				gInterface.DrawGUI(eUnCheck, opSO, gInterface.Data[eADDPOINT_MAIN].Y + 122 + CustomY);
			}
		}
		// ---- Inicio Remove Wings (PEGUEI DO FPS
		gInterface.DrawGUI(eUSERSPANEL_INVIS1, opSO, gInterface.Data[eADDPOINT_MAIN].Y + 142 + CustomY);
		gInterface.DrawGUI(eUSERSPANEL_OPTION, opStart, gInterface.Data[eADDPOINT_MAIN].Y + 143 + CustomY);
		gInterface.DrawGUI(eUSERSPANEL_LINE, opLine, gInterface.Data[eADDPOINT_MAIN].Y + 160 + CustomY);
		gInterface.DrawFormat(eAncient, opTxt, gInterface.Data[eADDPOINT_MAIN].Y + 145 + CustomY, +125, 1, "Invisibility Wings");
		{
			if (testFunctionInvItem5 == 1)
			{
			}
			else
			{
				gInterface.DrawGUI(eUnCheck, opSO, gInterface.Data[eADDPOINT_MAIN].Y + 142 + CustomY);
			}
		}
		// ---- Inicio RemoveObjects
		gInterface.DrawGUI(eUSERSPANEL_INVIS2, opSO, gInterface.Data[eADDPOINT_MAIN].Y + 162 + CustomY);
		gInterface.DrawGUI(eUSERSPANEL_OPTION, opStart, gInterface.Data[eADDPOINT_MAIN].Y + 163 + CustomY);
		gInterface.DrawGUI(eUSERSPANEL_LINE, opLine, gInterface.Data[eADDPOINT_MAIN].Y + 180 + CustomY);
		gInterface.DrawFormat(eAncient, opTxt, gInterface.Data[eADDPOINT_MAIN].Y + 165 + CustomY, +125, 1, "Invisibility Weapons");
		{
			if (testFunctionInvItem6 == 1)
			{
			}
			else
			{
				gInterface.DrawGUI(eUnCheck, opSO, gInterface.Data[eADDPOINT_MAIN].Y + 162 + CustomY);
			}
		}
		// ---- Inicio RemoveObjects
		gInterface.DrawGUI(eUSERSPANEL_DRAGON, opSO, gInterface.Data[eADDPOINT_MAIN].Y + 182 + CustomY);
		gInterface.DrawGUI(eUSERSPANEL_OPTION, opStart, gInterface.Data[eADDPOINT_MAIN].Y + 183 + CustomY);
		gInterface.DrawGUI(eUSERSPANEL_LINE, opLine, gInterface.Data[eADDPOINT_MAIN].Y + 200 + CustomY);
		gInterface.DrawFormat(eAncient, opTxt, gInterface.Data[eADDPOINT_MAIN].Y + 185 + CustomY, +125, 1, "Transparency");
		{
			if (testFunctionInvItem == 1)
			{
			}
			else
			{
				gInterface.DrawGUI(eUnCheck, opSO, gInterface.Data[eADDPOINT_MAIN].Y + 182 + CustomY);
			}
		}
		// ---- Fin RemoveObjects
		// ---- Inicio RemoveObjects
		gInterface.DrawGUI(eUSERSPANEL_INVIS3, opSO, gInterface.Data[eADDPOINT_MAIN].Y + 202 + CustomY);
		gInterface.DrawGUI(eUSERSPANEL_OPTION, opStart, gInterface.Data[eADDPOINT_MAIN].Y + 203 + CustomY);
		gInterface.DrawGUI(eUSERSPANEL_LINE, opLine, gInterface.Data[eADDPOINT_MAIN].Y + 220 + CustomY);
		gInterface.DrawFormat(eAncient, opTxt, gInterface.Data[eADDPOINT_MAIN].Y + 205 + CustomY, +125, 1, "Effect +15");
		{
			if (testFunctionInvItem7 == 1)
			{
			}
			else
			{
				gInterface.DrawGUI(eUnCheck, opSO, gInterface.Data[eADDPOINT_MAIN].Y + 202 + CustomY);
			}
		}
		// ---- Fin RemoveObjects

		// ---- Fin RemoveObjects
		// ---- Inicio RemoveObjects
		gInterface.DrawGUI(eUSERSPANEL_INVIS4, opSO, gInterface.Data[eADDPOINT_MAIN].Y + 222 + CustomY);
		gInterface.DrawGUI(eUSERSPANEL_OPTION, opStart, gInterface.Data[eADDPOINT_MAIN].Y + 223 + CustomY);
		gInterface.DrawGUI(eUSERSPANEL_LINE, opLine, gInterface.Data[eADDPOINT_MAIN].Y + 240 + CustomY);
		gInterface.DrawFormat(eAncient, opTxt, gInterface.Data[eADDPOINT_MAIN].Y + 225 + CustomY, +125, 1, "Objects Render");
		{
			if (testFunctionInvItem8 == 1)
			{
			}
			else
			{
				gInterface.DrawGUI(eUnCheck, opSO, gInterface.Data[eADDPOINT_MAIN].Y + 222 + CustomY);
			}
		}
		// ---- Inicio Remove Excellent
		gInterface.DrawGUI(eUSERSPANEL_INVIS5, opSO, gInterface.Data[eADDPOINT_MAIN].Y + 242 + CustomY);
		gInterface.DrawGUI(eUSERSPANEL_OPTION, opStart, gInterface.Data[eADDPOINT_MAIN].Y + 243 + CustomY);
		gInterface.DrawGUI(eUSERSPANEL_LINE, opLine, gInterface.Data[eADDPOINT_MAIN].Y + 260 + CustomY);
		gInterface.DrawFormat(eAncient, opTxt, gInterface.Data[eADDPOINT_MAIN].Y + 245 + CustomY, +125, 1, "Terrain Render");
		{
			if (testFunctionInvItem9 == 1)
			{
			}
			else
			{
				gInterface.DrawGUI(eUnCheck, opSO, gInterface.Data[eADDPOINT_MAIN].Y + 242 + CustomY);
			}
		}
		// ---- Fin RemoveObjects	
		// ---- Inicio Remove Level Item
		gInterface.DrawGUI(eUSERSPANEL_INVIS6, opSO, gInterface.Data[eADDPOINT_MAIN].Y + 262 + CustomY);
		gInterface.DrawGUI(eUSERSPANEL_OPTION, opStart, gInterface.Data[eADDPOINT_MAIN].Y + 263 + CustomY);
		gInterface.DrawGUI(eUSERSPANEL_LINE, opLine, gInterface.Data[eADDPOINT_MAIN].Y + 280 + CustomY);
		gInterface.DrawFormat(eAncient, opTxt, gInterface.Data[eADDPOINT_MAIN].Y + 265 + CustomY, +125, 1, "Excellent Effect");
		{
			if (testFunctionInvItem10 == 1)
			{
			}
			else
			{
				gInterface.DrawGUI(eUnCheck, opSO, gInterface.Data[eADDPOINT_MAIN].Y + 262 + CustomY);
			}
		}
		// ---- Fin RemoveObjects	
		// ---- Inicio Remove Level Item
		gInterface.DrawGUI(eUSERSPANEL_INVIS7, opSO, gInterface.Data[eADDPOINT_MAIN].Y + 282 + CustomY);
		gInterface.DrawGUI(eUSERSPANEL_OPTION, opStart, gInterface.Data[eADDPOINT_MAIN].Y + 283 + CustomY);
		gInterface.DrawGUI(eUSERSPANEL_LINE, opLine, gInterface.Data[eADDPOINT_MAIN].Y + 300 + CustomY);
		gInterface.DrawFormat(eAncient, opTxt, gInterface.Data[eADDPOINT_MAIN].Y + 285 + CustomY, +125, 1, "Reduce Zen Drop");
		{
			if (testFunctionInvItem11 == 1)
			{
			}
			else
			{
				gInterface.DrawGUI(eUnCheck, opSO, gInterface.Data[eADDPOINT_MAIN].Y + 282 + CustomY);
			}
		}
	}
	else
	{
		if (!gInterface.Data[eADDPOINT_MAIN].OnShow) 
		{
			return;
		}
		if (gInterface.CheckWindow(ObjWindow::MoveList) || gInterface.CheckWindow(ObjWindow::CashShop) || gInterface.CheckWindow(ObjWindow::SkillTree) || gInterface.CheckWindow(ObjWindow::FullMap) || (gInterface.CheckWindow(Inventory) && gInterface.CheckWindow(ExpandInventory) && gInterface.CheckWindow(Store)) || (gInterface.CheckWindow(Inventory) && gInterface.CheckWindow(Warehouse) && gInterface.CheckWindow(ExpandWarehouse))) {
			this->CloseTestWindow();
			return;
		}
		// ----
		pSetCursorFocus = true;
		float MainWidth = 230.0;
		float MainHeight = 320.0;
		float StartBody = ((MAX_WIN_HEIGHT - 51) / 2) - (MainHeight / 2);
		float StartY = ((MAX_WIN_HEIGHT - 51) / 2) - (MainHeight / 2);
		float StartX = (MAX_WIN_WIDTH / 2) - (MainWidth / 2);
		float MainCenter = StartX + (MainWidth / 3);
		float ButtonX = MainCenter - (float)(29.0 / 2);
		// ----
		DWORD Color = eGray100;

		gCentral.PrintDropBox(StartX, StartY, MainWidth, MainHeight, 0, 0);
		// ----
		gInterface.DrawFormat(eGold, (int)StartX + 10, (int)StartBody + 10, 210, 3, "Painel AntiLag");

		//
		pDrawGUI(71520, StartX + (MainWidth / 2) - (200 / 2), StartBody + 35, 200, 1); //-- Divisor

		float opLine, opStart, opSO, opTxt, CustomY;
		opSO = ButtonX + 110;
		opStart = StartX + 35;
		opLine = StartX + 35;
		opTxt = StartX + 50;
		CustomY = 40; //Y CUSTOM PARA TODOS!
		// ---- Inicio Glow

		gInterface.DrawGUI(eUSERSPANEL_GLOW, opSO, gInterface.Data[eADDPOINT_MAIN].Y + 62 + CustomY);
		gInterface.DrawGUI(eUSERSPANEL_OPTION, opStart, gInterface.Data[eADDPOINT_MAIN].Y + 63 + CustomY);
		gInterface.DrawGUI(eUSERSPANEL_LINE, opLine, gInterface.Data[eADDPOINT_MAIN].Y + 80 + CustomY);
		gInterface.DrawFormat(eAncient, opTxt, gInterface.Data[eADDPOINT_MAIN].Y + 65 + CustomY, +125, 1, "Glow Effect");
		{
			if (DisableGlowEffect == 1)
			{
			}
			else
			{
				gInterface.DrawGUI(eUnCheck, opSO, gInterface.Data[eADDPOINT_MAIN].Y + 62 + CustomY);
			}
		}
		// ---- Fin Glow
		// ---- Inicio MiniMap
		gInterface.DrawGUI(eUSERSPANEL_MINIMAP, opSO, gInterface.Data[eADDPOINT_MAIN].Y + 82 + CustomY);
		gInterface.DrawGUI(eUSERSPANEL_OPTION, opStart, gInterface.Data[eADDPOINT_MAIN].Y + 83 + CustomY);
		gInterface.DrawGUI(eUSERSPANEL_LINE, opLine, gInterface.Data[eADDPOINT_MAIN].Y + 100 + CustomY);
		gInterface.DrawFormat(eAncient, opTxt, gInterface.Data[eADDPOINT_MAIN].Y + 85 + CustomY, +125, 1, "Effect Dynamic");
		{
			if (testFunctionInvItem3 == 1)
			{
			}
			else
			{
				gInterface.DrawGUI(eUnCheck, opSO, gInterface.Data[eADDPOINT_MAIN].Y + 82 + CustomY);
			}
		}
		// ---- Inicio static
		gInterface.DrawGUI(eUSERSPANEL_FPS, opSO, gInterface.Data[eADDPOINT_MAIN].Y + 102 + CustomY);
		gInterface.DrawGUI(eUSERSPANEL_OPTION, opStart, gInterface.Data[eADDPOINT_MAIN].Y + 103 + CustomY);
		gInterface.DrawGUI(eUSERSPANEL_LINE, opLine, gInterface.Data[eADDPOINT_MAIN].Y + 120 + CustomY);
		gInterface.DrawFormat(eAncient, opTxt, gInterface.Data[eADDPOINT_MAIN].Y + 105 + CustomY, +125, 1, "Effect Static");
		{
			if (testFunctionInvItem4 == 1)
			{
			}
			else
			{
				gInterface.DrawGUI(eUnCheck, opSO, gInterface.Data[eADDPOINT_MAIN].Y + 102 + CustomY);
			}
		}
		// ---- Fin MiniMap
		// ---- Inicio Time
		gInterface.DrawGUI(eUSERSPANEL_TIME, opSO, gInterface.Data[eADDPOINT_MAIN].Y + 122 + CustomY);
		gInterface.DrawGUI(eUSERSPANEL_OPTION, opStart, gInterface.Data[eADDPOINT_MAIN].Y + 123 + CustomY);
		gInterface.DrawGUI(eUSERSPANEL_LINE, opLine, gInterface.Data[eADDPOINT_MAIN].Y + 140 + CustomY);
		gInterface.DrawFormat(eAncient, opTxt, gInterface.Data[eADDPOINT_MAIN].Y + 125 + CustomY, +125, 1, "Invisibility");
		{
			if (testFunctionInvItem2 == 1)
			{
			}
			else
			{
				gInterface.DrawGUI(eUnCheck, opSO, gInterface.Data[eADDPOINT_MAIN].Y + 122 + CustomY);
			}
		}
		// ---- Inicio Remove Wings (PEGUEI DO FPS
		gInterface.DrawGUI(eUSERSPANEL_INVIS1, opSO, gInterface.Data[eADDPOINT_MAIN].Y + 142 + CustomY);
		gInterface.DrawGUI(eUSERSPANEL_OPTION, opStart, gInterface.Data[eADDPOINT_MAIN].Y + 143 + CustomY);
		gInterface.DrawGUI(eUSERSPANEL_LINE, opLine, gInterface.Data[eADDPOINT_MAIN].Y + 160 + CustomY);
		gInterface.DrawFormat(eAncient, opTxt, gInterface.Data[eADDPOINT_MAIN].Y + 145 + CustomY, +125, 1, "Invisibility Wings");
		{
			if (testFunctionInvItem5 == 1)
			{
			}
			else
			{
				gInterface.DrawGUI(eUnCheck, opSO, gInterface.Data[eADDPOINT_MAIN].Y + 142 + CustomY);
			}
		}
		// ---- Inicio RemoveObjects
		gInterface.DrawGUI(eUSERSPANEL_INVIS2, opSO, gInterface.Data[eADDPOINT_MAIN].Y + 162 + CustomY);
		gInterface.DrawGUI(eUSERSPANEL_OPTION, opStart, gInterface.Data[eADDPOINT_MAIN].Y + 163 + CustomY);
		gInterface.DrawGUI(eUSERSPANEL_LINE, opLine, gInterface.Data[eADDPOINT_MAIN].Y + 180 + CustomY);
		gInterface.DrawFormat(eAncient, opTxt, gInterface.Data[eADDPOINT_MAIN].Y + 165 + CustomY, +125, 1, "Invisibility Weapons");
		{
			if (testFunctionInvItem6 == 1)
			{
			}
			else
			{
				gInterface.DrawGUI(eUnCheck, opSO, gInterface.Data[eADDPOINT_MAIN].Y + 162 + CustomY);
			}
		}
		// ---- Inicio RemoveObjects
		gInterface.DrawGUI(eUSERSPANEL_DRAGON, opSO, gInterface.Data[eADDPOINT_MAIN].Y + 182 + CustomY);
		gInterface.DrawGUI(eUSERSPANEL_OPTION, opStart, gInterface.Data[eADDPOINT_MAIN].Y + 183 + CustomY);
		gInterface.DrawGUI(eUSERSPANEL_LINE, opLine, gInterface.Data[eADDPOINT_MAIN].Y + 200 + CustomY);
		gInterface.DrawFormat(eAncient, opTxt, gInterface.Data[eADDPOINT_MAIN].Y + 185 + CustomY, +125, 1, "Transparency");
		{
			if (testFunctionInvItem == 1)
			{
			}
			else
			{
				gInterface.DrawGUI(eUnCheck, opSO, gInterface.Data[eADDPOINT_MAIN].Y + 182 + CustomY);
			}
		}
		// ---- Fin RemoveObjects
		// ---- Inicio RemoveObjects
		gInterface.DrawGUI(eUSERSPANEL_INVIS3, opSO, gInterface.Data[eADDPOINT_MAIN].Y + 202 + CustomY);
		gInterface.DrawGUI(eUSERSPANEL_OPTION, opStart, gInterface.Data[eADDPOINT_MAIN].Y + 203 + CustomY);
		gInterface.DrawGUI(eUSERSPANEL_LINE, opLine, gInterface.Data[eADDPOINT_MAIN].Y + 220 + CustomY);
		gInterface.DrawFormat(eAncient, opTxt, gInterface.Data[eADDPOINT_MAIN].Y + 205 + CustomY, +125, 1, "Effect +15");
		{
			if (testFunctionInvItem7 == 1)
			{
			}
			else
			{
				gInterface.DrawGUI(eUnCheck, opSO, gInterface.Data[eADDPOINT_MAIN].Y + 202 + CustomY);
			}
		}
		// ---- Fin RemoveObjects

		// ---- Fin RemoveObjects
		// ---- Inicio RemoveObjects
		gInterface.DrawGUI(eUSERSPANEL_INVIS4, opSO, gInterface.Data[eADDPOINT_MAIN].Y + 222 + CustomY);
		gInterface.DrawGUI(eUSERSPANEL_OPTION, opStart, gInterface.Data[eADDPOINT_MAIN].Y + 223 + CustomY);
		gInterface.DrawGUI(eUSERSPANEL_LINE, opLine, gInterface.Data[eADDPOINT_MAIN].Y + 240 + CustomY);
		gInterface.DrawFormat(eAncient, opTxt, gInterface.Data[eADDPOINT_MAIN].Y + 225 + CustomY, +125, 1, "Objects Render");
		{
			if (testFunctionInvItem8 == 1)
			{
			}
			else
			{
				gInterface.DrawGUI(eUnCheck, opSO, gInterface.Data[eADDPOINT_MAIN].Y + 222 + CustomY);
			}
		}
		// ---- Inicio Remove Excellent
		gInterface.DrawGUI(eUSERSPANEL_INVIS5, opSO, gInterface.Data[eADDPOINT_MAIN].Y + 242 + CustomY);
		gInterface.DrawGUI(eUSERSPANEL_OPTION, opStart, gInterface.Data[eADDPOINT_MAIN].Y + 243 + CustomY);
		gInterface.DrawGUI(eUSERSPANEL_LINE, opLine, gInterface.Data[eADDPOINT_MAIN].Y + 260 + CustomY);
		gInterface.DrawFormat(eAncient, opTxt, gInterface.Data[eADDPOINT_MAIN].Y + 245 + CustomY, +125, 1, "Terrain Render");
		{
			if (testFunctionInvItem9 == 1)
			{
			}
			else
			{
				gInterface.DrawGUI(eUnCheck, opSO, gInterface.Data[eADDPOINT_MAIN].Y + 242 + CustomY);
			}
		}
		// ---- Fin RemoveObjects	
		// ---- Inicio Remove Level Item
		gInterface.DrawGUI(eUSERSPANEL_INVIS6, opSO, gInterface.Data[eADDPOINT_MAIN].Y + 262 + CustomY);
		gInterface.DrawGUI(eUSERSPANEL_OPTION, opStart, gInterface.Data[eADDPOINT_MAIN].Y + 263 + CustomY);
		gInterface.DrawGUI(eUSERSPANEL_LINE, opLine, gInterface.Data[eADDPOINT_MAIN].Y + 280 + CustomY);
		gInterface.DrawFormat(eAncient, opTxt, gInterface.Data[eADDPOINT_MAIN].Y + 265 + CustomY, +125, 1, "Excellent Effect");
		{
			if (testFunctionInvItem10 == 1)
			{
			}
			else
			{
				gInterface.DrawGUI(eUnCheck, opSO, gInterface.Data[eADDPOINT_MAIN].Y + 262 + CustomY);
			}
		}
		// ---- Fin RemoveObjects	
		// ---- Inicio Remove Level Item
		gInterface.DrawGUI(eUSERSPANEL_INVIS7, opSO, gInterface.Data[eADDPOINT_MAIN].Y + 282 + CustomY);
		gInterface.DrawGUI(eUSERSPANEL_OPTION, opStart, gInterface.Data[eADDPOINT_MAIN].Y + 283 + CustomY);
		gInterface.DrawGUI(eUSERSPANEL_LINE, opLine, gInterface.Data[eADDPOINT_MAIN].Y + 300 + CustomY);
		gInterface.DrawFormat(eAncient, opTxt, gInterface.Data[eADDPOINT_MAIN].Y + 285 + CustomY, +125, 1, "Reduce Zen Drop");
		{
			if (testFunctionInvItem11 == 1)
			{
			}
			else
			{
				gInterface.DrawGUI(eUnCheck, opSO, gInterface.Data[eADDPOINT_MAIN].Y + 282 + CustomY);
			}
		}
		// ---- Fin RemoveObjects	
	}
	// ---- Fin RemoveObjects	
}
//antilag system
bool cAntiLagSystem::EventUsersPanelAntiLag(DWORD Event)
{
	this->EventUsersPanelAntiLag_GLOW(Event);
	this->EventUsersPanelAntiLag_EFFECTDYNAMIC(Event);
	this->EventUsersPanelAntiLag_TRANSPARENCE(Event);
	this->EventUsersPanelAntiLag_EFFECTSTATIC(Event);
	this->EventUsersPanelAntiLag_INVISIBLY(Event);
	this->EventUsersPanelAntiLag_INVISIBLYWINGS(Event);
	this->EventUsersPanelAntiLag_INVISIBLYWEAPONS(Event);
	this->EventUsersPanelAntiLag_EFFECT15(Event);
	this->EventUsersPanelAntiLag_OBJECTS(Event);
	this->EventUsersPanelAntiLag_EFFECTEXCELLENT1(Event);
	this->EventUsersPanelAntiLag_REMOVELEVELITEM(Event);
	this->EventUsersPanelAntiLag_REMOVEZENDROP(Event);
	this->EventUsersPanelAntiLag_CLOSE(Event);
	return true;
}

bool cAntiLagSystem::EventUsersPanelAntiLag_GLOW(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - gInterface.Data[eUSERSPANEL_GLOW].EventTick);
	// ----
	if (!gInterface.Data[eADDPOINT_MAIN].OnShow || !gInterface.IsWorkZone(eUSERSPANEL_GLOW))
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		gInterface.Data[eUSERSPANEL_GLOW].OnClick = true;
		pSetCursorFocus = true;
		return true;
	}
	// ----
	gInterface.Data[eUSERSPANEL_GLOW].OnClick = false;
	pSetCursorFocus = true;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	// ----
	gInterface.Data[eUSERSPANEL_GLOW].EventTick = GetTickCount();
	if (DisableGlowEffect != 0)
	{
		DisableGlowEffect = 0;
	}
	else
	{
		DisableGlowEffect = 1;
	}
	return true;
}

bool cAntiLagSystem::EventUsersPanelAntiLag_TRANSPARENCE(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - gInterface.Data[eUSERSPANEL_DRAGON].EventTick);
	// ----
	if (!gInterface.Data[eADDPOINT_MAIN].OnShow || !gInterface.IsWorkZone(eUSERSPANEL_DRAGON))
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		gInterface.Data[eUSERSPANEL_DRAGON].OnClick = true;
		pSetCursorFocus = true;
		return true;
	}
	// ----
	gInterface.Data[eUSERSPANEL_DRAGON].OnClick = false;
	pSetCursorFocus = true;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	// ----
	gInterface.Data[eUSERSPANEL_DRAGON].EventTick = GetTickCount();
	if (testFunctionInvItem != 0)
	{
		testFunctionInvItem = 0;
		InvisibleItem2();
		InvisibleItemX();
	}
	else
	{
		InvisibleItem1();
		testFunctionInvItem = 1;
	}
	return true;
}

bool cAntiLagSystem::EventUsersPanelAntiLag_INVISIBLY(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - gInterface.Data[eUSERSPANEL_TIME].EventTick);
	// ----
	if (!gInterface.Data[eADDPOINT_MAIN].OnShow || !gInterface.IsWorkZone(eUSERSPANEL_TIME))
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		gInterface.Data[eUSERSPANEL_TIME].OnClick = true;
		pSetCursorFocus = true;
		return true;
	}
	// ----
	gInterface.Data[eUSERSPANEL_TIME].OnClick = false;
	pSetCursorFocus = true;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	// ----
	gInterface.Data[eUSERSPANEL_TIME].EventTick = GetTickCount();
	if (testFunctionInvItem2 != 0)
	{
		testFunctionInvItem2 = 0;
		DelectlpViewPlayerOff_Hook();
	}
	else
	{
		DelectlpViewPlayerOn_Hook();
		testFunctionInvItem2 = 1;
	}
	return true;
}

bool cAntiLagSystem::EventUsersPanelAntiLag_EFFECTDYNAMIC(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - gInterface.Data[eUSERSPANEL_MINIMAP].EventTick);
	// ----
	if (!gInterface.Data[eADDPOINT_MAIN].OnShow || !gInterface.IsWorkZone(eUSERSPANEL_MINIMAP))
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		gInterface.Data[eUSERSPANEL_MINIMAP].OnClick = true;
		pSetCursorFocus = true;
		return true;
	}
	// ----
	gInterface.Data[eUSERSPANEL_MINIMAP].OnClick = false;
	pSetCursorFocus = true;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	// ----
	gInterface.Data[eUSERSPANEL_MINIMAP].EventTick = GetTickCount();
	if (testFunctionInvItem3 != 0)
	{
		testFunctionInvItem3 = 0;
		SetByte(0x74CD30, 0xC3);
		SetByte(0x00608FB0, 0xC3); //Disable Skill Effects
		SetDword((0x0072D1BA + 3), 0);
	}
	else
	{
		SetByte(0x74CD30, 0x55);
		SetByte(0x00608FB0, 0x55); //Disable Skill Effects
		SetDword((0x0072D1BA + 3), 500);
		testFunctionInvItem3 = 1;
	}
	return true;
}

bool cAntiLagSystem::EventUsersPanelAntiLag_EFFECTSTATIC(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - gInterface.Data[eUSERSPANEL_FPS].EventTick);
	// ----
	if (!gInterface.Data[eADDPOINT_MAIN].OnShow || !gInterface.IsWorkZone(eUSERSPANEL_FPS))
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		gInterface.Data[eUSERSPANEL_FPS].OnClick = true;
		pSetCursorFocus = true;
		return true;
	}
	// ----
	gInterface.Data[eUSERSPANEL_FPS].OnClick = false;
	pSetCursorFocus = true;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	// ----
	gInterface.Data[eUSERSPANEL_FPS].EventTick = GetTickCount();
	if (testFunctionInvItem4 != 0)
	{
		testFunctionInvItem4 = 0;
		SetByte(0x771310, 0x55);
	}
	else
	{
		SetByte(0x771310, 0xC3);
		testFunctionInvItem4 = 1;
	}
	return true;
}


bool cAntiLagSystem::EventUsersPanelAntiLag_INVISIBLYWINGS(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - gInterface.Data[eUSERSPANEL_INVIS1].EventTick);
	// ----
	if (!gInterface.Data[eADDPOINT_MAIN].OnShow || !gInterface.IsWorkZone(eUSERSPANEL_INVIS1))
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		gInterface.Data[eUSERSPANEL_INVIS1].OnClick = true;
		pSetCursorFocus = true;
		return true;
	}
	// ----
	gInterface.Data[eUSERSPANEL_INVIS1].OnClick = false;
	pSetCursorFocus = true;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	// ----
	gInterface.Data[eUSERSPANEL_INVIS1].EventTick = GetTickCount();
	if (testFunctionInvItem5 != 0)
	{
		testFunctionInvItem5 = 0;
		SetOp((LPVOID)0x00588661, (LPVOID)0x005655C0, ASM::CALL);
		SetByte(0x0051EC90, 0x55);
		SetByte(0x0051EE20, 0x55); //Disable Cloaks
	}
	else
	{
		MemorySet(0x588661, 0x90, 0x5);
		SetByte(0x0051EC90, 0xC3);
		SetByte(0x0051EE20, 0xC3); //Disable Cloaks
		testFunctionInvItem5 = 1;
	}
	return true;
}

bool cAntiLagSystem::EventUsersPanelAntiLag_INVISIBLYWEAPONS(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - gInterface.Data[eUSERSPANEL_INVIS2].EventTick);
	// ----
	if (!gInterface.Data[eADDPOINT_MAIN].OnShow || !gInterface.IsWorkZone(eUSERSPANEL_INVIS2))
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		gInterface.Data[eUSERSPANEL_INVIS2].OnClick = true;
		pSetCursorFocus = true;
		return true;
	}
	// ----
	gInterface.Data[eUSERSPANEL_INVIS2].OnClick = false;
	pSetCursorFocus = true;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	// ----
	gInterface.Data[eUSERSPANEL_INVIS2].EventTick = GetTickCount();
	if (testFunctionInvItem6 != 0)
	{
		testFunctionInvItem6 = 0;
		SetOp((LPVOID)0x00576DDB, (LPVOID)0x005655C0, ASM::CALL);
		SetOp((LPVOID)0x005883F4, (LPVOID)0x005655C0, ASM::CALL);
	}
	else
	{
		MemorySet(0x576DDB, 0x90, 0x5);
		MemorySet(0x5883F4, 0x90, 0x5);
		testFunctionInvItem6 = 1;
	}
	return true;
}

bool cAntiLagSystem::EventUsersPanelAntiLag_EFFECT15(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - gInterface.Data[eUSERSPANEL_INVIS3].EventTick);
	// ----
	if (!gInterface.Data[eADDPOINT_MAIN].OnShow || !gInterface.IsWorkZone(eUSERSPANEL_INVIS3))
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		gInterface.Data[eUSERSPANEL_INVIS3].OnClick = true;
		pSetCursorFocus = true;
		return true;
	}
	// ----
	gInterface.Data[eUSERSPANEL_INVIS3].OnClick = false;
	pSetCursorFocus = true;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	// ----
	gInterface.Data[eUSERSPANEL_INVIS3].EventTick = GetTickCount();
	if (testFunctionInvItem7 != 0)
	{
		testFunctionInvItem7 = 0;
		SetOp((LPVOID)0x0057655B, (LPVOID)0x006097B0, ASM::CALL); //original +15
	}
	else
	{

		MemorySet(0x0057655B, 0x90, 0x5); //remove +15
		testFunctionInvItem7 = 1;
	}
	return true;
}

bool cAntiLagSystem::EventUsersPanelAntiLag_OBJECTS(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - gInterface.Data[eUSERSPANEL_INVIS4].EventTick);
	// ----
	if (!gInterface.Data[eADDPOINT_MAIN].OnShow || !gInterface.IsWorkZone(eUSERSPANEL_INVIS4))
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		gInterface.Data[eUSERSPANEL_INVIS4].OnClick = true;
		pSetCursorFocus = true;
		return true;
	}
	// ----
	gInterface.Data[eUSERSPANEL_INVIS4].OnClick = false;
	pSetCursorFocus = true;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	// ----
	gInterface.Data[eUSERSPANEL_INVIS4].EventTick = GetTickCount();
	if (testFunctionInvItem8 != 0)
	{
		testFunctionInvItem8 = 0;
		SetByte((PVOID)(0x005DE2B2), 0); //RESTAURA
	}
	else
	{

		SetByte((PVOID)(0x005DE2B2), 1); //REMOVE OBJETOS
		testFunctionInvItem8 = 1;
	}
	return true;
}

bool cAntiLagSystem::EventUsersPanelAntiLag_EFFECTEXCELLENT1(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - gInterface.Data[eUSERSPANEL_INVIS5].EventTick);
	// ----
	if (!gInterface.Data[eADDPOINT_MAIN].OnShow || !gInterface.IsWorkZone(eUSERSPANEL_INVIS5))
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		gInterface.Data[eUSERSPANEL_INVIS5].OnClick = true;
		pSetCursorFocus = true;
		return true;
	}
	// ----
	gInterface.Data[eUSERSPANEL_INVIS5].OnClick = false;
	pSetCursorFocus = true;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	// ----
	gInterface.Data[eUSERSPANEL_INVIS5].EventTick = GetTickCount();
	if (testFunctionInvItem9 != 0)
	{
		testFunctionInvItem9 = 0;
	}
	else
	{
		testFunctionInvItem9 = 1;
	}
	return true;
}

bool cAntiLagSystem::EventUsersPanelAntiLag_REMOVELEVELITEM(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - gInterface.Data[eUSERSPANEL_INVIS6].EventTick);
	// ----
	if (!gInterface.Data[eADDPOINT_MAIN].OnShow || !gInterface.IsWorkZone(eUSERSPANEL_INVIS6))
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		gInterface.Data[eUSERSPANEL_INVIS6].OnClick = true;
		pSetCursorFocus = true;
		return true;
	}
	// ----
	gInterface.Data[eUSERSPANEL_INVIS6].OnClick = false;
	pSetCursorFocus = true;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	// ----
	gInterface.Data[eUSERSPANEL_INVIS6].EventTick = GetTickCount();
	if (testFunctionInvItem10 != 0)
	{
		testFunctionInvItem10 = 0;

		SetRange(0x0060954D, 7, 0x90);
		SetOp(0x0060954D, (LPVOID)DisableExcellentGlow002_off, 0xE9);

		SetRange(0x0060F04C, 7, 0x90);
		SetOp(0x0060F04C, (LPVOID)DisableExcellentGlow003_off, 0xE9);
	}
	else
	{
		SetRange(0x0060954D, 7, 0x90);
		SetOp(0x0060954D, (LPVOID)DisableExcellentGlow002_on, 0xE9);

		SetRange(0x0060F04C, 7, 0x90); //desativa o efeito excellent
		SetOp(0x0060F04C, (LPVOID)DisableExcellentGlow003_on, 0xE9); //desativa o efeito excellent
		testFunctionInvItem10 = 1;
	}
	return true;
}

bool cAntiLagSystem::EventUsersPanelAntiLag_REMOVEZENDROP(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - gInterface.Data[eUSERSPANEL_INVIS7].EventTick);
	// ----
	if (!gInterface.Data[eADDPOINT_MAIN].OnShow || !gInterface.IsWorkZone(eUSERSPANEL_INVIS7))
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		gInterface.Data[eUSERSPANEL_INVIS7].OnClick = true;
		pSetCursorFocus = true;
		return true;
	}
	// ----
	gInterface.Data[eUSERSPANEL_INVIS7].OnClick = false;
	pSetCursorFocus = true;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	// ----
	gInterface.Data[eUSERSPANEL_INVIS7].EventTick = GetTickCount();
	if (testFunctionInvItem11 != 0)
	{
		testFunctionInvItem11 = 0;
		SetOp((LPVOID)0x005F8924, (LPVOID)0x0095A1E0, ASM::CALL); //Restore Drop Zen
	}
	else
	{
		MemorySet(0x005F8924, 0x90, 0x5); //Reduce Drop Zen
		testFunctionInvItem11 = 1;
	}
	return true;
}

bool cAntiLagSystem::EventUsersPanelAntiLag_CLOSE(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - gInterface.Data[eADDPOINT_CLOSE].EventTick);
	// ----
	if (!gInterface.Data[eADDPOINT_MAIN].OnShow || !gInterface.IsWorkZone(eADDPOINT_CLOSE))
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		gInterface.Data[eADDPOINT_CLOSE].OnClick = true;
		return true;
	}
	// ----
	gInterface.Data[eADDPOINT_CLOSE].OnClick = false;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	// ----
	gInterface.Data[eADDPOINT_CLOSE].EventTick = GetTickCount();
	gInterface.Data[eADDPOINT_MAIN].Close();
	// ----
	return false;
}
