// CustomItem.cpp: implementation of the cCustomBow class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "CustomCrossBow.h"
#include "MemScript.h"

cCustomBow gCustomCrossBow;
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

cCustomBow::cCustomBow() // OK
{
	this->Init();
}

cCustomBow::~cCustomBow() // OK
{

}

void cCustomBow::Init() // OK
{
	for(int n=0;n < MAX_CUSTOM_BOW;n++)
	{
		this->m_CustomBowInfo[n].Index = -1;
	}
}

void cCustomBow::Load(char* path) // OK
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

			CUSTOM_BOW_INFO info;

			memset(&info,0,sizeof(info));

			static int CustomItemIndexCount = 0;

			info.Index = CustomItemIndexCount++;

			info.ItemIndex = lpMemScript->GetNumber();

			strcpy_s(info.ModelName,lpMemScript->GetAsString());

			info.ItemType = lpMemScript->GetAsNumber();

			info.SkillShot = lpMemScript->GetAsNumber();

			info.ColorR = lpMemScript->GetAsNumber();

			info.ColorG = lpMemScript->GetAsNumber();

			info.ColorB = lpMemScript->GetAsNumber();

			this->SetInfo(info);
		}
	}
	catch(...)
	{
		printf(lpMemScript->GetLastError());
	}

	delete lpMemScript;
}

void cCustomBow::SetInfo(CUSTOM_BOW_INFO info) // OK
{
	if(info.Index < 0 || info.Index >= MAX_CUSTOM_BOW)
	{
		return;
	}

	this->m_CustomBowInfo[info.Index] = info;
}