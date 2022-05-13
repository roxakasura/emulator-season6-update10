#include "stdafx.h"
#include "CustomRanking.h"
#include "Defines.h"
#include "HealthBar.h"
#include "Interface.h"
#include "Util.h"
#include "Object.h"
#include "Import.h"
#include "Central.h"
#include "Protect.h"

CCustomRanking::CCustomRanking()
{
}

CCustomRanking gCustomRanking;

void CCustomRanking::ClearCustomRanking() // OK
{
	for(int n=0;n < MAX_RANK;n++)
	{
		memset(gCustomRanking[n].szName,0,sizeof(gCustomRanking[n].szName));
		gCustomRanking[n].valor = -1;
	}
	this->RankEnable = 0;
}

void CCustomRanking::GCReqRanking(PMSG_CUSTOM_RANKING_RECV* lpMsg) // OK
{
	//this->ClearCustomRanking();

	memcpy(this->rankname,lpMsg->rankname,sizeof(this->rankname)); 
	memcpy(this->col1,lpMsg->col1,sizeof(this->col1)); 
	memcpy(this->col2,lpMsg->col2,sizeof(this->col2));
	this->RankEnable = 1;

	this->count = lpMsg->count;

	for(int n=0;n < lpMsg->count;n++)
	{
		CUSTOM_RANKING_DATA* lpInfo = (CUSTOM_RANKING_DATA*)(((BYTE*)lpMsg)+sizeof(PMSG_CUSTOM_RANKING_RECV)+(sizeof(CUSTOM_RANKING_DATA)*n));

		memcpy(gCustomRanking[n].szName,lpInfo->szName,sizeof(gCustomRanking[n].szName));
		gCustomRanking[n].valor = lpInfo->valor;
	}
}

void CCustomRanking::GCReqRankingCount(PMSG_CUSTOM_RANKING_COUNT_RECV* lpMsg) // OK
{
	this->RankingCount = (lpMsg->count > 0) ? lpMsg->count : 0;
}

void CCustomRanking::DrawRankPanelWindow()
{
	if (gProtect.m_MainInfo.CustomInterfaceType != 3)
	{
		if (!gInterface.Data[eADDPOINT4_MAIN].OnShow)
		{
			return;
		}

		pSetCursorFocus = true;

		float MainWidth = 230.0;
		float MainHeight = 180.0;
		float StartBody = 80.0;
		float StartY = 80.0;
		float StartX = (MAX_WIN_WIDTH / 2) - (MainWidth / 2);
		float MainCenter = StartX + (MainWidth / 3);
		float ButtonX = MainCenter - (float)(29.0 / 2);

		gInterface.DrawGUI(eADDPOINT4_MAIN, StartX, StartY + (float)2.0);
		gInterface.DrawGUI(eADDPOINT4_TITLE, StartX, StartY);
		//gInterface.DrawFormat(eGold, (int)StartX + 9, (int)StartBody + 10, 210, 3, "Event Time");
		gInterface.DrawFormat(eGold, (int)StartX + 10, (int)StartBody + 10, 210, 3, "Ranking %s", this->rankname);
		StartY = gInterface.DrawRepeatGUI(eADDPOINT4_FRAME, StartX, StartY + (float)5.0, 12);
		gInterface.DrawGUI(eADDPOINT4_FOOTER, StartX, StartY);
		gInterface.DrawGUI(eADDPOINT4_CLOSE, StartX + MainWidth - gInterface.Data[eADDPOINT4_CLOSE].Width, StartBody);

		DWORD Color = eGray100;
		if (gInterface.IsWorkZone(eADDPOINT4_CLOSE))
		{
			// ----
			if (gInterface.Data[eADDPOINT4_CLOSE].OnClick)
			{
				Color = eGray150;
			}
			// ----
			gInterface.DrawColoredGUI(eADDPOINT4_CLOSE, gInterface.Data[eADDPOINT4_CLOSE].X, StartBody, Color);
			gInterface.DrawToolTip((int)gInterface.Data[eADDPOINT4_CLOSE].X + 5, (int)gInterface.Data[eADDPOINT4_CLOSE].Y + 25, "Close");
		}

		if (this->RankingType > 0)
		{
			gInterface.DrawGUI(eSAMPLEBUTTON2, StartX + 10, 170);
		}
		else
		{
			gInterface.ResetDrawIMG(eSAMPLEBUTTON2);
		}

		if (this->RankingType < this->RankingCount - 1)
		{
			gInterface.DrawGUI(eSAMPLEBUTTON, StartX + MainWidth - gInterface.Data[eSAMPLEBUTTON].Width - 15, 170);
		}
		else
		{
			gInterface.ResetDrawIMG(eSAMPLEBUTTON);
		}

		if (this->RankEnable == 1)
		{

			//gInterface.DrawFormat(eAncient,  MainCenter - (sizeof(this->rankname) / 2)-15, StartY + 40, 52, 3, "(%s)",this->rankname);

			gInterface.DrawFormat(eWhite, StartX + 65, StartBody + 40, 52, 1, "Rank:");

			gInterface.DrawFormat(eWhite, StartX + 90, StartBody + 40, 52, 1, "%s", this->col1);

			gInterface.DrawFormat(eWhite, StartX + 145, StartBody + 40, 52, 1, "%s", this->col2);

			char* name = (char*)(oUserPreviewStruct + 0x38);

			for (int i = 0; i < this->count; i++)
			{

				Color = eGold;

				if (strcmp(name, this->gCustomRanking[i].szName) == 0)
				{
					Color = eExcellent;
				}

				gInterface.DrawFormat(Color, StartX + 65, StartBody + 55 + (12 * i), 52, 1, "%dº", (i + 1));

				gInterface.DrawFormat(Color, StartX + 90, StartBody + 55 + (12 * i), 52, 1, "%s", this->gCustomRanking[i].szName);

				gInterface.DrawFormat(Color, StartX + 145, StartBody + 55 + (12 * i), 52, 1, "%d", this->gCustomRanking[i].valor);

				gInterface.DrawFormat(eGray100, StartX + 64, StartBody + 55 + (12 * i) + 2, 110, 1, "_________________________________");
			}
		}
		else
		{
			if (this->RankLoad == 1)
			{
				gInterface.DrawFormat(eGold, MainCenter - (sizeof(this->rankname) / 2) + 30, StartBody + 100, 52, 1, "Loading ..");
				this->RankLoad = 2;
			}
			else if (this->RankLoad == 2)
			{
				gInterface.DrawFormat(eGold, MainCenter - (sizeof(this->rankname) / 2) + 30, StartBody + 100, 52, 1, "Loading ...");
				this->RankLoad = 3;
			}
			else if (this->RankLoad == 3)
			{
				gInterface.DrawFormat(eGold, MainCenter - (sizeof(this->rankname) / 2) + 30, StartBody + 100, 52, 1, "Loading ....");
				this->RankLoad = 4;
			}
			else if (this->RankLoad == 4)
			{
				gInterface.DrawFormat(eGold, MainCenter - (sizeof(this->rankname) / 2) + 30, StartBody + 100, 52, 1, "Loading .....");
				this->RankLoad = 0;
			}
			else
			{
				gInterface.DrawFormat(eGold, MainCenter - (sizeof(this->rankname) / 2) + 30, StartBody + 100, 52, 1, "Loading .");
				this->RankLoad = 1;
			}
		}
	}
	else
	//Season 8
	{
		if (!gInterface.Data[eADDPOINT4_MAIN].OnShow)
		{
			return;
		}

		float MainWidth = 230.0;
		float MainHeight = 240.0;
		float StartBody = ((MAX_WIN_HEIGHT - 51) / 2) - (MainHeight / 2);
		float StartY = ((MAX_WIN_HEIGHT - 51) / 2) - (MainHeight / 2);
		float StartX = (MAX_WIN_WIDTH / 2) - (MainWidth / 2);
		float MainCenter = StartX + (MainWidth / 3);
		float ButtonX = MainCenter - (float)(29.0 / 2);
		//--
		DWORD Color = eGray100;

		gCentral.PrintDropBox(StartX, StartY, MainWidth, MainHeight, 0, 0);

		gInterface.DrawFormat(eGold, (int)StartX + 10, (int)StartBody + 10, 210, 3, "Ranking %s", this->rankname);

		pDrawGUI(71520, StartX + (MainWidth / 2) - (200 / 2), StartBody + 35, 200, 1); //-- Divisor

		pDrawGUI(71520, StartX + (MainWidth / 2) - (200 / 2), StartBody + 210, 200, 1); //-- Divisor

		if (this->RankingType > 0)
		{
			gInterface.DrawGUI(eSAMPLEBUTTON2, StartX + 10, 170);
		}
		else
		{
			gInterface.ResetDrawIMG(eSAMPLEBUTTON2);
		}

		if (this->RankingType < this->RankingCount - 1)
		{
			gInterface.DrawGUI(eSAMPLEBUTTON, StartX + MainWidth - gInterface.Data[eSAMPLEBUTTON].Width - 15, 170);
		}
		else
		{
			gInterface.ResetDrawIMG(eSAMPLEBUTTON);
		}

		if (this->RankEnable == 1)
		{

			//gInterface.DrawFormat(eAncient,  MainCenter - (sizeof(this->rankname) / 2)-15, StartY + 40, 52, 3, "(%s)",this->rankname);

			gInterface.DrawFormat(eWhite, StartX + 65, StartBody + 55, 52, 1, "Rank:");

			gInterface.DrawFormat(eWhite, StartX + 90, StartBody + 55, 52, 1, "%s", this->col1);

			gInterface.DrawFormat(eWhite, StartX + 145, StartBody + 55, 52, 1, "%s", this->col2);

			char* name = (char*)(oUserPreviewStruct + 0x38);

			for (int i = 0; i < this->count; i++)
			{

				Color = eGold;

				if (strcmp(name, this->gCustomRanking[i].szName) == 0)
				{
					Color = eExcellent;
				}

				gInterface.DrawFormat(Color, StartX + 65, StartBody + 70 + (12 * i), 52, 1, "%dº", (i + 1));

				gInterface.DrawFormat(Color, StartX + 90, StartBody + 70 + (12 * i), 52, 1, "%s", this->gCustomRanking[i].szName);

				gInterface.DrawFormat(Color, StartX + 145, StartBody + 70 + (12 * i), 52, 1, "%d", this->gCustomRanking[i].valor);

				//gInterface.DrawFormat(eGray100,  StartX + 64, StartBody + 55 + (12*i) + 2, 110, 1,"_________________________________");
			}
		}
		else
		{
			if (this->RankLoad == 1)
			{
				gInterface.DrawFormat(eGold, MainCenter - (sizeof(this->rankname) / 2) + 30, StartBody + 120, 52, 1, "Loading ..");
				this->RankLoad = 2;
			}
			else if (this->RankLoad == 2)
			{
				gInterface.DrawFormat(eGold, MainCenter - (sizeof(this->rankname) / 2) + 30, StartBody + 120, 52, 1, "Loading ...");
				this->RankLoad = 3;
			}
			else if (this->RankLoad == 3)
			{
				gInterface.DrawFormat(eGold, MainCenter - (sizeof(this->rankname) / 2) + 30, StartBody + 120, 52, 1, "Loading ....");
				this->RankLoad = 4;
			}
			else if (this->RankLoad == 4)
			{
				gInterface.DrawFormat(eGold, MainCenter - (sizeof(this->rankname) / 2) + 30, StartBody + 120, 52, 1, "Loading .....");
				this->RankLoad = 0;
			}
			else
			{
				gInterface.DrawFormat(eGold, MainCenter - (sizeof(this->rankname) / 2) + 30, StartBody + 120, 52, 1, "Loading .");
				this->RankLoad = 1;
			}
		}
	}
}

bool CCustomRanking::EventRankingNext(DWORD Event)
{
	DWORD CurrentTick	= GetTickCount();
	DWORD Delay			= (CurrentTick - gInterface.Data[eSAMPLEBUTTON].EventTick);
	DWORD Delay2		= (CurrentTick - gInterface.Data[eSAMPLEBUTTON2].EventTick);

	if( !gInterface.Data[eADDPOINT4_MAIN].OnShow )
	{
		return false;
	}
	
	if( !gInterface.IsWorkZone(eSAMPLEBUTTON) )
	{
		return false;
	}

	if( Event == WM_LBUTTONDOWN )
	{
		gInterface.Data[eSAMPLEBUTTON].OnClick = true;
		return true;
	}

	if( Delay < 1000 || Delay2 < 1000 )
	{
		return false;
	}
	
	this->ClearCustomRanking();
	
	gInterface.Data[eSAMPLEBUTTON].OnClick = false;
	
	gInterface.Data[eSAMPLEBUTTON].EventTick = GetTickCount();
	
	PMSG_CUSTOM_RANKING_SEND pMsg;

	pMsg.header.set(0xF3, 0xE6,sizeof(pMsg));

	RankingType++;
	pMsg.type = RankingType;

	DataSend((BYTE*)&pMsg,pMsg.header.size);
	return true;
}

bool CCustomRanking::EventRankingBack(DWORD Event)
{
	DWORD CurrentTick	= GetTickCount();
	DWORD Delay			= (CurrentTick - gInterface.Data[eSAMPLEBUTTON].EventTick);
	DWORD Delay2		= (CurrentTick - gInterface.Data[eSAMPLEBUTTON2].EventTick);

	if( !gInterface.Data[eADDPOINT4_MAIN].OnShow )
	{
		return false;
	}
	
	if( !gInterface.IsWorkZone(eSAMPLEBUTTON2) )
	{
		return false;
	}

	if( Event == WM_LBUTTONDOWN )
	{
		gInterface.Data[eSAMPLEBUTTON2].OnClick = true;
		return true;
	}

	if( Delay < 1000 || Delay2 < 1000 )
	{
		return false;
	}

	this->ClearCustomRanking();
	
	gInterface.Data[eSAMPLEBUTTON2].OnClick = false;
	
	gInterface.Data[eSAMPLEBUTTON2].EventTick = GetTickCount();
	
	PMSG_CUSTOM_RANKING_SEND pMsg;

	pMsg.header.set(0xF3, 0xE6,sizeof(pMsg));

	RankingType--;
	pMsg.type = RankingType;

	DataSend((BYTE*)&pMsg,pMsg.header.size);
	return true;
}

bool CCustomRanking::EventVipWindow_Close(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - gInterface.Data[eADDPOINT4_CLOSE].EventTick);
	// ----
	if (!gInterface.Data[eADDPOINT4_MAIN].OnShow || !gInterface.IsWorkZone(eADDPOINT4_CLOSE))
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		gInterface.Data[eADDPOINT4_CLOSE].OnClick = true;
		return true;
	}
	// ----
	gInterface.Data[eADDPOINT4_CLOSE].OnClick = false;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	// ----
	gInterface.Data[eADDPOINT4_CLOSE].EventTick = GetTickCount();
	gInterface.Data[eADDPOINT4_MAIN].OnShow = false;
	this->CloseTestWindow();
	pSetCursorFocus = false;
	// ----
	return false;
}

void CCustomRanking::OpenWindow()
{

	if((GetTickCount() - gInterface.Data[eADDPOINT4_MAIN].EventTick) < 1500 )
	{
		//gInterface.Data[eRankPANEL_MAIN].OnShow = false;
		return;
	}

	gInterface.Data[eADDPOINT4_MAIN].EventTick = GetTickCount();

	if (gInterface.Data[eADDPOINT4_MAIN].OnShow == true)
	{
		gInterface.Data[eADDPOINT4_MAIN].OnShow = false;
		pSetCursorFocus = false;
		return;
	}

	gInterface.CloseCustomWindow();

	this->ClearCustomRanking();

	this->RankingCount = 0;

	PMSG_CUSTOM_RANKING_COUNT_SEND pMsg1;

	pMsg1.header.set(0xF3, 0xE7,sizeof(pMsg1));

	DataSend((BYTE*)&pMsg1,pMsg1.header.size);

	PMSG_CUSTOM_RANKING_SEND pMsg;

	pMsg.header.set(0xF3, 0xE6,sizeof(pMsg));

	this->RankingType = 0;

	pMsg.type = 0;

	DataSend((BYTE*)&pMsg,pMsg.header.size);

	gInterface.Data[eADDPOINT4_MAIN].OnShow = true;
	pSetCursorFocus = true;

}