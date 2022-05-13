#include "StdAfx.h"
#include "user.h"
#include "protocol.h"
#include "StatsAdvanced.h"
#include "ServerInfo.h"
#include "Util.h"


CStatsAdvance g_StatsAdvance;

CStatsAdvance::CStatsAdvance()
{
	this->m_Enable = true;
}

CStatsAdvance::~CStatsAdvance()
{
}

void CStatsAdvance::Load()
{
	this->m_Enable = true;
}

void CStatsAdvance::Send(LPOBJ lpObj)
{
	PMSG_STATS_ADVANCE pMsg;

	pMsg.h.set(0xF3, 0xF3, sizeof(pMsg));

	pMsg.Result = true;
	pMsg.StatInfo.Level = lpObj->Level;
	pMsg.StatInfo.Reset = lpObj->Reset;
	pMsg.StatInfo.TotalDamageReflect = lpObj->DamageReflect;
	pMsg.StatInfo.FullDamageReflectRate = lpObj->FullDamageReflectRate;
	pMsg.StatInfo.CriticalDamageRate = lpObj->CriticalDamageRate;
	//--
	pMsg.StatInfo.CriticalDamagePVM = lpObj->CriticalDamageRate * gServerInfo.m_DamageRatePvM[lpObj->Class];
	pMsg.StatInfo.CriticalDamagePVP = lpObj->CriticalDamageRate * gServerInfo.m_DamageRatePvP[lpObj->Class];
	//--
	pMsg.StatInfo.ExellentDamageRate = lpObj->ExcellentDamageRate;
	//--
	pMsg.StatInfo.ExellentDamagePVM = lpObj->ExcellentDamageRate * gServerInfo.m_DamageRatePvM[lpObj->Class];
	pMsg.StatInfo.ExellentDamagePVP = lpObj->ExcellentDamageRate * gServerInfo.m_DamageRatePvP[lpObj->Class];
	//--
	pMsg.StatInfo.DoubleDamageRate = lpObj->DoubleDamageRate;
	pMsg.StatInfo.TripleDamageRate = lpObj->TripleDamageRate;
	pMsg.StatInfo.DamageReductionRate = lpObj->DamageReduction[MAX_DAMAGE_REDUCTION];
	pMsg.StatInfo.ShieldSkillDamageReductionRate = lpObj->ShieldDamageReduction;
	pMsg.StatInfo.SDDamageReductionRate = lpObj->DamageReduction[DAMAGE_REDUCTION_JOH_ITEM];
	pMsg.StatInfo.SDDecreaseDamageRate = lpObj->DecreaseShieldGaugeRate;
	pMsg.StatInfo.IgnoreDefenceRate = lpObj->IgnoreDefenseRate;
	pMsg.StatInfo.IgnoreSDRate = lpObj->IgnoreShieldGaugeRate;
	pMsg.StatInfo.IncreaseDamagePvP = lpObj->AttackSuccessRatePvP;
	pMsg.StatInfo.IncreaseDefencePvP = lpObj->DefenseSuccessRatePvP;
	pMsg.StatInfo.ResistDoubleDamageRate = lpObj->ResistDoubleDamageRate;
	pMsg.StatInfo.ResistIgnoreDefenceRate = lpObj->ResistIgnoreDefenseRate;
	pMsg.StatInfo.ResistIgnoreSDRate = lpObj->ResistIgnoreShieldGaugeRate;
	pMsg.StatInfo.ResistCriticalDamageRate = lpObj->ResistCriticalDamageRate;
	pMsg.StatInfo.ResistExellentDamageRate = lpObj->ResistExcellentDamageRate;
	pMsg.StatInfo.ResistStumRate = lpObj->ResistStunRate;
	pMsg.StatInfo.IncreaseIce = lpObj->AddResistance[0];
	pMsg.StatInfo.IncreasePoison = lpObj->AddResistance[1];
	pMsg.StatInfo.IncreaseLighting = lpObj->AddResistance[2];
	pMsg.StatInfo.IncreaseFire = lpObj->AddResistance[3];
	pMsg.StatInfo.IncreaseEarth = lpObj->AddResistance[4];
	pMsg.StatInfo.IncreaseWind = lpObj->AddResistance[5];
	pMsg.StatInfo.IncreaseWater = lpObj->AddResistance[6];
	pMsg.StatInfo.ResistIce = lpObj->Resistance[0];
	pMsg.StatInfo.ResistPoison = lpObj->Resistance[1];
	pMsg.StatInfo.ResistLighting = lpObj->Resistance[2];
	pMsg.StatInfo.ResistFire = lpObj->Resistance[3];
	pMsg.StatInfo.ResistEarth = lpObj->Resistance[4];
	pMsg.StatInfo.ResistWind = lpObj->Resistance[5];
	pMsg.StatInfo.ResistWater = lpObj->Resistance[6];
	pMsg.StatInfo.FullHPRestoreRateDef = lpObj->DefensiveFullHPRestoreRate;
	pMsg.StatInfo.FullMPRestoreRateDef = lpObj->DefensiveFullMPRestoreRate;
	pMsg.StatInfo.FullSDRestoreRateDef = lpObj->DefensiveFullSDRestoreRate;
	pMsg.StatInfo.FullHPRestoreRate = lpObj->OffensiveFullHPRestoreRate;
	pMsg.StatInfo.FullMPRestoreRate = lpObj->OffensiveFullMPRestoreRate;
	pMsg.StatInfo.FullSDRestoreRate = lpObj->OffensiveFullSDRestoreRate;
	DataSend(lpObj->Index, (BYTE*)&pMsg, pMsg.h.size);
}