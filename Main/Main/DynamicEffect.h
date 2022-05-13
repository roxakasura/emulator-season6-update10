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
	float Effect1;
	float Effect2;
	float Effect;
};

class CDynamicWingEffect
{
public:
	CDynamicWingEffect();
	virtual ~CDynamicWingEffect();
	void Load(DYNAMIC_WING_EFFECT_INFO* info);
public:
	std::map<int,DYNAMIC_WING_EFFECT_INFO> m_DynamicWingEffectInfo;
};

extern CDynamicWingEffect gDynamicWingEffect;
