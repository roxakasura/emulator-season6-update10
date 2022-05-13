// SetItemOption.cpp: implementation of the CItemOptionCombination class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "ItemOptionCombination.h"
#include "ItemManager.h"
#include "MemScript.h"
#include "ItemTypeCombination.h"
#include "Util.h"
#include "SetItemOption.h"

CItemOptionCombination gItemOptionCombination;
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CItemOptionCombination::CItemOptionCombination() // OK
{
	this->Init();
}

CItemOptionCombination::~CItemOptionCombination() // OK
{

}

void CItemOptionCombination::Init() // OK
{
	for(int n=0;n < MAX_ITEM_OPTION_COMBINATION;n++)
	{
		this->m_ItemOptionCombinationInfo[n].Index = -1;
	}
}

void CItemOptionCombination::Load(char* path) // OK
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

	this->Init();

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

					ITEM_TYPE_COMBINATION_INFO info;

					memset(&info,0,sizeof(info));

					info.Index = lpMemScript->GetNumber();

					for(int n=0;n < MAX_ITEM_OPTION_INDEX_COMBINATION;n++)
					{
						info.OptionIndex[n] = lpMemScript->GetAsNumber();
					}

					gItemTypeOption.SetInfo(info);
				}
				else if(section == 1)
				{
					if(strcmp("end",lpMemScript->GetAsString()) == 0)
					{
						break;
					}

					ITEM_OPTION_COMBINATION_INFO info;

					memset(&info,0,sizeof(info));

					info.Index = lpMemScript->GetNumber();

					for(int n=0;n < MAX_ITEM_OPTION_TABLE_COMBINATION;n++)
					{
						info.OptionTable[n].Index = lpMemScript->GetAsNumber();
						info.OptionTable[n].Value = lpMemScript->GetAsNumber();
					}

					this->SetInfo(info);
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

void CItemOptionCombination::SetInfo(ITEM_OPTION_COMBINATION_INFO info) // OK
{
	if(info.Index < 0 || info.Index >= MAX_ITEM_OPTION_COMBINATION)
	{
		return;
	}

	this->m_ItemOptionCombinationInfo[info.Index] = info;
}

ITEM_OPTION_COMBINATION_INFO* CItemOptionCombination::GetInfo(int index) // OK
{
	if(index < 0 || index >= MAX_ITEM_OPTION_COMBINATION)
	{
		return 0;
	}

	if(this->m_ItemOptionCombinationInfo[index].Index != index)
	{
		return 0;
	}

	return &this->m_ItemOptionCombinationInfo[index];
}

int CItemOptionCombination::GetItemCombinationMaxOptionCount(int index) // OK
{
	ITEM_OPTION_COMBINATION_INFO* lpInfo = this->GetInfo(index);

	if(lpInfo == 0)
	{
		return 0;
	}

	int count = 0;

	for(int n=0;n < MAX_ITEM_OPTION_TABLE_COMBINATION;n++)
	{
		if(lpInfo->OptionTable[n].Index != -1)
		{
			count++;
			break;
		}
	}

	return count;
}

int CItemOptionCombination::GetInventoryItemCombinationOptionCount(LPOBJ lpObj,int index) // OK
{
	int OptionCount = 0;
	int WeaponOptionIndex = 0;
	int RingOptionIndex = 0;

	for(int n=0;n < INVENTORY_WEAR_SIZE;n++)
	{
		if(lpObj->Inventory[n].IsItem() == 0 || lpObj->Inventory[n].m_IsValidItem == 0)
		{
			continue;
		}

		if(gItemTypeOption.CheckItemTypeCombination(lpObj->Inventory[n].m_Index) == 0)
		{
			continue;
		}

		int OptionIndex = gItemTypeOption.GetItemCombinationOptionIndex(lpObj->Inventory[n].m_Index,0);

		if(OptionIndex == 0 || OptionIndex != index)
		{
			continue;
		}

		if(n == 0 || n == 1)
		{
			if(WeaponOptionIndex == 0)
			{
				WeaponOptionIndex = OptionIndex;
			}
			else if(WeaponOptionIndex == OptionIndex && lpObj->Inventory[0].m_Index == lpObj->Inventory[1].m_Index) 
			{
				continue;
			}
		}
		else if(n == 10 || n == 11)
		{
			if(RingOptionIndex == 0)
			{
				RingOptionIndex = OptionIndex;
			}
			else if(RingOptionIndex == OptionIndex && lpObj->Inventory[10].m_Index == lpObj->Inventory[11].m_Index) 
			{
				continue;
			}
		}

		OptionCount++;
	}

	return OptionCount;
}

void CItemOptionCombination::CalcItemOptionCombination(LPOBJ lpObj,bool flag) // OK
{
	lpObj->IsFullSetItem = 0;

	for(int n=0;n < MAX_ITEM_OPTION_COMBINATION;n++)
	{
		ITEM_OPTION_COMBINATION_INFO* lpInfo = this->GetInfo(n);

		if(lpInfo == 0)
		{
			continue;
		}

		int ItemOptionCount = this->GetInventoryItemCombinationOptionCount(lpObj,lpInfo->Index);

		if(ItemOptionCount == 0)
		{
			continue;
		}

		for(int i=0;i < (ItemOptionCount-1);i++)
		{
			if(lpInfo->OptionTable[i].Index != -1)
			{
				this->InsertOption(lpObj,lpInfo->OptionTable[i].Index,lpInfo->OptionTable[i].Value,flag);
			}
		}
	}
}

void CItemOptionCombination::InsertOption(LPOBJ lpObj,int index,int value,bool flag) // OK
{
	if(flag == 0)
	{
		if(index == SET_ITEM_OPTION_ADD_STRENGTH || index == SET_ITEM_OPTION_ADD_DEXTERITY || index == SET_ITEM_OPTION_ADD_VITALITY || index == SET_ITEM_OPTION_ADD_ENERGY || index == SET_ITEM_OPTION_ADD_LEADERSHIP)
		{
			return;
		}
	}
	else
	{
		if(index != SET_ITEM_OPTION_ADD_STRENGTH && index != SET_ITEM_OPTION_ADD_DEXTERITY && index != SET_ITEM_OPTION_ADD_VITALITY && index != SET_ITEM_OPTION_ADD_ENERGY && index != SET_ITEM_OPTION_ADD_LEADERSHIP)
		{
			return;
		}
	}

	switch(index)
	{
		case SET_ITEM_OPTION_ADD_STRENGTH:
			lpObj->AddStrength += value;
			break;
		case SET_ITEM_OPTION_ADD_DEXTERITY:
			lpObj->AddDexterity += value;
			break;
		case SET_ITEM_OPTION_ADD_VITALITY:
			lpObj->AddVitality += value;
			break;
		case SET_ITEM_OPTION_ADD_ENERGY:
			lpObj->AddEnergy += value;
			break;
		case SET_ITEM_OPTION_ADD_LEADERSHIP:
			lpObj->AddLeadership += value;
			break;
		case SET_ITEM_OPTION_ADD_MIN_PHYSI_DAMAGE:
			lpObj->PhysiDamageMinLeft += value;
			lpObj->PhysiDamageMinRight += value;
			break;
		case SET_ITEM_OPTION_ADD_MAX_PHYSI_DAMAGE:
			lpObj->PhysiDamageMaxLeft += value;
			lpObj->PhysiDamageMaxRight += value;
			break;
		case SET_ITEM_OPTION_MUL_MAGIC_DAMAGE:
			lpObj->MagicDamageMin += (lpObj->MagicDamageMin*value)/100;
			lpObj->MagicDamageMax += (lpObj->MagicDamageMax*value)/100;
			break;
		case SET_ITEM_OPTION_ADD_PHYSI_DAMAGE:
			lpObj->PhysiDamageMinLeft += value;
			lpObj->PhysiDamageMinRight += value;
			lpObj->PhysiDamageMaxLeft += value;
			lpObj->PhysiDamageMaxRight += value;
			break;
		case SET_ITEM_OPTION_MUL_ATTACK_SUCCESS_RATE:
			lpObj->AttackSuccessRate += (lpObj->AttackSuccessRate*value)/100;
			break;
		case SET_ITEM_OPTION_ADD_DEFENSE:
			lpObj->Defense += value;
			break;
		case SET_ITEM_OPTION_ADD_MAX_LIFE:
			lpObj->AddLife += value;
			break;
		case SET_ITEM_OPTION_ADD_MAX_MANA:
			lpObj->AddMana += value;
			break;
		case SET_ITEM_OPTION_ADD_MAX_BP:
			lpObj->AddBP += value;
			break;
		case SET_ITEM_OPTION_ADD_BP_RECOVERY:
			lpObj->BPRecovery += value;
			break;
		case SET_ITEM_OPTION_ADD_CRITICAL_DAMAGE_RATE:
			lpObj->CriticalDamageRate += value;
			break;
		case SET_ITEM_OPTION_ADD_CRITICAL_DAMAGE:
			lpObj->CriticalDamage += value;
			break;
		case SET_ITEM_OPTION_ADD_EXCELLENT_DAMAGE_RATE:
			lpObj->ExcellentDamageRate += value;
			break;
		case SET_ITEM_OPTION_ADD_EXCELLENT_DAMAGE:
			lpObj->ExcellentDamage += value;
			break;
		case SET_ITEM_OPTION_ADD_SKILL_DAMAGE:
			lpObj->SkillDamageBonus += value;
			break;
		case SET_ITEM_OPTION_ADD_DOUBLE_DAMAGE_RATE:
			lpObj->DoubleDamageRate += value;
			break;
		case SET_ITEM_OPTION_ADD_IGNORE_DEFENSE_RATE:
			lpObj->IgnoreDefenseRate += value;
			break;
		case SET_ITEM_OPTION_MUL_SHIELD_DEFENSE:
			if(lpObj->Inventory[1].m_Index >= GET_ITEM(6,0) && lpObj->Inventory[1].m_Index < GET_ITEM(7,0))
			{
				lpObj->Defense += (lpObj->Defense*value)/100;
			}
			break;
		case SET_ITEM_OPTION_MUL_TWO_HAND_PHYSI_DAMAGE:
			if((lpObj->Inventory[0].IsItem() != 0 && lpObj->Inventory[0].m_TwoHand != 0) || (lpObj->Inventory[1].IsItem() != 0 && lpObj->Inventory[1].m_TwoHand != 0))
			{
				lpObj->PhysiDamageMinLeft += (lpObj->PhysiDamageMinLeft*value)/100;
				lpObj->PhysiDamageMinRight += (lpObj->PhysiDamageMinRight*value)/100;
				lpObj->PhysiDamageMaxLeft += (lpObj->PhysiDamageMaxLeft*value)/100;
				lpObj->PhysiDamageMaxRight += (lpObj->PhysiDamageMaxRight*value)/100;
			}
			break;
		case SET_ITEM_OPTION_ADD_PHYSI_DAMAGE_BY_STRENGTH:
			lpObj->PhysiDamageMinLeft += ((value==0)?0:(lpObj->Strength/value));
			lpObj->PhysiDamageMinRight += ((value==0)?0:(lpObj->Strength/value));
			lpObj->PhysiDamageMaxLeft += ((value==0)?0:(lpObj->Strength/value));
			lpObj->PhysiDamageMaxRight += ((value==0)?0:(lpObj->Strength/value));
			break;
		case SET_ITEM_OPTION_ADD_PHYSI_DAMAGE_BY_DEXTERITY:
			lpObj->PhysiDamageMinLeft += ((value==0)?0:(lpObj->Dexterity/value));
			lpObj->PhysiDamageMinRight += ((value==0)?0:(lpObj->Dexterity/value));
			lpObj->PhysiDamageMaxLeft += ((value==0)?0:(lpObj->Dexterity/value));
			lpObj->PhysiDamageMaxRight += ((value==0)?0:(lpObj->Dexterity/value));
			break;
		case SET_ITEM_OPTION_ADD_DEFENSE_BY_DEXTERITY:
			lpObj->Defense += ((value==0)?0:(lpObj->Dexterity/value));
			break;
		case SET_ITEM_OPTION_ADD_DEFENSE_BY_VITALITY:
			lpObj->Defense += ((value==0)?0:(lpObj->Vitality/value));
			break;
		case SET_ITEM_OPTION_ADD_MAGIC_DAMAGE_BY_ENERGY:
			lpObj->MagicDamageMin += ((value==0)?0:(lpObj->Energy/value));
			lpObj->MagicDamageMax += ((value==0)?0:(lpObj->Energy/value));
			break;
		case SET_ITEM_OPTION_ADD_ICE_DAMAGE:
			lpObj->AddResistance[0] += value;
			break;
		case SET_ITEM_OPTION_ADD_POISON_DAMAGE:
			lpObj->AddResistance[1] += value;
			break;
		case SET_ITEM_OPTION_ADD_LIGHTNING_DAMAGE:
			lpObj->AddResistance[2] += value;
			break;
		case SET_ITEM_OPTION_ADD_FIRE_DAMAGE:
			lpObj->AddResistance[3] += value;
			break;
		case SET_ITEM_OPTION_ADD_EARTH_DAMAGE:
			lpObj->AddResistance[4] += value;
			break;
		case SET_ITEM_OPTION_ADD_WIND_DAMAGE:
			lpObj->AddResistance[5] += value;
			break;
		case SET_ITEM_OPTION_ADD_WATER_DAMAGE:
			lpObj->AddResistance[6] += value;
			break;
	}
}
