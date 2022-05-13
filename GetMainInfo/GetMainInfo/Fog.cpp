#include "stdafx.h"
#include "Fog.h" 
#include "MemScript.h"

cFog gFog;

cFog::cFog()
{
	this->Init();
}

cFog::~cFog()
{
	
}

void cFog::Init()
{
	for (int n = 0; n < MAX_FOG; n++)
	{
		this->m_CustomFog[n].Index = -1;
	}
}

void cFog::Load(char* path)
{
	CMemScript* lpMemScript = new CMemScript;

	int Index = 0;

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

			CUSTOM_FOG info;

			info.Index = Index++;

			info.MapNumber = lpMemScript->GetNumber();

			info.Red = lpMemScript->GetAsNumber();

			info.Green = lpMemScript->GetAsNumber();

			info.Blue = lpMemScript->GetAsNumber();

			this->SetInfo(info);
		}
	}
	catch(...)
	{
		printf(lpMemScript->GetLastError());
	}

	delete lpMemScript;
}

void cFog::SetInfo(CUSTOM_FOG info)
{
	if(info.Index < 0 || info.Index >= MAX_FOG)
	{
		return;
	}
	this->m_CustomFog[info.Index] = info;
}