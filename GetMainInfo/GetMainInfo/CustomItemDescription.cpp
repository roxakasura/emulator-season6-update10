// CustomItem.cpp: implementation of the CCustomItem class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "CustomItemDescription.h"
#include "MemScript.h"

CCustomItemDescription gCustomItemDescription;
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CCustomItemDescription::CCustomItemDescription() // OK
{
	this->Init();
}

CCustomItemDescription::~CCustomItemDescription() // OK
{

}

void CCustomItemDescription::Init() // OK
{
	for(int n=0;n < MAX_DESCRIPTION_ITEM;n++)
	{
		this->m_Info[n].Index = -1;
	}
}

void CCustomItemDescription::Load(char* path) // OK
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

			CUSTOM_DESCRIPTION_INFO info;

			memset(&info,0,sizeof(info));

			static int CustomItemIndexCount = 0;

			info.Index = CustomItemIndexCount++;

			info.ItemIndex = lpMemScript->GetNumber();

			info.Line = lpMemScript->GetAsNumber();

			info.Color = lpMemScript->GetAsNumber();

			info.Border = lpMemScript->GetAsNumber();

			strcpy_s(info.Description,lpMemScript->GetAsString());

			this->SetInfo(info);
		}
	}
	catch(...)
	{
		printf(lpMemScript->GetLastError());
	}

	delete lpMemScript;
}

void CCustomItemDescription::SetInfo(CUSTOM_DESCRIPTION_INFO info) // OK
{
	if(info.Index < 0 || info.Index >= MAX_DESCRIPTION_ITEM)
	{
		return;
	}

	this->m_Info[info.Index] = info;
}
