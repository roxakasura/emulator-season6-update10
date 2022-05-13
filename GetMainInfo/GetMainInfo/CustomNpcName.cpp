#include "stdafx.h"
#include "CustomNpcName.h"
#include "MemScript.h"

cNPCName gNPCName;

cNPCName::cNPCName()
{
	
}

cNPCName::~cNPCName()
{

}

void cNPCName::Init()
{
	for (int n = 0; n < MAX_CUSTOM_NPCNAME; n++)
	{
		this->m_CustomNpcName[n].Index = -1;
	}
}

void cNPCName::Load(char* path)
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

			NPCNAME_DATA info;

			memset(&info,0,sizeof(info));

			static int CustomIndexCount = 0;

			info.Index = CustomIndexCount++;

			info.NPCId = lpMemScript->GetNumber();

			info.Map = lpMemScript->GetAsNumber();

			info.X = lpMemScript->GetAsNumber();

			info.Y = lpMemScript->GetAsNumber();

			strcpy_s(info.Name,lpMemScript->GetAsString());

			this->SetInfo(info);
		}
	}
	catch(...)
	{
		printf(lpMemScript->GetLastError());
	}

	delete lpMemScript;
}

void cNPCName::SetInfo(NPCNAME_DATA info)
{
	if(info.Index < 0 || info.Index >= MAX_CUSTOM_NPCNAME)
	{
		return;
	}
	this->m_CustomNpcName[info.Index] = info;
}