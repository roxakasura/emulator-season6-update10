#include "stdafx.h"
#include "CustomMonster.h"
#include "MemScript.h"

cCustomMonsters gMonsters;

cCustomMonsters::cCustomMonsters()
{
	this->Init();
}

cCustomMonsters::~cCustomMonsters()
{
	
}

void cCustomMonsters::Init()
{
	for (int n = 0; n < MAX_CUSTOMMONSTER; n++)
	{
		this->m_Monsters[n].Index = -1;
	}
}

void cCustomMonsters::Load(char * path)
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

			CUSTOMMONSTER_DATA info;

			info.Index = Index++;

			info.ID = lpMemScript->GetNumber();

			info.Type = lpMemScript->GetAsNumber();

			strcpy_s(info.Name,lpMemScript->GetAsString());

			strcpy_s(info.Dir,lpMemScript->GetAsString());

			strcpy_s(info.Folder,lpMemScript->GetAsString());

			strcpy_s(info.BMDFile,lpMemScript->GetAsString());

			info.Size = lpMemScript->GetAsFloatNumber();

			this->SetInfo(info);
		}
	}
	catch(...)
	{
		printf(lpMemScript->GetLastError());
	}

	delete lpMemScript;
}

void cCustomMonsters::SetInfo(CUSTOMMONSTER_DATA info)
{
	if(info.Index < 0 || info.Index >= MAX_CUSTOMMONSTER)
	{
		return;
	}

	this->m_Monsters[info.Index] = info;
}