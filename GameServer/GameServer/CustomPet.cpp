#include "stdafx.h"
#include "CustomPet.h"
#include "MemScript.h"
#include "Util.h"

CCustomPet gCustomPet;

CCustomPet::CCustomPet() // OK
{
	this->Init();
}


CCustomPet::~CCustomPet() // OK
{

}


void CCustomPet::Init() // OK
{
	for (int n = 0; n < MAX_CUSTOM_PET; n++)
	{
		this->m_CustomPetInfo[n].Index = -1;
	}
}


void CCustomPet::Load(char* path) // OK
{
	CMemScript* lpMemScript = new CMemScript;

	if (lpMemScript == 0)
	{
		ErrorMessageBox(MEM_SCRIPT_ALLOC_ERROR, path);
		return;
	}

	if (lpMemScript->SetBuffer(path) == 0)
	{
		ErrorMessageBox(lpMemScript->GetLastError());
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

			info.Index = lpMemScript->GetNumber();

			info.ItemIndex = lpMemScript->GetAsNumber();

			info.IsMontaria = lpMemScript->GetAsNumber();

			info.IsImortal = lpMemScript->GetAsNumber();

			info.IncLife = lpMemScript->GetAsNumber();

			info.IncMana = lpMemScript->GetAsNumber();

			info.IncDamageRate = lpMemScript->GetAsNumber();

			info.IncAttackSpeed = lpMemScript->GetAsNumber();

			info.IncDoubleDamageRate = lpMemScript->GetAsNumber();

			strcpy_s(info.ModelName, lpMemScript->GetAsString());

			this->SetInfo(info);
		}
	}
	catch (...)
	{
		ErrorMessageBox(lpMemScript->GetLastError());
	}

	delete lpMemScript;
}


void CCustomPet::SetInfo(CUSTOM_PET_INFO info) // OK
{
	if (info.Index < 0 || info.Index >= MAX_CUSTOM_PET)
	{
		return;
	}

	this->m_CustomPetInfo[info.Index] = info;
}


CUSTOM_PET_INFO* CCustomPet::GetInfo(int index) // OK
{
	if (index < 0 || index >= MAX_CUSTOM_PET)
	{
		return 0;
	}

	if (this->m_CustomPetInfo[index].Index != index)
	{
		return 0;
	}

	return &this->m_CustomPetInfo[index];
}


CUSTOM_PET_INFO* CCustomPet::GetInfoByItem(int ItemIndex) // OK
{
	for (int n = 0; n < MAX_CUSTOM_PET; n++)
	{
		CUSTOM_PET_INFO* lpInfo = this->GetInfo(n);

		if (lpInfo == 0)
		{
			continue;
		}

		if (lpInfo->ItemIndex == ItemIndex)
		{
			return lpInfo;
		}
	}

	return 0;
}


bool CCustomPet::CheckCustomPet(int index) // OK
{
	if (this->GetInfo(index) != 0)
	{
		return 1;
	}

	return 0;
}

bool CCustomPet::CheckCustomPetByItem(int ItemIndex) // OK
{
	if (this->GetInfoByItem(ItemIndex) != 0)
	{
		return 1;
	}

	return 0;
}

int CCustomPet::GetCustomPetIsMontaria(int ItemIndex) // OK
{
	CUSTOM_PET_INFO* lpInfo = this->GetInfoByItem(ItemIndex);

	if (lpInfo == 0)
	{
		return 0;
	}

	return (lpInfo->IsMontaria);
}

bool CCustomPet::CheckCustomPetIsMontaria(int ItemIndex) // OK
{
	if (this->GetCustomPetIsMontaria(ItemIndex) != 0)
	{
		return 1;
	}

	return 0;
}

int CCustomPet::GetCustomPetIndex(int ItemIndex) // OK
{
	CUSTOM_PET_INFO* lpInfo = this->GetInfoByItem(ItemIndex);

	if (lpInfo == 0)
	{
		return 0;
	}

	return lpInfo->Index;
}

int CCustomPet::GetCustomPetDamageRate(int ItemIndex) // OK
{
	CUSTOM_PET_INFO* lpInfo = this->GetInfoByItem(ItemIndex);

	if (lpInfo == 0)
	{
		return 0;
	}

	return (lpInfo->IncDamageRate);
}


int CCustomPet::GetCustomPetLife(int ItemIndex) // OK
{
	CUSTOM_PET_INFO* lpInfo = this->GetInfoByItem(ItemIndex);

	if (lpInfo == 0)
	{
		return 0;
	}

	return (lpInfo->IncLife);
}


int CCustomPet::GetCustomPetMana(int ItemIndex) // OK
{
	CUSTOM_PET_INFO* lpInfo = this->GetInfoByItem(ItemIndex);

	if (lpInfo == 0)
	{
		return 0;
	}

	return (lpInfo->IncMana);
}

int CCustomPet::GetCustomPetAttackSpeed(int ItemIndex) // OK
{
	CUSTOM_PET_INFO* lpInfo = this->GetInfoByItem(ItemIndex);

	if (lpInfo == 0)
	{
		return 0;
	}

	return (lpInfo->IncAttackSpeed);
}


int CCustomPet::GetCustomPetDoubleDamageRate(int ItemIndex) // OK
{
	CUSTOM_PET_INFO* lpInfo = this->GetInfoByItem(ItemIndex);

	if (lpInfo == 0)
	{
		return 0;
	}

	return (lpInfo->IncDoubleDamageRate);
}

/*
long CCustomPet::GetCustomPetExperienceRate(int ItemIndex) // OK
{
	CUSTOM_PET_INFO CustomPetInfo;

	if(this->GetCustomMonsterInfo(index,map,&CustomMonsterInfo) == 0)
	{
		return 100;
	}
	else
	{
		return ((CustomMonsterInfo.ExperienceRate==-1)?100:CustomMonsterInfo.ExperienceRate);
	}
}


long CCustomPet::GetCustomPetMasterExperienceRate(int ItemIndex) // OK
{
	CUSTOM_PET_INFO CustomPetInfo;

	if(this->GetCustomMonsterInfo(index,map,&CustomMonsterInfo) == 0)
	{
		return 100;
	}
	else
	{
		return ((CustomMonsterInfo.ExperienceRate==-1)?100:CustomMonsterInfo.ExperienceRate);
	}
}
*/

int CCustomPet::GetCustomPetIsImortal(int ItemIndex) // OK
{
	CUSTOM_PET_INFO* lpInfo = this->GetInfoByItem(ItemIndex);

	if (lpInfo == 0)
	{
		return 0;
	}

	return (lpInfo->IsImortal);
}

bool CCustomPet::CheckCustomPetIsImortal(int ItemIndex) // OK
{
	if (this->GetCustomPetIsImortal(ItemIndex) != 0)
	{
		return 1;
	}

	return 0;
}


void CCustomPet::CalcCustomPetOption(LPOBJ lpObj, bool flag)
{
	if (flag != 0)
	{
		return;
	}

	CItem* Helper = &lpObj->Inventory[8];

	if (this->CheckCustomPetByItem(Helper->m_Index) != 0)
	{
		lpObj->AddLife += GetCustomPetLife(Helper->m_Index);
		lpObj->AddMana += GetCustomPetMana(Helper->m_Index);
		lpObj->PhysiSpeed += GetCustomPetAttackSpeed(Helper->m_Index);
		lpObj->MagicSpeed += GetCustomPetAttackSpeed(Helper->m_Index);
		lpObj->DoubleDamageRate += GetCustomPetDoubleDamageRate(Helper->m_Index);
		lpObj->IsMontaria += GetCustomPetIsMontaria(Helper->m_Index);
	}

}