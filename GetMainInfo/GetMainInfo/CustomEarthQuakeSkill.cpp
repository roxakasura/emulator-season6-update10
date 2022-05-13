#include "StdAfx.h"
#include "CustomEarthQuakeSkill.h"
#include "MemScript.h"

cCEarthQuake gCustomEarthQuake;

cCEarthQuake::cCEarthQuake()
{
	this->Init();
}
cCEarthQuake::~cCEarthQuake()
{

}

void cCEarthQuake::Init()
{
	for(int n=0;n < MAX_EARTH_QUAKE;n++)
	{
		this->m_EarthQuake[n].Index = -1;
	};
}

void cCEarthQuake::Load(char* path)
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
			HORSE_EARTH_QUAKE info;
			memset(&info,0,sizeof(info));
			static int CustomItemIndexCount = 0;
			info.Index = CustomItemIndexCount++;
			info.ItemIndex = lpMemScript->GetNumber();
			info.EffectCode = lpMemScript->GetAsNumber();
			info.ColorR = lpMemScript->GetAsFloatNumber();
			info.ColorG = lpMemScript->GetAsFloatNumber();
			info.ColorB = lpMemScript->GetAsFloatNumber();
			info.EffectSize = lpMemScript->GetAsNumber();
			info.SkillEarthQuake1 = lpMemScript->GetAsNumber();
			info.SkillEarthQuake2 = lpMemScript->GetAsNumber();
			this->SetInfo(info);
		}
	}
	catch(...)
	{
		printf(lpMemScript->GetLastError());
	}

	delete lpMemScript;
}

void cCEarthQuake::SetInfo(HORSE_EARTH_QUAKE info)
{
	if(info.Index < 0 || info.Index >= MAX_EARTH_QUAKE)
	{
		return;
	}
	this->m_EarthQuake[info.Index] = info;
}
