#pragma once

#pragma once
#include "Protocol.h"
#include "Object.h"

#define pHelperUsePotion		((char(__thiscall*)(MUHelper *pHelper)) 0x95E980)
#define pHelperUseBuff			((bool(__thiscall*)(MUHelper *pHelper, lpViewObj lpPlayer)) 0x95FDA0)
#define pHelperPartyUseBaff		((char(__thiscall*)(MUHelper *pHelper)) 0x95FE30)
#define pGetSkillPos			((int(__stdcall*)(int SkillID)) 0x95F8D0)
#define pIs3rdClass				((bool(__cdecl*)(BYTE Class)) 0x005878E0)
#define sub_95EC00_Addr			((int(__thiscall*)(MUHelper *pHelper)) 0x95EC00)
#define pHelperUseSkill			((char(__thiscall*)(MUHelper *pHelper, int SkillID, lpViewObj lpTarget, int Type)) 0x95F930)
#define sub_95FCD0_Addr			((char(__thiscall*)(MUHelper *pHelper)) 0x95FCD0)
#define sub_95F0D0_Addr			((char(__thiscall*)(MUHelper *pHelper)) 0x95F0D0)
#define sub_95F490_Addr			((char(__thiscall*)(MUHelper *pHelper, int a1)) 0x95F490)
#define HelperRepairItems		((void(__thiscall*)()) 0x95F6B0)
#define sub_95EFA0_Addr			((char(__thiscall*)(MUHelper *pHelper)) 0x95EFA0)
#define sub_59B2B0_Addr			((void(__cdecl*)(lpViewObj lpPlayer, int a2)) 0x59B2B0)
#define sub_54EA80_Addr			((void(__cdecl*)(lpViewObj lpPlayer)) 0x54EA80)
#define sub_95FF40_Addr			((char(__thiscall*)(MUHelper *pHelper)) 0x95FF40)

#define sub_4DB6B0			((char(__thiscall*)(int a1)) 0x4DB6B0)

#define sub_960140_Addr			((bool(__thiscall*)(MUHelper *pHelper, int a1,  int a2)) 0x960140)
#define sub_9600A0_Addr			((char(__thiscall*)(MUHelper *pHelper, int a1, int a2)) 0x9600A0)
#define sub_95FAE0_Addr			((char(__thiscall*)(MUHelper *pHelper, SkillData *a1, int a2)) 0x95FAE0)
#define sub_409AD0_Addr			((int(__thiscall*)(LPVOID a1)) 0x00409AD0)
#define sub_409A50_addr			((void(__thiscall*)(void *This, int a2)) 0x409A50)
#define pOpenInfoBox1			((bool(__cdecl*)(LPVOID This, int Arg2)) 0x790A10)
#define pGetItemList( x )		((const char*) (*(DWORD*)(0x00E8CB7C)+ 304 + ( 28 * x )))
#define sub_9CF630  	        ((char(__cdecl*)(char *a1, int a2, int a3)) 0x009CF630)
#define RenderBitMapColored		((void(__cdecl*)(int a4, float a5, float a6, float a7, float a8, float a9, float a10, float a11, float a12, int a13))0x00790DF0)
#define sub_7798F0				((char(__thiscall*)(int This, char a9))0x007798F0)
#define sub_50D100				((size_t(__cdecl*)(char * a1, char * a2, ...)) 0x50D100)

struct CharTest
{
	int unk1;
	BYTE unk4;
	BYTE unk6;
	BYTE unk7;
	BYTE unk8;
	BYTE unk9;
	BYTE unk10;
	BYTE unk11;
	BYTE unk12;
	BYTE unk13;
	BYTE unk14;
	BYTE unk15;
	BYTE unk16;
	BYTE unk17;
	BYTE unk18;
	BYTE unk19;
	BYTE unk20_;
	DWORD unk20;
	DWORD unk24;
	BYTE gap1[46];
};

struct PMSG_PET_ITEM_COMMAND_SEND
{
	PBMSG_HEAD header; // C1:A7
	BYTE type;
	BYTE command;
	BYTE index[2];
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


class cMuOffHelper
{
public:
	void Load();
	bool m_Disconnect;
	void OffHelper(DWORD id, float x, float y, float w, float h);
	void RenderHelperFrame(int This);
	void EventMuOffhelper(DWORD Event);
	void RunningOffHelper();
	void HelperOffline();
};
extern cMuOffHelper gMuHelper;
