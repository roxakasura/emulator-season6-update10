#include "stdafx.h"
#include "Defines.h"
#include "Import.h"
#include "CustomCloak.h"

cCustomCloak gCloak;

cCustomCloak::cCustomCloak() // OK
{
	this->Init();
}
// -------------------------------------------------------------------------------
cCustomCloak::~cCustomCloak() // OK
{

}
// -------------------------------------------------------------------------------
void cCustomCloak::Init() // OK
{
	for(int n=0;n < MAX_CUSTOMCLOAK;n++)
	{
		this->m_Cloak[n].Index = -1;

		this->m_Cloak[n].IndexCloak = -1;

		this->m_Cloak[n].IndexStrip = -1;
	}
}
// -------------------------------------------------------------------------------
void cCustomCloak::Load(CUSTOMCLOAK_DATA* info) // OK
{
	for(int n=0;n < MAX_CUSTOMCLOAK;n++)
	{
		this->SetInfo(info[n]);
	}
}
// -------------------------------------------------------------------------------
void cCustomCloak::SetInfo(CUSTOMCLOAK_DATA info) // OK
{
	if(info.Index < 0 || info.Index >= MAX_CUSTOMCLOAK)
	{
		return;
	}

	this->m_Cloak[info.Index] = info;
}
// -------------------------------------------------------------------------------
CUSTOMCLOAK_DATA* cCustomCloak::GetInfo(int index) // OK
{
	if(index < 0 || index >= MAX_CUSTOMCLOAK)
	{
		return 0;
	}

	if(this->m_Cloak[index].Index != index)
	{
		return 0;
	}

	return &this->m_Cloak[index];
}
// -------------------------------------------------------------------------------
CUSTOMCLOAK_DATA* cCustomCloak::GetInfoByItem(int ItemIndex) // OK
{
	for(int n=0;n < MAX_CUSTOMCLOAK;n++)
	{
		CUSTOMCLOAK_DATA* lpInfo = this->GetInfo(n);

		if(lpInfo == 0)
		{
			continue;
		}

		if(lpInfo->ItemIndex == ItemIndex)
		{
			return lpInfo;
		}
	}

	return 0;
}
// -------------------------------------------------------------------------------
bool cCustomCloak::isCloak(int ItemIndex) // OK
{
	for (int i = 0 ; i < MAX_CUSTOMCLOAK ; i++)
	{
		if (ItemIndex == this->m_Cloak[i].ItemIndex)
		{
			return true;
		}
	}
	return false;
}

// -------------------------------------------------------------------------------
DWORD cCustomCloak::getCodeCape(int ItemIndex) // OK
{
	for (int i = 0 ; i < MAX_CUSTOMCLOAK ; i++)
	{
		if (ItemIndex == this->m_Cloak[i].ItemIndex)
		{
			return this->m_Cloak[i].IndexCloak;
		}
	}
	return -1;
}

// -------------------------------------------------------------------------------
bool cCustomCloak::isCloakStrip(int ItemIndex) // OK
{
	for (int i = 0 ; i < MAX_CUSTOMCLOAK ; i++)
	{
		if (ItemIndex == this->m_Cloak[i].ItemIndex && this->m_Cloak[i].Mode == 1)
		{
			return true;
		}
	}
	return false;
}
// -------------------------------------------------------------------------------
void cCustomCloak::LoadTexture() // OK
{
	this->code = 0x16305;

	for(int n=0;n < MAX_CUSTOMCLOAK;n++)
	{
		if(this->m_Cloak[n].Index != -1){

			pLoadImage(this->m_Cloak[n].CloakName, this->code, GL_LINEAR, GL_REPEAT, 1, 0);
			
			this->m_Cloak[n].IndexCloak = this->code;

			this->code++;

			if(this->m_Cloak[n].Mode == 1){

				pLoadImage(this->m_Cloak[n].StripName, this->code, GL_LINEAR, GL_REPEAT, 1, 0);

				this->m_Cloak[n].IndexStrip = this->code;

				this->code++;
			}
		}
	}
}