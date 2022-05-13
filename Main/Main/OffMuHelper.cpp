#include "stdafx.h"
#include "CMacroUIEx.h"
#include "OffMuHelper.h"
#include "Util.h"
#include "Offset.h"
#include "Import.h"
#include "User.h"
#include "Interface.h"
#include "Defines.h"
#include "MuHelper.h"
#include "Protocol.h"
#include "Common.h"
#include "MiniMap.h"
#include "InfoLog.h"

cMuOffHelper gMuHelper;

void cMuOffHelper::Load()
{
	this->m_Disconnect = false;
}

void cMuOffHelper::OffHelper(DWORD id, float x, float y, float w, float h)
{
	pDrawGUI(id, x, y, w, h);

	if (gInterface.IsWorkZone(ButtonStartAttack))
	{
		if (gInterface.Data[ButtonStartAttack].OnClick)
		{
			if (offhelper == 0)
			{
				offhelper = 1;
			}
			else
			{
				offhelper = 0;
			}
			gInterface.Data[ButtonStartAttack].OnClick = false;
		}
	}
	if (offhelper == 1)
	{
		gInterface.DrawButtonRender(ButtonStartAttack, x + 50, y + 8, 0, 0);
	}
	else
	{
		gInterface.DrawButtonRender(ButtonStartAttack, x + 50, y + 8, 0, 15);
	}
	gInterface.DrawFormat(eWhite190, x + 50 + 16, y + 12, 60, 1, "Offline Helper");
}

void cMuOffHelper::RenderHelperFrame(int This)
{
	char Cord[256];
	EnableAlphaTest(1);
	glColor4f(1.0, 1.0, 1.0, 1.0);

	//Imagem 1
	float green = (double)*(signed int *)(This + 24);
	float red = (double)*(signed int *)(This + 20);
	DrawInterface(31602, red, green, 22.0, 25.0);

	//Imagem 2
	int v10 = pMakeColor(0xFFu, 0xFFu, 0xFFu, 0xFFu);
	float v11 = (double)*(signed int *)(This + 12);
	float v12 = (double)*(signed int *)(This + 24);
	float v13 = (double)(*(DWORD *)(This + 20) + 22);
	RenderBitMapColored(31603, v13, v12, v11, 25.0, 0.1, 0.0, 0.69999999, 0.78125, v10);

	//Imagem 3
	float v14 = (double)*(signed int *)(This + 24);
	float v15 = (double)(*(DWORD *)(This + 20) + *(DWORD *)(This + 12) + 22);
	pDrawGUI(31604, v15, v14, 73.0, 20.0);
	
	//Button Config
	sub_7798F0(This + 36, 0);

	//Button Start or Pause
	if (sub_4DB6B0((int)pMUHelperThis()))
	{
		if (offhelper == 1)
		{
			gMuHelper.RunningOffHelper();
		}
		sub_7798F0(This + 380, 0);
	}
	else
	{
		if (offhelper == 1)
		{
			gMuHelper.RunningOffHelper();
		}
		sub_7798F0(This + 208, 0);
	}

	//Mapa e Coordenadas
	if (World >= 84 && World <= 100)
	{
		wsprintf(Cord, "%s  (%d , %d)", pGetTextLine(pTextLineThis, (3669 + World - 84)), gObjUser.CoordenadaX, gObjUser.CoordenadaY);
	}
	else
	{
		wsprintf(Cord, "%s  (%d , %d)", pGetMapName(World), gObjUser.CoordenadaX, gObjUser.CoordenadaY);
	}

	//Textos

	int v20 = *(DWORD *)(This + 12) + 20;
	int v21 = *(DWORD *)(This + 24) + 5;
	int v22 = *(DWORD *)(This + 20) + 10;

	pSetFont(pTextThis(), (int)pFontNormal2);
	pSetBackgroundTextColor(pTextThis(), 0, 0, 0, 0);
	pSetTextColor(pTextThis(), 240, 240, 240, 255);
	pDrawText(pTextThis(), v22, v21, Cord, v20, 9, (PINT)3, 0);
	pGLSwitch();
	EnableAlphaTest(0);
}

void cMuOffHelper::EventMuOffhelper(DWORD Event)
{
	if ((GetTickCount() - gInterface.Data[ButtonStartAttack].EventTick) < 1000)
	{
		return;
	}
	
	if (gInterface.IsWorkZone(ButtonStartAttack))
	{
		if (Event == WM_LBUTTONDOWN)
		{
			gInterface.Data[ButtonStartAttack].OnClick = true;
			return;
		}
		// ----
		gInterface.Data[ButtonStartAttack].OnClick = false;
	
		// ----
		gInterface.Data[ButtonStartAttack].EventTick = GetTickCount();
		// ----
	}
}

void cMuOffHelper::RunningOffHelper()
{
	if (!*(BYTE*)(*(DWORD*)(MAIN_HELPER_STRUCT)+0x08))
	{
		return;
	}

	this->m_Disconnect = true;
	CG_OFFMODE_RESULT pRequest;
	pRequest.h.set((LPBYTE)&pRequest, 0xFB, 0x3D, sizeof(pRequest));
	//-- Range Attack
	pRequest.HuntingRange = *(WORD*)(*(DWORD*)(MAIN_HELPER_STRUCT)+172);
	//-- Auto Heling, Drain and Potion
	pRequest.RecoveryPotionOn = *(BYTE*)(*(DWORD*)(MAIN_HELPER_STRUCT)+176);
	pRequest.RecoveryPotionPercent = *(BYTE*)(*(DWORD*)(MAIN_HELPER_STRUCT)+177);
	pRequest.RecoveryHealOn = *(BYTE*)(*(DWORD*)(MAIN_HELPER_STRUCT)+178);
	pRequest.RecoveryHealPercent = *(BYTE*)(*(DWORD*)(MAIN_HELPER_STRUCT)+179);
	pRequest.RecoveryDrainOn = *(BYTE*)(*(DWORD*)(MAIN_HELPER_STRUCT)+180);
	pRequest.RecoveryDrainPercent = *(BYTE*)(*(DWORD*)(MAIN_HELPER_STRUCT)+181);
	//-- Attack
	pRequest.DistanceLongOn = *(BYTE*)(*(DWORD*)(MAIN_HELPER_STRUCT)+182);
	pRequest.DistanceReturnOn = *(BYTE*)(*(DWORD*)(MAIN_HELPER_STRUCT)+183);
	pRequest.DistanceMin = *(WORD*)(*(DWORD*)(MAIN_HELPER_STRUCT)+184);
	pRequest.SkillBasicID = *(WORD*)(*(DWORD*)(MAIN_HELPER_STRUCT)+188);
	pRequest.ComboOn = *(BYTE*)(*(DWORD*)(MAIN_HELPER_STRUCT)+240);
	//-- Party Settings
	pRequest.PartyModeOn = *(BYTE*)(*(DWORD*)(MAIN_HELPER_STRUCT)+241);
	pRequest.PartyModeHealOn = *(BYTE*)(*(DWORD*)(MAIN_HELPER_STRUCT)+242);
	pRequest.PartyModeHealPercent = *(BYTE*)(*(DWORD*)(MAIN_HELPER_STRUCT)+243);
	pRequest.PartyModeBuffOn = *(BYTE*)(*(DWORD*)(MAIN_HELPER_STRUCT)+244);
	//-- AutoBuffo
	pRequest.BuffOn = *(BYTE*)(*(DWORD*)(MAIN_HELPER_STRUCT)+260);
	pRequest.BuffSkill[0] = *(WORD*)(*(DWORD*)(MAIN_HELPER_STRUCT)+264);
	pRequest.BuffSkill[1] = *(WORD*)(*(DWORD*)(MAIN_HELPER_STRUCT)+268);
	pRequest.BuffSkill[2] = *(WORD*)(*(DWORD*)(MAIN_HELPER_STRUCT)+272);
	//-- PickObtain
	pRequest.ObtainRange = *(WORD*)(*(DWORD*)(MAIN_HELPER_STRUCT)+288);
	pRequest.ObtainRepairOn = *(BYTE*)(*(DWORD*)(MAIN_HELPER_STRUCT)+292);
	pRequest.ObtainPickNear = *(BYTE*)(*(DWORD*)(MAIN_HELPER_STRUCT)+293);
	pRequest.ObtainPickSelected = *(BYTE*)(*(DWORD*)(MAIN_HELPER_STRUCT)+294);
	pRequest.ObtainPickMoney = *(BYTE*)(*(DWORD*)(MAIN_HELPER_STRUCT)+297);
	pRequest.ObtainPickJewels = *(BYTE*)(*(DWORD*)(MAIN_HELPER_STRUCT)+295);
	pRequest.ObtainPickExcellent = *(BYTE*)(*(DWORD*)(MAIN_HELPER_STRUCT)+298);
	pRequest.ObtainPickAncient = *(BYTE*)(*(DWORD*)(MAIN_HELPER_STRUCT)+296);
	pRequest.ObtainPickExtra = *(BYTE*)(*(DWORD*)(MAIN_HELPER_STRUCT)+299);

	pRequest.ObtainPickExtraCount = 0;

	for (int i = 0; i < 12; i++)
	{
		ZeroMemory(pRequest.ObtainPickItemList[i], sizeof(pRequest.ObtainPickItemList[i]));
		wsprintf(pRequest.ObtainPickItemList[i], pGetItemList(i));

		if ((strcmp(pGetItemList(i), "") != 0))
		{
			pRequest.ObtainPickExtraCount++;
		}
	}

	DataSend((LPBYTE)&pRequest, pRequest.h.size);
}

void cMuOffHelper::HelperOffline()
{
	SetCompleteHook(0xE8, 0x007F76CD, &cMuOffHelper::OffHelper);
	SetCompleteHook(0xE9, 0x007D2BC0, &cMuOffHelper::RenderHelperFrame);
}