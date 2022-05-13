#pragma once

#include "StdAfx.h"
#include "Protocol.h"
// ----------------------------------------------------------------------------------------------

#define OFFMAXTIME_FOR_BUFF		20	

#define OFFLINE_MODE_RESTORE	0
#define OFFLINEMODE_DBMAX		8
#define OFFLINEMODE_DBPRICE		544

enum MAP_INDEX
{
	MAP_INDEX_RORENCIA = 0x0,
	MAP_INDEX_DUNGEON = 0x1,
	MAP_INDEX_DEVIAS = 0x2,
	MAP_INDEX_NORIA = 0x3,
	MAP_INDEX_LOSTTOWER = 0x4,
	MAP_INDEX_RESERVED = 0x5,
	MAP_INDEX_BATTLESOCCER = 0x6,
	MAP_INDEX_ATHLANSE = 0x7,
	MAP_INDEX_TARKAN = 0x8,
	MAP_INDEX_DEVILSQUARE = 0x9,
	MAP_INDEX_ICARUS = 0xa,
	MAP_INDEX_BLOODCASTLE1 = 0xb,
	MAP_INDEX_BLOODCASTLE2 = 0xc,
	MAP_INDEX_BLOODCASTLE3 = 0xd,
	MAP_INDEX_BLOODCASTLE4 = 0xe,
	MAP_INDEX_BLOODCASTLE5 = 0xf,
	MAP_INDEX_BLOODCASTLE6 = 0x10,
	MAP_INDEX_BLOODCASTLE7 = 0x11,
	MAP_INDEX_CHAOSCASTLE1 = 0x12,
	MAP_INDEX_CHAOSCASTLE2 = 0x13,
	MAP_INDEX_CHAOSCASTLE3 = 0x14,
	MAP_INDEX_CHAOSCASTLE4 = 0x15,
	MAP_INDEX_CHAOSCASTLE5 = 0x16,
	MAP_INDEX_CHAOSCASTLE6 = 0x17,
	MAP_INDEX_KALIMA1 = 0x18,
	MAP_INDEX_KALIMA2 = 0x19,
	MAP_INDEX_KALIMA3 = 0x1a,
	MAP_INDEX_KALIMA4 = 0x1b,
	MAP_INDEX_KALIMA5 = 0x1c,
	MAP_INDEX_KALIMA6 = 0x1d,
	MAP_INDEX_CASTLESIEGE = 0x1e,
	MAP_INDEX_CASTLEHUNTZONE = 0x1f,
	MAP_INDEX_DEVILSQUARE2 = 0x20,
	MAP_INDEX_AIDA = 0x21,
	MAP_INDEX_CRYWOLF_FIRSTZONE = 0x22,
	MAP_INDEX_CRYWOLF_SECONDZONE = 0x23,
	MAP_INDEX_KALIMA7 = 0x24,
	MAP_INDEX_KANTURU1 = 0x25,
	MAP_INDEX_KANTURU2 = 0x26,
	MAP_INDEX_KANTURU_BOSS = 0x27,
	MAP_INDEX_GM_SUMMONZONE = 0x28,
	MAP_INDEX_BALGASS_BARRACKS = 0x29,
	MAP_INDEX_BALGASS_REFUGEE = 0x2A,
	MAP_INDEX_ILLUSIONTEMPLE1 = 0x2D,
	MAP_INDEX_ILLUSIONTEMPLE2 = 0x2E,
	MAP_INDEX_ILLUSIONTEMPLE3 = 0x2F,
	MAP_INDEX_ILLUSIONTEMPLE4 = 0x30,
	MAP_INDEX_ILLUSIONTEMPLE5 = 0x31,
	MAP_INDEX_ILLUSIONTEMPLE6 = 0x32,
	MAP_INDEX_ELBELAND = 0x33,
	MAP_INDEX_BLOODCASTLE8 = 0x34,
	MAP_INDEX_CHAOSCASTLE7 = 0x35,
	MAP_INDEX_DEVILSQUARE7 = 0x36,
	MAP_INDEX_SWAMPOFCALMNESS = 0x38,
	MAP_INDEX_RAKLION = 0x39,
	MAP_INDEX_RAKLION_BOSS = 0x3A,
	MAP_INDEX_SANTATOWN = 0x3E,
	MAP_INDEX_VULCAN = 0x3f,
	MAP_INDEX_VULCANROOM = 0x40,
	MAP_INDEX_DOUBLE_GOER1 = 65,	//Season 5 DoppelGanger
	MAP_INDEX_DOUBLE_GOER2 = 66,	//Season 5 DoppelGanger
	MAP_INDEX_DOUBLE_GOER3 = 67,	//Season 5 DoppelGanger
	MAP_INDEX_DOUBLE_GOER4 = 68,	//Season 5 DoppelGanger
	MAP_INDEX_IMPERIAL1 = 69,		//Season 5 ImperialFort
	MAP_INDEX_IMPERIAL2 = 70,
	MAP_INDEX_IMPERIAL3 = 71,
	MAP_INDEX_IMPERIAL4 = 72
};

struct CG_OFFMODE_RESULT
{
	PBMSG_HEAD2 h;
	WORD HuntingRange;
	//-- Potion
	BYTE RecoveryPotionOn;
	BYTE RecoveryPotionPercent;
	BYTE RecoveryHealOn; //-> CLASS_ELF
	BYTE RecoveryHealPercent; //-> CLASS_ELF
	BYTE RecoveryDrainOn; //-> CLASS_SUMMONER
	BYTE RecoveryDrainPercent; //-> CLASS_SUMMONER
	//-- Attack
	BYTE DistanceLongOn;
	BYTE DistanceReturnOn;
	WORD DistanceMin;//-- tiempo
	WORD SkillBasicID;
	BYTE ComboOn;				//-> CLASS_KNIGHT
	BYTE PartyModeOn;
	BYTE PartyModeHealOn;		//-> CLASS_ELF
	BYTE PartyModeHealPercent;	//-> CLASS_ELF
	BYTE PartyModeBuffOn;
	BYTE BuffOn;
	WORD BuffSkill[3];
	//-- Obtaing
	WORD ObtainRange;
	BYTE ObtainRepairOn;
	BYTE ObtainPickNear;
	BYTE ObtainPickSelected;
	BYTE ObtainPickMoney;
	BYTE ObtainPickJewels;
	BYTE ObtainPickExcellent;
	BYTE ObtainPickAncient;
	BYTE ObtainPickExtra;
	int ObtainPickExtraCount;
	char ObtainPickItemList[12][16];
};

class OfflineMode
{
public:
	OfflineMode();
	~OfflineMode();
	bool m_bLoadedDB;
	int m_ConnectIndex;
	DWORD m_ConnectTick;
	int m_MUOffHelperEnabled[MAX_ACCOUNT_LEVEL];
	int m_MUOffHelperTimer[MAX_ACCOUNT_LEVEL];
	void ReadOffLine(char* section,char* path);
	void Start(CG_OFFMODE_RESULT* aRecv, int UserIndex);
	void Attack(int UserIndex);
	void RenderAttack(int UserIndex);
	void RenderAutoBuffParty(int aIndex);
	void RenderAutoPote(int aIndex);
	int PickUP(int aIndex);
	//-- Protocolo
	void CGPositionOfflineRecv(PMSG_POSITION_RECV* lpMsg,int aIndex); // OK
	//-- [/]Protocolo
	void OnAttackSecondProcHelper(LPOBJ lpObj); // OK
	void OnHelperpAlreadyConnected(LPOBJ lpObj); // OK
	void regresar(int aIndex);
};
// ----------------------------------------------------------------------------------------------
extern OfflineMode g_OfflineMode;
// ----------------------------------------------------------------------------------------------