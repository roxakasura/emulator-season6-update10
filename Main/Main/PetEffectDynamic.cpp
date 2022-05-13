#include "StdAfx.h"
#include "PetEffectDynamic.h"
#include "CustomPet.h"
#include "Import.h"
#include "zzzmathlib.h"
#include "Util.h"
#include "Pet.h"
#include "PetGlow.h"

cCEffectDynamicPet gCustomCEffectDynamicPet;

cCEffectDynamicPet::cCEffectDynamicPet()
{
	this->m_PetDynamicCEffect.clear();
}

cCEffectDynamicPet::~cCEffectDynamicPet()
{

}

void cCEffectDynamicPet::Load(PET_DYNAMIC_CUSTOM * info)
{
	for (int n = 0; n < max_ceffectdin; n++)
	{
		if (info[n].Index < 0 || info[n].Index >= max_ceffectdin)
		{
			return;
		}
		this->m_PetDynamicCEffect.push_back(info[n]);
	}
}