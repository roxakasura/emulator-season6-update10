// CustomWingEffect.h: interface for the CCustomWingEffect class.
//
//////////////////////////////////////////////////////////////////////

#pragma once


struct DYNAMIC_WING_EFFECT_INFO
{
	int Index;
	int ItemIndex;
	int EffectIndex;
	int EffectValue;
	int EffectLevel;
	float ColorR;
	float ColorG;
	float ColorB;
	float ColorSize;
	float ColorMain;
	float ColorSide;
};

class CDynamicWingEffect
{
public:
	CDynamicWingEffect();
	virtual ~CDynamicWingEffect();
	void Init();
	void Load(char* path);
	void SetInfo(DYNAMIC_WING_EFFECT_INFO info);
public:
	DYNAMIC_WING_EFFECT_INFO m_DynamicWingEffectInfo[MAX_DYNAMIC_WING_EFFECT];
};

extern CDynamicWingEffect gDynamicWingEffect;
