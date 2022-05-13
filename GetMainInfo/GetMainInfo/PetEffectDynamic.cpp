#include "StdAfx.h"
#include "PetEffectDynamic.h"
#include "MemScript.h"

cCEffectDynamicPet gCustomCEffectDynamicPet;

cCEffectDynamicPet::cCEffectDynamicPet()
{
	this->Init();
}
cCEffectDynamicPet::~cCEffectDynamicPet()
{
}


void cCEffectDynamicPet::Init() // OK
{
	for (int n = 0; n < max_ceffectdin; n++)
	{
		this->m_PetDynamicCEffect[n].Index = -1;
	};
}

void cCEffectDynamicPet::Load(char* path) // OK
{
	CMemScript* lpMemScript = new CMemScript;

	if (lpMemScript == 0)
	{
		printf(MEM_SCRIPT_ALLOC_ERROR, path);
		return;
	}

	if (lpMemScript->SetBuffer(path) == 0)
	{
		printf(lpMemScript->GetLastError());
		delete lpMemScript;
		return;
	}

	this->Init();

	try
	{
		while (true)
		{
			if (lpMemScript->GetToken() == TOKEN_END)
			{
				break;
			}

			if (strcmp("end", lpMemScript->GetString()) == 0)
			{
				break;
			}

			PET_DYNAMIC_CUSTOM info;

			memset(&info, 0, sizeof(info));

			static int CustomItemIndexCount = 0;

			info.Index = CustomItemIndexCount++;

			info.ItemIndex = lpMemScript->GetNumber();

			info.EffectCode = lpMemScript->GetAsNumber();

			info.Join = lpMemScript->GetAsNumber();

			info.TypeEffect = lpMemScript->GetAsNumber();

			info.ColorR = lpMemScript->GetAsFloatNumber();

			info.ColorG = lpMemScript->GetAsFloatNumber();

			info.ColorB = lpMemScript->GetAsFloatNumber();

			info.Effect1 = lpMemScript->GetAsFloatNumber();

			info.EffectSize = lpMemScript->GetAsFloatNumber();

			info.Effect = lpMemScript->GetAsFloatNumber();

			this->SetInfo(info);
		}
	}
	catch (...)
	{
		printf(lpMemScript->GetLastError());
	}

	delete lpMemScript;
}

void cCEffectDynamicPet::SetInfo(PET_DYNAMIC_CUSTOM info) // OK
{
	if (info.Index < 0 || info.Index >= max_ceffectdin)
	{
		return;
	}

	this->m_PetDynamicCEffect[info.Index] = info;
}