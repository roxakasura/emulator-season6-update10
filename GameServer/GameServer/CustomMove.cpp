// CustomMove.cpp: implementation of the CCustomMove class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "CommandManager.h"
#include "CustomMove.h"
#include "CustomPet.h"
#include "GensSystem.h"
#include "Log.h"
#include "Map.h"
#include "MapManager.h"
#include "MemScript.h"
#include "Message.h"
#include "Notice.h"
#include "Util.h"
#include "EffectManager.h"

CCustomMove gCustomMove;
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CCustomMove::CCustomMove() // OK
{
	this->m_CustomMoveInfo.clear();
}

CCustomMove::~CCustomMove() // OK
{

}

void CCustomMove::Load(char* path) // OK
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

	this->m_CustomMoveInfo.clear();

	try
	{
		while(true)
		{
			if(lpMemScript->GetToken() == TOKEN_END)
			{
				break;
			}

			if(strcmp("end",lpMemScript->GetString()) == 0)
			{
				break;
			}

			CUSTOMMOVE_INFO info;

			info.Index = lpMemScript->GetNumber();

			strcpy_s(info.Name,lpMemScript->GetAsString());

			info.Map = lpMemScript->GetAsNumber();

			info.X = lpMemScript->GetAsNumber();

			info.Y = lpMemScript->GetAsNumber();

			info.MinLevel = lpMemScript->GetAsNumber();

			info.MaxLevel = lpMemScript->GetAsNumber();

			info.MinReset = lpMemScript->GetAsNumber();

			info.MaxReset = lpMemScript->GetAsNumber();

			info.MinMReset = lpMemScript->GetAsNumber();

			info.MaxMReset = lpMemScript->GetAsNumber();

			info.AccountLevel = lpMemScript->GetAsNumber();

			info.PkMove = lpMemScript->GetAsNumber();

			this->m_CustomMoveInfo.insert(std::pair<int,CUSTOMMOVE_INFO>(info.Index,info));
		}
	}
	catch(...)
	{
		ErrorMessageBox(lpMemScript->GetLastError());
	}

	delete lpMemScript;
}

bool CCustomMove::GetInfo(int index,CUSTOMMOVE_INFO* lpInfo) // OK
{
	std::map<int,CUSTOMMOVE_INFO>::iterator it = this->m_CustomMoveInfo.find(index);

	if(it == this->m_CustomMoveInfo.end())
	{
		return 0;
	}
	else
	{
		(*lpInfo) = it->second;
		return 1;
	}
}

bool CCustomMove::GetInfoByName(char* message,CUSTOMMOVE_INFO* lpInfo) // OK
{
	char command[32] = {0};

	memset(command,0,sizeof(command));

	gCommandManager.GetString(message,command,sizeof(command),0);


	for(std::map<int,CUSTOMMOVE_INFO>::iterator it=this->m_CustomMoveInfo.begin();it != this->m_CustomMoveInfo.end();it++)
	{
		if(_stricmp(it->second.Name,command) == 0)
		{
			(*lpInfo) = it->second;
			return 1;
		}
	}

	return 0;
}

void CCustomMove::GetMove(LPOBJ lpObj,int index) // OK
{
	CUSTOMMOVE_INFO CustomMoveInfo;

	if(this->GetInfo(index,&CustomMoveInfo) == 0)
	{
		return;
	}

	if(CustomMoveInfo.MinLevel != -1 && lpObj->Level < CustomMoveInfo.MinLevel)
	{
		gNotice.GCNoticeSend(lpObj->Index,1,0,0,0,0,0,gMessage.GetMessage(224),CustomMoveInfo.MinLevel);
		return;
	}

	if(CustomMoveInfo.MaxLevel != -1 && lpObj->Level > CustomMoveInfo.MaxLevel)
	{
		gNotice.GCNoticeSend(lpObj->Index,1,0,0,0,0,0,gMessage.GetMessage(230),CustomMoveInfo.MaxLevel);
		return;
	}

	if(CustomMoveInfo.MinReset != -1 && lpObj->Reset < CustomMoveInfo.MinReset)
	{
		gNotice.GCNoticeSend(lpObj->Index,1,0,0,0,0,0,gMessage.GetMessage(231),CustomMoveInfo.MinReset);
		return;
	}

	if(CustomMoveInfo.MaxReset != -1 && lpObj->Reset > CustomMoveInfo.MaxReset)
	{
		gNotice.GCNoticeSend(lpObj->Index,1,0,0,0,0,0,gMessage.GetMessage(232),CustomMoveInfo.MaxReset);
		return;
	}

	if(CustomMoveInfo.MinReset != -1 && lpObj->MasterReset < CustomMoveInfo.MinMReset)
	{
		gNotice.GCNoticeSend(lpObj->Index,1,0,0,0,0,0,gMessage.GetMessage(818),CustomMoveInfo.MinMReset);
		return;
	}

	if(CustomMoveInfo.MaxReset != -1 && lpObj->MasterReset > CustomMoveInfo.MaxMReset)
	{
		gNotice.GCNoticeSend(lpObj->Index,1,0,0,0,0,0,gMessage.GetMessage(819),CustomMoveInfo.MaxMReset);
		return;
	}

	if(lpObj->AccountLevel < CustomMoveInfo.AccountLevel)
	{
		gNotice.GCNoticeSend(lpObj->Index,1,0,0,0,0,0,gMessage.GetMessage(226));
		return;
	}

	if(CustomMoveInfo.PkMove == 0 && lpObj->PKLevel >= 5)
	{
		gNotice.GCNoticeSend(lpObj->Index,1,0,0,0,0,0,gMessage.GetMessage(227));
		return;
	}

	if(lpObj->Interface.use != 0 || lpObj->Teleport != 0 || lpObj->DieRegen != 0 || lpObj->PShopOpen != 0)
	{
		gNotice.GCNoticeSend(lpObj->Index,1,0,0,0,0,0,gMessage.GetMessage(226));
		return;
	}

	if(CustomMoveInfo.Map == MAP_ATLANS && (lpObj->Inventory[8].IsItem() != 0 && (lpObj->Inventory[8].m_Index == GET_ITEM(13,2) || lpObj->Inventory[8].m_Index == GET_ITEM(13,3)))) // Uniria,Dinorant
	{
		gNotice.GCNoticeSend(lpObj->Index,1,0,0,0,0,0,gMessage.GetMessage(274));
		return;
	}

	if(gEffectManager.CheckStunEffect(lpObj) != 0 || gEffectManager.CheckImmobilizeEffect(lpObj) != 0)
	{
		gNotice.GCNoticeSend(lpObj->Index,1,0,0,0,0,0,gMessage.GetMessage(226));
		return;
	}

	CItem* Inv = &lpObj->Inventory[8];

	if((CustomMoveInfo.Map == MAP_ICARUS || CustomMoveInfo.Map == MAP_KANTURU3) && (lpObj->Inventory[7].IsItem() == 0 && lpObj->Inventory[8].m_Index != GET_ITEM(13,3) && lpObj->Inventory[8].m_Index != GET_ITEM(13,37) && lpObj->Inventory[8].m_Index != GET_ITEM(13,4) && gCustomPet.CheckCustomPetIsMontaria(Inv->m_Index) != 1)) // Dinorant,Fenrir
	{
		gNotice.GCNoticeSend(lpObj->Index,1,0,0,0,0,0,gMessage.GetMessage(228));
		return;
	}

	#if(GAMESERVER_UPDATE>=501)

	if(lpObj->GensFamily == GENS_FAMILY_NONE && gMapManager.GetMapGensBattle(CustomMoveInfo.Map) != 0)
	{
		gNotice.GCNoticeSend(lpObj->Index,1,0,0,0,0,0,gMessage.GetMessage(229));
		return;
	}

	#endif

	gObjTeleport(lpObj->Index,CustomMoveInfo.Map,CustomMoveInfo.X,CustomMoveInfo.Y);
	gLog.Output(LOG_COMMAND,"[CustomMove][%s][%s] - (MoveIndex: %d)",lpObj->Account,lpObj->Name,index);
}