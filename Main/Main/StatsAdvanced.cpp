#include "stdafx.h"
#include "protocol.h"
#include "Interface.h"
#include "StatsAdvanced.h"
#include "Defines.h"


CStatsAdvance g_StatsAdvance;

CStatsAdvance::CStatsAdvance()
{
	this->m_Enable = false;
	this->m_Loaded = false;

	memset(&this->m_Data, 0, sizeof(this->m_Data));
}

CStatsAdvance::~CStatsAdvance()
{
}

void CStatsAdvance::Load()
{
	this->m_Enable = true;
}

void CStatsAdvance::DrawInfo()
{
	if (!this->m_Enable && !this->m_Loaded)
	{
		return;
	}

	if (!gInterface.CheckWindow(ObjWindow::Character))
	{
		return;
	}

	pLoadImage("Custom\\Interface\\info_block.tga", ex_INFO_2, 0x2601, 0x2900, 1, 0);

	DWORD dwColor = eWhite;
	float flDrawX = this->m_CharX + 583;	//450;
	float flDrawY = this->m_CharY + 85;	//18;

	gInterface.DrawGUI(eADVANCE_STAT_INFO, flDrawX, flDrawY-10);

	if (!gInterface.IsWorkZone(eADVANCE_STAT_INFO))
	{
		return;
	}

	flDrawX = this->m_CharX + 450;	// - 15;
	flDrawY = 0;//this->m_CharY - 52;	//18;

	float flWidth = 190;
	float flHight = 430;

	gInterface.DrawBarForm(flDrawX, flDrawY, flWidth, flHight, 0, 0, 0, 1.0);
	flDrawY += 15;

	this->DrawLine(flDrawX, flDrawY, flWidth, "Total Damage Reflect:");
	flDrawY = this->DrawLineR(flDrawX, flDrawY, flWidth, eGold, "%d%%", this->m_Data.TotalDamageReflect);
	
	this->DrawLine(flDrawX, flDrawY, flWidth, "Full DamageReflect Rate:");
	flDrawY = this->DrawLineR(flDrawX, flDrawY, flWidth, eGold, "%d%%", this->m_Data.FullDamageReflectRate);
	
	this->DrawLine(flDrawX, flDrawY, flWidth, "Critical Damage Rate:");
	flDrawY = this->DrawLineR(flDrawX, flDrawY, flWidth, eGold, "%d%%", this->m_Data.CriticalDamageRate);
	
	this->DrawLine(flDrawX, flDrawY, flWidth, "Critical Damage (PVM):");
	flDrawY = this->DrawLineR(flDrawX, flDrawY, flWidth, eBlue, "%d", this->m_Data.CriticalDamagePVM);

	this->DrawLine(flDrawX, flDrawY, flWidth, "Critical Damage (PVP)");
	flDrawY = this->DrawLineR(flDrawX, flDrawY, flWidth, eBlue, "%d", this->m_Data.CriticalDamagePVP);
	
	this->DrawLine(flDrawX, flDrawY, flWidth, "Exellent Damage Rate:");
	flDrawY = this->DrawLineR(flDrawX, flDrawY, flWidth, eGold, "%d%%", this->m_Data.ExellentDamageRate);
	
	this->DrawLine(flDrawX, flDrawY, flWidth, "Exellent Damage (PVM):");
	flDrawY = this->DrawLineR(flDrawX, flDrawY, flWidth, eAncient, "%d", this->m_Data.ExellentDamagePVM);

	this->DrawLine(flDrawX, flDrawY, flWidth, "Exellent Damage (PVP):");
	flDrawY = this->DrawLineR(flDrawX, flDrawY, flWidth, eAncient, "%d", this->m_Data.ExellentDamagePVP);
	
	this->DrawLine(flDrawX, flDrawY, flWidth, "Double Damage Rate:");
	flDrawY = this->DrawLineR(flDrawX, flDrawY, flWidth, eGold, "%d%%", this->m_Data.DoubleDamageRate);
	
	this->DrawLine(flDrawX, flDrawY, flWidth, "Triple Damage Rate:");
	flDrawY = this->DrawLineR(flDrawX, flDrawY, flWidth, eGold, "%d%%", this->m_Data.TripleDamageRate);
	
	this->DrawLine(flDrawX, flDrawY, flWidth, "Damage Reduction Rate:");
	flDrawY = this->DrawLineR(flDrawX, flDrawY, flWidth, eGold, "%d%%", this->m_Data.DamageReductionRate);
	
	this->DrawLine(flDrawX, flDrawY, flWidth, "Shield Skill Damage Reduction Rate:");
	flDrawY = this->DrawLineR(flDrawX, flDrawY, flWidth, eGold, "%d%%", this->m_Data.ShieldSkillDamageReductionRate);
	
	this->DrawLine(flDrawX, flDrawY, flWidth, "SD Damage Reduction Rate:");
	flDrawY = this->DrawLineR(flDrawX, flDrawY, flWidth, eGold, "%d%%", this->m_Data.SDDamageReductionRate);
	
	this->DrawLine(flDrawX, flDrawY, flWidth, "SD Decrease Damage Rate:");
	flDrawY = this->DrawLineR(flDrawX, flDrawY, flWidth, eGold, "%d%%", this->m_Data.SDDecreaseDamageRate);
	
	this->DrawLine(flDrawX, flDrawY, flWidth, "Ignore Defence Rate:");
	flDrawY = this->DrawLineR(flDrawX, flDrawY, flWidth, eGold, "%d%%", this->m_Data.IgnoreDefenceRate);
	
	this->DrawLine(flDrawX, flDrawY, flWidth, "Ignore SD Rate:");
	flDrawY = this->DrawLineR(flDrawX, flDrawY, flWidth, eGold, "%d%%", this->m_Data.IgnoreSDRate);
	
	this->DrawLine(flDrawX, flDrawY, flWidth, "Increase Damage PvP:");
	flDrawY = this->DrawLineR(flDrawX, flDrawY, flWidth, eGold, "%d", this->m_Data.IncreaseDamagePvP);
	
	this->DrawLine(flDrawX, flDrawY, flWidth, "Increase Defence PvP:");
	flDrawY = this->DrawLineR(flDrawX, flDrawY, flWidth, eGold, "%d", this->m_Data.IncreaseDefencePvP);
	
	this->DrawLine(flDrawX, flDrawY, flWidth, "Resist Double Damage Rate:");
	flDrawY = this->DrawLineR(flDrawX, flDrawY, flWidth, eGold, "%d%%", this->m_Data.ResistDoubleDamageRate);
	
	this->DrawLine(flDrawX, flDrawY, flWidth, "Resist Ignore Defence Rate:");
	flDrawY = this->DrawLineR(flDrawX, flDrawY, flWidth, eGold, "%d%%", this->m_Data.ResistIgnoreDefenceRate);
	
	this->DrawLine(flDrawX, flDrawY, flWidth, "Resist Ignore SD Rate:");
	flDrawY = this->DrawLineR(flDrawX, flDrawY, flWidth, eGold, "%d%%", this->m_Data.ResistIgnoreSDRate);
	
	this->DrawLine(flDrawX, flDrawY, flWidth, "Resist Critical Damage Rate:");
	flDrawY = this->DrawLineR(flDrawX, flDrawY, flWidth, eGold, "%d%%", this->m_Data.ResistCriticalDamageRate);
	
	this->DrawLine(flDrawX, flDrawY, flWidth, "Resist Exellent Damage Rate:");
	flDrawY = this->DrawLineR(flDrawX, flDrawY, flWidth, eGold, "%d%%", this->m_Data.ResistExellentDamageRate);
	
	this->DrawLine(flDrawX, flDrawY, flWidth, "Resist Stum Rate:");
	flDrawY = this->DrawLineR(flDrawX, flDrawY, flWidth, eGold, "%d%%", this->m_Data.ResistStumRate);
	
	this->DrawLine(flDrawX, flDrawY, flWidth, "Ice Increase / Resist Rate:");
	flDrawY = this->DrawLineR(flDrawX, flDrawY, flWidth, eGold, "%d - %d%%", this->m_Data.IncreaseIce, this->m_Data.ResistIce);
	
	this->DrawLine(flDrawX, flDrawY, flWidth, "Poison Increase / Resist Rate:");
	flDrawY = this->DrawLineR(flDrawX, flDrawY, flWidth, eGold, "%d - %d%%", this->m_Data.IncreasePoison, this->m_Data.ResistPoison);
	
	this->DrawLine(flDrawX, flDrawY, flWidth, "Lighting Increase / Resist Rate:");
	flDrawY = this->DrawLineR(flDrawX, flDrawY, flWidth, eGold, "%d - %d%%", this->m_Data.IncreaseLighting, this->m_Data.ResistLighting);
	
	this->DrawLine(flDrawX, flDrawY, flWidth, "Fire Increase / Resist Rate:");
	flDrawY = this->DrawLineR(flDrawX, flDrawY, flWidth, eGold, "%d - %d%%", this->m_Data.IncreaseFire, this->m_Data.ResistFire);
	
	this->DrawLine(flDrawX, flDrawY, flWidth, "Earth Increase / Resist Rate:");
	flDrawY = this->DrawLineR(flDrawX, flDrawY, flWidth, eGold, "%d - %d%%", this->m_Data.IncreaseEarth, this->m_Data.ResistEarth);
	
	this->DrawLine(flDrawX, flDrawY, flWidth, "Wind Increase / Resist Rate:");
	flDrawY = this->DrawLineR(flDrawX, flDrawY, flWidth, eGold, "%d - %d%%", this->m_Data.IncreaseWind, this->m_Data.ResistWind);
	
	this->DrawLine(flDrawX, flDrawY, flWidth, "Water Increase / Resist Rate:");
	flDrawY = this->DrawLineR(flDrawX, flDrawY, flWidth, eGold, "%d - %d%%", this->m_Data.IncreaseWater, this->m_Data.ResistWater);
	
	this->DrawLine(flDrawX, flDrawY, flWidth, "Full HP Restore Rate (Def, Att):");
	flDrawY = this->DrawLineR(flDrawX, flDrawY, flWidth, eGold, "%d%% - %d%%", this->m_Data.FullHPRestoreRateDef, this->m_Data.FullHPRestoreRate);
	
	this->DrawLine(flDrawX, flDrawY, flWidth, "Full MP Restore Rate (Def, Att):");
	flDrawY = this->DrawLineR(flDrawX, flDrawY, flWidth, eGold, "%d%% - %d%%", this->m_Data.FullMPRestoreRateDef, this->m_Data.FullMPRestoreRate);
	
	this->DrawLine(flDrawX, flDrawY, flWidth, "Full SD Restore Rate (Def, Att):");
	flDrawY = this->DrawLineR(flDrawX, flDrawY, flWidth, eGold, "%d%% - %d%%", this->m_Data.FullSDRestoreRateDef, this->m_Data.FullSDRestoreRate);

	gInterface.DrawFormat(eGold180, flDrawX, 5, flWidth, 3, "ADVANCED STATUS");

}

void CStatsAdvance::DrawLine(float PosX, float PosY, int Width, LPCSTR Text, ...)
{
	float flResult = 0.0;

	char szBuff[256];
	int iBuffLen = sizeof(szBuff) - 1;
	ZeroMemory(szBuff, iBuffLen);

	va_list args;
	va_start(args, Text);
	int Len = vsprintf_s(szBuff, iBuffLen, Text, args);
	va_end(args);

	pDrawColorText(szBuff, PosX + 10, PosY, 150, 0, eWhite, 0, 1);
}

float CStatsAdvance::DrawLineR(float PosX, float PosY, int Width, DWORD dwColor, LPCSTR Text, ...)
{
	float flResult = 0.0;

	char szBuff[256];
	int iBuffLen = sizeof(szBuff) - 1;
	ZeroMemory(szBuff, iBuffLen);

	va_list args;
	va_start(args, Text);
	int Len = vsprintf_s(szBuff, iBuffLen, Text, args);
	va_end(args);

	pDrawColorText(szBuff, PosX + 140, PosY, 50, 0, dwColor, 0, 1);

	pDrawColorButton(31460, PosX + 10, PosY + 10, Width - 20, 0.85, NULL, NULL, 0);

	flResult = PosY + 12;

	return flResult;
}

void CStatsAdvance::Recv(PMSG_STATS_ADVANCE* lpMsg)
{
	if (!lpMsg->Result)
	{
		return;
	}

	memcpy(&this->m_Data, &lpMsg->StatInfo, sizeof(this->m_Data));

	this->m_Loaded = true;
}