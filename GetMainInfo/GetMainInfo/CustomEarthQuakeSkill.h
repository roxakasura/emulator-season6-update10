#pragma once

#define MAX_EARTH_QUAKE 512

struct HORSE_EARTH_QUAKE{
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
	void Init();
	void Load(char* path);
	void SetInfo(HORSE_EARTH_QUAKE info);

public:
	HORSE_EARTH_QUAKE m_EarthQuake [MAX_EARTH_QUAKE];

}; extern cCEarthQuake gCustomEarthQuake;