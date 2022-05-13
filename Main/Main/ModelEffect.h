//--
// BY: TAKUMI12 ©
//--
#pragma once

#define MAX_MODEL_EFFECT 1000

#define pSkillEffect				((void(__cdecl*)(int a1, int a2, int a3, float * a4, int a5, int a6, __int16 a7, __int16 a8, __int16 a9, __int16 a10, float a11, __int16 a12)) 0x6D9070)

struct MU3Float
{
	float X;
	float Y;
	float Z;
};

struct CUSTOM_MODEL_EFFECT_INFO
{
	int		Index;
	int		ItemType;
	int		ItemIndex;
	int		MinLevel;
	int		MaxLevel;
	int		MinExcellent;
	int		MaxExcellent;
	float	Color[3];
	int		EffectIndex;
	int		EffectType;
	int		EffectCode;
	float	EffectScale;
};

class CCustomModelEffect
{
public:
	CCustomModelEffect();
	virtual ~CCustomModelEffect();
	void Load(CUSTOM_MODEL_EFFECT_INFO* info);
	bool ModelComplete(short a1, BYTE a2, BYTE a3);
	void ModelRenderEffect(int EffectType,int EffectCode ,DWORD * lBone, int lBone2, float * Color, int EffectMode, float Scale);
	static void ModelEffectRender(DWORD ObjectPointer,DWORD Model, DWORD a3);
public:
	std::map<int,CUSTOM_MODEL_EFFECT_INFO> m_CustomModelEffectInfo;
};

extern CCustomModelEffect gCustomModelEffect;
