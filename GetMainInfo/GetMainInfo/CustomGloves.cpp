#include "stdafx.h"
#include "CustomGloves.h"
#include "MemScript.h"

CCustomGloves gCustomGloves;

CCustomGloves::CCustomGloves() // OK
{
	this->Init();
}

CCustomGloves::~CCustomGloves() // OK
{

}

void CCustomGloves::Init() // OK
{
	for(int n=0;n < MAX_CUSTOM_GLOVES;n++)
	{
		this->m_CustomGlovesInfo[n].Index = -1;
	}
}

void CCustomGloves::Load(char* path)
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

			CUSTOM_RF_GLOVES info;

			memset(&info,0,sizeof(info));

			static int CustomItemIndexCount = 0;

			info.Index = CustomItemIndexCount++;

			info.ItemIndex = lpMemScript->GetNumber();

			strcpy_s(info.ModelName,lpMemScript->GetAsString());

			info.TextureLeftIndex = lpMemScript->GetAsNumber();

			strcpy_s(info.TextureLeftName,lpMemScript->GetAsString());

			info.TextureRightIndex = lpMemScript->GetAsNumber();

			strcpy_s(info.TextureRightName,lpMemScript->GetAsString());

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

void CCustomGloves::SetInfo(CUSTOM_RF_GLOVES info) // OK
{
	if(info.Index < 0 || info.Index >= MAX_CUSTOM_GLOVES)
	{
		return;
	}

	this->m_CustomGlovesInfo[info.Index] = info;
}

