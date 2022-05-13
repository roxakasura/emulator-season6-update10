#include "stdafx.h"
#include "GameMain.h"
#include "BattleSoccerManager.h"
#include "CommandManager.h"
#include "DSProtocol.h"
#include "ESProtocol.h"
#include "HackCheck.h"
#include "JSProtocol.h"
#include "MasterSkillTree.h"
#include "MonsterAI.h"
#include "MonsterManager.h"
#include "ObjectManager.h"
#include "Protect.h"
#include "QueueTimer.h"
#include "ServerInfo.h"
#include "SocketManagerUdp.h"
#include "User.h"
#include "Util.h"
#include "OfflineMode.h"
#include "ManagerMonsterSetBase.h"

CConnection gJoinServerConnection;
CConnection gDataServerConnection;

void GameMainInit(HWND hwnd) // OK
{
	if(CreateMutex(0,0,gServerInfo.m_ServerMutex) == 0 || GetLastError() == ERROR_ALREADY_EXISTS)
	{
		ErrorMessageBox("Could not open GameServer");
		return;
	}

	PROTECT_START

//	gProtect.SystemOut1();

//	gProtect.SystemOut2();

//	gProtect.SystemOut3();
	
	gObjInit();

	InitHackCheck();

	InitBattleSoccer();

	gGameServerLogOut = 0;

	gGameServerDisconnect = 0;

	gServerInfo.ReadInit();

	//gCommandManager.Init();

	gObjSetExperienceTable();

	//Leitura de todos as alocações de spots
	gMonsterManager.SetMonsterData();

	//gMonsterSetBaseDungeon.SetMonsterDataDungeon();

	//gMonsterSetBaseDevias.SetMonsterDataDevias();

	//gMonsterSetBaseNoria.SetMonsterDataNoria();

	//gMonsterSetBaseLosttower.SetMonsterDataLosttower();

	//gMonsterSetBaseArena.SetMonsterDataArena();

	//gMonsterSetBaseAtlans.SetMonsterDataAtlans();

	//gMonsterSetBaseTarkan.SetMonsterDataTarkan();

	//gMonsterSetBaseIcarus.SetMonsterDataIcarus();

	//gMonsterSetBaseKalimaOne.SetMonsterDataKalimaOne();

	//gMonsterSetBaseKalimaTwo.SetMonsterDataKalimaTwo();

	//gMonsterSetBaseKalimaThree.SetMonsterDataKalimaThree();

	//gMonsterSetBaseKalimaFour.SetMonsterDataKalimaFour();

	//gMonsterSetBaseKalimaFive.SetMonsterDataKalimaFive();

	//gMonsterSetBaseKalimaSix.SetMonsterDataKalimaSix();

	//gMonsterSetBaseKalimaSeven.SetMonsterDataKalimaSeven();

	//gMonsterSetBaseCastleSiege.SetMonsterDataCastleSiege();

	//gMonsterSetBaseLandOfTrials.SetMonsterDataLandOfTrials();

	//gMonsterSetBaseCrywolf.SetMonsterDataCrywolf();

	//gMonsterSetBaseAida.SetMonsterDataAida();

	//gMonsterSetBaseKanturuOne.SetMonsterDataKanturuOne();

	//gMonsterSetBaseKanturuTwo.SetMonsterDataKanturuTwo();

	//	gKanturuMonsterMng.SetMonsterDataKanturuTower();

	//gMonsterSetBaseBarracks.SetMonsterDataBarracks();

	//gMonsterSetBaseRefuge.SetMonsterDataRefuge();

	//gMonsterSetBaseElbeland.SetMonsterDataElbeland();

	//gMonsterSetBaseSwamp.SetMonsterDataSwamp();

	//gMonsterSetBaseRaklion.SetMonsterDataRaklion();

	//gMonsterSetBaseRaklionBoss.SetMonsterDataRaklionBoss();

	//gMonsterSetBaseSantaTown.SetMonsterDataSantaTown();

	//gMonsterSetBaseVulcanus.SetMonsterDataVulcanus();

	//gMonsterSetBaseLorenMarket.SetMonsterDataLorenMarket();

	//gMonsterSetBaseKarutanOne.SetMonsterDataKarutanOne();

	//gMonsterSetBaseKarutanTwo.SetMonsterDataKarutanTwo();

	//gMonsterSetBaseCustomOne.SetMonsterDataCustomOne();

	//gMonsterSetBaseCustomTwo.SetMonsterDataCustomTwo();

	//gMonsterSetBaseCustomThe.SetMonsterDataCustomThe();

	//gMonsterSetBaseCustomFor.SetMonsterDataCustomFor();

	//gMonsterSetBaseCustomFiv.SetMonsterDataCustomFiv();

	//gMonsterSetBaseCustomSix.SetMonsterDataCustomSix();

	//gMonsterSetBaseCustomSev.SetMonsterDataCustomSev();

	//gMonsterSetBaseCustomEig.SetMonsterDataCustomEig();

	//gMonsterSetBaseCustomNin.SetMonsterDataCustomNin();

	//gMonsterSetBaseBloodCastle.SetMonsterDataBloodCastle();

	//gMonsterSetBaseBloodCastleTwo.SetMonsterDataBloodCastleTwo();

	//gMonsterSetBaseBloodCastleThe.SetMonsterDataBloodCastleThe();

	//gMonsterSetBaseBloodCastleFor.SetMonsterDataBloodCastleFor();

	//gMonsterSetBaseBloodCastleFiv.SetMonsterDataBloodCastleFiv();

	//gMonsterSetBaseBloodCastleSix.SetMonsterDataBloodCastleSix();

	//gMonsterSetBaseBloodCastleSev.SetMonsterDataBloodCastleSev();

	//gMonsterSetBaseBloodCastleEig.SetMonsterDataBloodCastleEig();

	//gMonsterSetBaseDevilSquareOne.SetMonsterDataDevilSquareOne();

	//gMonsterSetBaseDevilSquareTwo.SetMonsterDataDevilSquareTwo();

	//gMonsterSetBaseChaosCastle.SetMonsterDataChaosCastle();

	//gMonsterSetBaseChaosCastleTwo.SetMonsterDataChaosCastleTwo();

	//gMonsterSetBaseChaosCastleThe.SetMonsterDataChaosCastleThe();

	//gMonsterSetBaseChaosCastleFor.SetMonsterDataChaosCastleFor();

	//gMonsterSetBaseChaosCastleFiv.SetMonsterDataChaosCastleFiv();

	//gMonsterSetBaseChaosCastleSix.SetMonsterDataChaosCastleSix();

	//gMonsterSetBaseChaosCastleSev.SetMonsterDataChaosCastleSev();
	//
	//gMonsterSetBaseIllusionOne.SetMonsterDataIllusionOne();

	//gMonsterSetBaseIllusionTwo.SetMonsterDataIllusionTwo();

	//gMonsterSetBaseIllusionThe.SetMonsterDataIllusionThe();

	//gMonsterSetBaseIllusionFor.SetMonsterDataIllusionFor();

	//gMonsterSetBaseIllusionFiv.SetMonsterDataIllusionFiv();

	//gMonsterSetBaseIllusionSix.SetMonsterDataIllusionSix();
	//
	//gMonsterSetBaseImperialOne.SetMonsterDataImperialOne();

	//gMonsterSetBaseImperialTwo.SetMonsterDataImperialTwo();

	//gMonsterSetBaseImperialThe.SetMonsterDataImperialThe();

	//gMonsterSetBaseImperialFor.SetMonsterDataImperialFor();

	////gMonsterSetBaseInvasion.SetMonsterDataInvasion();
	//
	////gMonsterSetBaseNoria.SetMonsterDataNoria();

	#if(GAMESERVER_UPDATE>=401)

	gMasterSkillTree.SetMasterLevelExperienceTable();

	#endif

	gJoinServerConnection.Init(hwnd,JoinServerProtocolCore);

	gDataServerConnection.Init(hwnd,DataServerProtocolCore);

	PROTECT_FINAL
}

void ConnectServerInfoSend() // OK
{
	PROTECT_START

	SDHP_GAME_SERVER_LIVE_SEND pMsg;

	pMsg.header.set(0x01,sizeof(pMsg));

	pMsg.ServerCode = (WORD)gServerInfo.m_ServerCode;

	pMsg.UserTotal = (BYTE)((gObjTotalUser==0)?0:((gObjTotalUser*100)/gServerInfo.m_ServerMaxUserNumber));

	pMsg.UserCount = (WORD)gObjTotalUser;

	pMsg.AccountCount = 0;

	pMsg.PCPointCount = 0;

	pMsg.MaxUserCount = (WORD)gServerInfo.m_ServerMaxUserNumber;

	gSocketManagerUdp.DataSend((BYTE*)&pMsg,pMsg.header.size);

	PROTECT_FINAL
}

bool JoinServerConnect(DWORD wMsg) // OK
{
	if(gJoinServerConnection.Connect(gServerInfo.m_JoinServerAddress,(WORD)gServerInfo.m_JoinServerPort,wMsg) == 0)
	{
		return 0;
	}

	GJServerInfoSend();
	return 1;
}

bool DataServerConnect(DWORD wMsg) // OK
{
	if(gDataServerConnection.Connect(gServerInfo.m_DataServerAddress,(WORD)gServerInfo.m_DataServerPort,wMsg) == 0)
	{
		return 0;
	}

	GDServerInfoSend();
	return 1;
}

bool JoinServerReconnect(HWND hwnd,DWORD wMsg) // OK
{
	if(gJoinServerConnection.CheckState() == 0)
	{
		gJoinServerConnection.Init(hwnd,JoinServerProtocolCore);
		return JoinServerConnect(wMsg);
	}

	return 1;
}

bool DataServerReconnect(HWND hwnd,DWORD wMsg) // OK
{
	if(gDataServerConnection.CheckState() == 0)
	{
		gDataServerConnection.Init(hwnd,DataServerProtocolCore);
		return DataServerConnect(wMsg);
	}

	return 1;
}

void JoinServerMsgProc(WPARAM wParam,LPARAM lParam) // OK
{
	switch(LOWORD(lParam))
	{
		case FD_READ:
			gJoinServerConnection.DataRecv();
			break;
		case FD_WRITE:
			gJoinServerConnection.DataSendEx();
			break;
		case FD_CLOSE:
			gJoinServerConnection.Disconnect();
			gObjAllDisconnect();
			break;
	}
}

void DataServerMsgProc(WPARAM wParam,LPARAM lParam) // OK
{
	switch(LOWORD(lParam))
	{
		case FD_READ:
			gDataServerConnection.DataRecv();
			break;
		case FD_WRITE:
			gDataServerConnection.DataSendEx();
			break;
		case FD_CLOSE:
			gDataServerConnection.Disconnect();
			gObjAllDisconnect();
			break;
	}
}

void CALLBACK QueueTimerCallback(PVOID lpParameter,BOOLEAN TimerOrWaitFired) // OK
{
	PROTECT_START

	static CCriticalSection critical;

	critical.lock();

	switch(((int)lpParameter))
	{
		case QUEUE_TIMER_MONSTER:
			gObjectManager.ObjectMonsterAndMsgProc();
			break;
		case QUEUE_TIMER_MONSTER_MOVE:
			gObjectManager.ObjectMoveProc();
			break;
		case QUEUE_TIMER_MONSTER_AI:
			CMonsterAI::MonsterAIProc();
			break;
		case QUEUE_TIMER_MONSTER_AI_MOVE:
			CMonsterAI::MonsterMoveProc();
			break;
		case QUEUE_TIMER_EVENT:
			gObjEventRunProc();
			break;
		case QUEUE_TIMER_VIEWPORT:
			gObjViewportProc();
			for (int n = OBJ_STARTUSERINDEX; n < MAX_OBJECT; n++)
			{
				g_OfflineMode.PickUP(n);
				g_OfflineMode.regresar(n);
			}
			break;
		case QUEUE_TIMER_FIRST:
			gObjFirstProc();
			break;
		case QUEUE_TIMER_CLOSE:
			gObjCloseProc();
			break;
		case QUEUE_TIMER_MATH_AUTHENTICATOR:
			gObjMathAuthenticatorProc();
			break;
		case QUEUE_TIMER_ACCOUNT_LEVEL:
			gObjAccountLevelProc();
			break;
		case QUEUE_TIMER_PICK_COMMAND:
			gObjPickProc();
			break;
	}

	critical.unlock();

	PROTECT_FINAL
}
