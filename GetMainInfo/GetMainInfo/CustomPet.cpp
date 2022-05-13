#include "stdafx.h"
#include "CustomPet.h"
#include "MemScript.h"

cCustomPet gCustomPet2;

cCustomPet::cCustomPet() // OK
{
	this->Init();
}

cCustomPet::~cCustomPet() // OK
{

}

void cCustomPet::Init() // OK
{
	for (int n = 0; n < MAX_PET_ITEM; n++)
	{
		this->m_CustomPetInfo[n].Index = -1;
	}
}

void cCustomPet::Load(char* path) // OK
{
	CMemScript* lpMemScript = new CMemScript;

	if (lpMemScript == 0)
	{
		printf(MEM_SCRIPT_ALLOC_ERROR, path);
		return;
	}

	if (lpMemScript->SetBuffer(path) == 0)
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
            CUSTOM_PET_INFO info;
            memset(&info, 0, sizeof(info));
            static int CustomItemIndexCount = 0;
            info.Index = CustomItemIndexCount++;
            info.ItemIndex = lpMemScript->GetNumber();
			info.IndexInventory = lpMemScript->GetAsNumber();
            info.PetType = lpMemScript->GetAsNumber();
            info.Scale_View = lpMemScript->GetAsFloatNumber();
            info.Scale_Drop = lpMemScript->GetAsFloatNumber();
            info.Scale_Inve = lpMemScript->GetAsFloatNumber();
            info.Scale_X = lpMemScript->GetAsFloatNumber();
            info.Scale_Y = lpMemScript->GetAsFloatNumber();
			info.Scale_Angle = lpMemScript->GetAsFloatNumber();
            info.FenrrirEffect = lpMemScript->GetAsNumber();
            strcpy_s(info.ModelName,lpMemScript->GetAsString());
            this->SetInfo(info);
        }
	}
	catch (...)
	{
		printf(lpMemScript->GetLastError());
	}

	delete lpMemScript;
}

void cCustomPet::SetInfo(CUSTOM_PET_INFO info) // OK
{
	if (info.Index < 0 || info.Index >= MAX_PET_ITEM)
	{
		return;
	}

	this->m_CustomPetInfo[info.Index] = info;
}
