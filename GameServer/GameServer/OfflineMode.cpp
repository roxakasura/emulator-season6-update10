#include "StdAfx.h"
#include "OfflineMode.h"
#include "user.h"
#include "GameMain.h"
#include "Message.h"
#include "MapServerManager.h"
#include "Util.h"
#include "Path.h"
#include "Notice.h"
#include "Map.h"
#include "Skill.h"
#include "Party.h"
#include "Attack.h"
#include "Quest.h"
#include "QuestObjective.h"
#include "SkillManager.h"
#include "ServerInfo.h"
#include "ObjectManager.h"
#include "Viewport.h"
#include "EffectManager.h"
#include "CustomAttack.h"
#include "ItemManager.h"
#include "MapManager.h"
#include "Log.h"

OfflineMode g_OfflineMode;


OfflineMode::OfflineMode()
{
	this->m_bLoadedDB = false;
}
// ----------------------------------------------------------------------------------------------

OfflineMode::~OfflineMode()
{
}

void OfflineMode::ReadOffLine(char* section,char* path)
{
	this->m_MUOffHelperEnabled[0] = GetPrivateProfileInt(section, "MuOffHelperEnabled_AL0", 0, path);
	this->m_MUOffHelperEnabled[1] = GetPrivateProfileInt(section, "MuOffHelperEnabled_AL1", 0, path);
	this->m_MUOffHelperEnabled[2] = GetPrivateProfileInt(section, "MuOffHelperEnabled_AL2", 0, path);
	this->m_MUOffHelperEnabled[3] = GetPrivateProfileInt(section, "MuOffHelperEnabled_AL3", 0, path);
	this->m_MUOffHelperTimer[0] = GetPrivateProfileInt(section, "MuOffHelperTime_AL0", -1, path);
	this->m_MUOffHelperTimer[1] = GetPrivateProfileInt(section, "MuOffHelperTime_AL1", -1, path);
	this->m_MUOffHelperTimer[2] = GetPrivateProfileInt(section, "MuOffHelperTime_AL2", -1, path);
	this->m_MUOffHelperTimer[3] = GetPrivateProfileInt(section, "MuOffHelperTime_AL3", -1, path);
}

void OfflineMode::OnHelperpAlreadyConnected(LPOBJ lpObj) // OK
{
	if(lpObj->m_OfflineMode != 0)
	{
		gObjDel(lpObj->Index);
		lpObj->m_OfflineMode = 0;
		lpObj->MuOffHelperTime = 0;
	}
}

void OfflineMode::Start(CG_OFFMODE_RESULT* aRecv, int aIndex)
{
	if (!gObjIsConnectedGP(aIndex))
	{
		return;
	}

	LPOBJ lpObj = &gObj[aIndex];

	if(gMapManager.GetMapHelperEnable(lpObj->Map) == 0)
	{
		gNotice.GCNoticeSend(lpObj->Index,1,0,0,0,0,0,"[Helper] Disable");
		return;
	}

	if(this->m_MUOffHelperEnabled[lpObj->AccountLevel] == 0)
	{
		gNotice.GCNoticeSend(lpObj->Index,1,0,0,0,0,0,gMessage.GetMessage(64));
		return;
	}

	switch(lpObj->Map)
	{
	case MAP_INDEX_CASTLESIEGE:
		gNotice.GCNoticeSend(aIndex, 1, 0, 0, 0, 0, 0, "[OfflineMode] Disable in Castle siege map");
		return;
	case MAP_INDEX_CRYWOLF_FIRSTZONE:
		gNotice.GCNoticeSend(aIndex, 1, 0, 0, 0, 0, 0, "[OfflineMode] Disable in Crywolf map");
		return;
	case MAP_INDEX_CRYWOLF_SECONDZONE:
		gNotice.GCNoticeSend(aIndex, 1, 0, 0, 0, 0, 0, "[OfflineMode] Disable in Crywolf map");
		return;
	case MAP_INDEX_CASTLEHUNTZONE:
		gNotice.GCNoticeSend(aIndex, 1, 0, 0, 0, 0, 0, "[OfflineMode] Disable in This Map");
		return;
	case MAP_INDEX_BALGASS_BARRACKS:
		gNotice.GCNoticeSend(aIndex, 1, 0, 0, 0, 0, 0, "[OfflineMode] Disable in This Map");
		return;
	case MAP_INDEX_BALGASS_REFUGEE:
		gNotice.GCNoticeSend(aIndex, 1, 0, 0, 0, 0, 0, "[OfflineMode] Disable in This Map");
		return;
	}
	//===========
	lpObj->HuntingRange = aRecv->HuntingRange;
	//--
	lpObj->RecoveryPotionOn = aRecv->RecoveryPotionOn;
	lpObj->RecoveryPotionPercent = aRecv->RecoveryPotionPercent;
	lpObj->RecoveryHealOn = (lpObj->Class == CLASS_FE) ? aRecv->RecoveryHealOn : 0; //-> CLASS_ELF
	lpObj->RecoveryHealPercent = (lpObj->Class == CLASS_FE) ? aRecv->RecoveryHealPercent : 0; //-> CLASS_ELF
	lpObj->RecoveryDrainOn = (lpObj->Class == CLASS_SU) ? aRecv->RecoveryDrainOn : 0; //-> CLASS_SUMMONER
	lpObj->RecoveryDrainPercent = (lpObj->Class == CLASS_SU) ?aRecv->RecoveryDrainPercent : 0; //-> CLASS_SUMMONER
	//--
	lpObj->DistanceLongOn = aRecv->DistanceLongOn;
	lpObj->DistanceReturnOn = aRecv->DistanceReturnOn;
	lpObj->DistanceMin = aRecv->DistanceMin;
	lpObj->SkillBasicID = aRecv->SkillBasicID;
	lpObj->ComboOn = (lpObj->Class == CLASS_DK) ? aRecv->ComboOn : 0;				//-> CLASS_KNIGHT
	//--
	lpObj->PartyModeOn = aRecv->PartyModeOn;
	lpObj->PartyModeHealOn = (lpObj->Class == CLASS_FE) ? aRecv->PartyModeHealOn : 0;		//-> CLASS_ELF
	lpObj->PartyModeHealPercent = (lpObj->Class == CLASS_FE) ? aRecv->PartyModeHealPercent : 0;	//-> CLASS_ELF
	lpObj->PartyModeBuffOn = aRecv->PartyModeBuffOn;
	//--
	lpObj->BuffOn = aRecv->BuffOn;
	lpObj->BuffSkill[0] = aRecv->BuffSkill[0];
	lpObj->BuffSkill[1] = aRecv->BuffSkill[1];
	lpObj->BuffSkill[2] = aRecv->BuffSkill[2];
	lpObj->ObtainRange = (DWORD) aRecv->ObtainRange;
	lpObj->ObtainRepairOn = aRecv->ObtainRepairOn;
	lpObj->ObtainPickNear = (aRecv->ObtainPickNear != 0) ? 1 : 0;
	lpObj->ObtainPickSelected = aRecv->ObtainPickSelected;
	lpObj->ObtainPickJewels = (aRecv->ObtainPickJewels != 0) ? 1 : 0;
	lpObj->ObtainPickAncient = (aRecv->ObtainPickAncient != 0) ? 1 : 0;
	lpObj->ObtainPickMoney = (aRecv->ObtainPickMoney != 0) ? 1 : 0;
	lpObj->ObtainPickExcellent = (aRecv->ObtainPickExcellent != 0) ? 1 : 0;
	lpObj->ObtainPickExtra = (aRecv->ObtainPickExtra != 0) ? 1 : 0;
	lpObj->ObtainPickExtraCount = aRecv->ObtainPickExtraCount;
	
	for(int i = 0 ; i < lpObj->ObtainPickExtraCount ; ++i)
	{
		memcpy(lpObj->ObtainPickItemList[ i ], aRecv->ObtainPickItemList[ i ], sizeof(lpObj->ObtainPickItemList[ i ]));
	}

	//===========
	lpObj->m_OfflineCoordX = lpObj->X;
	lpObj->m_OfflineCoordY = lpObj->Y;
	lpObj->m_OfflineTimeResetMove = GetTickCount();
	lpObj->AttackCustomDelay = GetTickCount();
	lpObj->MuOffHelperTime = this->m_MUOffHelperTimer[lpObj->AccountLevel] * 600;
	lpObj->m_OfflineSocket = true;
	CloseClient(aIndex);
	lpObj->m_OfflineSocket = false;
	lpObj->m_OfflineMode = 1;
	lpObj->orderskill = 0;
}

void OfflineMode::OnAttackSecondProcHelper(LPOBJ lpObj) // OK
{
	if(lpObj->m_OfflineMode != 0)
	{
		lpObj->CheckSumTime = GetTickCount();
		lpObj->ConnectTickCount = GetTickCount();
		lpObj->PcPointPointTime = ((gCustomAttack.m_CustomAttackOfflineGPGain == 0)?GetTickCount():lpObj->PcPointPointTime);
		lpObj->CashShopGoblinPointTime = ((gCustomAttack.m_CustomAttackOfflineGPGain == 0)?GetTickCount():lpObj->CashShopGoblinPointTime);
	}
}

void AnimationMove(int aIndex, int x, int y)
{
	LPOBJ lpObj = &gObj[aIndex];

	int map_num = gObj[aIndex].Map;
 
	BYTE path[8];
 
	if (lpObj->Teleport != 0)
	{
		return;
	}
 
	if (gObjCheckMapTile(lpObj, 1) != 0)
	{
		return;
	}
 
	if ((GetTickCount() - lpObj->LastMoveTime) < 100)
	{
		return;
	}
 
	if (gEffectManager.CheckStunEffect(lpObj) != 0 || gEffectManager.CheckImmobilizeEffect(lpObj) != 0)
	{
		return;
	}
 
	if (lpObj->SkillSummonPartyTime != 0)
	{
		lpObj->SkillSummonPartyTime = 0;
		gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, gMessage.GetMessage(272));
	}
 
	lpObj->Dir = path[0] >> 4;
	lpObj->Rest = 0;
	lpObj->PathCur = 0;
	lpObj->PathCount = path[0] & 0x0F;
	lpObj->LastMoveTime = GetTickCount();
 
	memset(lpObj->PathX, 0, sizeof(lpObj->PathX));
 
	memset(lpObj->PathY, 0, sizeof(lpObj->PathY));
 
	memset(lpObj->PathOri, 0, sizeof(lpObj->PathOri));
 
	lpObj->TX = x;
	lpObj->TY = y;
	lpObj->PathCur = ((lpObj->PathCount > 0) ? 1 : 0);
	lpObj->PathCount = ((lpObj->PathCount > 0) ? (lpObj->PathCount + 1) : lpObj->PathCount);
	lpObj->PathStartEnd = 1;
	lpObj->PathX[0] = x;
	lpObj->PathY[0] = y;
	lpObj->PathDir[0] = lpObj->Dir;
 
	for (int n = 1; n < lpObj->PathCount; n++)
	{
		if ((n % 2) == 0)
		{
			lpObj->TX = lpObj->PathX[n - 1] + RoadPathTable[((path[((n + 1) / 2)] & 0x0F) * 2) + 0];
			lpObj->TY = lpObj->PathY[n - 1] + RoadPathTable[((path[((n + 1) / 2)] & 0x0F) * 2) + 1];
			lpObj->PathX[n] = lpObj->PathX[n - 1] + RoadPathTable[((path[((n + 1) / 2)] & 0x0F) * 2) + 0];
			lpObj->PathY[n] = lpObj->PathY[n - 1] + RoadPathTable[((path[((n + 1) / 2)] & 0x0F) * 2) + 1];
			lpObj->PathOri[n - 1] = path[((n + 1) / 2)] & 0x0F;
			lpObj->PathDir[n + 0] = path[((n + 1) / 2)] & 0x0F;
		}
		else
		{
			lpObj->TX = lpObj->PathX[n - 1] + RoadPathTable[((path[((n + 1) / 2)] / 0x10) * 2) + 0];
			lpObj->TY = lpObj->PathY[n - 1] + RoadPathTable[((path[((n + 1) / 2)] / 0x10) * 2) + 1];
			lpObj->PathX[n] = lpObj->PathX[n - 1] + RoadPathTable[((path[((n + 1) / 2)] / 0x10) * 2) + 0];
			lpObj->PathY[n] = lpObj->PathY[n - 1] + RoadPathTable[((path[((n + 1) / 2)] / 0x10) * 2) + 1];
			lpObj->PathOri[n - 1] = path[((n + 1) / 2)] / 0x10;
			lpObj->PathDir[n + 0] = path[((n + 1) / 2)] / 0x10;
		}
	}

	lpObj->X = x;
	lpObj->Y = y;
	lpObj->TX = lpObj->TX;
	lpObj->TY = lpObj->TY;
	lpObj->OldX = lpObj->TX;
	lpObj->OldY = lpObj->TY;
	lpObj->ViewState = 0;
 
	gMap[lpObj->Map].SetStandAttr(lpObj->TX, lpObj->TY);
 
	PMSG_MOVE_SEND pMsg;
 
	pMsg.header.set(PROTOCOL_CODE1, sizeof(pMsg));
 
	pMsg.index[0] = SET_NUMBERHB(lpObj->Index);
 
	pMsg.index[1] = SET_NUMBERLB(lpObj->Index);
 
	pMsg.x = (BYTE)lpObj->TX;
 
	pMsg.y = (BYTE)lpObj->TY;
 
	pMsg.dir = lpObj->Dir << 4;
	lpObj->PathCur = 0;
	lpObj->PathCount = 0;
	lpObj->TX = lpObj->X;
	lpObj->TY = lpObj->Y;
	pMsg.x = (BYTE) lpObj->X;
	pMsg.y = (BYTE) lpObj->Y;
 
	for (int n = 0; n < MAX_VIEWPORT; n++)
	{
		if (lpObj->VpPlayer2[n].type == OBJECT_USER)
		{
			if (lpObj->VpPlayer2[n].state != OBJECT_EMPTY && lpObj->VpPlayer2[n].state != OBJECT_DIECMD && lpObj->VpPlayer2[n].state != OBJECT_DIED)
			{
				DataSend(lpObj->VpPlayer2[n].index, (BYTE*)&pMsg, pMsg.header.size);
			}
		}
	}
}

void MuOffHelperRepair(int aIndex)
{
	if (!gObjIsConnectedGP(aIndex))
	{
		return;
	}

	LPOBJ lpObj = &gObj[aIndex];

	for(int n=0 ; n < INVENTORY_WEAR_SIZE; ++n)
	{
		if(lpObj->Inventory[n].IsItem() != 0)
		{
			int money = gItemManager.RepairItem(lpObj,&lpObj->Inventory[n], n, 1);

			if(money != 0)
			{
				gObjectManager.CharacterCalcAttribute(aIndex);
			}
		}
	}
}

void OfflineMode::Attack(int aIndex)
{
	if (OBJMAX_RANGE(aIndex) == FALSE)
	{
		return;
	}

	if (!gObjIsConnectedGP(aIndex))
	{
		return;
	}

	LPOBJ lpObj = &gObj[aIndex];

	if (lpObj->m_OfflineMode == 0)
	{
		return;
	}

	if (gServerInfo.InSafeZone(aIndex) == true)
	{
		this->OnHelperpAlreadyConnected(lpObj);
		return;
	}

	if(lpObj->MuOffHelperTime > 0)
	{
		if((--lpObj->MuOffHelperTime) == 0)
		{
			gObjDel(lpObj->Index);
			lpObj->m_OfflineMode = 0;
			lpObj->MuOffHelperTime = 0;
		}
	}

	this->RenderAutoPote(aIndex);

	this->RenderAutoBuffParty(aIndex);

	this->RenderAttack(aIndex);

	MuOffHelperRepair(aIndex);
}

void OfflineMode::RenderAutoPote(int aIndex)	//-- OK
{
	if (!gObjIsConnectedGP(aIndex))
	{
		return;
	}

	LPOBJ lpObj = &gObj[aIndex];

	//-- AUTO POTION HP
	if(lpObj->RecoveryPotionOn != 0)
	{
		if( lpObj->Life > 0 && lpObj->Life < (( lpObj->MaxLife * lpObj->RecoveryPotionPercent) / 100) )
		{
			PMSG_ITEM_USE_RECV pMsg;

			pMsg.header.set(0x26,sizeof(pMsg));

			pMsg.SourceSlot = 0xFF;

			pMsg.SourceSlot = ((pMsg.SourceSlot==0xFF)?gItemManager.GetInventoryItemSlot(lpObj,GET_ITEM(14,3),-1):pMsg.SourceSlot);

			pMsg.SourceSlot = ((pMsg.SourceSlot==0xFF)?gItemManager.GetInventoryItemSlot(lpObj,GET_ITEM(14,2),-1):pMsg.SourceSlot);

			pMsg.SourceSlot = ((pMsg.SourceSlot==0xFF)?gItemManager.GetInventoryItemSlot(lpObj,GET_ITEM(14,1),-1):pMsg.SourceSlot);

			pMsg.TargetSlot = 0xFF;

			pMsg.type = 0;

			if(INVENTORY_FULL_RANGE(pMsg.SourceSlot) != 0)
			{
				gItemManager.CGItemUseRecv(&pMsg,lpObj->Index);
			}
		}
	}

	//-- RECOVERY HEALING ELF
	if(lpObj->RecoveryHealOn != 0)
	{
		CSkill* RenderSkillHealing;

		RenderSkillHealing = gSkillManager.GetSkill(lpObj, SKILL_HEAL);

		if (RenderSkillHealing != 0)
		{
			if( lpObj->Life < (( lpObj->MaxLife * lpObj->RecoveryHealPercent) / 100) )
			{
				if( gEffectManager.CheckEffect(lpObj, gSkillManager.GetSkillEffect(RenderSkillHealing->m_index)) == 0 )
				{
					gSkillManager.UseAttackSkill(lpObj->Index, lpObj->Index, RenderSkillHealing);
				}
			}
		}
	}
}

void OfflineMode::RenderAutoBuffParty(int aIndex)	//-- OK
{
	if (!gObjIsConnectedGP(aIndex))
	{
		return;
	}
	LPOBJ lpObj = &gObj[aIndex];
	LPOBJ lpTarget;

	//-- AUTOBUFF ONLY
	if ( lpObj->BuffOn != 0)
	{
		CSkill* RenderBuff;
		for(int n = 0; n < 3 ; n++)
		{
			if(lpObj->BuffSkill[n] > 0)
			{
				RenderBuff = gSkillManager.GetSkill(lpObj, lpObj->BuffSkill[n]);

				if (RenderBuff != 0)
				{
					if(gEffectManager.CheckEffect(lpObj, gSkillManager.GetSkillEffect(RenderBuff->m_index)) == 0 )
					{
						gSkillManager.UseAttackSkill(lpObj->Index, lpObj->Index, RenderBuff); //Buff Your self
					}
				}
			}
		}
	}

	//-- PARTY MODE ON
	if ( lpObj->PartyModeOn != 0 )
	{
		//-- PARTY HEAL ELF
		if( lpObj->PartyModeHealOn != 0 && lpObj->Class == CLASS_FE)
		{
			CSkill* RenderPartyHealing;

			for(int i = 0; i < MAX_PARTY_USER ; i++)
			{

				if(OBJECT_RANGE(gParty.m_PartyInfo[lpObj->PartyNumber].Index[i]) != 0)
				{
					RenderPartyHealing = gSkillManager.GetSkill(lpObj, SKILL_HEAL);

					if (RenderPartyHealing != 0)
					{
						lpTarget = &gObj[gParty.m_PartyInfo[lpObj->PartyNumber].Index[i]];

						if(lpTarget->Index == lpObj->Index)
						{
							continue;
						}
						if( lpTarget->Life < (( lpTarget->MaxLife * lpObj->PartyModeHealPercent) / 100))
						{
							if( gEffectManager.CheckEffect(lpTarget, gSkillManager.GetSkillEffect(RenderPartyHealing->m_index)) == 0 )
							{
								gSkillManager.UseAttackSkill(lpObj->Index, lpTarget->Index, RenderPartyHealing);
							}
						}
					}
				}
			}
		}
		//-- PARTY BUFF
		if( lpObj->PartyModeBuffOn != 0)
		{
			CSkill* RenderPartyBuff;

			for(int i = 0; i < MAX_PARTY_USER ; i++)
			{
				if(OBJECT_RANGE(gParty.m_PartyInfo[lpObj->PartyNumber].Index[i]) != 0)
				{
					for(int n = 0; n < 3 ; n++)
					{
						if(lpObj->BuffSkill[n] > 0)
						{
							RenderPartyBuff = gSkillManager.GetSkill(lpObj, lpObj->BuffSkill[n]);

							if (RenderPartyBuff != 0)
							{
								lpTarget = &gObj[gParty.m_PartyInfo[lpObj->PartyNumber].Index[i]];

								if(gEffectManager.CheckEffect(lpTarget, gSkillManager.GetSkillEffect(RenderPartyBuff->m_index)) == 0 )
								{
									gSkillManager.UseAttackSkill(lpObj->Index, gParty.m_PartyInfo[lpObj->PartyNumber].Index[i], RenderPartyBuff);
								}
							}
						}
					}
				}
			}
		}
	}
}

void OfflineMode::RenderAttack(int aIndex)	//-- INCOMPLETO
{
	if (!gObjIsConnectedGP(aIndex))
	{
		return;
	}

	LPOBJ lpObj = &gObj[aIndex];
	int caminar = 0;
	int distance = (lpObj->HuntingRange > 6) ? 6 : lpObj->HuntingRange;

	//-- SKILL ATTACK
	CSkill * SkillRender;

	SkillRender = ( lpObj->Life < (( lpObj->MaxLife * lpObj->RecoveryDrainPercent) / 100) && lpObj->RecoveryDrainOn != 0) ? gSkillManager.GetSkill(lpObj, SKILL_DRAIN_LIFE) : gSkillManager.GetSkill(lpObj, lpObj->SkillBasicID);

	if (SkillRender == 0)
	{
		return;
	}

	int atacar = 0;

	int tObjNum = -1;

	if (gCustomAttack.GetTargetMonster(lpObj, SkillRender->m_index, &tObjNum) != 0)
	{
		
		atacar = 0;

		if (gObj[tObjNum].Live == 0 || gObj[tObjNum].State == OBJECT_EMPTY || gObj[tObjNum].RegenType != 0)
		{
			return;
		}

		if (OBJMAX_RANGE(tObjNum) == FALSE)
		{
			return;
		}

		if (gObj[tObjNum].Type != OBJECT_MONSTER)
		{
			return;
		}

		if (gServerInfo.InSafeZone(tObjNum) == true)
		{
			return;
		}

		int dis = (int) sqrt((float)((lpObj->X - gObj[tObjNum].X) * (lpObj->X - gObj[tObjNum].X) + (lpObj->Y - gObj[tObjNum].Y) * (lpObj->Y - gObj[tObjNum].Y)));

		if (dis > distance)
		{
			return;
		}
		else
		{
			if(gSkillManager.CheckSkillRange(SkillRender->m_index, lpObj->X, lpObj->Y, gObj[tObjNum].X, gObj[tObjNum].Y) != 0)
			{
				caminar = 0;
			}
			else
			{
				caminar = 1;
				
			}

			if(gSkillManager.CheckSkillRadio(SkillRender->m_index, lpObj->X, lpObj->Y,gObj[tObjNum].X, gObj[tObjNum].Y) != 0)
			{
				caminar = 0;
			}
			else
			{
				caminar = 1;
			}

			if(caminar == 1)
			{
				AnimationMove(lpObj->Index, gObj[tObjNum].X, gObj[tObjNum].Y);
			}

			atacar = 1;
		}

		if(atacar != 0)
		{
			if(lpObj->Mana < gSkillManager.GetSkillMana(SkillRender->m_index))
			{
				//-- AUTO POTION MP PRIMERO VALIDA QUE NO ESTE MUERTO
				PMSG_ITEM_USE_RECV pMsgMP;

				pMsgMP.header.set(0x26,sizeof(pMsgMP));

				pMsgMP.SourceSlot = 0xFF;

				pMsgMP.SourceSlot = ((pMsgMP.SourceSlot==0xFF) ? gItemManager.GetInventoryItemSlot(lpObj, GET_ITEM(14,6), -1) : pMsgMP.SourceSlot);

				pMsgMP.SourceSlot = ((pMsgMP.SourceSlot==0xFF) ? gItemManager.GetInventoryItemSlot(lpObj, GET_ITEM(14,5), -1) : pMsgMP.SourceSlot);

				pMsgMP.SourceSlot = ((pMsgMP.SourceSlot==0xFF) ? gItemManager.GetInventoryItemSlot(lpObj, GET_ITEM(14,4), -1) : pMsgMP.SourceSlot);

				pMsgMP.TargetSlot = 0xFF;

				pMsgMP.type = 0;

				if(INVENTORY_FULL_RANGE(pMsgMP.SourceSlot) != 0)
				{
					gItemManager.CGItemUseRecv(&pMsgMP,lpObj->Index);
				}
				else
				{
					return;
				}
			}

			int MultiPlicador = (lpObj->Class == CLASS_RF)? 1 : 5;

			if((GetTickCount()-((DWORD) lpObj->AttackCustomDelay )) >= (((((DWORD) lpObj->PhysiSpeed) * MultiPlicador) > 1500 ) ? 0 : ( 1500 - (((DWORD) lpObj->PhysiSpeed) * MultiPlicador ))))
			{
				lpObj->AttackCustomDelay = GetTickCount();

				if(SkillRender->m_skill != SKILL_FLAME 
					&& SkillRender->m_skill != SKILL_TWISTER 
					&& SkillRender->m_skill != SKILL_EVIL_SPIRIT 
					&& SkillRender->m_skill != SKILL_HELL_FIRE 
					&& SkillRender->m_skill != SKILL_AQUA_BEAM 
					&& SkillRender->m_skill != SKILL_BLAST 
					&& SkillRender->m_skill != SKILL_INFERNO 
					&& SkillRender->m_skill != SKILL_TRIPLE_SHOT 
					&& SkillRender->m_skill != SKILL_IMPALE
					&& SkillRender->m_skill != SKILL_MONSTER_AREA_ATTACK 
					&& SkillRender->m_skill != SKILL_PENETRATION 
					&& SkillRender->m_skill != SKILL_FIRE_SLASH 
					&& SkillRender->m_skill != SKILL_FIRE_SCREAM)
				{
					if(SkillRender->m_skill != SKILL_DARK_SIDE)
					{

						PMSG_DURATION_SKILL_ATTACK_RECV pMsg;

						pMsg.header.set(0x1E, sizeof(pMsg));

						#if(GAMESERVER_UPDATE>=701)

						pMsg.skillH = SET_NUMBERHB(0);

						pMsg.skillL = SET_NUMBERLB((((GetLargeRand()%100)>=25)?1:0));

						#else

						pMsg.skill[0] = SET_NUMBERHB(SkillRender->m_index);

						pMsg.skill[1] = SET_NUMBERLB(SkillRender->m_index);

						#endif

						pMsg.x = (BYTE)gObj[tObjNum].X;

						pMsg.y = (BYTE)gObj[tObjNum].Y;

						pMsg.dir = (gSkillManager.GetSkillAngle(gObj[tObjNum].X, gObj[tObjNum].Y, lpObj->X, lpObj->Y)*255) / 360;

						pMsg.dis = 0;

						pMsg.angle = (gSkillManager.GetSkillAngle(lpObj->X, lpObj->Y, gObj[tObjNum].X, gObj[tObjNum].Y)*255) / 360;

						#if(GAMESERVER_UPDATE>=803)

						pMsg.indexH = SET_NUMBERHB(lpObj->TargetNumber);

						pMsg.indexL = SET_NUMBERLB(lpObj->TargetNumber);

						#else

						pMsg.index[0] = SET_NUMBERHB(tObjNum);

						pMsg.index[1] = SET_NUMBERLB(tObjNum);

						#endif

						pMsg.MagicKey = 0;

						gSkillManager.CGDurationSkillAttackRecv(&pMsg,lpObj->Index);
						gAttack.Attack(lpObj, &gObj[tObjNum], SkillRender, FALSE, 1, 0, FALSE, 0);
					}
					else
					{
						gCustomAttack.SendRFSkillAttack(lpObj, tObjNum, SkillRender->m_index);
					}
				}
				else
				{
					gCustomAttack.SendMultiSkillAttack(lpObj, tObjNum, SkillRender->m_index);
				}
			}
		}
	}
}

bool isJewels(int index)
{
	if (index == GET_ITEM(12, 15) ||
		index == GET_ITEM(14, 13) ||
		index == GET_ITEM(14, 14) ||
		index == GET_ITEM(14, 16) ||
		index == GET_ITEM(14, 22) ||
		index == GET_ITEM(14, 31) ||
		index == GET_ITEM(14, 42))
	{
		return true;
	}

	return false;
}

bool itemListPickUp(int Index, int Level, LPOBJ lpObj) //olhar dps
{
	for( int i = 0 ; i < lpObj->ObtainPickExtraCount ; i++ )
	{
		/*if( strstr(gItemLevel.GetItemName(Index, Level), lpObj->ObtainPickItemList[ i ]) != NULL )
		{
			return true;
		}*/
	}
	return false;
}

int OfflineMode::PickUP(int aIndex)
{
	if (OBJMAX_RANGE(aIndex) == FALSE)
	{
		return 0;
	}

	if (!gObjIsConnectedGP(aIndex))
	{
		return 0;
	}

	LPOBJ lpObj = &gObj[aIndex];

	if (lpObj->m_OfflineMode == 0)
	{
		return 0;
	}

	if (gServerInfo.InSafeZone(aIndex) == true)
	{
		this->OnHelperpAlreadyConnected(lpObj);
		return 0;
	}

	CMapItem * lpMapItem;

	int distance = lpObj->ObtainRange;

	int map_num = gObj[aIndex].Map;

	if (gObj[aIndex].DieRegen != 0)
	{
		return 0;
	}

	if (MAP_RANGE(map_num) == FALSE)
	{
		return 0;
	}

	int OldX;
	int OldY;
	bool PickItem;

	for (int n = 0; n < MAX_MAP_ITEM; n++)
	{
		PickItem = false;

		lpMapItem = &gMap[map_num].m_Item[n];

		if (lpMapItem->IsItem() == TRUE  && lpMapItem->m_Give == false && lpMapItem->m_Live == true)
		{
			int dis = (int) sqrt((float)((lpObj->X - lpMapItem->m_X) * (lpObj->X - lpMapItem->m_X) + (lpObj->Y - lpMapItem->m_Y) * (lpObj->Y - lpMapItem->m_Y)));

			if (dis > distance)
			{
				continue;
			}
			OldX = lpObj->X;
			OldY = lpObj->Y;
			if (lpObj->ObtainPickSelected == 1)
			{
				if( (lpObj->ObtainPickMoney == 1 && lpMapItem->m_Index == GET_ITEM(14, 15)) 
					|| (lpObj->ObtainPickExcellent == 1 && lpMapItem->m_NewOption > 0) 
					|| (lpObj->ObtainPickAncient == 1 && lpMapItem->m_SetOption > 0) 
					|| (lpObj->ObtainPickJewels == 1 && isJewels(lpMapItem->m_Index) == true))
				{
					PickItem = true;
					AnimationMove(lpObj->Index, lpMapItem->m_X, lpMapItem->m_Y);
				}
				else if(lpObj->ObtainPickExtra == 1)
				{
					if( itemListPickUp(lpMapItem->m_Index, lpMapItem->m_Level, lpObj) == true )
					{
						PickItem = true;
						AnimationMove(lpObj->Index, lpMapItem->m_X, lpMapItem->m_Y);
					}
				}
				else
				{
					PickItem = false;
					continue;
				}
			}
			else
			{
				PickItem = false;
				continue;
			}

			if (PickItem == false)
			{
				continue;
			}

			if(lpObj->X == lpMapItem->m_X && lpObj->Y == lpMapItem->m_Y)
			{
				//zen item
				if ( lpMapItem->m_Index == GET_ITEM(14, 15) )
				{
					if ( lpObj->ObtainPickMoney == 1 )
					{
						gMap[map_num].ItemGive(aIndex, n);

						if (!gObjCheckMaxMoney(aIndex, lpMapItem->m_BuyMoney))
						{
							if (lpObj->Money < MAX_MONEY)
							{
								lpObj->Money = MAX_MONEY;
								continue;
							}
						}
						else
						{
							lpObj->Money += lpMapItem->m_BuyMoney;
						}
						continue;
					}
				}
				//all items
				if (lpMapItem->m_QuestItem != false)
				{
					if (!gQuestObjective.CheckQuestObjectiveItemCount(lpObj, lpMapItem->m_Index, lpMapItem->m_Level))
					{
						continue;
					}
				}

				CItem item = (*lpMapItem);

				BYTE result = gItemManager.InventoryInsertItemStack(&gObj[aIndex], lpMapItem);
				if (result != 0xFF)
				{
					gMap[map_num].ItemGive(aIndex, n);
					{
						BYTE pos = gItemManager.InventoryInsertItem(aIndex, item);
						if (pos != 0xFF)
						{
							::GCPartyItemInfoSend(aIndex, lpMapItem);
						}
						
					}
				}
			}
		}
	}

	return 1;
}

void OfflineMode::regresar(int aIndex)
{
	if (OBJMAX_RANGE(aIndex) == FALSE)
	{
		return;
	}

	if (!gObjIsConnectedGP(aIndex))
	{
		return;
	}

	LPOBJ lpObj = &gObj[aIndex];

	if (lpObj->m_OfflineMode == 0)
	{
		return;
	}

	if (gServerInfo.InSafeZone(aIndex) == true)
	{
		this->OnHelperpAlreadyConnected(lpObj);
		return;
	}

	if(lpObj->DistanceReturnOn != 0)
	{
		if (GetTickCount() >= lpObj->m_OfflineTimeResetMove + 1000 + (lpObj->DistanceMin * 1000))
		{
			if(lpObj->m_OfflineCoordX != lpObj->X && lpObj->m_OfflineCoordY != lpObj->Y)
			{
				AnimationMove(lpObj->Index, lpObj->m_OfflineCoordX, lpObj->m_OfflineCoordY);
			}
			lpObj->m_OfflineTimeResetMove = GetTickCount();
		}
	}
}