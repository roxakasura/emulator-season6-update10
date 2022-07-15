#include "StdAfx.h"
#include "CustomPetEffect.h"
#include "CustomPet.h"
#include "Import.h"
#include "zzzmathlib.h"
#include "Util.h"
#include "Pet.h"
#include "PetGlow.h"
#include "PetEffectDynamic.h"

cCEffectPet gCustomCEffectPet;

cCEffectPet::cCEffectPet()
{
	this->m_PetCEffect.clear();
}

cCEffectPet::~cCEffectPet()
{

}

void cCEffectPet::Load(PET_EFFECT_CUSTOM * info)
{
	for( int n = 0; n < max_ceffect; n++)
	{
		if(info[n].Index < 0 || info[n].Index >= max_ceffect)
		{
			return;
		}
		this->m_PetCEffect.push_back(info[n]);
	}
}

void cCEffectPet::addEffect(int a1, int a2, int a3, int a4) // OK
{
	Draw_RenderObjectR(a1, a2, a3, a4);
	int v42; // eax@182
	vec3_t Bone;
	vec3_t Color;
	vec3_t WorldPos;
	//
	int ModelE;
	LPVOID v397 = pGetModel(pModelThis(), *(DWORD *)(a1 + 48));
	ModelE = (int)v397;
	if ( !v397 )
	{
		return;
	}

	if ( !0x81C03BC && (0x81C03BC || *(DWORD *)(a1 + 60) == -2) )
	{
		return;
	}

	if ( v397 )
	{
		if ( gCustomPet2.CheckCustomPetByItem(*(DWORD *)(a1 + 48) - 1171) )
		{
			if (gCustomPet2.GetInfoPetType(*(DWORD*)(a1 + 48) - 1171) == 1 ||
				gCustomPet2.GetInfoPetType(*(DWORD*)(a1 + 48) - 1171) == 2 || 
				gCustomPet2.GetInfoPetType(*(DWORD*)(a1 + 48) - 1171) == 3)
			{
				//-- Sombra
				if (pMapNumber != 10 && !pCheckMap(pMapNumber))
				{
					v42 = sub_4DB250();
					if (!sub_4E44A0(v42 + 132))
					{
						if (*(DWORD*)(a1 + 48) != 8045) //não apagar, futuramente usarei.
						{
							EnableAlphaTest(1);
							if (pMapNumber == 7)
								glColor4f(0.0, 0.0, 0.0, 0.2);
							else
								glColor4f(0.0, 0.0, 0.0, 0.69558);
							//sub_54A270(v401, *(_DWORD *)(a1 + 68), v399, -1, -1);
							ShadowMaster(ModelE, -1, 5, -1, -1);
							pGLSwitch();
							EnableAlphaTest(0);
						}
					}
				}
			}
		}
		for(std::vector<PET_EFFECT_CUSTOM>::iterator it = gCustomCEffectPet.m_PetCEffect.begin();it != gCustomCEffectPet.m_PetCEffect.end();it++)
		{
			if(it->ItemIndex== (*(DWORD *)(a1 + 48) - 1171))
			{
				Vector(it->ColorR, it->ColorG, it->ColorB, Color);//<<Color
				Vector( 0.0, 0.0, 0.0, WorldPos);//<<Posicion a partir del Joint

				TransformPosition((int)v397, Joint(it->Join), WorldPos, Bone, 0);

				CreateSprite(it->EffectCode, Bone, it->EffectSize, Color, a1, it->ColorMain, it->ColorSide);//<<Estatico antiga

			}
		}
		for (std::vector<PET_DYNAMIC_CUSTOM>::iterator it2 = gCustomCEffectDynamicPet.m_PetDynamicCEffect.begin(); it2 != gCustomCEffectDynamicPet.m_PetDynamicCEffect.end(); it2++)
		{
			if (it2->ItemIndex == (*(DWORD *)(a1 + 48) - 1171))
			{
				Vector(it2->ColorR, it2->ColorG, it2->ColorB, Color);//<<Color
				Vector(0.0, 0.0, 0.0, WorldPos);//<<Posicion a partir del Joint

				TransformPosition((int)v397, Joint(it2->Join), WorldPos, Bone, 0);

				//CreateParticle2(it2->EffectCode, Bone, a1 + 264, Color, 0.0, it2->EffectSize, 1);//<<Dinamico original

				CreateParticle2(it2->EffectCode, Bone, a1 + 264, Color, it2->Effect1, it2->EffectSize, it2->Effect);//<<Dinamico
				CreateParticle2(it2->EffectCode, Bone, a1 + 264, Color, it2->Effect1, it2->EffectSize, it2->Effect);//<<Dinamico

			}
		}

		for(std::vector<RENDER_MESH>::iterator it = cRender.m_RenderMeshPet.begin();it != cRender.m_RenderMeshPet.end();it++)
		{
			if(it->ItemIndex== (*(DWORD *)(a1 + 48) - 1171))
			{
				glColor3fv((GLfloat*)(ModelE+72));
				*(float *)(ModelE + 72) = (float)(it->ColorR / 255.0f);
				*(float *)(ModelE + 76) = (float)(it->ColorG / 255.0f);
				*(float *)(ModelE + 80) = (float)(it->ColorB / 255.0f);
				*(float *)(ModelE + 100) = (float)(it->ColorR / 255.0f);
				*(float *)(ModelE + 104) = (float)(it->ColorG / 255.0f);
				*(float *)(ModelE + 108) = (float)(it->ColorB / 255.0f);
				//*(DWORD *)(a1 + 60) = -2;
				RenderMesh(ModelE,it->EffectIndex,it->EffectType,*(float *)(a1 + 152),*(float *)(a1 + 68),*(float *)(a1 + 100),*(float *)(a1 + 104),*(float *)(a1 + 108),-1);
				RenderMesh(ModelE,it->EffectIndex,it->EffectType,*(float *)(a1 + 152),*(float *)(a1 + 68),*(float *)(a1 + 100),*(float *)(a1 + 104),*(float *)(a1 + 108),-1);
			}
		}
	}
}

void cCEffectPet::Init() // OK
{
	SetCompleteHook(0xE8, 0x0056F476, &this->addEffect);
	SetCompleteHook(0xE8, 0x005EBBE6, &this->addEffect);
}