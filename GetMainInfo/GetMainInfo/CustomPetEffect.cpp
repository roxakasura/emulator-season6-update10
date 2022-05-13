#include "StdAfx.h"
#include "CustomPetEffect.h"
#include "MemScript.h"

cCEffectPet gCustomCEffectPet;

cCEffectPet::cCEffectPet()
{
	this->Init();
}
cCEffectPet::~cCEffectPet()
{
}


void cCEffectPet::Init() // OK
{
	for(int n=0;n < max_ceffect;n++)
	{
		this->m_PetCEffect[n].Index = -1;
	};
}

void cCEffectPet::Load(char* path) // OK
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

			PET_EFFECT_CUSTOM info;

			memset(&info,0,sizeof(info));

			static int CustomItemIndexCount = 0;

			info.Index = CustomItemIndexCount++;

			info.ItemIndex = lpMemScript->GetNumber();

			info.EffectCode = lpMemScript->GetAsNumber();

			info.Join = lpMemScript->GetAsNumber();

			info.TypeEffect = lpMemScript->GetAsNumber();

			info.ColorR = lpMemScript->GetAsFloatNumber();
			
			info.ColorG = lpMemScript->GetAsFloatNumber();
			
			info.ColorB = lpMemScript->GetAsFloatNumber();

			info.EffectSize = lpMemScript->GetAsFloatNumber();

			info.ColorMain = lpMemScript->GetAsFloatNumber();

			info.ColorSide = lpMemScript->GetAsFloatNumber();

			this->SetInfo(info);
		}
	}
	catch(...)
	{
		printf(lpMemScript->GetLastError());
	}

	delete lpMemScript;
}

void cCEffectPet::SetInfo(PET_EFFECT_CUSTOM info) // OK
{
	if(info.Index < 0 || info.Index >= MAX_CUSTOPETEFFECT)
	{
		return;
	}

	this->m_PetCEffect[info.Index] = info;
}
