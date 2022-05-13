#include "StdAfx.h"
#include "CustomCommandInfo.h"
#include "Defines.h"
#include "Interface.h"
#include "User.h"
#include "Central.h"
#include "Protect.h"
// -------------------------------------------------------------------------------

CCustomCommandInfo gCustomCommandInfo;
// -------------------------------------------------------------------------------

CCustomCommandInfo::CCustomCommandInfo()
{
	this->Init();
}
// -------------------------------------------------------------------------------

CCustomCommandInfo::~CCustomCommandInfo()
{
	// ----
}
// -------------------------------------------------------------------------------

void CCustomCommandInfo::Init() // OK
{
	for(int n=0;n < MAX_CUSTOM_COMMAND;n++)
	{
		this->m_CustomCommandInfo[n].Index = -1;
	}
	this->Count = 0;
	this->Page = 0;
}

void CCustomCommandInfo::Load(CUSTOM_COMMAND_INFO* info) // OK
{
	for(int n=0;n < MAX_CUSTOM_COMMAND;n++)
	{
		this->SetInfo(info[n]);
	}
}

void CCustomCommandInfo::SetInfo(CUSTOM_COMMAND_INFO info) // OK
{
	if(info.Index < 0 || info.Index >= MAX_CUSTOM_COMMAND)
	{
		return;
	}
	this->Count = info.Index+1;
	this->m_CustomCommandInfo[info.Index] = info;
}

CUSTOM_COMMAND_INFO* CCustomCommandInfo::GetInfo(int index) // OK
{
	if(index < 0 || index >= MAX_CUSTOM_COMMAND)
	{
		return 0;
	}

	if(this->m_CustomCommandInfo[index].Index != index)
	{
		return 0;
	}

	return &this->m_CustomCommandInfo[index];
}

void CCustomCommandInfo::DrawCommandWindow()
{
	if (gProtect.m_MainInfo.CustomInterfaceType != 3)
	{
		if (!gInterface.Data[eCommand_MAIN].OnShow)
		{
			return;
		}

		pSetCursorFocus = true;

		// ----
		float MainWidth = 230.0;
		float MainHeight = 180.0;
		float StartBody = 10.0;
		float StartY = 10.0;
		float StartX = (MAX_WIN_WIDTH / 2) - (MainWidth / 2);
		float MainCenter = StartX + (MainWidth / 3);
		float ButtonX = MainCenter - (float)(29.0 / 2);
		// ----
		gInterface.DrawGUI(eCommand_MAIN, StartX, StartY + (float)2.0);
		gInterface.DrawGUI(eCommand_TITLE, StartX, StartY);
		StartY = gInterface.DrawRepeatGUI(eCommand_FRAME, StartX, StartY + (float)15.0, 16);
		gInterface.DrawGUI(eCommand_FOOTER, StartX, StartY);
		gInterface.DrawGUI(eCommand_CLOSE, StartX + MainWidth - gInterface.Data[eCommand_CLOSE].Width, StartBody);
		// ----
		DWORD Color = eGray100;

		if (gInterface.IsWorkZone(eCommand_CLOSE))
		{

			// ----
			if (gInterface.Data[eCommand_CLOSE].OnClick)
			{
				Color = eGray150;
			}
			// ----
			gInterface.DrawColoredGUI(eCommand_CLOSE, gInterface.Data[eCommand_CLOSE].X, StartBody, Color);
			gInterface.DrawToolTip((int)gInterface.Data[eCommand_CLOSE].X + 5, StartBody + 25, "Close");
		}
		// ----
		gInterface.DrawFormat(eGold, (int)StartX + 10, (int)StartBody + 10, 210, 3, "Commands");

		if ((this->Page == 0 && this->Count > 25) || (this->Page == 1 && this->Count > 50) || (this->Page == 2 && this->Count > 75))
		{
			gInterface.DrawGUI(eNextCommand, StartX + MainWidth - 8, 150);
		}
		else
		{
			gInterface.ResetDrawIMG(eNextCommand);
		}

		if (this->Page == 1 || this->Page == 2 || this->Page == 3)
		{
			gInterface.DrawGUI(ePrevCommand, StartX - 20, 150);
		}
		else
		{
			gInterface.ResetDrawIMG(ePrevCommand);
		}

		for (int i = (25 * Page) + 0; i < (25 * Page) + 25; i++)
		{
			if (this->m_CustomCommandInfo[i].Index == -1)
			{
				continue;
			}

			if (this->m_CustomCommandInfo[i].Color == 1)
			{
				Color = eGold;
			}
			else if (this->m_CustomCommandInfo[i].Color == 2)
			{
				Color = eWhite;
			}
			else if (this->m_CustomCommandInfo[i].Color == 3)
			{
				Color = eOrange;
			}
			else if (this->m_CustomCommandInfo[i].Color == 4)
			{
				Color = eRed2;
			}
			else if (this->m_CustomCommandInfo[i].Color == 5)
			{
				Color = eExcellent;
			}
			else if (this->m_CustomCommandInfo[i].Color == 6)
			{
				Color = eYellow;
			}
			else if (this->m_CustomCommandInfo[i].Color == 7)
			{
				Color = eSocket;
			}
			else
			{
				Color = eGold;
			}

			int x = i;

			if (this->Page > 0)
			{
				x = x - (25 * Page);
			}

			gInterface.DrawFormat(Color, (int)StartX + 18, (int)StartBody + 35 + (x * 10), 100, 1, this->m_CustomCommandInfo[i].Command);

			//gInterface.DrawFormat(Color, (int)StartX + 112, (int)StartBody + 35 + (i*10), 100, 1, this->m_CustomCommandInfo[i].Description);
			pDrawColorText(this->m_CustomCommandInfo[i].Description, (int)StartX + 112, (int)StartBody + 35 + (x * 10), 100, 0, Color, 0, 1);
		}
	}
	else
	{
		if (!gInterface.Data[eCommand_MAIN].OnShow)
		{
			return;
		}

		// ----
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
		gInterface.DrawFormat(eGold, (int)StartX + 10, (int)StartBody + 10, 210, 3, "Commands");

		//
		pDrawGUI(71520, StartX + (MainWidth / 2) - (200 / 2), StartBody + 35, 200, 1); //-- Divisor


		if ((this->Page == 0 && this->Count > 25) || (this->Page == 1 && this->Count > 50) || (this->Page == 2 && this->Count > 75))
		{
			gInterface.DrawGUI(eNextCommand, StartX + MainWidth - 8, StartBody + 80);
		}
		else
		{
			gInterface.ResetDrawIMG(eNextCommand);
		}

		if (this->Page == 1 || this->Page == 2 || this->Page == 3)
		{
			gInterface.DrawGUI(ePrevCommand, StartX - 20, StartBody + 80);
		}
		else
		{
			gInterface.ResetDrawIMG(ePrevCommand);
		}

		for (int i = (25 * Page) + 0; i < (25 * Page) + 25; i++)
		{
			if (this->m_CustomCommandInfo[i].Index == -1)
			{
				continue;
			}

			if (this->m_CustomCommandInfo[i].Color == 1)
			{
				Color = eGold;
			}
			else if (this->m_CustomCommandInfo[i].Color == 2)
			{
				Color = eWhite;
			}
			else if (this->m_CustomCommandInfo[i].Color == 3)
			{
				Color = eOrange;
			}
			else if (this->m_CustomCommandInfo[i].Color == 4)
			{
				Color = eRed2;
			}
			else if (this->m_CustomCommandInfo[i].Color == 5)
			{
				Color = eExcellent;
			}
			else if (this->m_CustomCommandInfo[i].Color == 6)
			{
				Color = eYellow;
			}
			else if (this->m_CustomCommandInfo[i].Color == 7)
			{
				Color = eSocket;
			}
			else
			{
				Color = eGold;
			}

			int x = i;

			if (this->Page > 0)
			{
				x = x - (25 * Page);
			}

			gInterface.DrawFormat(Color, (int)StartX + 18, (int)StartBody + 50 + (x * 10), 100, 1, this->m_CustomCommandInfo[i].Command);

			pDrawColorText(this->m_CustomCommandInfo[i].Description, (int)StartX + 112, (int)StartBody + 50 + (x * 10), 100, 0, Color, 0, 1);

		}

		pDrawGUI(71520, StartX + (MainWidth / 2) - (200 / 2), StartBody + 285, 200, 1); //-- Divisor
	}

}

void CCustomCommandInfo::OpenCommandWindow()
{

	if (gInterface.Data[eCommand_MAIN].OnShow == true)
	{
		gInterface.Data[eCommand_MAIN].OnShow = false;
		pSetCursorFocus = false;
		return;
	}

	DWORD CurrentTick	= GetTickCount();
	DWORD Delay			= (CurrentTick - gInterface.Data[eRankPANEL_MAIN].EventTick);

	if(Delay < 1500 )
	{
		gInterface.Data[eCommand_MAIN].OnShow = false;
		return;
	}

	gInterface.CloseCustomWindow();
	gInterface.Data[eCommand_MAIN].EventTick = GetTickCount();
	gInterface.Data[eCommand_MAIN].OnShow = true;
	pSetCursorFocus = true;

}

bool CCustomCommandInfo::EventCommandWindow_Close(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - gInterface.Data[eCommand_CLOSE].EventTick);
	// ----
	if (!gInterface.Data[eCommand_MAIN].OnShow || !gInterface.IsWorkZone(eCommand_CLOSE))
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		gInterface.Data[eCommand_CLOSE].OnClick = true;
		return true;
	}
	// ----
	gInterface.Data[eCommand_CLOSE].OnClick = false;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	// ----
	gInterface.Data[eCommand_CLOSE].EventTick = GetTickCount();
	gInterface.Data[eCommand_MAIN].OnShow = false;
	pSetCursorFocus = false;
	// ----
	return false;
}

bool CCustomCommandInfo::CommandNext(DWORD Event)
{
	DWORD CurrentTick	= GetTickCount();
	DWORD Delay			= (CurrentTick - gInterface.Data[eNextCommand].EventTick);
	DWORD Delay2		= (CurrentTick - gInterface.Data[ePrevCommand].EventTick);

	if( !gInterface.Data[eCommand_MAIN].OnShow )
	{
		return false;
	}
	
	if( !gInterface.IsWorkZone(eNextCommand) )
	{
		return false;
	}

	if( Event == WM_LBUTTONDOWN )
	{
		gInterface.Data[eNextCommand].OnClick = true;
		return true;
	}

	if( Delay < 100 || Delay2 < 100 )
	{
		return false;
	}
	
	gInterface.Data[eNextCommand].OnClick = false;
	
	this->Page++;
	
	gInterface.Data[eNextCommand].EventTick = GetTickCount();
	

	return true;
}

bool CCustomCommandInfo::CommandPrev(DWORD Event)
{
	DWORD CurrentTick	= GetTickCount();
	DWORD Delay			= (CurrentTick - gInterface.Data[ePrevCommand].EventTick);
	DWORD Delay2		= (CurrentTick - gInterface.Data[eNextCommand].EventTick);

	if( !gInterface.Data[eCommand_MAIN].OnShow )
	{
		return false;
	}
	
	if( !gInterface.IsWorkZone(ePrevCommand) )
	{
		return false;
	}

	if( Event == WM_LBUTTONDOWN )
	{
		gInterface.Data[ePrevCommand].OnClick = true;
		return true;
	}

	if( Delay < 100 || Delay2 < 100 )
	{
		return false;
	}
	
	gInterface.Data[ePrevCommand].OnClick = false;
	
	gInterface.Data[ePrevCommand].EventTick = GetTickCount();

	this->Page--;
	
	return true;
}


