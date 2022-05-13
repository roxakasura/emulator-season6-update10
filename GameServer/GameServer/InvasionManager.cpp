// InvasionManager.cpp: implementation of the CInvasionManager class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "InvasionManager.h"
#include "Map.h"
#include "MapManager.h"
#include "MemScript.h"
#include "Message.h"
#include "Monster.h"
#include "Notice.h"
#include "ObjectManager.h"
#include "ScheduleManager.h"
#include "ServerInfo.h"
#include "Util.h"

CInvasionManager gInvasionManager;
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CInvasionManager::CInvasionManager() // OK
{
	for(int n=0;n < MAX_INVASION;n++)
	{
		INVASION_INFO* lpInfo = &this->m_InvasionInfo[n];

		lpInfo->Index = n;
		lpInfo->State = INVASION_STATE_BLANK;
		lpInfo->RemainTime = 0;
		lpInfo->TargetTime = 0;
		lpInfo->TickCount = GetTickCount();

		this->CleanMonster(lpInfo);
	}
}

CInvasionManager::~CInvasionManager() // OK
{

}

void CInvasionManager::Init() // OK
{
	for(int n=0;n < MAX_INVASION;n++)
	{
		if(gServerInfo.m_InvasionManagerSwitch == 0)
		{
			this->SetState(&this->m_InvasionInfo[n],INVASION_STATE_BLANK);
		}
		else
		{
			this->SetState(&this->m_InvasionInfo[n],INVASION_STATE_EMPTY);
		}
	}
}

void CInvasionManager::Load(char* path) // OK
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

	for(int n=0;n < MAX_INVASION;n++)
	{
		this->m_InvasionInfo[n].RespawnMessage = -1;
		this->m_InvasionInfo[n].DespawnMessage = -1;
		this->m_InvasionInfo[n].BossIndex = -1;
		memset(this->m_InvasionInfo[n].BossCount,0,sizeof(this->m_InvasionInfo[n].BossCount));
		this->m_InvasionInfo[n].BossMessage = -1;
		this->m_InvasionInfo[n].InvasionTime = 0;
		this->m_InvasionInfo[n].StartTime.clear();
		this->m_InvasionInfo[n].AlarmTime = 0; //Igk Dev - Alarm Time <-Agregar esta linea

		for(int i=0;i<MAX_INVASION_RESPAWN_GROUP;i++)
		{
			this->m_InvasionInfo[n].RespawnInfo[i].clear();
		}

		this->m_InvasionInfo[n].MonsterInfo.clear();
	}

	try
	{
		while(true)
		{
			if(lpMemScript->GetToken() == TOKEN_END)
			{
				break;
			}

			int section = lpMemScript->GetNumber();

			while(true)
			{
				if(section == 0)
				{
					if(strcmp("end",lpMemScript->GetAsString()) == 0)
					{
						break;
					}

					INVASION_START_TIME info;

					int index = lpMemScript->GetNumber();

					info.Year = lpMemScript->GetAsNumber();

					info.Month = lpMemScript->GetAsNumber();

					info.Day = lpMemScript->GetAsNumber();

					info.DayOfWeek = lpMemScript->GetAsNumber();

					info.Hour = lpMemScript->GetAsNumber();

					info.Minute = lpMemScript->GetAsNumber();

					info.Second = lpMemScript->GetAsNumber();

					this->m_InvasionInfo[index].StartTime.push_back(info);
				}
				else if(section == 1)
				{
					if(strcmp("end",lpMemScript->GetAsString()) == 0)
					{
						break;
					}

					int index = lpMemScript->GetNumber();

					this->m_InvasionInfo[index].RespawnMessage = lpMemScript->GetAsNumber();

					this->m_InvasionInfo[index].DespawnMessage = lpMemScript->GetAsNumber();

					this->m_InvasionInfo[index].BossIndex = lpMemScript->GetAsNumber();

					this->m_InvasionInfo[index].BossMessage = lpMemScript->GetAsNumber();

					this->m_InvasionInfo[index].InvasionTime = lpMemScript->GetAsNumber();

					//this->m_InvasionInfo[index].Effect = lpMemScript->GetAsNumber();

					this->m_InvasionInfo[index].AlarmTime = lpMemScript->GetAsNumber();
					
					strcpy_s(this->m_InvasionInfo[index].AlertMessage,lpMemScript->GetAsString());
				}
				else if(section == 2)
				{
					if(strcmp("end",lpMemScript->GetAsString()) == 0)
					{
						break;
					}

					INVASION_RESPWAN_INFO info;

					int index = lpMemScript->GetNumber();

					info.Group = lpMemScript->GetAsNumber();

					info.Map = lpMemScript->GetAsNumber();

					info.Stage = lpMemScript->GetAsNumber();

					this->m_InvasionInfo[index].RespawnInfo[info.Group].push_back(info);
				}
				else if(section == 3)
				{
					if(strcmp("end",lpMemScript->GetAsString()) == 0)
					{
						break;
					}

					INVASION_MONSTER_INFO info;

					int index = lpMemScript->GetNumber();

					info.Group = lpMemScript->GetAsNumber();

					info.MonsterClass = lpMemScript->GetAsNumber();

					info.Range = lpMemScript->GetAsNumber();

					info.Map = lpMemScript->GetAsNumber();

					info.X = lpMemScript->GetAsNumber();

					info.Y = lpMemScript->GetAsNumber();

					info.TX = lpMemScript->GetAsNumber();

					info.TY = lpMemScript->GetAsNumber();

					info.Count = lpMemScript->GetAsNumber();

					info.Stage = lpMemScript->GetAsNumber();

					info.RegenType = lpMemScript->GetAsNumber();

					info.RegenTime = lpMemScript->GetAsNumber();

					this->m_InvasionInfo[index].MonsterInfo.push_back(info);
				}
				else
				{
					break;
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

void CInvasionManager::MainProc() // OK
{
	for(int n=0;n < MAX_INVASION;n++)
	{
		INVASION_INFO* lpInfo = &this->m_InvasionInfo[n];

		DWORD elapsed = GetTickCount()-lpInfo->TickCount;

		if(elapsed < 1000)
		{
			continue;
		}


		if(lpInfo->State == INVASION_STATE_BLANK)
		{
			if (gServerDisplayer.EventInvasion[n] != -1)
			{
				gServerDisplayer.EventInvasion[n] = -1;
			}
		}
		else 
		{
			if (lpInfo->State == INVASION_STATE_EMPTY)
			{
				gServerDisplayer.EventInvasion[n] = lpInfo->RemainTime;
			}
			else 
			{
				if (gServerDisplayer.EventInvasion[n] != 0)
				{
					gServerDisplayer.EventInvasion[n] = 0;
				}
			}
		}

		if(gServerDisplayer.EventInvasion[n] > 0)
		{
			if (lpInfo->State != INVASION_STATE_EMPTY && lpInfo->State != INVASION_STATE_BLANK)
			{
				gServerDisplayer.EventInvasion[n] = 0;
			}
		}

		lpInfo->TickCount = GetTickCount();

		lpInfo->RemainTime = (int)difftime(lpInfo->TargetTime,time(0));

		switch(lpInfo->State)
		{
			case INVASION_STATE_BLANK:
				this->ProcState_BLANK(lpInfo);
				break;
			case INVASION_STATE_EMPTY:
				this->ProcState_EMPTY(lpInfo);
				break;
			case INVASION_STATE_START:
				this->ProcState_START(lpInfo);
				break;
		}
	}
}

void CInvasionManager::ProcState_BLANK(INVASION_INFO* lpInfo) // OK
{

}

void CInvasionManager::ProcState_EMPTY(INVASION_INFO* lpInfo) // OK
{
	//Igk Dev - Alarm Time <- Agregar este if
	if(lpInfo->RemainTime > 0 && lpInfo->RemainTime <= (lpInfo->AlarmTime*60))
	{
		if((lpInfo->AlarmMinSave=(((lpInfo->RemainTime%60)==0)?((lpInfo->RemainTime/60)-1):(lpInfo->RemainTime/60))) != lpInfo->AlarmMinLeft)
		{
			lpInfo->AlarmMinLeft = lpInfo->AlarmMinSave;

			gNotice.GCNoticeSendToAll(0,0,0,0,0,0,gMessage.GetMessage(861),lpInfo->AlertMessage,(lpInfo->AlarmMinLeft+1));

		}
	}

	if(lpInfo->RemainTime <= 0)
	{
		if(lpInfo->RespawnMessage != -1)
		{
			gNotice.GCNoticeSendToAll(0,0,0,0,0,0,gMessage.GetMessage(lpInfo->RespawnMessage));
		}

		this->SetState(lpInfo,INVASION_STATE_START);
	}
}

void CInvasionManager::ProcState_START(INVASION_INFO* lpInfo) // OK
{
	if(lpInfo->RemainTime <= 0)
	{
		if(lpInfo->DespawnMessage != -1)
		{
			gNotice.GCNoticeSendToAll(0,0,0,0,0,0,gMessage.GetMessage(lpInfo->DespawnMessage));
		}

		this->SetState(lpInfo,INVASION_STATE_EMPTY);
	}
}

void CInvasionManager::SetState(INVASION_INFO* lpInfo,int state) // OK
{
	lpInfo->State = state;

	switch(lpInfo->State)
	{
		case INVASION_STATE_BLANK:
			this->SetState_BLANK(lpInfo);
			break;
		case INVASION_STATE_EMPTY:
			this->SetState_EMPTY(lpInfo);
			break;
		case INVASION_STATE_START:
			this->SetState_START(lpInfo);
			break;
	}
}

void CInvasionManager::SetState_BLANK(INVASION_INFO* lpInfo) // OK
{

}

void CInvasionManager::SetState_EMPTY(INVASION_INFO* lpInfo) // OK
{
	this->ClearMonster(lpInfo);

	this->CheckSync(lpInfo);

	memset(lpInfo->BossCount,0,sizeof(lpInfo->BossCount));

	if(lpInfo->Index == 1)
	{
		GCEventStateSendToAll(-1,0,1);
	}

	if(lpInfo->Index == 2)
	{
		GCEventStateSendToAll(-1,0,3);
	}

}

void CInvasionManager::SetState_START(INVASION_INFO* lpInfo) // OK
{
	memset(lpInfo->BossCount,0,sizeof(lpInfo->BossCount));

	for(int n=0;n < MAX_INVASION_RESPAWN_GROUP;n++)
	{
		if(lpInfo->RespawnInfo[n].empty() == 0)
		{
			INVASION_RESPWAN_INFO* lpRespawnInfo = &lpInfo->RespawnInfo[n][(GetLargeRand()%lpInfo->RespawnInfo[n].size())];

			for(std::vector<INVASION_MONSTER_INFO>::iterator it=lpInfo->MonsterInfo.begin();it != lpInfo->MonsterInfo.end();it++)
			{
				if(it->Group != lpRespawnInfo->Group || it->Map != lpRespawnInfo->Map || it->Stage != lpRespawnInfo->Stage)
				{
					continue;
				}

				for(int n=0;n < it->Count;n++)
				{
					int index = gObjAddMonster(it->Map);

					if(OBJECT_RANGE(index) == 0)
					{
						continue;
					}

					LPOBJ lpObj = &gObj[index];

					int px = it->X;
					int py = it->Y;

					if(gObjGetRandomMonsterLocation(it->Map,&px,&py,(it->TX - it->X),(it->TY - it->Y),50) == 0)
					{
						px = it->X;
						py = it->Y;
					}

					lpObj->PosNum = -1;
					lpObj->X = px;
					lpObj->Y = py;
					lpObj->TX = px;
					lpObj->TY = py;
					lpObj->OldX = px;
					lpObj->OldY = py;
					lpObj->StartX = px;
					lpObj->StartY = py;
					lpObj->Dir = GetLargeRand() % 8;
					lpObj->Map = it->Map;
					lpObj->MoveRange = it->Range;
					lpObj->InvasionIndex = lpInfo->Index;

					if(gObjSetMonster(index,it->MonsterClass) == 0)
					{
						gObjDel(index);
						continue;
					}

					lpObj->DieRegen = 0;
					lpObj->RegenTime = 1;
					lpObj->Attribute = 5;
					lpObj->MaxRegenTime = ((it->RegenType == 0) ? (lpInfo->InvasionTime*1000) : it->RegenTime);
					lpObj->LastCheckTick = GetTickCount();

					if(this->AddMonster(lpInfo,index) == 0)
					{
						gObjDel(index);
						continue;
					}

					if(lpInfo->BossIndex == it->MonsterClass)
					{
						lpInfo->BossCount[it->Map]++;
						if(lpInfo->Index == 1)
						{
							GCEventStateSendToAll(it->Map,1,1);
						}
						if(lpInfo->Index == 2)
						{
							GCEventStateSendToAll(it->Map,1,3);
						}
					}
					LogAdd(LOG_EVENT,"[Invasion Manager] Index(%d) Boss Position (Map: %d X: %d Y: %d)",lpInfo->Index,lpObj->Map,lpObj->X,lpObj->Y);
					//LogAdd(LOG_BLACK,"[Invasion Manager] (%d) SpawnMonster [%d] [%s][%d][%d]",lpInfo->Index,it->MonsterClass,gMapManager.GetMapName(lpObj->Map),lpObj->X,lpObj->Y);
				}
			}
		}
	}

	lpInfo->RemainTime = lpInfo->InvasionTime;

	lpInfo->TargetTime = (int)(time(0)+lpInfo->RemainTime);
}

void CInvasionManager::CheckSync(INVASION_INFO* lpInfo) // OK
{
	if(lpInfo->StartTime.empty() != 0)
	{
		this->SetState(lpInfo,INVASION_STATE_BLANK);
		return;
	}

	CTime ScheduleTime;

	CScheduleManager ScheduleManager;

	for(std::vector<INVASION_START_TIME>::iterator it=lpInfo->StartTime.begin();it != lpInfo->StartTime.end();it++)
	{
		ScheduleManager.AddSchedule(it->Year,it->Month,it->Day,it->Hour,it->Minute,it->Second,it->DayOfWeek);
	}

	if(ScheduleManager.GetSchedule(&ScheduleTime) == 0)
	{
		this->SetState(lpInfo,INVASION_STATE_BLANK);
		return;
	}

	lpInfo->RemainTime = (int)difftime(ScheduleTime.GetTime(),time(0));

	lpInfo->TargetTime = (int)ScheduleTime.GetTime();

	//LogAdd(LOG_BLACK,"[Invasion Manager] (%d) Sync Start Time. [%d] min remain",lpInfo->Index,(lpInfo->RemainTime/60));
}

int CInvasionManager::GetState(int index) // OK
{
	if(index < 0 || index >= MAX_INVASION)
	{
		return INVASION_STATE_BLANK;
	}

	return this->m_InvasionInfo[index].State;
}

int CInvasionManager::GetRemainTime(int index) // OK
{
	if(index < 0 || index >= MAX_INVASION)
	{
		return 0;
	}

	INVASION_INFO* lpInfo = &this->m_InvasionInfo[index];

	if(lpInfo->StartTime.empty() != 0)
	{
		return 0;
	}

	CTime ScheduleTime;

	CScheduleManager ScheduleManager;

	for(std::vector<INVASION_START_TIME>::iterator it=lpInfo->StartTime.begin();it != lpInfo->StartTime.end();it++)
	{
		ScheduleManager.AddSchedule(it->Year,it->Month,it->Day,it->Hour,it->Minute,it->Second,it->DayOfWeek);
	}

	if(ScheduleManager.GetSchedule(&ScheduleTime) == 0)
	{
		return 0;
	}

	int RemainTime = (int)difftime(ScheduleTime.GetTime(),time(0));

	return (((RemainTime%60)==0)?(RemainTime/60):((RemainTime/60)+1));
}

bool CInvasionManager::AddMonster(INVASION_INFO* lpInfo,int aIndex) // OK
{
	if(OBJECT_RANGE(aIndex) == 0)
	{
		return 0;
	}

	if(this->GetMonster(lpInfo,aIndex) != 0)
	{
		return 0;
	}

	for(int n=0;n < MAX_INVASION_MONSTER;n++)
	{
		if(OBJECT_RANGE(lpInfo->MonsterIndex[n]) == 0)
		{
			lpInfo->MonsterIndex[n] = aIndex;
			return 1;
		}
	}

	return 0;
}

bool CInvasionManager::DelMonster(INVASION_INFO* lpInfo,int aIndex) // OK
{
	if(OBJECT_RANGE(aIndex) == 0)
	{
		return 0;
	}

	int* index = this->GetMonster(lpInfo,aIndex);

	if(index == 0)
	{
		return 0;
	}

	(*index) = -1;
	return 1;
}

int* CInvasionManager::GetMonster(INVASION_INFO* lpInfo,int aIndex) // OK
{
	if(OBJECT_RANGE(aIndex) == 0)
	{
		return 0;
	}

	for(int n=0;n < MAX_INVASION_MONSTER;n++)
	{
		if(lpInfo->MonsterIndex[n] == aIndex)
		{
			return &lpInfo->MonsterIndex[n];
		}
	}

	return 0;
}

void CInvasionManager::CleanMonster(INVASION_INFO* lpInfo) // OK
{
	for(int n=0;n < MAX_INVASION_MONSTER;n++)
	{
		lpInfo->MonsterIndex[n] = -1;
	}
}

void CInvasionManager::ClearMonster(INVASION_INFO* lpInfo) // OK
{
	for(int n=0;n < MAX_INVASION_MONSTER;n++)
	{
		if(OBJECT_RANGE(lpInfo->MonsterIndex[n]) != 0)
		{
			gObjDel(lpInfo->MonsterIndex[n]);
			lpInfo->MonsterIndex[n] = -1;
		}
	}
}

int CInvasionManager::GetMonsterCount(INVASION_INFO* lpInfo) // OK
{
	int count = 0;

	for(int n=0;n < MAX_INVASION_MONSTER;n++)
	{
		if(OBJECT_RANGE(lpInfo->MonsterIndex[n]) != 0)
		{
			count++;
		}
	}

	return count;
}

void CInvasionManager::MonsterDieProc(LPOBJ lpObj,LPOBJ lpTarget) // OK
{
	int aIndex = gObjMonsterGetTopHitDamageUser(lpObj);

	if(OBJECT_RANGE(aIndex) != 0)
	{
		lpTarget = &gObj[aIndex];
	}

	if(this->GetState(lpObj->InvasionIndex) != INVASION_STATE_START)
	{
		return;
	}

	INVASION_INFO* lpInfo = &this->m_InvasionInfo[lpObj->InvasionIndex];

	if(this->GetMonster(lpInfo,lpObj->Index) == 0)
	{
		return;
	}
		
	if(lpObj->Class == lpInfo->BossIndex)
	{
		if ((--lpInfo->BossCount[lpTarget->Map]) <= 0)
		{
			if(lpInfo->Index == 1)
			{
				GCEventStateSendToAll(lpTarget->Map,0,1);
			}
			if(lpInfo->Index == 2)
			{
				GCEventStateSendToAll(lpTarget->Map,0,3);
			}
		}

		if(lpInfo->BossMessage != -1)
		{
			gNotice.GCNoticeSendToAll(0,0,0,0,0,0,gMessage.GetMessage(lpInfo->BossMessage),lpTarget->Name,gMapManager.GetMapName(lpTarget->Map));
		}
	}
}

void CInvasionManager::CheckEvent(LPOBJ lpObj) // OK
{
	for(int n=0;n<MAX_INVASION;n++)
	{
		if(this->GetState(n) != INVASION_STATE_START)
		{
			continue;
		}

		if(this->m_InvasionInfo[n].BossCount[lpObj->Map] <= 0)
		{
			continue;
		}

		//if(this->m_InvasionInfo[n].Effect == 0)
		//{
		//	continue;
		//}

		if(this->m_InvasionInfo[n].Index == 1)
		{
			GCEventStateSend(lpObj->Index,1,1);
		}

		if(this->m_InvasionInfo[n].Index == 2)
		{
			GCEventStateSend(lpObj->Index,1,3);
		}

		return;
	}

	GCEventStateSend(lpObj->Index,0,0);
}

void CInvasionManager::StartInvasion(int index)
{
	CTime CurrentTime = CTime::GetTickCount();

	int hour	= (int)CurrentTime.GetHour();
	int minute	= (int)CurrentTime.GetMinute()+2;

	if (minute >= 60)
	{
		hour++;
		minute = minute-60; 
	}

	INVASION_START_TIME info;

	info.Year = (int)CurrentTime.GetYear();

	info.Month = (int)CurrentTime.GetMonth();

	info.Day = (int)CurrentTime.GetDay();

	info.DayOfWeek = -1;

	info.Hour = hour;

	info.Minute = minute;

	info.Second = 0;

	this->m_InvasionInfo[index].StartTime.push_back(info);

	LogAdd(LOG_EVENT,"[Set Invasion Start] Index %d At %2d:%2d:00",index,hour,minute);

	this->SetState(&this->m_InvasionInfo[index],INVASION_STATE_EMPTY);
}
