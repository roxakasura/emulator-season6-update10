#pragma once

#define max_ceffect 1000
#define MAX_CUSTOPETEFFECT	1000

struct PET_EFFECT_CUSTOM
{
	int Index;				//int Index
	int ItemIndex;			//int ItemIndex
	int EffectCode;			//int EffectIndex;
	int Join;				//int EffectValue
	int TypeEffect;			// -descartável
//	int LargeRand;			// -descartável
	float ColorR;			//float ColorR;
	float ColorG;			//float ColorG;
	float ColorB;			//float ColorB;
	float EffectSize;		//float ColorSize;
	float ColorMain;
	float ColorSide;
};

class cCEffectPet
{
public:
	cCEffectPet();
	virtual ~cCEffectPet();
	void Init();
	void Load(char* path);
	void SetInfo(PET_EFFECT_CUSTOM info);

public:
	PET_EFFECT_CUSTOM m_PetCEffect [max_ceffect];

}; extern cCEffectPet gCustomCEffectPet;