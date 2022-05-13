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
	void Load(CUSTOM_SMOKEEFFECT* info);
	void SetInfo(CUSTOM_SMOKEEFFECT info);
	CUSTOM_SMOKEEFFECT* GetEffect(int ItemID);
	CUSTOM_SMOKEEFFECT* GetEffectByIndex(int Index);
	int GetItemID(int ItemID);
	float GetRedColor(int ItemID);
	float GetGreenColor(int ItemID);
	float GetBlueColor(int ItemID);
public:
	CUSTOM_SMOKEEFFECT m_CustomSmokeEffect[MAX_SMOKE_ITEMS];
}; extern cSmokeEffect gSmokeEffect;