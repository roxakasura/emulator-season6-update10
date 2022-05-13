#include "StdAfx.h"
#include "CustomJewelBank.h"
#include "MemScript.h"

JewelBank gJewelBank;

JewelBank::JewelBank()
{
	this->Init();
}
JewelBank::~JewelBank()
{

}

void JewelBank::Init()
{
	for(int n=0;n < MAX_JEWELBANK;n++)
	{
		this->m_JewelBank[n].Index = -1;
	};
}

void JewelBank::Load(char* path)
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
			JEWEL_BANK info;
			memset(&info,0,sizeof(info));
			static int CustomItemIndexCount = 0;

			info.Index = CustomItemIndexCount++;

			info.ID = lpMemScript->GetNumber();

			info.ItemID = lpMemScript->GetAsNumber();
		
			strcpy_s(info.ItemName,lpMemScript->GetAsString());

			this->SetInfo(info);
		}
	}
	catch(...)
	{
		printf(lpMemScript->GetLastError());
	}

	delete lpMemScript;
}

void JewelBank::SetInfo(JEWEL_BANK info)
{
	if(info.Index < 0 || info.Index >= MAX_JEWELBANK)
	{
		return;
	}
	this->m_JewelBank[info.Index] = info;
}
