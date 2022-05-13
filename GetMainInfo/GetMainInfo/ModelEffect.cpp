// CustomWingEffect.cpp: implementation of the CCustomModelEffect class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "ModelEffect.h"
#include "MemScript.h"

CCustomModelEffect gCustomModelEffect;
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CCustomModelEffect::CCustomModelEffect() // OK
{
	this->Init();
}

CCustomModelEffect::~CCustomModelEffect() // OK
{

}

void CCustomModelEffect::Init() // OK
{
	for(int n=0;n < MAX_MODEL_EFFECT;n++)
	{
		this->m_CustomModelEffectInfo[n].Index = -1;
	}
}

void CCustomModelEffect::Load(char* path) // OK
{
	CMemScript* lpMemScript = new CMemScript;

	if(lpMemScript == 0)
	{
		printf(MEM_SCRIPT_ALLOC_ERROR,path);
		return;
	}

	if(lpMemScript->SetBuffer(path) == 0)
	{
		printf(lpMemScript->GetLastError());
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

			if(strcmp("end",lpMemScript->GetString()) == 0)
			{
				break;
			}

			CUSTOM_MODEL_EFFECT_INFO info;

			memset(&info,0,sizeof(info));

			static int CustomModelEffectIndexCount = 0;

			info.Index = CustomModelEffectIndexCount++;
			info.ItemType = lpMemScript->GetNumber();
			info.ItemIndex = lpMemScript->GetAsNumber();
			info.MinLevel = lpMemScript->GetAsNumber();
			info.MaxLevel = lpMemScript->GetAsNumber();
			info.MinExcellent = lpMemScript->GetAsNumber();
			info.MaxExcellent = lpMemScript->GetAsNumber();
			info.Color[0] = lpMemScript->GetAsFloatNumber();
			info.Color[1] = lpMemScript->GetAsFloatNumber();
			info.Color[2] = lpMemScript->GetAsFloatNumber();
			info.EffectIndex = lpMemScript->GetAsNumber();
			info.EffectCode = lpMemScript->GetAsNumber();
			info.EffectType = lpMemScript->GetAsNumber();
			info.EffectScale = lpMemScript->GetAsFloatNumber();
			this->SetInfo(info);
		}
	}
	catch(...)
	{
		printf(lpMemScript->GetLastError());
	}

	delete lpMemScript;
}

void CCustomModelEffect::SetInfo(CUSTOM_MODEL_EFFECT_INFO info) // OK
{
	if(info.Index < 0 || info.Index >= MAX_MODEL_EFFECT)
	{
		return;
	}

	this->m_CustomModelEffectInfo[info.Index] = info;
}
