// CustomAttack.h: interface for the CCustomAttack class.
//
//////////////////////////////////////////////////////////////////////

#pragma once

#include "User.h"
#include "Protocol.h"
#include "DefaultClassInfo.h"

struct SDHP_CARESUME_SEND
{
    PBMSG_HEAD header; // C1:F5
    WORD index;
    char name[11];
};

struct SDHP_CARESUME_SAVE_SEND
{
    PBMSG_HEAD header; // C1:F6
    WORD index;
    char name[11];
	WORD active;
	WORD skill;
	WORD map;
	WORD posx;
	WORD posy;
	WORD autobuff;
	WORD offpvp;
	WORD autoreset;
	DWORD autoaddstr;
	DWORD autoaddagi;
	DWORD autoaddvit;
	DWORD autoaddene;
	DWORD autoaddcmd;
};

struct SDHP_CARESUME_RECV
{
    PBMSG_HEAD header; // C1:F5
    WORD index;
    char name[11];
	WORD active;
	WORD skill;
	WORD map;
	WORD posx;
	WORD posy;
	WORD autobuff;
	WORD offpvp;
	WORD autoreset;
	DWORD autoaddstr;
	DWORD autoaddagi;
	DWORD autoaddvit;
	DWORD autoaddene;
	DWORD autoaddcmd;
};

struct CUSTOM_ATTACK_SKILL_INFO
{
	int Class;
	int Skill;
	int Group;
	int BaseSpeed;
	int MainSpeed;
};

class CCustomAttack
{
public:
	CCustomAttack();
	virtual ~CCustomAttack();
	void ReadCustomAttackInfo(char* section,char* path);
	void Load(char* path);
	void SetInfo(CUSTOM_ATTACK_SKILL_INFO info);
	CUSTOM_ATTACK_SKILL_INFO* GetInfo(int Class,int SkillNumber);
	bool CommandCustomAttack(LPOBJ lpObj,char* arg);
	bool CommandCustomAttackOffline(LPOBJ lpObj,char* arg);
	bool GetAttackSkill(LPOBJ lpObj,int* SkillNumber,int SetSkill);
	bool GetTargetMonster(LPOBJ lpObj,int SkillNumber,int* MonsterIndex);
	void OnAttackClose(LPOBJ lpObj);
	void OnAttackSecondProc(LPOBJ lpObj);
	void OnAttackAlreadyConnected(LPOBJ lpObj);
	void OnAttackMonsterAndMsgProc(LPOBJ lpObj);
	void SendSkillAttack(LPOBJ lpObj,int aIndex,int SkillNumber);
	void SendMultiSkillAttack(LPOBJ lpObj,int aIndex,int SkillNumber);
	void SendDurationSkillAttack(LPOBJ lpObj,int aIndex,int SkillNumber);
	void SendRFSkillAttack(LPOBJ lpObj,int aIndex,int SkillNumber);
	void GetTargetParty(LPOBJ lpObj,int SkillNumber);
	void DGCustomAttackResumeSend(int aIndex);
	void DGCustomAttackResumeRecv(SDHP_CARESUME_RECV* lpMsg);
	void DGCustomAttackResumeSaveSend(int Index);
	void CustomAttackUseSkill(LPOBJ lpObj,LPOBJ lpTarget,CUSTOM_ATTACK_SKILL_INFO* lpInfo,CSkill* lpSkill);
	CSkill* CustomAttackFindSkill(LPOBJ lpObj,int SkillNumber) ;
	int GetSkillApply(int index);
	int GetSkillGroup(int index);
	int GetSkillMainSpeed(int index);
	int GetSkillBaseSpeed(int index);
public:
	std::map<int,CUSTOM_ATTACK_SKILL_INFO> m_CustomAttackSkillInfo;
	int m_CustomAttackTime[4];
	int m_CustomAttackOfflineGPGain;
	int m_CustomAttackDelay;
	int m_CustomAttackPotionDelay;
	int m_CustomAttackAutoBuff[4];
	int m_CustomAttackAutoBuffDelay;
	int m_CustomAttackAutoResume[4];
};

extern CCustomAttack gCustomAttack;
