#include "stdafx.h"
#include "ModelEffect.h"
#include "Defines.h"
#include "User.h"
#include "Import.h"
#include "zzzmathlib.h"

CCustomModelEffect gCustomModelEffect;

CCustomModelEffect::CCustomModelEffect() // OK
{
	this->m_CustomModelEffectInfo.clear();
}

CCustomModelEffect::~CCustomModelEffect() // OK
{

}

void CCustomModelEffect::Load(CUSTOM_MODEL_EFFECT_INFO* info) // OK
{
	int index;

	for( int n=0 ; n < MAX_MODEL_EFFECT ; n++ )
	{
		if(info[n].Index < 0 || info[n].Index >= MAX_MODEL_EFFECT)
		{
			return;
		}

		this->m_CustomModelEffectInfo.insert(std::pair<int,CUSTOM_MODEL_EFFECT_INFO>(info[n].Index, info[n]));
	}
}

bool CCustomModelEffect::ModelComplete(short a1, BYTE a2, BYTE a3)
{
	std::map<int, CUSTOM_MODEL_EFFECT_INFO>::iterator it = this->m_CustomModelEffectInfo.find(a1);
	
	for(std::map<int, CUSTOM_MODEL_EFFECT_INFO>::iterator it = this->m_CustomModelEffectInfo.begin(); it != this->m_CustomModelEffectInfo.end(); it++)
	{
		if(a1 == ITEM2(it->second.ItemType, it->second.ItemIndex))
		{
			if(a2 >= it->second.MinLevel && a2 <= it->second.MaxLevel && a3 >= it->second.MinExcellent)
			{
				return true;
			}
		}
	}

	return false;
}

void CCustomModelEffect::ModelRenderEffect(int EffectType,int EffectCode ,DWORD * lBone, int lBone2, float * Color, int EffectMode, float Scale)
{
	if(EffectType == 1)
	{
		pPlayDynamicEffect(EffectCode, lBone, lBone2, Color, EffectMode, Scale, 0); // 3}
	}
	else if(EffectType == 2)
	{
		pSkillEffect(EffectCode, (int)lBone, lBone2, Color, EffectMode, 0, 0, 0, 0, 0, 0.0, -1);
	}
	else
	{
		pPlayStaticEffect(EffectCode, lBone, Scale, Color, lBone2, 0, 0);
	}
}

MU3Float lBone[MAX_MODEL_EFFECT];
MU3Float lBone2[MAX_MODEL_EFFECT];

void CCustomModelEffect::ModelEffectRender(DWORD ObjectPointer,DWORD ObjectModel, DWORD a3)
{
	lpViewObj Object = &*(ObjectPreview*)(ObjectPointer);

	vec3_t Color;
	vec3_t ColorRandom;

	Vector(1.0, 1.0, 1.0, Color);

	int Iterator = 0;

	for(std::map<int,CUSTOM_MODEL_EFFECT_INFO>::iterator it = gCustomModelEffect.m_CustomModelEffectInfo.begin(); it != gCustomModelEffect.m_CustomModelEffectInfo.end(); it++)
	{
		
		lBone[Iterator].X = *(float*)(ObjectModel + 252);
		lBone[Iterator].Y = *(float*)(ObjectModel + 256);
		lBone[Iterator].Z = *(float*)(ObjectModel + 260);
		lBone2[Iterator].X =*(float*)(ObjectModel + 264);
		lBone2[Iterator].Y =*(float*)(ObjectModel + 268);
		lBone2[Iterator].Z =*(float*)(ObjectModel + 272);

		Vector(it->second.Color[0], it->second.Color[1], it->second.Color[2], Color);

		if(Object->HelmSlot == ITEM2(it->second.ItemType,it->second.ItemIndex))
		{
			if(gCustomModelEffect.ModelComplete(Object->HelmSlot,Object->HelmLevel,Object->HelmExcellent))
			{
				lBone[Iterator].Z = lBone[Iterator].Z + (float)(150);
				lBone2[Iterator].Z = lBone2[Iterator].Z + (float)(150);

				gCustomModelEffect.ModelRenderEffect(it->second.EffectIndex, it->second.EffectCode, (DWORD*)&lBone[Iterator], (int)&lBone2[Iterator], Color, it->second.EffectType,it->second.EffectScale);
			}
		}
		else if(Object->ArmorSlot == ITEM2(it->second.ItemType,it->second.ItemIndex))
		{
			if(gCustomModelEffect.ModelComplete(Object->ArmorSlot,Object->ArmorLevel,Object->ArmorExcellent))
			{
				lBone[Iterator].Z = lBone[Iterator].Z + (float)(120);
				lBone2[Iterator].Z = lBone2[Iterator].Z + (float)(120);

				gCustomModelEffect.ModelRenderEffect(it->second.EffectIndex, it->second.EffectCode, (DWORD*)&lBone[Iterator], (int)&lBone2[Iterator], Color, it->second.EffectType, it->second.EffectScale);
			}
		}
		else if(Object->PantsSlot == ITEM2(it->second.ItemType,it->second.ItemIndex))
		{
			if(gCustomModelEffect.ModelComplete(Object->PantsSlot,Object->PantsLevel,Object->PantsExcellent))
			{
				lBone[Iterator].Z = lBone[Iterator].Z + (float)(60);
				lBone2[Iterator].Z = lBone2[Iterator].Z + (float)(60);

				gCustomModelEffect.ModelRenderEffect(it->second.EffectIndex, it->second.EffectCode, (DWORD*)&lBone[Iterator], (int)&lBone2[Iterator], Color, it->second.EffectType, it->second.EffectScale);
			}
		}
		else if(Object->BootsSlot == ITEM2(it->second.ItemType,it->second.ItemIndex))
		{
			if(gCustomModelEffect.ModelComplete(Object->BootsSlot,Object->BootsLevel,Object->BootsExcellent))
			{
				if (Object->InSafeZone)
				{
					lBone[Iterator].Z = lBone[Iterator].Z + (float)(20);
					lBone2[Iterator].Z = lBone2[Iterator].Z + (float)(20);

				}
				else if(Object->PetSlot == ITEM2(13,37))
				{
					lBone[Iterator].Z = lBone[Iterator].Z + (float)(210);
					lBone2[Iterator].Z = lBone2[Iterator].Z + (float)(210);
				}
				else if (Object->PetSlot == ITEM2(13, 4))
				{
					lBone[Iterator].Z = lBone[Iterator].Z + (float)(250);
					lBone2[Iterator].Z = lBone2[Iterator].Z + (float)(250);
				}
				else if (Object->WingsSlot >= 1)
				{
					lBone[Iterator].Z = lBone[Iterator].Z + (float)(180);
					lBone2[Iterator].Z = lBone2[Iterator].Z + (float)(180);
				}

				gCustomModelEffect.ModelRenderEffect(it->second.EffectIndex, it->second.EffectCode, (DWORD*)&lBone[Iterator], (int)&lBone2[Iterator], Color, it->second.EffectType, it->second.EffectScale);
			}
		}
		Iterator++;
	}

	Iterator = 0;
}
