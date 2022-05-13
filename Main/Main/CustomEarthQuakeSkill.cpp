#include "stdafx.h"
#include "CustomEarthQuakeSkill.h"
#include "Object.h"
#include "zzzmathlib.h"
#include "Util.h"
#include "CustomPet.h"
#include "Import.h"

int Externo;

#define pAngleMatrix2			((int(__cdecl*)(vec3_t a1, vec34_t a2)) 0x959CE0)
#define pVectorRotate2			((int(__cdecl*)(vec3_t a1, vec34_t a2, vec3_t a3)) 0x95A1E0)
#define pMoveSceneFrame			*(int*)0x00E8CB20
#define pEarthQuake				*(float*)0x08787D48
#define pCreateEffect			((int(__cdecl*)(int a4, vec3_t Bone1, float* a6, vec3_t color, int a8, int a9, __int16 a10, __int16 a11, __int16 a12, __int16 a13, float a14, __int16 a1)) 0x006D9070)

cCEarthQuake gCustomEarthQuake;

cCEarthQuake::cCEarthQuake()
{
	this->m_EarthQuake.clear();
}
cCEarthQuake::~cCEarthQuake()
{

}

void cCEarthQuake::Load(HORSE_EARTH_QUAKE * info)
{
	for( int n = 0; n < MAX_EARTH_QUAKE; n++)
	{
		if(info[n].Index < 0 || info[n].Index >= MAX_EARTH_QUAKE)
		{
			return;
		}
		this->m_EarthQuake.push_back(info[n]);
	}
}

void RenderDarkHorseSkill(lpModelObj lpObjModel, lpViewObj lpObj)
{
	lpViewObj Object = &*(ObjectPreview*)oUserPreviewStruct;

	if (lpObjModel && lpObj)
	{
		vec3_t Color;
		++lpObjModel->OnAttacking;

		if ( !(pMoveSceneFrame % 10) )

		for(std::vector<HORSE_EARTH_QUAKE>::iterator it = gCustomEarthQuake.m_EarthQuake.begin();it != gCustomEarthQuake.m_EarthQuake.end();it++)
		{
			if(it->ItemIndex == (*(DWORD *)((int)lpObjModel + 48) - 1171))
			{	
				Color[0] = it->ColorR;
				Color[1] = it->ColorG;
				Color[2] = it->ColorB;

				pCreateEffect(it->EffectCode, &lpObjModel->VecPosX, &lpObjModel->WorldPos.X, Color, it->EffectSize, 0, -1, 0, 0, 0, 0.0, -1);
			}
			else if (!gCustomPet2.CheckCustomPetByItem( *(DWORD *)((int)lpObjModel + 48) - 1171 ))
			{
				pCreateEffect(32279, &lpObjModel->VecPosX, &lpObjModel->WorldPos.X, &lpObjModel->ColorR, 0, 0, -1, 0, 0, 0, 0.0, -1);
			}
		}

		if ( lpObjModel->CoordX < 8.0 || lpObjModel->CoordX > 9.5 )
		{
			if ( lpObjModel->OnAttacking == 19 )
			{
				for(std::vector<HORSE_EARTH_QUAKE>::iterator it = gCustomEarthQuake.m_EarthQuake.begin();it != gCustomEarthQuake.m_EarthQuake.end();it++)
				{
					if(it->ItemIndex == (*(DWORD *)((int)lpObjModel + 48) - 1171))
					{
					    pCreateEffect(it->SkillEarthQuake1, &lpObjModel->VecPosX, &lpObjModel->WorldPos.X, &lpObjModel->ColorR, 0, (int)lpObjModel, -1, 0, 2, 0, 0.0, -1);
				    }
					else if (!gCustomPet2.CheckCustomPetByItem( *(DWORD *)((int)lpObjModel + 48) - 1171 ))
					{
					    pCreateEffect(301, &lpObjModel->VecPosX, &lpObjModel->WorldPos.X, &lpObjModel->ColorR, 0, (int)lpObjModel, -1, 0, 2, 0, 0.0, -1);
				    }
				}
				lpObjModel->OnAttacking = -3;
			}
		}
		else
		{
			for(std::vector<HORSE_EARTH_QUAKE>::iterator it = gCustomEarthQuake.m_EarthQuake.begin();it != gCustomEarthQuake.m_EarthQuake.end();it++)
			{
			    if ( lpObjModel->OnAttacking % 2 == 1 )
				{
				    vec3_t WorldPos;
				    vec3_t AnglePos;
				    Vector(0.0, (double)(lpObjModel->OnAttacking / 2) * 150.0, 0.0, WorldPos);
				    Vector(0.0, 0.0, (double)(rand() % 360), AnglePos);
				    vec34_t Matrix;
				    vec3_t ResultPosition;
				    for (int i = 0; i < 6; ++i )
					{
					    AnglePos[2] += 60;
					    pAngleMatrix2(AnglePos,Matrix);
					    pVectorRotate2(WorldPos,Matrix,ResultPosition);
					    ResultPosition[0] += lpObjModel->VecPosX;
					    ResultPosition[1] += lpObjModel->VecPosY;
					    ResultPosition[2] += lpObjModel->VecPosZ;
					    if(it->ItemIndex == (*(DWORD *)((int)lpObjModel + 48) - 1171))
						{
							pCreateEffect(it->SkillEarthQuake2, ResultPosition, &lpObjModel->WorldPos.X, &lpObjModel->ColorR, 0, 0, -1, 0, 0, 0, 0.0, -1);
					    }
						else if (!gCustomPet2.CheckCustomPetByItem(*(DWORD *)((int)lpObjModel + 48) - 1171 ))
						{
							pCreateEffect((rand() % 2) + 331, ResultPosition, &lpObjModel->WorldPos.X, &lpObjModel->ColorR, 0, 0, -1, 0, 0, 0, 0.0, -1);
						}
					}
					pEarthQuake = (double)(rand() % 3 - 3) * 0.699999988079071;
				}
			}
		}
	}
}

void cCEarthQuake::LoadRenderSkill()
{
	MemorySet(0x00502A95,0x90,0x5);
	SetCompleteHook(0xE8,0x00502A95,&RenderDarkHorseSkill);
}