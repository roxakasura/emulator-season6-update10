#pragma once

#define MAX_SMOKE_ITEMS 500

struct CUSTOM_SMOKEEFFECT
{
	int Index;
	int ItemIndex;
	float Red;
	float Green;
	float Blue;
};

class cSmokeEffect
{
public:
	cSmokeEffect();
	virtual ~cSmokeEffect();
	void Init();
	void Load(char* path);
	void SetInfo(CUSTOM_SMOKEEFFECT info);
public:
	CUSTOM_SMOKEEFFECT m_CustomSmokeEffect[MAX_SMOKE_ITEMS];
}; extern cSmokeEffect gSmokeEffect;