#include "stdafx.h"
#include "CustomItemPosition.h"
#include "MemScript.h"

cCustomPosition gCustomPosition;

cCustomPosition::cCustomPosition() // OK
{
	this->Init();
}

cCustomPosition::~cCustomPosition() // OK
{

}

void cCustomPosition::Init() // OK
{
	for (int n = 0; n < MAX_POSITION_ITEM; n++)
	{
		this->m_CustomPositionInfo[n].Index = -1;
	}
}

void cCustomPosition::Load(char* path) // OK
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

			CUSTOM_POSITION_INFO info;

			memset(&info, 0, sizeof(info));

			static int CustomItemIndexCount = 0;

			info.Index = CustomItemIndexCount++;

			info.ItemIndex = lpMemScript->GetNumber();

			info.translationX = lpMemScript->GetAsFloatNumber();

			info.translationY = lpMemScript->GetAsFloatNumber();

			info.RotationX = lpMemScript->GetAsFloatNumber();

			info.RotationY = lpMemScript->GetAsFloatNumber();

			info.RotationZ = lpMemScript->GetAsFloatNumber();

			info.Scale = lpMemScript->GetAsFloatNumber();

			this->SetInfo(info);
		}
		
	}
	catch (...)
	{
		printf(lpMemScript->GetLastError());
	}

	delete lpMemScript;
}

void cCustomPosition::SetInfo(CUSTOM_POSITION_INFO info) // OK
{
	if (info.Index < 0 || info.Index >= MAX_POSITION_ITEM)
	{
		return;
	}

	this->m_CustomPositionInfo[info.Index] = info;
}
