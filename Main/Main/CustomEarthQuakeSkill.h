#pragma once

#define MAX_EARTH_QUAKE 512

#include <vector>


extern int Externo;


struct HORSE_EARTH_QUAKE
{
	int Index;
	int ItemIndex;
	int EffectCode;
	int ColorR;
	int ColorG;
	int ColorB;
	int EffectSize;
	int SkillEarthQuake1;
	int SkillEarthQuake2;
};

class cCEarthQuake
{
public:
	cCEarthQuake();
	virtual ~cCEarthQuake();
	void Load(HORSE_EARTH_QUAKE* info);
	void LoadRenderSkill();
public:
	std::vector<HORSE_EARTH_QUAKE> m_EarthQuake;
}; extern cCEarthQuake gCustomEarthQuake;