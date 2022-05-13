#include "stdafx.h"
#include "CustomLuckyWheel.h"
#include "MemScript.h"
#include "DSProtocol.h"
#include "Util.h"
#include "ItemManager.h"
#include "CashShop.h"
#include "User.h"
#include "Notice.h"
#include "Message.h"
#include "ServerInfo.h"
#include "ScheduleManager.h"
#include "pugixml.hpp"

CLuckyWheel gLuckyWheel;
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CLuckyWheel::CLuckyWheel()
{
	this->m_State = LUCKYWHEEL_STATE_BLANK;
	this->m_RemainTime = 0;
	this->m_TargetTime = 0;
	this->m_TickCount = GetTickCount();
	this->MinutesLeft = -1;
	this->Init();
}

CLuckyWheel::~CLuckyWheel()
{
}

void CLuckyWheel::Init()
{
	if (gServerInfo.LuckyWheelSwitch == 0)
	{
		this->SetState(LUCKYWHEEL_STATE_BLANK);
	}
	else
	{
		this->SetState(LUCKYWHEEL_STATE_EMPTY);
	}

	for(int n=0;n < MAX_LUCKYWHEEL_ITEM;n++)
	{
		this->m_LuckyWheelInfo[n].Index = -1;
	}
}

void CLuckyWheel::Load(char* path) // OK
{
	CMemScript* lpMemScript = new CMemScript;

	if(lpMemScript == 0)
	{
		ErrorMessageBox(MEM_SCRIPT_ALLOC_ERROR,path);
		return;
	}

	if(lpMemScript->SetBuffer(path) == 0)
	{
		ErrorMessageBox(lpMemScript->GetLastError());
		delete lpMemScript;
		return;
	}

	this->Init();

	try
	{
		while(true)
		{
			if(lpMemScript->GetToken() == TOKEN_END)
			{
				break;
			}			
			
			int section = lpMemScript->GetNumber();

			while (true)
			{
				if (section == 0)
				{
					if (strcmp("end", lpMemScript->GetAsString()) == 0)
					{
						break;
					}

					this->m_WarningTime = lpMemScript->GetNumber();

					this->m_EventTime = lpMemScript->GetAsNumber();

				}
				else if (section == 1)
				{
					if (strcmp("end", lpMemScript->GetAsString()) == 0)
					{
						break;
					}

					LUCKYWHEEL_START_TIME info;

					info.Year = lpMemScript->GetNumber();

					info.Month = lpMemScript->GetAsNumber();

					info.Day = lpMemScript->GetAsNumber();

					info.DayOfWeek = lpMemScript->GetAsNumber();

					info.Hour = lpMemScript->GetAsNumber();

					info.Minute = lpMemScript->GetAsNumber();

					info.Second = lpMemScript->GetAsNumber();

					this->m_LuckyWheelStartTime.push_back(info);
				}
				else if (section == 2)
				{

					if (strcmp("end", lpMemScript->GetAsString()) == 0)
					{
						break;
					}

					LUCKYWHEEL_INFO info;

					memset(&info, 0, sizeof(info));

					info.Index = lpMemScript->GetNumber();

					info.ItemType = lpMemScript->GetAsNumber();

					info.ItemIndex = lpMemScript->GetAsNumber();

					info.Level = lpMemScript->GetAsNumber();

					info.Skill = lpMemScript->GetAsNumber();

					info.Luck = lpMemScript->GetAsNumber();

					info.Option = lpMemScript->GetAsNumber();

					info.Exc = lpMemScript->GetAsNumber();

					this->SetInfo(info);
				}
			}
		}
	}
	catch(...)
	{
		ErrorMessageBox(lpMemScript->GetLastError());
	}

	delete lpMemScript;
}

void CLuckyWheel::MainProc() // OK
{
	DWORD elapsed = GetTickCount() - this->m_TickCount;

	if (elapsed < 1000)
	{
		return;
	}

	this->m_TickCount = GetTickCount();

	this->m_RemainTime = (int)difftime(this->m_TargetTime, time(0));

	if (gServerInfo.LuckyWheelSwitch == 0)
	{
		if (gServerDisplayer.EventLuckyWheel != -1)
		{
			gServerDisplayer.EventLuckyWheel = -1;
		}
	}
	else
	{
		if (this->m_State == LUCKYWHEEL_STATE_EMPTY)
		{
			gServerDisplayer.EventLuckyWheel = this->m_RemainTime;
		}
		else
		{
			if (gServerDisplayer.EventLuckyWheel != 0)
			{
				gServerDisplayer.EventLuckyWheel = 0;
			}
		}
	}


	switch (this->m_State)
	{
	case LUCKYWHEEL_STATE_BLANK:
		this->ProcState_BLANK();
		break;
	case LUCKYWHEEL_STATE_EMPTY:
		this->ProcState_EMPTY();
		break;
	case LUCKYWHEEL_STATE_START:
		this->ProcState_START();
		break;
	}
}


void CLuckyWheel::ProcState_BLANK() // OK
{

}

void CLuckyWheel::ProcState_EMPTY() // OK
{

	if (this->m_RemainTime > 0 && this->m_RemainTime <= (this->m_WarningTime * 60))
	{
		int minutes = this->m_RemainTime / 60;

		if ((this->m_RemainTime % 60) == 0)
		{
			minutes--;
		}

		if (this->MinutesLeft != minutes)
		{
			this->MinutesLeft = minutes;

			gNotice.GCNoticeSendToAll(0, 0, 0, 0, 0, 0, gMessage.GetMessage(883), (MinutesLeft + 1));
		}
	}

	if (this->m_RemainTime > 0 && this->m_RemainTime <= 5)
	{
		gNotice.GCNoticeSendToAll(0, 0, 0, 0, 0, 0, gMessage.GetMessage(884), m_RemainTime);
	}

	if (this->m_RemainTime <= 0)
	{
		gNotice.GCNoticeSendToAll(0, 0, 0, 0, 0, 0, gMessage.GetMessage(881));

		this->SetState(LUCKYWHEEL_STATE_START);
	}
}

void CLuckyWheel::ProcState_START() // OK
{

	if (this->m_RemainTime > 0 && this->m_RemainTime <= 300)
	{
		int minutes = this->m_RemainTime / 60;

		if (this->MinutesLeft != minutes)
		{
			this->MinutesLeft = minutes;

			gNotice.GCNoticeSendToAll(0, 0, 0, 0, 0, 0, gMessage.GetMessage(885), (MinutesLeft + 1));
		}
	}

	if (this->m_RemainTime <= 0)
	{
		gNotice.GCNoticeSendToAll(0, 0, 0, 0, 0, 0, gMessage.GetMessage(882));
		for (int n = OBJECT_START_USER; n < MAX_OBJECT; n++)
		{
			if (gObjIsConnectedGP(n) == 0)
			{
				continue;
			}

			LPOBJ lpObj = &gObj[n];

			this->m_Active = 0;
			gLuckyWheel.State(lpObj);
		}
		//LogAdd(LOG_EVENT, "[LUCKY WHEEL] valor2: %d", this->m_Active);
		this->SetState(LUCKYWHEEL_STATE_EMPTY);
	}
}

void CLuckyWheel::SetState(int state) // OK
{
	this->m_State = state;

	switch (this->m_State)
	{
	case LUCKYWHEEL_STATE_BLANK:
		this->SetState_BLANK();
		break;
	case LUCKYWHEEL_STATE_EMPTY:
		this->SetState_EMPTY();
		break;
	case LUCKYWHEEL_STATE_START:
		this->SetState_START();
		break;
	}
}

void CLuckyWheel::SetState_BLANK() // OK
{

}

void CLuckyWheel::SetState_EMPTY() // OK
{
	this->CheckSync();
}

void CLuckyWheel::SetState_START() // OK
{
	for (int n = OBJECT_START_USER; n < MAX_OBJECT; n++)
	{
		if (gObjIsConnectedGP(n) == 0)
		{
			continue;
		}

		LPOBJ lpObj = &gObj[n];
		this->m_Active = 1;
		gLuckyWheel.State(lpObj);
	}

	this->m_RemainTime = this->m_EventTime * 60;

	this->m_TargetTime = (int)(time(0) + this->m_RemainTime);

	//LogAdd(LOG_EVENT, "[LUCKY WHEEL] valor: %d", this->m_Active);
	LogAdd(LOG_EVENT, "[LUCKY WHEEL] Start");

}

void CLuckyWheel::CheckSync() // OK
{

	if (this->m_LuckyWheelStartTime.empty() != 0)
	{
		this->SetState(LUCKYWHEEL_STATE_BLANK);
		return;
	}

	CTime ScheduleTime;

	CScheduleManager ScheduleManager;

	for (std::vector<LUCKYWHEEL_START_TIME>::iterator it = this->m_LuckyWheelStartTime.begin(); it != this->m_LuckyWheelStartTime.end(); it++)
	{
		ScheduleManager.AddSchedule(it->Year, it->Month, it->Day, it->Hour, it->Minute, it->Second, it->DayOfWeek);
	}

	if (ScheduleManager.GetSchedule(&ScheduleTime) == 0)
	{
		this->SetState(LUCKYWHEEL_STATE_BLANK);
		return;
	}

	this->m_RemainTime = (int)difftime(ScheduleTime.GetTime(), time(0));

	this->m_TargetTime = (int)ScheduleTime.GetTime();

}

void CLuckyWheel::SetInfo(LUCKYWHEEL_INFO info)
{
	if(info.Index < 0 || info.Index >= MAX_LUCKYWHEEL_ITEM)
	{
		return;
	}
	this->m_LuckyWheelInfo[info.Index] = info;
}

//#MULTICHARACTER
void CLuckyWheel::State(LPOBJ lpObj)
{
	PMSG_LUCKYWHEELACTIVE_SEND pMsg;

	pMsg.header.set(0xFB, 0x17, sizeof(pMsg));

	pMsg.Active = this->m_Active;

	//LogAdd(LOG_RED, "vl1 - %d/ vl2 - %d", pMsg.Active, this->m_Active);

	DataSend(lpObj->Index, (BYTE*)&pMsg, pMsg.header.size);
}

void CLuckyWheel::Start(LPOBJ lpUser)
{
	if(gServerInfo.LuckyWheelMoney > 0)
	{
		if(lpUser->Coin1 < gServerInfo.LuckyWheelMoney)
		{
			gNotice.GCNoticeSend(lpUser->Index,1,0,0,0,0,0,gMessage.GetMessage(878),gServerInfo.LuckyWheelMoney);
			ITEM_WIN_SEND pMsg;
			pMsg.header.set(0xFB,0x16,sizeof(pMsg));
			pMsg.number = 0;
			DataSend(lpUser->Index,(BYTE*)&pMsg,pMsg.header.size);
			return;
		}
	}

	if (gItemManager.CheckItemInventorySpace(lpUser,m_LuckyWheelInfo[0].ItemIndex) == 0)
	{
		gNotice.GCNoticeSend(lpUser->Index,1,0,0,0,0,0,gMessage.GetMessage(876));
		ITEM_WIN_SEND pMsg;
		pMsg.header.set(0xFB,0x16,sizeof(pMsg));
		pMsg.number = 0;
		DataSend(lpUser->Index,(BYTE*)&pMsg,pMsg.header.size);
		return;
	}

	if(gServerInfo.LuckyWheelMoney > 0)
	{
		gCashShop.GDCashShopSubPointSaveSend(lpUser->Index,0,gServerInfo.LuckyWheelMoney,0,0);
		gCashShop.CGCashShopPointRecv(lpUser->Index);
	}

	Sleep(3000);
	srand((unsigned int)time((NULL)));
	int number = rand() % 12;
	GDCreateItemSend(lpUser->Index,0xEB,0,0,GET_ITEM(m_LuckyWheelInfo[number].ItemType,m_LuckyWheelInfo[number].ItemIndex),m_LuckyWheelInfo[number].Level,0,m_LuckyWheelInfo[number].Skill,m_LuckyWheelInfo[number].Luck,m_LuckyWheelInfo[number].Option,-1,m_LuckyWheelInfo[number].Exc,0,0,0,0,0xFF,0);
	gNotice.GCNoticeSend(lpUser->Index,1,0,0,0,0,0,gMessage.GetMessage(879),lpUser->Name);
	GCFireworksSend(lpUser,lpUser->X,lpUser->Y);
	ITEM_WIN_SEND pMsg;
	pMsg.header.set(0xFB,0x16,sizeof(pMsg));
	pMsg.number = number;
	DataSend(lpUser->Index,(BYTE*)&pMsg,pMsg.header.size);
}

void CLuckyWheel::StartLucky()
{
	time_t theTime = time(NULL);
	struct tm *aTime = localtime(&theTime);

	int hour = aTime->tm_hour;
	int minute = aTime->tm_min + 2;


	if (minute >= 60)
	{
		hour++;
		minute = minute - 60;
	}

	LUCKYWHEEL_START_TIME info;

	info.Year = -1;

	info.Month = -1;

	info.Day = -1;

	info.DayOfWeek = -1;

	info.Hour = hour;

	info.Minute = minute;

	info.Second = 0;

	this->m_LuckyWheelStartTime.push_back(info);

	LogAdd(LOG_EVENT, "[Set Lucky Wheel Start] At %2d:%2d:00", hour, minute);

	this->Init();
}