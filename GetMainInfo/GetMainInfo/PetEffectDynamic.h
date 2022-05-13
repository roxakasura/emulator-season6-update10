#pragma once

#define max_ceffectdin 1000

struct PET_DYNAMIC_CUSTOM
{
	int Index;				  //int Index;
	int ItemIndex;			  //int ItemIndex;
	int EffectCode;			  //int EffectIndex;
	int Join;				  //int EffectValue;
	int TypeEffect;			  //int EffectLevel;
	float ColorR;			  //float ColorR;
	float ColorG;			  //float ColorG;
	float ColorB;			  //float ColorB;
	float Effect1;
	float EffectSize;		  //
	float Effect;
};

class cCEffectDynamicPet
{
public:
	cCEffectDynamicPet();
	virtual ~cCEffectDynamicPet();
	void Init();
	void Load(char* path);
	void SetInfo(PET_DYNAMIC_CUSTOM info);

public:
	PET_DYNAMIC_CUSTOM m_PetDynamicCEffect[max_ceffectdin];

}; extern cCEffectDynamicPet gCustomCEffectDynamicPet;
